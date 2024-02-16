/*
 * display.c
 *
 *  Created on: 15 февр. 2024 г.
 *      Author: Yuriy
 */
#include "time.h"
#include "user.h"

enum Menu_number
{
	LINE_1 = 24*1,
	LINE_2 = 24*2,
	LINE_3 = 24*3,
	LINE_4 = 24*4
};



void print_text_Line1_F1(void){

};


void print_text_Line2_F1(void){

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

void print_text_Line3_F1(void){

	TFT9341_SetTextColor(TFT9341_CYAN);
    TFT9341_SetBackColor(TFT9341_BLACK);
    TFT9341_SetFont(&Font24);
    char curTime[] = "         ";
    char clear[] = "              " ; // 5 + 9

    TFT9341_String( 10, 78, clear);

    char time[] = "Time:";
    TFT9341_String( 10, 78, time);


    get_Time( (char*)curTime );
    TFT9341_String( 116, 78, clear);
    TFT9341_String( 116, 78, curTime);

}

void print_text_Line4_F1(void){

};

