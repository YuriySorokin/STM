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

void Get_time ( void ) {

	//char buffer[11];
	char bufferH[4];
	char bufferM[4];
	char bufferS[4];

		//char buffer2[32];

	extern RTC_HandleTypeDef hrtc ;
	extern RTC_TimeTypeDef sTime;
	extern RTC_DateTypeDef sDate;

	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	sprintf(bufferH, "   %2d:", (int)sTime.Hours);
	print_comm3(bufferH);

	sprintf(bufferM, "%2d:", (int)sTime.Minutes);
	print_comm3(bufferM);

	sprintf(bufferS, "%2d", (int)sTime.Seconds);
	print_comm3(bufferS);





//	HAL_UART_Transmit_IT(&huart1, (uint8_t*) buffer, 20) ;


    // Получить отображение времени
//extern RTC_TimeTypeDef sTime;
 //  HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);

//

	//printf("%02d:",sTime.Hours);
	//printf("%02d:",sTime.Minutes);
	//printf("%02d\n",sTime.Seconds);


	HAL_Delay(1000);

};
