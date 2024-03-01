/*
 * time.c
 *
 *  Created on: 14 февр. 2024 г.
 *      Author: Yuriy
 */

#include "main.h"
#include "time.h"
#include "stdio.h"
#include "usart1.h"

/*
typedef enum
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;

*/

RTC_TimeTypeDef sTime = {0};
RTC_DateTypeDef sDate = {0};
RTC_AlarmTypeDef sAlarm = {0};



void get_Time_to_comm3 (void){
	char bufferH[] = "        "; // обязательно 8-мь, не меньше, чем сформируется строка
	char spaces[] = "   ";


	extern RTC_HandleTypeDef hrtc ;
	extern RTC_TimeTypeDef sTime;
	extern RTC_DateTypeDef sDate;

	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	print_comm3(spaces);

	sprintf(bufferH, "%2d:%2d:%2d", (int)sTime.Hours, (int)sTime.Minutes, (int)sTime.Seconds);

	print_comm3(bufferH);

//	HAL_Delay(1000);
}

void get_Time (char *curTime){
	char bufferH[] = "        "; // обязательно 8-мь, не меньше, чем сформируется строка
	int i = 0 ;

	extern RTC_HandleTypeDef hrtc ;
	extern RTC_TimeTypeDef sTime;
	extern RTC_DateTypeDef sDate;

	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN); // GetDate for closing register
	sprintf(bufferH, "%2d:%2d:%2d", (int)sTime.Hours, (int)sTime.Minutes, (int)sTime.Seconds);
	//curTime = bufferH ;
	while (bufferH[i]){
		if (bufferH[i] == 32) { // change space to Zero
			curTime[i] = 48 ;
		} else {
		curTime[i] = bufferH[i] ;
		}

		i++;
	}
   // on_Zero_hoursetcurrent_date_and_time (&hrtc);
}


void get_time_to_comm ( void ) { // на экран

	//char buffer[11];
	char bufferH[4];
	char bufferM[4];
	char bufferS[4];
	char spaces[] = "   ";
		//char buffer2[32];

	extern RTC_HandleTypeDef hrtc ;
	extern RTC_TimeTypeDef sTime;
	extern RTC_DateTypeDef sDate;

	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);


	print_comm3(spaces);


	sprintf(bufferH, "%2d:", (int)sTime.Hours);
	print_comm3(bufferH);

	sprintf(bufferM, "%2d:", (int)sTime.Minutes);
	print_comm3(bufferM);

	sprintf(bufferS, "%2d", (int)sTime.Seconds);
	print_comm3(bufferS);

//	HAL_Delay(1000);

};

void get_Date (char *curDate){

	extern RTC_HandleTypeDef hrtc ;
	extern RTC_DateTypeDef sDate;

	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	char bufferH[] = "        "; // обязательно 8-мь, не меньше, чем сформируется строка
		int i = 0 ;

		extern RTC_HandleTypeDef hrtc ;
		//extern RTC_TimeTypeDef sTime;
		extern RTC_DateTypeDef sDate;

		//HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN); // GetDate for closing register
		sprintf(bufferH, "%2d:%2d:%2d", (int)sDate.Date, (int)sDate.Month, (int)sDate.Year);
		//curTime = bufferH ;
		while (bufferH[i]){
			if (bufferH[i] == 32) { // change space to Zero
				curDate[i] = 48 ;
			} else {
				curDate[i] = bufferH[i] ;
			}

			i++;
		}
}

void set_Date( uint8_t _DD, uint8_t _MM, uint8_t _YY ){

	//	Deal: up date for one
	// 1. get date
	// 2. plus date
	// 3. save date
	extern RTC_HandleTypeDef hrtc ;
	extern RTC_DateTypeDef sDate;

	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	sDate.Year = _YY ;
	sDate.Month = _MM ;
	sDate.Date = _DD ;

	HAL_RTC_SetDate( &hrtc, &sDate, RTC_FORMAT_BIN) ;

	// 1.get current Date

}

void set_Alarm (uint8_t SS,uint8_t MM,uint8_t HH){

	extern RTC_AlarmTypeDef sAlarm ;
	extern RTC_HandleTypeDef hrtc ;

	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	HAL_RTC_GetAlarm( &hrtc, &sAlarm, RTC_ALARM_A, RTC_FORMAT_BIN) ;




	  sAlarm.AlarmTime.Hours = HH;
	  sAlarm.AlarmTime.Minutes = MM;
	  sAlarm.AlarmTime.Seconds = SS;
	  sAlarm.AlarmTime.SubSeconds = 0;
	  sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	  sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	  sAlarm.AlarmMask = RTC_ALARMMASK_NONE;
	  sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	  sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
	  sAlarm.AlarmDateWeekDay = sAlarm.AlarmDateWeekDay;
	  sAlarm.Alarm = RTC_ALARM_A;

	  if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK)
	  {
	    Error_Handler();
	  }
}
void set_Time (void){
	  /** Initialize RTC and set the Time and Date
	  */

	extern RTC_HandleTypeDef hrtc ;
	extern RTC_TimeTypeDef sTime;


	sTime.Hours = 1;
	  sTime.Minutes = 0;
	  sTime.Seconds = 0;
	  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
	  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
	  {
	    Error_Handler();
	  }

}


void get_Alarm (char *curTime){



	char bufferH[] = "        "; // обязательно 8-мь, не меньше, чем сформируется строка
	int i = 0 ;

	extern RTC_HandleTypeDef hrtc ;
	extern RTC_TimeTypeDef sTime;
	extern RTC_DateTypeDef sDate;
	extern RTC_AlarmTypeDef sAlarm ;

	//HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	//HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN); // GetDate for closing register
	HAL_RTC_GetAlarm(&hrtc, &sAlarm, RTC_ALARM_A, RTC_FORMAT_BIN) ;



	sprintf(bufferH, "%2d:%2d:%2d", (int)sAlarm.AlarmTime.Hours, (int)sAlarm.AlarmTime.Minutes, (int)sAlarm.AlarmTime.Seconds);
	//curTime = bufferH ;
	while (bufferH[i]){
		if (bufferH[i] == 32) { // change space to Zero
			curTime[i] = 48 ;
		} else {
		curTime[i] = bufferH[i] ;
		}

		i++;
	}
   // on_Zero_hoursetcurrent_date_and_time (&hrtc);
}

