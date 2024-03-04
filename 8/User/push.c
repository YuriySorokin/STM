/*
 * push.c
 *
 *  Created on: 29 февр. 2024 г.
 *      Author: Yuriy
 */

#include "push.h"
#include "main.h"
#include "stm32f4xx.h"
#include "LED.h"
#include "power.h"


uint32_t button(void){



	uint32_t key = 0 ;

#ifndef STANBY
	//button_Pin LL_GPIO_PIN_0
	//button_GPIO_Port

	if( (LL_GPIO_ReadInputPort(button_GPIO_Port) & (1 << 0)) != 0 ) {
	    // на выводе PB10 высокий уровень
		//if( (LL_GPIO_ReadInputPort(button_GPIO_Port) & (1 << 10)) != 0 ) {
		key = 1 ;
		Led_red_on();

	}

#endif

	return key ;
}
