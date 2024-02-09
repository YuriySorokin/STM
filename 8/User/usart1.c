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
    char pData_Receive[] =  "1234567891234567";
    char pData_Transmit[] =  "123_DMA_45678912";
    char pData_Receive_DMA_string[21]={0};
    uint32_t Delay = 1000 ;

    while (1){

   	delay_Led_on(Delay);
   	if ( HAL_UART_Transmit( &huart1, (uint8_t*)pData_Receive, 16, 10000) == HAL_OK ){

   		TFT9341_String( 10 ,134, (char*)"       Sended       ");
        TFT9341_String( 10 ,134, (char*)pData_Receive);

   	};

   	// transmit use DMA

   	HAL_UART_Transmit_DMA(&huart1, (uint8_t*)pData_Transmit,( sizeof (pData_Transmit)) -1);
   	Led_red_off(Delay);


   	//

   	 TFT9341_String( 10 ,134, (char*)"       wait        ");


   	 if ( HAL_UART_Receive_DMA(&huart1 , (uint8_t*) pData_Receive_DMA_string, 20) == HAL_OK ){
   		 LedOn();

   		 TFT9341_String( 10 ,134, (char*)"     Received_DMA      ");
   		 TFT9341_String( 10 ,134, (char*)pData_Receive_DMA_string);


   	 } else {
   		 TFT9341_String( 10 ,134, (char*)"                   ");
   		 TFT9341_String( 10 ,134, (char*)"  FALSE_DMA_Receive      ");
   	 }

   	 delay_Led_off(Delay);

    zeroing_string(pData_Receive);
    TFT9341_String( 10 ,134, (char*)"                         ");
    TFT9341_String( 10 ,134, (char*)"      wait 2 symbols     ");

   	 if ( HAL_UART_Receive(&huart1, (uint8_t*)pData_Receive,2,10000) == HAL_OK ){
   		 LedOn();

   		 TFT9341_String( 10 ,134, (char*)"                     ");
   		 TFT9341_String( 10 ,134, (char*)pData_Receive);


   	 } else {
   		 TFT9341_String( 10 ,134, (char*)"                   ");
   		 TFT9341_String( 10 ,134, (char*)"  FALSE Received   ");
   	 }
   	 delay_Led_off(Delay);


 /*  	 if ( HAL_UART_Receive( &huart1, pData_Receive, 16, 10000) == HAL_OK ){
   		TFT9341_String( 10 ,154, (char*)"                   ");
        TFT9341_String( 10 ,154, (char*)pData_Receive);
    	};
*/
     TFT9341_String( 10 ,154, (char*)"                         ");
     TFT9341_String( 10 ,154, (char*)"      wait 1 symbol     ");
     if ( HAL_UART_Receive(&huart1, (uint8_t*)pData_Receive,1,10000) == HAL_OK ){

    	 LedOn();

    	 TFT9341_String( 10 ,154, (char*)"                   ");
    	 TFT9341_String( 10 ,154, (char*)pData_Receive);
     } else {
    	 TFT9341_String( 10 ,154, (char*)"                   ");
    	 TFT9341_String( 10 ,154, (char*)"      FALSE      ");
     }
   	 delay_Led_off(Delay);

    }
}
