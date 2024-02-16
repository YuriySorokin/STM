/*
 * data.c
 *
 *  Created on: 16 февр. 2024 г.
 *      Author: Yuriy
 */
#include "data.h"
#include "usart1.h"



void fill_string(uint8_t* destString, uint8_t* string ){

	uint8_t  count_size = 0;
	count_size = sizeof ( destString ) ;
	count_size = sizeof ( *destString ) ;

	  /* strcpy: копирует строку t в s;
				вариант 2 с указателями */

	      while ((*destString++ = *string++) != '\0');
}

void fill_menu_data (void){

	uint8_t count_size = 0;
	uint8_t string[] = "one";

	Menu_Data Datamenu;

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
