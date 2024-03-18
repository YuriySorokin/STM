/*
 * screen.c
 *
 *  Created on: 12 мар. 2024 г.
 *      Author: Yuriy
 */

#include "screen.h"


extern uint8_t active_window ;
mainEventType main_Event ;
uint32_t FlagIRQ = 0  ;


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

    // clear string
    	TFT9341_String( paint[n].pos_n_x[0], paint[n].pos_n_y[0], "               ");

    	TFT9341_String( paint[n].pos_n_x[0], paint[n].pos_n_y[0], paint[n].name);
    // clear string
    	TFT9341_String( paint[n].pos_z_x[0], paint[n].pos_z_y[0], "               ");

    	TFT9341_String( paint[n].pos_z_x[0], paint[n].pos_z_y[0], paint[n].znach);
	}
}


void poll_screen (void){

	main_Event = main_READY ;
	//FlagIRQ = 0 ;
	uint8_t was = 0 ;

	while ( FlagIRQ ) {

		switch ( main_Event ) {
			case  main_READY : {
				if (!was) {

					was++ ;

#ifdef DEBUGuart
uart_debug ( 3 , "FlagIRQ = ", FlagIRQ ) ;
#endif
				}

				if ( FlagIRQ > 0 )
					{

						main_Event = key_PRESSED ;

#ifdef DEBUGuart
uart_debug ( 3 , " main_Event = ", main_Event ) ;
#endif

						move_next_window () ;

						print_screen() ;
						main_Event = main_READY ;



						FlagIRQ-- ;
						was-- ;
					}

			} break ;

			case  key_PRESSED : {


			} break ;


			case  key_RELEASED : {} break ;
			case  uart_RECIEVED : {} break ;
			case  mon_REFRESH : {} break ;
			default : break ;
		}



	}

}
