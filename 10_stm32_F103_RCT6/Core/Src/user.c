/*
 * user.c
 *
 *  Created on: 6 февр. 2024 г.
 *      Author: Yuriy
 */
#include "user.h"
#include "usart.h"


void LedOn(void){
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
}

void LedOff(void){
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
}

void delay_Led_off( uint32_t Delay ) {

	LedOff();
  	for ( uint32_t i = 0 ; i < Delay ; i++)  {
  		LedOff();
  	}
}

void delay_Led_on( uint32_t Delay ) {

	LedOn();
  	for ( uint32_t i = 0 ; i < Delay ; i++)  {
  		LedOn();
  	}
}

void Uart_Send_Recive(void){

	//void start(void)

		uint8_t pData[18] = "WAIT Transmit\r\n";
		uint8_t pData_Receive[5] =  "US12T";
		uint8_t pData_error[5]="FALSE";

	//	HAL_GPIO_WritePin(GPIOG, LD3_Pin, GPIO_PIN_SET);
		//HAL_GPIO_WritePin(GPIOG, LD4_Pin, GPIO_PIN_SET);


		while (1){
			//HAL_GPIO_WritePin(GPIOG, LD3_Pin, GPIO_PIN_SET);

			//pData[18] = "WAIT Transmit\r\n";
			HAL_UART_Transmit(&huart2, pData, 15, 1000);
			delay_Led_on(500);
			LedOff();

	//		if ( HAL_UART_Receive( &huart2, pData_Receive, 2, 10000) == HAL_OK ){
	//			delay_Led_on(1000);
	//			delay_Led_off(1000);
			//	HAL_GPIO_WritePin(GPIOG, LD4_Pin, GPIO_PIN_SET);
			//	HAL_Delay (1000);
			//	HAL_GPIO_WritePin(GPIOG, LD4_Pin, GPIO_PIN_RESET);
		//	}
	//		else
			{
				//pData[18] = "FALSE\r\n";
	//			HAL_UART_Transmit(&huart2, pData_error, 15, 1000);
	//			LedOff();

			}
		//	HAL_GPIO_WritePin(GPIOG, LD3_Pin, GPIO_PIN_RESET);
		//	HAL_Delay(500);

		}



}

void LED_togle (void){

	uint32_t Delay = 0 , i = 0  ;
	Delay = 10000;
	for ( i = 0 ; i < Delay*20 ; i++ ){
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	}
	Delay = 1000;
	while (1) {
		for ( i = 0 ; i < Delay ; i++ ){

			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
		}
		for ( i = 0 ; i < Delay*10 ; i++ ){

			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
		}
	}
}



