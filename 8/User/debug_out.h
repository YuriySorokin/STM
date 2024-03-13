/*
 * debug_out.h
 *
 *  Created on: 27 февр. 2024 г.
 *      Author: Yuriy
 */

#ifndef DEBUG_OUT_H_
#define DEBUG_OUT_H_

#include "stdio.h"
#include "stdarg.h"
#include "usart1.h"
#include "string.h"

int sum ( int s1 , ... );

void uart_debug (int s1, ... ) ; // через один текст и целое


#endif /* DEBUG_OUT_H_ */
