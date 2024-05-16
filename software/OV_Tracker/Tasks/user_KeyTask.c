/* Private includes -----------------------------------------------------------*/
//includes
#include "user_TasksInit.h"
#include "key.h"
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


/**
  * @brief  Key press check task
  * @param  argument: Not used
  * @retval None
  */
void KeyTask(void *argument)
{
	while(1)
	{
		if(KeyScan(0))
		{
			HAL_GPIO_TogglePin(LED_TEST_GPIO_Port, LED_TEST_Pin);
		}
		osDelay(1);
	}
}
