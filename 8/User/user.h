/*
 * user.h
 *
 *  Created on: 1 февр. 2024 г.
 *      Author: Yuriy
 */

#ifndef USER_H_
#define USER_H_

#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"
#include "fonts.h"
#include "menu.h"
#include "time.h"
#include "bat.h"
#include "mb.h"

void start(void);
void TFT9341_ini(uint16_t, uint16_t);
void TFT9341_reset(void);
void TFT9341_FillRect(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
void TFT9341_FillScreen(uint16_t);
void TFT9341_DrawPixel(int, int, uint16_t);
void TFT9341_DrawCircle(uint16_t x0, uint16_t y0, int r, uint16_t color);
void TFT9341_SetTextColor(uint16_t color);
void TFT9341_SetBackColor(uint16_t color);
void TFT9341_SetFont(sFONT *pFonts);
void TFT9341_DrawChar(uint16_t x, uint16_t y, uint8_t c);
void TFT9341_String(uint16_t x,uint16_t y, char *str);
void TFT9341_SetRotation(uint8_t r);
void Print_text(void);
void TFT9341_SendCommand(uint8_t );
void TFT9341_SendData(uint8_t );
void Check_borders_addSpace_symblols(uint32_t, char *);
//sprintf(buffer, "%10d", (int)num);
int	sprintf (char *, const char *, ...);

void zeroing_string(char *);

void  Start_2(void);

void Display_welcomeScreen(void);
void print_text_distance(void);
void fill_menu_data (void);
void 	print_Line1_F2(void);




extern SPI_HandleTypeDef hspi5;
//extern RNG_HandleTypeDef hrng;


typedef enum
{
    main_READY,                 /*!< Startup finished. */
    key_PRESSED,          		/*!< change screen. */
	key_RELEASED,
    uart_RECIEVED,				/*!< Execute send*/
    mon_REFRESH              	/*!< Execute refresh display. */
} mainEventType;

typedef enum
{
	key_RELEAS,
	key_PRESS

} keyStatusType ;


//mainEventType main_Event = 0 ;


#define RESET_ACTIVE() LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_12)
#define RESET_IDLE() LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_12)
#define CS_ACTIVE() LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_2)
#define CS_IDLE() LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_2)
#define DC_COMMAND() LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_13)
#define DC_DATA() LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_13)

// LL_GPIO_SetOutputPin(GPIOG, LL_GPIO_PIN_13)




//-------------------------------------------------------------------
#define TFT9341_MADCTL_MY  0x80
#define TFT9341_MADCTL_MX  0x40
#define TFT9341_MADCTL_MV  0x20
#define TFT9341_MADCTL_ML  0x10
#define TFT9341_MADCTL_RGB 0x00
#define TFT9341_MADCTL_BGR 0x08
#define TFT9341_MADCTL_MH  0x04
#define TFT9341_ROTATION (TFT9341_MADCTL_MX | TFT9341_MADCTL_BGR)
#define	TFT9341_BLACK   0x0000
#define	TFT9341_BLUE    0x001F
#define	TFT9341_RED     0xF800
#define	TFT9341_GREEN   0x07E0
#define TFT9341_CYAN    0x07FF
#define TFT9341_MAGENTA 0xF81F
#define TFT9341_YELLOW  0xFFE0
#define TFT9341_WHITE   0xFFFF
//-------------------------------------------------------------------
#define swap(a,b) {int16_t t=a;a=b;b=t;}




#endif /* USER_H_ */
