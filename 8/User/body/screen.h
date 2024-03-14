/*
 * screen.h
 *
 *  Created on: 12 мар. 2024 г.
 *      Author: Yuriy
 */

#ifndef SRC_SCREEN_H_
#define SRC_SCREEN_H_


#include "data.h"
#include "main.h"
#include "user.h"
#include "debug_out.h"


void
get_current_screen(uint8_t*);

void
prepare_next_screen(void);

void
out_screen(uint8_t);

void
print_screen(void) ;

void				// опрос отрисовки экрана по кнопке
poll_screen (void);

void
move_next_window (void ) ;






#endif //SRC_SCREEN_H_
