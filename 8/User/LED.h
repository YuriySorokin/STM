/*
 * LED.h
 *
 *  Created on: 14 февр. 2024 г.
 *      Author: Yuriy
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_hal_gpio.h"
#include "main.h"

#define LED1_ON() LL_GPIO_SetOutputPin(GPIOG, LL_GPIO_PIN_13)
#define LED1_OFF() LL_GPIO_ResetOutputPin(GPIOG, LL_GPIO_PIN_13)
#define LED2_ON() LL_GPIO_SetOutputPin(GPIOG, LL_GPIO_PIN_14)
#define LED2_OFF() LL_GPIO_ResetOutputPin(GPIOG, LL_GPIO_PIN_14)


void LedOn(void);
void LedOff(void);
void delay_Led_on( uint32_t );
void delay_Led_off( uint32_t );
void Led_red_off(uint32_t );
void Leds_flash_on_start_led1_led2(void);
void Led_red_on(void);
void Led_green_on(void);
void Led_red_toogle (void);






#endif /* LED_H_ */
