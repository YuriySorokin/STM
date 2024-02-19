/*
 * assebler.s
 *
 *  Created on: 19 февр. 2024 г.
 *      Author: Yuriy
 */


// #include "stm32f4xx.asm"



/*

.syntax unified




.text
.global ASM_Function
.thumb_func

 	MOV32 R0, CPACR
    LDR R1, [R0]
    ORR R1, R1, (0xF << 20)
    STR R1, [R0]

*/
    /*
        MOV32 R1, 0x3FDD70A4 @ 1.73
    	VMOV S2, R1 @ Передать число в регистр сопроцессора
    	MOV32 R1, 0x403D70A4 @ 2.96
    	VMOV S3, R1
    	VDIV.F32 S1, S2, S3 @ Разделить: S1=S2/S3
    	VMOV R1, S1 @ R1 теперь = 0x3F159F23 или ~0.584459 - вот именно, что приблизительно!
    */
