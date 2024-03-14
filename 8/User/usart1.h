/*
 * usart.h
 *
 *  Created on: 2 февр. 2024 г.
 *      Author: Yuriy
 */

#ifndef USART1_H_
#define USART1_H_

void transmitUSART_Transmit (void);
void Uart_Send_Recive(void);
void Uart_Receive_IRQ_DMA(void);
void Uart_transmit(char*);
void Uart_transmit_IT(char * );
void user_MX_USART1_UART_reInit( uint32_t  ) ; // uart на modbus


void print_comm3( char* );

#endif /* USART1_H_ */
