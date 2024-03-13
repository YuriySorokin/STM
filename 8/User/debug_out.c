/*
 * debug_out.c
 *
 *  Created on: 27 февр. 2024 г.
 *      Author: Yuriy
 */
#include "debug_out.h"

int sum ( int s1 , ... ){

	int result = 0 ;

	va_list factor ;
	va_start (factor, s1) ;
	for ( int i = 0; i < s1 ; i ++ )
	{
		result += va_arg(factor, int);
	}
	va_end(factor);

	return result ;

}
/*
 * фугкция вывода неограниченного количество
 * лементв
 *
 *
 *
 *
 *
 */
void uart_debug (int s1, ... ) {

	va_list out_list ;
	va_start (out_list, s1) ;

	char *buffer ;
	int param = 0 ;
	char str[5] = {0x0} ;

	while (--s1)
	{
		buffer = va_arg(out_list, char*);
		//
		print_comm3( buffer );

		s1--;
		param = va_arg(out_list, int);
		sprintf(str, "%4d", param);
		print_comm3( str );
		print_comm3 ("\r");
	}

	va_end(out_list);

}

