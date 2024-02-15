/*
 * display.c
 *
 *  Created on: 15 февр. 2024 г.
 *      Author: Yuriy
 */
#include "time.h"
#include "user.h"


void print_text_Line2(void){

	TFT9341_SetTextColor(TFT9341_CYAN);
    TFT9341_SetBackColor(TFT9341_BLACK);
    TFT9341_SetFont(&Font24);
    char curTime[] = "         ";
    char clear[] = "              " ; // 5 + 9

    TFT9341_String( 10, 54, clear);

    char time[] = "Time:";
    TFT9341_String( 10, 54, time);


    get_Time( (char*)curTime );
    TFT9341_String( 116, 54, clear);
    TFT9341_String( 116, 54, curTime);

}
