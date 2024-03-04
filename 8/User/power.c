/*
 * power.c
 *
 *  Created on: 29 февр. 2024 г.
 *      Author: Yuriy
 */
#include "power.h"
#include "stm32f4xx_hal.h"


void set_lowPower(void ){

	HAL_SuspendTick () ;
	HAL_PWR_EnterSLEEPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);
	// HAL_ResumeTick() ; in all IRQ on wakeup
	//HAL_ResumeTick()
	// https://istarik.ru/blog/stm32/117.html
	/*
	 *  если поставить бит, то в сон уйдёт сразу, иначе по обработке всез прерываний
	 * 	HAL_PWR_EnableSleepOnExit(); // установить
		HAL_PWR_DisableSleepOnExit(); // очистить
	 */
}

void set_stop_mode(void){

	/*
	 * Stop mode — режим глубокой спячки ядра.
	 * Останавливаются все генераторы тактовой частоты в 1.8V domain,
	 *  а так же HSI и HSE. Все цепи ввода-вывода сохраняют своё состояние.
	 *  нужно заново запустить SystemClock_Config();
	 *  потому-что уходит на LSI
	 *
	 * Выход из режима остановки возможен только с помощью прерывания
	 *  или события на любой линии EXTI
	 *
	 *  При выходе из режима остановки используется HSI RC генератор,
	 *  поэтому нужно заново сконфигурировать тактирование с помощью функции SystemClock_Config().
	 */
	HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
	// или PWR_STOPENTRY_WFE

}


void set_standby_mode(){
	/*
	 *
	 * Standby mode Это самый экономичный режим.
	 * Отключается почти что всё, кроме RTC и IWDG (независимый WatchDog. См. ниже).
	 * Информация в регистрах теряется, а цепи ввода-вывода отключаются.
	 * Состояние МК почти такое же как и без питания.
	 *
	 *
	 *
	 * Здесь есть один нюанс. Дело в том, что после срабатывания WakeUp'а
	 * Здесь микроконтроллер сразу же ресетится, а флаг WakeUp'а остаётся
	 * Здесь в регистрах взведённым. Соответственно после инициализации и
	 * Здесь очередного входа в режим, МК видит этот флаг и тут же опять ресетится,
	 * Здесь  и так по кругу. Побороть это очень просто,
	 * Здесь   надо сбрасывать флаг до бесконечного цикла:
	 *     __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
	 */
	  __HAL_RCC_PWR_CLK_ENABLE();
	  HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);
	  __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
	  HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
	  HAL_PWR_EnterSTANDBYMode();

	//HAL_PWR_EnterSTANDBYMode();
}
