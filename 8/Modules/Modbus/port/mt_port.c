/*
 * mt_port.c
 *
 *  Created on: 5 мар. 2024 г.
 *      Author: Yuriy
 */
#include "main.h"
#include "mt_port.h"
static uint32_t lockCounter = 0;

UART_HandleTypeDef* modbusUart;
TIM_HandleTypeDef* modbusTimer;
/* Functions -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
void EnterCriticalSection()
{
  __disable_irq();
  lockCounter++;
}


void ExitCriticalSection()
{
  lockCounter--;
  if (lockCounter == 0)
  {
    __enable_irq();
  }
}
/*----------------------------------------------------------------------------*/\
void MT_PORT_SetTimerModule(TIM_HandleTypeDef* timer)
{
  modbusTimer = timer;
}
/*----------------------------------------------------------------------------*/\
void MT_PORT_SetUartModule(UART_HandleTypeDef* uart)
{
  modbusUart = uart;
}

