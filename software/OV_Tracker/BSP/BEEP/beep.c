#include "beep.h"
#include "tim.h"


void beep_open(void)
{
		if (HAL_TIM_PWM_Start(&htim22, TIM_CHANNEL_2) != HAL_OK)
		{
			Error_Handler();
		}
}

void beep_close(void)
{
		HAL_TIM_PWM_Stop(&htim22, TIM_CHANNEL_2);
}
