#include <ros/ros.h>
#include <iostream>
#include <string.h>

#include "serial.hpp"

//#include "serial/serial.h"
#include "std_msgs/String.h"
#include "ros/time.h"

#define RX_packet_lenth 33
#define TX_packet_lenth 5
#define num_output 3
	
	char r_buf[1024];

std::string node_name("Gyro_R6093U");

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


			if(_serialPort) 
				result=_serialPort->Read((uint8_t *)&buf[0],readcount);
				//printf("ssingmintesttesttest:  %d\n, result");
				
	
			if (result == PACKET_SIZE)
			{


					for (int i=0;i<33;i++) {
            
					ParseData(buf[i]);
					}


				//int retval = R6093U_parse_data((unsigned char *)&buf[0], PACKET_SIZE);
				
				//printf("\n");

				// if (retval == 1 ) {  // need to soft reset (header...error)
				// 	//gyro_reset_command();
				// 	ROS_WARN ("gyro_reset_command !!!");
				// 	return ;

				// } else if ( retval == 2)  // need to hard reset..
				// {   // only CRC error ...
				// 	//gyro_reset_command();
				// 	//HardResetCommand();
				// 	ROS_WARN ("HardResetCommand !!!");
				// 	return ;
				// }
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
		float a[3],w[3],Angle[3],h[3];

		static char chrBuf[100];
		static unsigned char chrCnt=0;
		signed short sData[4];
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
					for (i=0;i<3;i++) Angle[i] = (float)sData[i]/32768.0*180.0;
					printf("A:%7.3f %7.3f %7.3f ",Angle[0],Angle[1],Angle[2]);
					break;
				case 0x54:
					for (i=0;i<3;i++) h[i] = (float)sData[i];
					printf("h:%4.0f %4.0f %4.0f ",h[0],h[1],h[2]);
					
					break;
		}		
		chrCnt=0;		
		}


		
		int R6093U_parse_data(uint8_t *data_packet, uint16_t length)
		{
		//int16_t header;
		int8_t header;
		int8_t index;

		float_t f_roll;
		float_t f_pitch;
		float_t f_yaw;

		float_t f_roll_rate;
		float_t f_pitch_rate;
		float_t f_yaw_rate;

		
		float_t f_roll_accel;
		float_t f_pitch_accel;
		float_t f_yaw_accel;


		signed short sData[3];
		unsigned short uData[3];

		int16_t roll;
		int16_t pitch;
		uint16_t yaw;

		int16_t roll_rate;
		int16_t pitch_rate;
		int16_t yaw_rate;

		int16_t roll_accel;
		int16_t pitch_accel;
		int16_t yaw_accel;

		uint8_t checksum_packet=0;
		//int16_t checksum_packet=0;
		//int16_t checksum;
		uint8_t checksum;

		static int header_err_count = 0;

		//memcpy(&header, data_packet, sizeof (short));
		uint8_t sort_packet[PACKET_SIZE];


		for(int i=0;i<PACKET_BUF_SIZE-1;i++)
		{
			if(data_packet[i]==0x55)
			{
				memcpy(sort_packet,data_packet+i,PACKET_SIZE);
				break;
			}
		}


		header= sort_packet[0];

		if (header != 0x55)
			{
				ROS_WARN ("header error !!!");
				header_err_count++;
				if (header_err_count > 2)
				{
				ROS_WARN ("header error over 2 !!!");
				header_err_count=0;
				return 2;
				}
				return 1;
			}
			header_err_count=0;
			
			checksum_packet = (sort_packet[PACKET_SIZE-1]);
			checksum=0;

			for(int s=0; s<(PACKET_SIZE-1); s++){	//Checksum: Sum=0x55+0x51+AxH+AxL+AyH+AyL+AzH+AzL+TH+TL

			checksum+=sort_packet[s];
			}

			

			if(checksum_packet != checksum)
			{
			printf("sort_packet:");
			for(int i=0;i<PACKET_SIZE;i++)	{printf(" %02X",sort_packet[i]);}
			printf("\n");
				printf("checksum: %02X, checksum_packet: %02X\n", checksum , checksum_packet);
				ROS_WARN ("checksum error !!!");
				checksum_packet = 0;
				checksum = 0;
				return 2;
			}



	//data_packet[1]=kind of Output
	//0x50=Time Output, 0x51=Acceleration Output, 0x52=Angular Velocity Output, 
	//0x53=Angle Output, 0x54=Magnetic Output, 0x59=Quaternion
			
			switch(sort_packet[1]){ 

				case 0x51 :  //Acceleration Output
					
					memcpy(&sData[0], &sort_packet[2],6);

					f_roll_accel = (float)sData[0]/32768.0*16.0;
					f_pitch_accel = (float)sData[1]/32768.0*16.0;
					f_yaw_accel = (float)sData[2]/32768.0*16.0;

					printf("%1.4f, %1.4f, %1.4f, ", f_roll_accel, f_pitch_accel, f_yaw_accel);

					break; 

				case 0x52 :  //Angular Velocity Output
					
					memcpy(&sData[0], &sort_packet[2],6);

					f_roll_rate = (float)sData[0]/32768.0*2000.0;
					f_pitch_rate = (float)sData[1]/32768.0*2000.0;
					f_yaw_rate = (float)sData[2]/32768.0*2000.0;

					printf("%1.4f, %1.4f, %1.4f, ", f_roll_rate, f_pitch_rate, f_yaw_rate);

					break;   

				case 0x53 :  //Angle Output
					
					memcpy(&uData[0], &sort_packet[2],6);

					f_roll = (float)uData[0]/32768.0*180.0;
					f_pitch = (float)uData[1]/32768.0*180.0;
					f_yaw = (float)uData[2]/32768.0*180.0;
					
					printf("%1.4f, %1.4f, %1.4f,", f_roll, f_pitch, f_yaw);
					printf("\n");
					break;   

				default :

					printf("error!!!!!!!!!!!!!!!!!!!!!\n"); 
					break; 
					
			} 

      return 0;
    }
	

};

int main(int argc, char **argv)
{
  //ros::init(argc, argv, "Gyro_R6093U");
	ros::init(argc,argv,node_name);
	ros::NodeHandle nh;

  	//std::string portName("/dev/ttyS1");
    std::string portName("/dev/ttyUSB0");
	int baudRate=115200;
	int count = 0;




	uint8_t HWT905_cmd[TX_packet_lenth] ={0xFF, 0xAA, 0x22, 0x01, 0x00};//sleep cmd

 	ros::Rate loop_rate(100);
	// MsgTutorial 메시지 파일 형식으로 msg 라는 메시지를 선언
	//ros_tutorials_topic::MsgTutorial msg;
	// 메시지에 사용될 변수 선언

	Gyro smleetmp(portName,baudRate);

	if(smleetmp.portOpen()==true)
    {
		usleep(500000);
		ROS_INFO("portopen!!"); 

	}
	else
		ROS_INFO("fail");
		

    int result = 0;

	printf("total: f_roll_accel, f_pitch_accel, f_yaw_accel, f_roll_rate, f_pitch_rate, f_yaw_rate, f_roll, f_pitch, f_yaw\n");
    //Gyro smlee(portName,baudRate);
 	while (ros::ok())
    {
		smleetmp.readMessage(smleetmp.PACKET_SIZE);
		count++;
		//temp test
		if(count == 1){
			count = 0;
			//HWT905_cmd[2]=0x27;
			//HWT905_cmd[3]=0x69;
			//smleetmp.sendDatas(HWT905_cmd, TX_packet_lenth);

			//HWT905_cmd[2]=0x27;
			//HWT905_cmd[3]=0x6A;
			//smleetmp.sendDatas(HWT905_cmd, TX_packet_lenth);

			// HWT905_cmd[2]=0x0a;//reset z axis angle
			// HWT905_cmd[3]=0x0;
			// HWT905_cmd[4]=0x0;
			// smleetmp.sendDatas(HWT905_cmd, TX_packet_lenth);
		}

    // 현재 시간을 msg의 하위 stamp 메시지에 담는다
    // count라는 변수값을 msg의 하위 data 메시지에 담는다
    
    //ROS_INFO("send msg = %d", msg.stamp.sec);
    //ROS_INFO("send msg = %d", msg.stamp.nsec);
    //ROS_INFO("send msg = %d", msg.data); // stamp.sec 메시지를 표시한다
    // stamp.nsec 메시지를 표시한다
    // data 메시지를 표시한다
    //ros_tutorial_pub.publish(msg); // 메시지를 발행한다

	//result=_serialPort->write("hihi");
    loop_rate.sleep(); // 위에서 정한 루프 주기에 따라 슬립에 들어간다
}
return 0;


}
