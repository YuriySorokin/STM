/*
 * menu.c
 *
 *  Created on: 9 февр. 2024 г.
 *      Author: Yuriy
 */
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_hal.h"
#include "user.h"
#include "menu.h"
#include "display.h"

typedef struct
{
	uint16_t TextColor;
	uint16_t BackColor;


}Menu_TypeDef;

Menu_TypeDef Menu;

enum Menu_number
{
	FRAME_1 = 1,
	FRAME_2 = 2,
	FRAME_3 = 3,
	FRAME_4 = 4,
	FRAME_5 = 5,
	FRAME_6 = 6,
	FRAME_7 = 7,
	FRAME_8 = 8,
};


void Switch_MenuScreen(uint8_t step_by_step){

	switch( step_by_step ){

	     case FRAME_1:
	     	    	 	 Frame_1(step_by_step);
	     	    	 	 break;
	     case FRAME_2:
	    	 	 	 	 Frame_2(step_by_step);
	     	    	 	 break;
	     case FRAME_3:
	    	 	 	 	 Frame_3(step_by_step);
	     	    	 	 break;
	     case FRAME_4:
	    	 	 	 	 Frame_4(step_by_step);
	     	    	 	 break;
	     case FRAME_5:
	    	 	 	 	 Frame_5(step_by_step);
	     	    	 	 break;
	     case FRAME_6:
	    	 	 	 	 Frame_6(step_by_step);
	     	    	 	 break;
	     case FRAME_7:
	    	 	 	 	 Frame_7(step_by_step);
	     	    	 	 break;
	     case FRAME_8:
	    	 	 	 	 Frame_8(step_by_step);
	     	    	 	 break;
	     default : break ;
	}
}


void Frame1(){

	/* Frame1
	 *
	 * print Line1
	 *	Name: firmware_name, version: firmware_version
	 *
	 * print Line2
	 *  Time: Time_current, (+timeZone), data
	 *
	 * print line3
	 * 	H: thickness, [mm]
	 *
	 * print line4
	 * 	Left before  <  pwd  > Right after
	 *
	 ** 	1	< Home >	1
	*/
	print_Line1_F1(); // x0 y10
	print_Line2_F1(); // x0 y10 + 24
	print_Line3_F1(); // x0 y10 + 24 + 24
	print_Line4_F1(); // x0 y10 + 24 + 24 +24
}

void 	print_Line1_F1(void){
	// * print Line1
	//	 *	Name: firmware_name, version: firmware_version
	print_text_Line1_F1();
};

void 	print_Line2_F1(void){

	 //* print Line2
	 //*  Time: Time_current, (+timeZone), data
	 print_text_Line2_F1();

}

void 	print_Line3_F1(void){

	 //* print line3
	 //* 	H: thickness, [mm]
	 print_text_Line3_F1();

}



void 	print_Line4_F1(void);

void 	print_Line1_F2(void){
	// * print Line1
	//	 *	Name: firmware_name, version: firmware_version
	print_text_Line1_F2();
};




void DrawMenu ( uint8_t count){

  switch (count)
  {
  	  case 1: { count++;

  	  } break ;

  	  case 2: { count++; count ++;

  	  } break ;
  	  default: break ;
  }

   // Start_2(); // not used

	/* Frame1

  }

	 *
	 * print Line1
	 *	Name: firmware_name, version: firmware_version
	 *
	 * print Line2
	 *  Time: Time_current, (+timeZone), data
	 *
	 * print line3
	 * 	H: thickness, [mm]
	 *
	 * print line4
	 * 	Left before  <  pwd  > Right after
	 *
	 ** 	1	< Home >	1
	*/

  	  /* Frame2
	 *
	 * print Line1
	 *	Battery : level [%]
	 *
	 * print Line2
	 *  Error : [0]
	 *
	 * print line3
	 * 	Net : Ok
	 *
	 * print line4
	 * 	Left before  <  pwd  > Right after

	 * 	Home	< 1 >	Home
	 *
	 */
	 /* Frame3
	  *
	 * print Line1
	 *	SN : SerialNumber, Temp: degrees [C]
	 *
	 * print Line2
	 *  V sound : 5900 [mm/s]
	 *
	 * print line3
	 * 	Contact: Ok , Int: 300sec
	 *
	 * print line4
	 * 	Left before  <  pwd  > Right after

	 * 	5	< Home >	1
	  */

	 /* Frame4
	  *
	 * print Line1
	 *	PIN :

	 * print Line2
	 *		5418
	 *
	 * print line3
	 *
	 *
	 * print line4
	 * 	select digit <    < Enter

	  */
	 /* Frame5
	  *
	 * print Line1
	 *	Net: LoraWan

	 *
	 * print Line2
	 *  Status: Ok
	 *
	 * print line3
	 * 	Last connect: 250 sec
	 *
	 * print line4
	 *
	 * 	5	< Home >	1
	  */

	 /* Frame6
		  *
		 * print Line1
		 *	Net: RS485
		 *
		 * print Line2
		 *  Speed: 9600K
		 *
		 * print line3
		 * 	Addres: 40
		 *
		 * print line4
		 *
		 * 	5	< Home >	1
		  */

	/* Frame7
			 *
			 * print Line1
			 *	Net: NB-10T
			 *
			 * print Line2
			 *  Status: Ok
			 *
			 * print line3
			 * 	Last connect: 250 sec
			 *
			 * print line4
			 *
			 * 	5	< Home >	1
			  */
	 /* Frame8
		  *
		 * print Line1
		 *	time: current , date

		 *
		 * print Line2
		 *  GPS: Ok
		 *
		 * print line3
		 * 	TimeZone : +5
		 *
		 * print line4
		 *
		 * 	5	< Home >	1
		  */

}
