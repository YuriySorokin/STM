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
