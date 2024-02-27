/*
 * display.c
 *
 *  Created on: 15 февр. 2024 г.
 *      Author: Yuriy
 */
#include "time.h"
#include "user.h"
#include "display.h"


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
    TFT9341_SetFont(&Font12);

    int y_Pixel = 54 ;
    int x_pixel_wTime = 10 ;
    int x_pixel_Time = 60 ;
    int x_pixel_Date = 150 ;

    char curTime[] = "         ";
    char curDate[] = "         ";

    char clear[] = "              " ; // 5 + 9

    TFT9341_String( 10, y_Pixel, clear);

    char time[] = "Time:";
    TFT9341_String( x_pixel_wTime, y_Pixel, time);


    get_Time( (char*)curTime );
    TFT9341_String( x_pixel_Time, y_Pixel, clear);
    TFT9341_String( x_pixel_Time, y_Pixel, curTime);

    get_Date ((char*)curDate );
    TFT9341_String( x_pixel_Date, y_Pixel, clear);
    TFT9341_String( x_pixel_Date, y_Pixel, curDate);

    on_Zero_hoursetcurrent_date_and_time ();
}


void on_Zero_hoursetcurrent_date_and_time (void){

	//HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, iSetFlag);

}


void print_text_Line3_F1(void){



}

void print_text_Line4_F1(void){

};


void print_text_Line1_F2(void){

	uint32_t shiftUp = 30 + 24 ; // смещение строк сверху на дисплее

	TFT9341_SetTextColor(TFT9341_CYAN);
    TFT9341_SetBackColor(TFT9341_BLACK);
    TFT9341_SetFont(&Font24);
    //char curTime[] = "         ";
    char clear[] = "              " ; // 5 + 9
    char battery_level[10] = "         " ;


    TFT9341_String( 10, shiftUp + 24 * 1, clear);

    char time[] = "Batt:";
    TFT9341_String( 10, shiftUp + 24 * 1, time);


    //get_Time( (char*)curTime );
    get_battery_level ( (char*)battery_level ) ;
    TFT9341_String( 116, shiftUp + 24 * 1, clear);
    TFT9341_String( 116, shiftUp + 24 * 1, battery_level);



}
