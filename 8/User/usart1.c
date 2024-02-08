/*
 * usart.c
 *
 *  Created on: 2 февр. 2024 г.
 *      Author: Yuriy
 */

#include "usart.h"
#include "user.h"



void transmitUSART_Transmit (void){
//	uint8_t str[]="USART Transmit\r\n";
    	// while (1)

    		  {
    		         //       HAL_UART_Transmit(&huart1,str,16,0xFFFF);

    		               // HAL_Delay(100);
    		  }
}


void Uart_Send_Recive(void){
    uint8_t pData_Receive[16] =  "1234567891234567";

    uint32_t Delay = 1000 ;

    while (1){
/*
   	 delay_Led_on(Delay);
   	if ( HAL_UART_Receive( &huart1, pData_Receive, 16, 10000) == HAL_OK ){
   		TFT9341_String( 10 ,154, (char*)"                   ");
        TFT9341_String( 10 ,154, (char*)pData_Receive);
   	};
*/


   	 if ( HAL_UART_Receive(&huart2, pData_Receive,16,10000) == HAL_OK ){
   		 TFT9341_String( 10 ,134, (char*)"                   ");
   		 TFT9341_String( 10 ,134, (char*)pData_Receive);

   	 } else {
   		 TFT9341_String( 10 ,134, (char*)"                   ");
   		 TFT9341_String( 10 ,134, (char*)"      FALSE      ");
   	 }
   	 delay_Led_off(Delay);


 /*  	 if ( HAL_UART_Receive( &huart1, pData_Receive, 16, 10000) == HAL_OK ){
   		TFT9341_String( 10 ,154, (char*)"                   ");
        TFT9341_String( 10 ,154, (char*)pData_Receive);
    	};
*/
     if ( HAL_UART_Receive(&huart2, pData_Receive,16,10000) == HAL_OK ){
     TFT9341_String( 10 ,154, (char*)"                   ");
     TFT9341_String( 10 ,154, (char*)pData_Receive);
     } else {
    	 TFT9341_String( 10 ,134, (char*)"      FALSE      ");
     }

    }
}
