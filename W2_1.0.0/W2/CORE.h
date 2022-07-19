/*--------------------------------------------------------------------
 * TITLE: CORE Defines
 * AUTHOR: Weize 
 * DATE CREATED: 2020/1/25
 * FILENAME: CORE.h
 * PROJECT: w2
 * COPYRIGHT: Camel Microelectronics, Inc.
 * DESCRIPTION:
 *    w2 Hardware Defines
 *
 *    2020-01-25: initial
 *--------------------------------------------------------------------*/
#ifndef __CORE_H__
#define __CORE_H__
#include "MCU.h"

uint32_t RT_SYS_Get_PLL_Freq();
void RT_SYS_Set_PLL_Freq(uint32_t freq);
uint32_t RT_SYS_Get_CLK_Freq();
void RT_SYS_Set_CLK2PLL(uint32_t n);
void RT_SYS_Init(uint32_t xtal_freq, uint32_t pll_freq, uint32_t pll2clk_div);
void RT_Delay_ms(uint32_t ms);
void RT_Clr_Ram();

#endif //__CORE_H__
















