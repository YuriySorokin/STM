/*
 * user.h
 *
 *  Created on: 6 февр. 2024 г.
 *      Author: Yuriy
 */

#ifndef SRC_USER_H_
#define SRC_USER_H_

#include "gpio.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_uart.h"

void LED_togle (void);
void LedOn(void);
void LedOff(void);

void Uart_Send_Recive(void);

#endif /* SRC_USER_H_ */
