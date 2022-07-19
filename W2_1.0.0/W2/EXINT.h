/*--------------------------------------------------------------------
 * TITLE: EXT interrput Defines
 * AUTHOR: Weize 
 * DATE CREATED: 2020/1/25
 * FILENAME: EXINT.h
 * PROJECT: w2
 * COPYRIGHT: Camel Microelectronics, Inc.
 * DESCRIPTION:
 *    w2 Hardware Defines
 *
 *    2020-01-25: initial
 *--------------------------------------------------------------------*/
#ifndef __EXINT_H__
#define __EXINT_H__
#include "MCU.h"

/*********** External interrupt***********/
//********************************************************//
// void RT_EXINT_En(int en, int trigger)                 //
// Description:                                           //
// This function set the external interrupt               //
// "n" is the the number of the interrupt you want to    //
// open. n = 0:5 stands for INT0:INT5 representively.    //
// "trigger" is the trigger constrant."trigger" = 1 means //
// high level trigger."trigger"=0 means low level trigger //
//********************************************************//
#define RT_EXINT_On(n, trigger)      {MCU_REG_WRITE(MCU_CTRL, CTRL_IRQ_EN_Msk, CTRL_IRQ_EN_Pos, 1);	\
                                      MCU_REG_WRITE(MCU_EXINT_EN, 1<<n, n, 1); \
                                      MCU_REG_WRITE(MCU_EXINT_SET, 1<<n, n, trigger);}
#define RT_EXINT_Off(n)               MCU_REG_WRITE(MCU_EXINT_EN, 1<<n, n, 0)
#define RT_EXINT_Clr()	        MCU_EXINT_CLR=1
#define RT_EXINT_Flag()	        MCU_EXINT_STA
/*********** External interrupt end*******/

#endif //__EXINT_H__
























