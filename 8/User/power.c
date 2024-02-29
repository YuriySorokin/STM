/*
 * power.c
 *
 *  Created on: 29 февр. 2024 г.
 *      Author: Yuriy
 */
#include "power.h"
#include "stm32f4xx_hal.h"


void set_lowPower(void ){

	HAL_PWR_EnterSLEEPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);

}
