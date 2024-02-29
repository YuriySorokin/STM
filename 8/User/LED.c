/*
 * LED.c
 *
 *  Created on: 14 февр. 2024 г.
 *      Author: Yuriy
 */
#include "LED.h"





void LedOn(void){

	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);

}
void Led_red_on(void){
	HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, GPIO_PIN_SET);
}

void Led_red_off(uint32_t Delay){

	for ( uint32_t i = 1 ; i < Delay ; i++)  {

		HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, GPIO_PIN_RESET);
	}
}
void LedOff(void){

	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);

}

void delay_Led_off( uint32_t Delay ) {

	LedOff();
  	for ( uint32_t i = Delay ; i < Delay ; i++)  {
  		LedOff();
  	}
}

void delay_Led_on( uint32_t Delay ) {

	LedOn();
  	for ( uint32_t i = Delay ; i < Delay ; i++)  {
  		LedOn();
  	}
}
void Leds_flash_on_start_led1_led2(void){

		LED1_ON();
		LED2_ON();
		LL_mDelay(500);
		//Delay_ms(500000);
		LED1_OFF();
		LED2_OFF();
		//Delay_ms(500000);
		LL_mDelay(500);

}
