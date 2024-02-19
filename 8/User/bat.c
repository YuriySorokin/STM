/*
 * bat.c
 *
 *  Created on: 16 февр. 2024 г.
 *      Author: Yuriy
 */
#include "bat.h"
#include "main.h"
#include "stm32f4xx_hal_adc_ex.h"
#include "adc.h"
#include <stdio.h>


void battery_metter(float*	batteryVoltage){

	uint8_t count10 = 10 ;
	float mcuVoltage = 0;
	uint32_t Timeout = 100 ;

//	float batteryVoltage = 0;

	uint16_t adcData[2];
	uint8_t ADC_REFERENCE_VOLTAGE = 1.2 ;
	uint16_t ADC_MAX			= 	0xFFF ;

		//HAL_ADCEx_Calibration_Start(&hadc1);
	//(&hadc1) ;
	//HAL_ADCEx_MultiModeStart_DMA(&hadc1);
//		HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcData, 2);

		while (count10--){

			HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcData, 2);
			 if ( HAL_ADC_PollForConversion(&hadc1, Timeout) != HAL_OK ) { ; };

			mcuVoltage = ADC_MAX * ADC_REFERENCE_VOLTAGE / adcData[0];
			*batteryVoltage = 2 * adcData[1] * mcuVoltage / ADC_MAX;



		}
}


void get_battery_level (char *curTime){


	char buffer[] = "                  "; // обязательно 8-мь, не меньше, чем сформируется строка
	int i = 0 ;
	float batteryVoltage = 0 ;
	//float mcuVoltage = 0;

	//HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	//HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	 battery_metter( &batteryVoltage);

	//sprintf(bufferH, "%2d:%2d:%2d", (int)sTime.Hours, (int)sTime.Minutes, (int)sTime.Seconds);
	 sprintf(buffer, "%g", batteryVoltage);

	// замена float

	//sprintf(buffer, "%d.%d",(int)batteryVoltage/10, (int)(batteryVoltage-(batteryVoltage/10)*100000000 ));

	//printf("Result is: %d.%d", i/10, i%10);

	//-u _printf_float
	//curTime = bufferH ;
	while (buffer[i]){
		if (buffer[i] == 32) {
			curTime[i] = 48 ;
		} else {
		curTime[i] = buffer[i] ;
		}

		i++;
	}

}

