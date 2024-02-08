/*
 * echo.c
 *
 *  Created on: 2 февр. 2024 г.
 *      Author: Yuriy
 */

#include "echo.h"
#include "main.h"

#define TRIG_PIN Signal_Pin
#define TRIG_PORT Signal_GPIO_Port
#define ECHO_PIN Echo_Pin
#define ECHO_PORT Echo_GPIO_Port

extern TIM_HandleTypeDef htim1;








void start_USonic(uint32_t *distance ){
	// init device
	uint32_t val1 = 0;
	uint32_t val2 = 0;
	uint32_t pMillis;
	HAL_TIM_Base_Start(&htim1);
	// start echo

	// start sound

		  HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);
		  __HAL_TIM_SET_COUNTER(&htim1, 0);
		   while (__HAL_TIM_GET_COUNTER (&htim1) < 10);  // wait for 10 us
		   HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);

		   pMillis = HAL_GetTick();
		   while (!(HAL_GPIO_ReadPin (ECHO_PORT, ECHO_PIN)) && pMillis + 10 >  HAL_GetTick());
		   val1 = __HAL_TIM_GET_COUNTER (&htim1);

		   pMillis = HAL_GetTick();
		   while ((HAL_GPIO_ReadPin (ECHO_PORT, ECHO_PIN)) && pMillis + 50 > HAL_GetTick());
		   val2 = __HAL_TIM_GET_COUNTER (&htim1);

		   *distance = (val2-val1)* 0.034/2;


}
