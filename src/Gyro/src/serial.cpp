/*
Copyright (c) 2018, 2019, NVIDIA CORPORATION. All rights reserved.

NVIDIA CORPORATION and its licensors retain all intellectual property
and proprietary rights in and to this software, related documentation
and any modifications thereto. Any use, reproduction, disclosure or
distribution of this software and related documentation without an express
license agreement from NVIDIA CORPORATION is strictly prohibited.
*/
#include "serial.hpp"
#include "ros/ros.h" ////////////////
#include "ros/time.h"

#include <errno.h>      // Error number definitions
#include <fcntl.h>      // File control definitions
#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // memset
#include <sys/ioctl.h>
#include <sys/poll.h>
#include <termios.h>    // POSIX terminal control definitions
#include <unistd.h>     // UNIX standard function definitions

#include <string>

#include "serial_baudrate.hpp"

Serial::Serial(const std::string& dev_port, int baudrate) : port_name_(dev_port) {

  fd_ = open(port_name_.c_str(), O_RDWR | O_NOCTTY | O_NONBLOCK | O_APPEND | O_NDELAY);

  ROS_INFO ("Port : %s, baudrate : %d", port_name_.c_str(), baudrate);

  if (fd_ == -1) {
    ROS_WARN ("Cannot open %s: %s [errno %d]", port_name_.c_str(), strerror(errno), errno);
  }

  // Set baud rate
  // Must be set before any termios operations
  SetSerialBaudrate(fd_, baudrate);

  // set no delay
  if (fcntl(fd_, F_SETFL, FNDELAY)) {
    ROS_WARN("Error configuring %s: %s [errno %d]", port_name_.c_str(), strerror(errno), errno);
  }


  // begin termios operations
  // see http://man7.org/linux/man-pages/man3/tcflow.3.html


}


void Serial::setReadPacaketSize(int packet_size)
{
    struct termios tty;
    memset(&tty, 0, sizeof(tty));

    if (tcgetattr(fd_, &tty) < 0) {
      ROS_WARN("Error configuring %s: %s [errno %d]", port_name_.c_str(), strerror(errno), errno);
    }

    // Make raw
    cfmakeraw(&tty);

    // control flags
    tty.c_cflag &= ~CSTOPB;           // Single stop bit
    tty.c_cflag &= ~CRTSCTS;          // No hardware flow control
    tty.c_cflag |= CREAD | CLOCAL;    // Enable receiver, ignore modem control lines

    // input flags
    tty.c_iflag |= IGNPAR;  // ignore framing and parity errors

    // special terminal characters
    tty.c_cc[VMIN]   =  packet_size ;  // minimum number of characters for non-conical read
    tty.c_cc[VTIME]  =  0;  // timeout (in deciseconds)

    // Flush Port, then applies attributes
    if (tcflush(fd_, TCIFLUSH) < 0) {
      ROS_WARN("Error configuring %s: %s [errno %d]", port_name_.c_str(), strerror(errno), errno);
    }

    if (tcsetattr(fd_, TCSANOW, &tty) < 0) {
      ROS_WARN("Error configuring %s: %s [errno %d]", port_name_.c_str(), strerror(errno), errno);
    }
}

void Serial::Flush(void)
{
    // Flush Port, then applies attributes
    if (tcflush(fd_, TCIOFLUSH) < 0) {
      ROS_WARN("Error configuring %s: %s [errno %d]", port_name_.c_str(), strerror(errno), errno);
    }

}
void Serial::Write(const unsigned char* c, size_t size) {
  if (write(fd_, c, size) != static_cast<int>(size)) {
    ROS_WARN("Enable to write to serial port %s", port_name_.c_str());
  }
}

int Serial::Read(unsigned char* buffer, size_t buffer_size) {
  if (buffer_size == 0) {
    ROS_WARN("You are reading 0 bytes, are you sure this is the deisred behavior?");
  }
  struct pollfd poll_fd[1];
  poll_fd[0].fd = fd_;
  poll_fd[0].events = POLLIN;
  //int poll_status = poll(poll_fd, 1, 1000);
  int poll_status = poll(poll_fd, 1, 1000);
  if (poll_status < 0) {
    ROS_WARN("Error %d while polling on serial port %s",  poll_status, port_name_.c_str());
    return -1;
  } else if (poll_status > 0) {
    if (poll_fd[0].revents & POLLIN) {
      ssize_t rc = read(fd_, buffer, buffer_size);
      if (rc > 0) {
        return rc;
      }
    }
  }
  ROS_WARN("Timeout on port %s", port_name_.c_str());
  return 0;
}

void Serial::setDTR(bool level) {
  int command = TIOCM_DTR;
  if (level) {
    if (-1 == ioctl(fd_, TIOCMBIS, &command)) {
      return;
    }
  } else {
    if (-1 == ioctl(fd_, TIOCMBIC, &command)) {
      return;
    }
  }
}


Serial::~Serial() {
  close(fd_);
}

