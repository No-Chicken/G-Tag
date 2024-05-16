/* Private includes -----------------------------------------------------------*/
//includes
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"
#include "key.h"
#include "Air780.h"
#include "onenet_MQTT.h"
#include <stdio.h>
#include "delay.h"
#include "usart.h"
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


/**
  * @brief  measure the light and send to the cloud
  * @param  argument: Not used
  * @retval None
  */
void HardwaresInitTask(void *argument)
{
	while(1)
	{
		vTaskSuspendAll();
		
		//key
		Key_Port_Init();
		
		//Air780
		Air780_Init();
		//PDP
		Air780_PDPact();
		//MQTT
		onenet_MQTTConnect();
		//set the rct
		Air780_GetTime();
		//check the TCP is connected or not
		if(!Connect_Check())
		{
			//断开TCP连接
			onenet_TCPDisConnect();
			//建立TCP连接
		  printf("AT+MIPSTART=\"%s\",%s\r\n",mqtturl,mqttport);
		  delay_ms(400);
		  //请求会话//是否erro
		  printf("AT+MCONNECT=1,120\r\n");
		  delay_ms(400);
			delay_ms(400);
			//订阅CMD主题
			printf("AT+MSUB=\"$sys/%s/%s/cmd/request/+\",0\r\n",ProductID,DeviceName);
			delay_ms(400);
		}
		
		xTaskResumeAll();
		vTaskDelete(NULL);
		osDelay(1000);
	}
	
}
