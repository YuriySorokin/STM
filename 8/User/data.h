/*
 * data.h
 *
 *  Created on: 16 февр. 2024 г.
 *      Author: Yuriy
 */

#ifndef SRC_DATA_H_
#define SRC_DATA_H_

#include "main.h"


enum netName {
	RS485 = 1,
	Lorawan = 2 ,
};

enum firmware {
	FirmwareName,
	Firmware_version
};

enum netStatus {
	OK = 0 ,
	Falt = 1
};



typedef struct {
	uint8_t firmware_name[12] ;
	uint8_t firmware_version ;
	uint8_t bat_level ;
	enum netName Net_name ;
	uint8_t net_status_ok ;
	uint8_t error ;
	uint8_t serial_number ;
	uint8_t degrees ;
	uint16_t V_sound ;
	uint8_t contact ;
	uint8_t interval;
	uint8_t pin_num;
	uint32_t last_connect_time ;
	uint16_t net_RS_speed ;
	uint8_t net_RS_addres;

} Menu_Data ;


#endif /* SRC_DATA_H_ */
