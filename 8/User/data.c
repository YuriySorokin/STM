/*
 * data.c
 *
 *  Created on: 16 февр. 2024 г.
 *      Author: Yuriy
 */
#include "data.h"



Menu_Data Datamenu;
MenuStruct paint[5] ;



void fill_string(uint8_t* destString, uint8_t* string ){

	//uint8_t  count_size = 0;
	//count_size = sizeof ( destString ) ;
	//count_size = sizeof ( *destString ) ;

	  /* strcpy: копирует строку t в s;
				вариант 2 с указателями */

	      while ((*destString++ = *string++) != '\0');
}

/*
 *
 * данные меню
 *
 *
 * */


void fill_menu_data (void){

	//uint8_t count_size = 0;
	uint8_t string[] = "one";

	// Menu_Data Datamenu; // move to Global

	extern Menu_Data Datamenu; ;

	Datamenu.Net_name = RS485 ;
	Datamenu.V_sound = 4550 ;
	Datamenu.bat_level = 80 ;
	Datamenu.contact = OK ;
	Datamenu.degrees = 20 ;
	Datamenu.error = 1 ;

	Datamenu.firmware_name[0] = '\n' ;

	Datamenu.firmware_version = 0 ;
	Datamenu.interval = 250 ;
	Datamenu.last_connect_time = 1000 ;
	Datamenu.net_RS_addres = 20 ;
	Datamenu.net_RS_speed = 9600 ;
	Datamenu.net_status_ok =  OK ;
	Datamenu.pin_num = 1 ;
	Datamenu.serial_number = 1 ;

	fill_string( Datamenu.firmware_name , string ) ;

	//print_comm3( Datamenu.firmware_name );

	//&Datamenu ;

}


/*
 * Расположение полей настроечного меню
 *
 *
 * */


void fill_menu_init (void) {

	// 1
	paint[0].frame_n = 1 ;			// рабочий номер окна

	strcpy(paint[0].name, "Time menu One" ) ; // наименование

	paint[0].pos_n[0] = 1  ;
	paint[0].pos_n_x[0] = 1 ;
	paint[0].pos_n_y[0] = 25 ;

	paint[0].pos_z[1] = 11 ;
	paint[0].pos_z_x[1] = 1+10 ;
	paint[0].pos_z_y[1] = 25 ;

	// 2
	paint[1].frame_n = 2 ;

	strcpy(paint[1].name, "Date menu Two" ) ;

	paint[1].pos_n[0] = 1  ;
	paint[1].pos_n_x[0] = 1 ;
	paint[1].pos_n_y[0] = 25 ;

	paint[1].pos_z[1] = 11 ;
	paint[1].pos_z_x[1] = 1+10 ;
	paint[1].pos_z_y[1] = 25 ;

	//3
	paint[2].frame_n = 3 ;

	strcpy(paint[2].name, "name menu Three" ) ;

	paint[2].pos_n[0] = 1  ;
	paint[2].pos_n_x[0] = 1 ;
	paint[2].pos_n_y[0] = 25 ;

	paint[2].pos_z[1] = 11 ;
	paint[2].pos_z_x[1] = 1+10 ;
	paint[2].pos_z_y[1] = 25 ;

	//4
	paint[3].frame_n = 4 ;

	strcpy(paint[3].name, "name menu Four" ) ;

	paint[3].pos_n[0] = 1  ;
	paint[3].pos_n_x[0] = 1 ;
	paint[3].pos_n_y[0] = 25 ;

	paint[3].pos_z[1] = 11 ;
	paint[3].pos_z_x[1] = 1+10 ;
	paint[3].pos_z_y[1] = 25 ;

	//5
		paint[3].frame_n = 5 ;

		strcpy(paint[4].name, "name menu Five" ) ;

		paint[4].pos_n[0] = 1  ;
		paint[4].pos_n_x[0] = 1 ;
		paint[4].pos_n_y[0] = 25 ;

		paint[4].pos_z[1] = 11 ;
		paint[4].pos_z_x[1] = 1+10 ;
		paint[4].pos_z_y[1] = 25 ;
}


