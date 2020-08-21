#include <ros/ros.h>
#include <iostream>
#include <string.h>

#include "serial.hpp"

#include "Gyro_sensor/Gyro_msg.h"

//#include "serial/serial.h"
#include "std_msgs/String.h"
#include "ros/time.h"

#define num_output 3
#define RX_packet_lenth 33	//11(packet length) * 3 (number of packet)
#define TX_packet_lenth 5

#define smleetest 1 //after complete, remove 
	

std::string node_name("Gyro_HWT905");

class Gyro
{
	public:
	    //static const uint16_t MAX_SAVE_BUF_SIZE=1024;

    	//clee add
		const int PACKET_SIZE = RX_packet_lenth;
		const int PACKET_BUF_SIZE = PACKET_SIZE * 2;
		const int CMD_PACKET_SIZE = 80;

		bool missedPortState;

		std::string m_portName;
		int m_baudRate;
		bool m_connected;

		uint16_t pBufEnd;
		uint16_t pBufStr;
		ros::Publisher pub_Gyrodata;
		

	private:
		Serial        *_serialPort;

	public:		
		Gyro(std::string portName_, int portBaudrate_):_serialPort(NULL)
		{	

			ros::NodeHandle _ph("~");

			flushSerial();
			
			m_connected=false;
			missedPortState=true;

			_ph.param<std::string>("portname", m_portName, portName_);
			_ph.param<int32_t>("baudrate", m_baudRate, portBaudrate_);
			
			pub_Gyrodata=_ph.advertise<Gyro_sensor::Gyro_msg>("/Gyro/HWT905",10);


			portOpen();
		}
		
		~Gyro()
		{		
			portClose();		
		}

		bool portOpen()
		{
 		
			if (_serialPort != NULL)
				delete _serialPort;

			_serialPort = new Serial(m_portName, m_baudRate);
			
			ROS_INFO("Serial port close");

			if (_serialPort)
			{
				m_connected = true;
				_serialPort->setReadPacaketSize(PACKET_SIZE);
			}
	
	        return m_connected;
		
		}
		
		void portClose()
		{
			m_connected=false;
			if (_serialPort)
				delete _serialPort;

			_serialPort=NULL;
			ROS_INFO("Serial port close");
			
		}


		void flushSerial()
		{
			if(_serialPort){ 
				_serialPort->Flush();
			}
		}
		
	
		void readMessage(int readcount)
		{
			int result = 0;
			int flushCount = 0;
			uint8_t buf[PACKET_BUF_SIZE  + 1];
			memset(buf,0x00,PACKET_BUF_SIZE + 1);

			Gyro_sensor::Gyro_msg gyro_data;

			if(_serialPort) 
				result=_serialPort->Read((uint8_t *)&buf[0],readcount);
				
			if (result == PACKET_SIZE)
			{

					for (int i=0;i<PACKET_SIZE;i++) {
            
					ParseData(buf[i]);
					}

			}
			flushCount++;
			if(flushCount == num_output) {flushCount=0;		flushSerial();}
	
		}


		void sendDatas(uint8_t *datas, int32_t length)
		{
			if(_serialPort){
				_serialPort->Write((const uint8_t *)&datas[0],length);
			}
		}


		void ParseData(char chr)
		{
			//float a[3],w[3],Angle[3],h[3];
			float a[3],w[3],h[3];
			float Angle[3];
			Gyro_sensor::Gyro_msg gyro_data;
		
			static char chrBuf[100];
			static unsigned char chrCnt=0;
			signed short sData[4];
			unsigned short uData[4];
			unsigned char i;
			char cTemp=0;
			time_t now;
			chrBuf[chrCnt++]=chr;
			
			if (chrCnt<11) return;
			for (i=0;i<10;i++) cTemp+=chrBuf[i];

			if ((chrBuf[0]!=0x55)||((chrBuf[1]&0x50)!=0x50)||(cTemp!=chrBuf[10])) {
				printf("Error:%x %x\r\n",chrBuf[0],chrBuf[1]);
				memcpy(&chrBuf[0],&chrBuf[1],10);
				chrCnt--;
				return;
				}
		
		memcpy(&sData[0],&chrBuf[2],8);
		memcpy(&uData[0],&chrBuf[2],8); //for sign of angle

		switch(chrBuf[1])
		{
				case 0x51:
					for (i=0;i<3;i++) a[i] = (float)sData[i]/32768.0*16.0;
					time(&now);
					printf("\r\nT:%s a:%6.3f %6.3f %6.3f ",asctime(localtime(&now)),a[0],a[1],a[2]);
					
					break;
				case 0x52:
					for (i=0;i<3;i++) w[i] = (float)sData[i]/32768.0*2000.0;
					printf("w:%7.3f %7.3f %7.3f ",w[0],w[1],w[2]);					
					break;
				case 0x53:
					for (i=0;i<3;i++) Angle[i] = (float)uData[i]/32768.0*180.0;
					printf("A:%7.3f %7.3f %7.3f ",Angle[0],Angle[1],Angle[2]);
					break;
				case 0x54:
					for (i=0;i<3;i++) h[i] = (float)sData[i];
					printf("h:%4.0f %4.0f %4.0f ",h[0],h[1],h[2]);
					
					break;
		}		

			gyro_data.a_x = a[0];	//5.1.2 Acceleration Output
			gyro_data.a_y = a[1];
			gyro_data.a_z = a[2];

			gyro_data.w_x = w[0];	//5.1.3 Angular Velocity Output
			gyro_data.w_y = w[1];
			gyro_data.w_z = w[2];

			gyro_data.an_x = Angle[0];	//5.1.4 Angle Output
			gyro_data.an_y = Angle[1];
			gyro_data.an_z = Angle[2];

			pub_Gyrodata.publish(gyro_data);

			chrCnt=0;
		}

};

int main(int argc, char **argv)
{
	ros::init(argc,argv,node_name);
	ros::NodeHandle nh;
	
	FILE *fp;


	#if smleetest
  		std::string portName("/dev/ttyUSB0");
	#elif
		std::string portName("/dev/ttyS1");
	#endif

	int baudRate=115200;
	int count = 0;

	uint8_t HWT905_cmd[TX_packet_lenth] ={0xFF, 0xAA, 0x22, 0x01, 0x00};//sleep cmd testtest

 	ros::Rate loop_rate(100);
	// MsgTutorial 메시지 파일 형식으로 msg 라는 메시지를 선언
	//ros_tutorials_topic::MsgTutorial msg;
	// 메시지에 사용될 변수 선언

	Gyro IMUdrvLOC(portName,baudRate);

	if(IMUdrvLOC.portOpen()==true)
    {
		usleep(500000);
		ROS_INFO("portopen!!"); 

	}
	else
		ROS_INFO("fail");

    int result = 0;
	
			 HWT905_cmd[2]=0x1;//5.2.3 Calibrate
			 HWT905_cmd[3]=0x0;
			 HWT905_cmd[4]=0x0;
			// IMUdrvLOC.sendDatas(HWT905_cmd, TX_packet_lenth);


	///log 
	fp = fopen("Record.txt","w");
	fprintf(fp,"test\n");

	///log 
 	while (ros::ok())
    {
		
		IMUdrvLOC.readMessage(IMUdrvLOC.PACKET_SIZE);
		count++;
		//temp test
		if(count == 1){
			count = 0;
			//  HWT905_cmd[2]=0x27;//test
			//  HWT905_cmd[3]=0x69;
			//  IMUdrvLOC.sendDatas(HWT905_cmd, TX_packet_lenth);

			// HWT905_cmd[2]=0x27;//test
			// HWT905_cmd[3]=0x6A;
			// IMUdrvLOC.sendDatas(HWT905_cmd, TX_packet_lenth);

			//  HWT905_cmd[2]=0x0a;//Z axis angular velocity bias TESTTEST
			//  HWT905_cmd[3]=0x0;
			//  HWT905_cmd[4]=0x0;
			//  IMUdrvLOC.sendDatas(HWT905_cmd, TX_packet_lenth);

			 HWT905_cmd[2]=0x3d;//Z axis Angle testtest
			 HWT905_cmd[3]=0x0;
			 HWT905_cmd[4]=0x0;
			 IMUdrvLOC.sendDatas(HWT905_cmd, TX_packet_lenth);


			 HWT905_cmd[2]=0x3e;//Z axis Angle testtest
			 HWT905_cmd[3]=0x0;
			 HWT905_cmd[4]=0x0;
			 IMUdrvLOC.sendDatas(HWT905_cmd, TX_packet_lenth);


			 HWT905_cmd[2]=0x3f;//Z axis Angle testtest
			 HWT905_cmd[3]=0x0;
			 HWT905_cmd[4]=0x0;
			 IMUdrvLOC.sendDatas(HWT905_cmd, TX_packet_lenth);


		}

    // 현재 시간을 msg의 하위 stamp 메시지에 담는다
    // count라는 변수값을 msg의 하위 data 메시지에 담는다
    
    //ROS_INFO("send msg = %d", msg.stamp.sec);
    //ROS_INFO("send msg = %d", msg.stamp.nsec);
    //ROS_INFO("send msg = %d", msg.data); // stamp.sec 메시지를 표시한다
    // stamp.nsec 메시지를 표시한다
    // data 메시지를 표시한다
    //ros_tutorial_pub.publish(msg); // 메시지를 발행한다

    loop_rate.sleep(); // 위에서 정한 루프 주기에 따라 슬립에 들어간다
}
return 0;


}
