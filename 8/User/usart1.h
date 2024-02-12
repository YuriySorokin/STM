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


#endif /* USART1_H_ */
