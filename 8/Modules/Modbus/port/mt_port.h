/*
 * mt_port.h
 *
 *  Created on: 5 мар. 2024 г.
 *      Author: Yuriy
 */

#ifndef MT_PORT_H_
#define MT_PORT_H_

extern void EnterCriticalSection();
extern void ExitCriticalSection();
#define ENTER_CRITICAL_SECTION()    EnterCriticalSection()
#define EXIT_CRITICAL_SECTION()     ExitCriticalSection()


#endif /* MT_PORT_H_ */
