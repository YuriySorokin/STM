/*
 * screen.c
 *
 *  Created on: 12 мар. 2024 г.
 *      Author: Yuriy
 */

#include "screen.h"


extern uint8_t active_window ;


void move_next_window (void) {

	 // от 0 до 4
	uint8_t  n = 0 ;


	n = active_window ;
	n++ ;

	if ( n > 4 ) n = 0 ;
	active_window  = n ;

#ifdef DEBUGuart
					uart_debug ( 3 , " active_window = ", active_window ) ;
#endif

}

void print_screen(void) {
	 // нужен номер экрана
		// взять из глобальной переменной
	uint8_t n = 0;

	get_current_screen( &n);

	prepare_next_screen();

	out_screen( n );

}

void get_current_screen( uint8_t *n){

	*n = active_window ;

}

void prepare_next_screen() {


}



void out_screen( uint8_t n ){
	// физический уровень вывода

	//extern uint8_t errno ;
	extern MenuStruct paint[5] ;

	if ( (n >= 0) && ( n < 5 ) )
	{
		TFT9341_SetTextColor(TFT9341_CYAN);
		TFT9341_SetBackColor(TFT9341_BLACK);
		TFT9341_SetFont(&Font24);

    // clear
    	TFT9341_String( paint[n].pos_n_x[0], paint[n].pos_n_y[0], "               ");

    	TFT9341_String( paint[n].pos_n_x[0], paint[n].pos_n_y[0], paint[n].name);

    	TFT9341_String( paint[n].pos_z_x[0], paint[n].pos_z_y[0], "               ");

    	TFT9341_String( paint[n].pos_z_x[0], paint[n].pos_z_y[0], paint[n].znach);
	}
}


