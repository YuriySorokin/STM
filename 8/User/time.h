/*
 * time.h
 *
 *  Created on: 14 февр. 2024 г.
 *      Author: Yuriy
 */

#ifndef TIME_H_
#define TIME_H_





void get_Date (char *);

void get_Time_to_display (void); // get time and fill global Time

void get_Time ( char* ) ; // get time and date and print in to comm3
void get_time_to_comm ( void ) ; // get time and print it to comm3 with Zero instead space

void set_Time (void);
void get_Alarm (char *);

void set_Date (uint8_t, uint8_t, uint8_t);
void set_Alarm (uint8_t, uint8_t,uint8_t );

#endif /* TIME_H_ */
