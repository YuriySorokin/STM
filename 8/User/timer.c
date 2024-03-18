/*
 * timer.c
 *
 *  Created on: 4 мар. 2024 г.
 *      Author: Yuriy
 */

#include "timer.h"
#include "stm32f4xx_ll_rcc.h"



void delay_ms (uint32_t s){

	uint32_t frequency = 0U;


	volatile uint32_t i;

	frequency =   RCC_GetSystemClockFreq();




	                                      //Функция задержки

	                                        //Объявляем переменную
	    //RCC_ClocksTypeDef rcc;                                  //Присваиваем структуре RCC_ClocksTypeDef имя rcc

	    //RCC_GetClocksFreq (&rcc);                               //Заполняем структуру rcc текущиим значением параметров SYSCLK, HCLK, PCLK1, PCLK2



	    i = (frequency/72000000)*s;                          //Получаем значение HCLK в герцах

	    for (i; i != 0; i--)
	    	{
	    		print_countDown( i );

	    	};                                   //Выполняем некоторое количество циклов с уменьшением значения переменной i


}

