/* Private includes -----------------------------------------------------------*/
//includes
#include <stdio.h>
#include <string.h>
#include "stm32l0xx_it.h"

#include "user_TasksInit.h"
#include "user_CmdRecTask.h"

#include "onenet_MQTT.h"


/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/



/* Private function prototypes -----------------------------------------------*/


/**
  * @brief  Key press check task
  * @param  argument: Not used
  * @retval None
  */
void CmdRecTask(void *argument)
{
	
	while(1)
	{
		//recieve the CMD from onenet, to set the offset
		if(HardInt_uart_flag == 1)
		{
			HardInt_uart_flag = 0;
			if(HardInt_receive_str[2] == '+' && HardInt_receive_str[3] == 'M' && HardInt_receive_str[4] == 'S' && HardInt_receive_str[5] == 'U' && HardInt_receive_str[6] == 'B' && HardInt_receive_str[7] == ':')
			{
				HAL_GPIO_TogglePin(LED_TEST_GPIO_Port, LED_TEST_Pin);
			}
		}
		
		osDelay(100);
	}
}
