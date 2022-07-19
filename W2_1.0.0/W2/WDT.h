/*--------------------------------------------------------------------
 * TITLE: SPI Defines
 * AUTHOR: Weize 
 * DATE CREATED: 2020/11/15
 * FILENAME: SPI.h
 * PROJECT: w2
 * COPYRIGHT: Camel Microelectronics, Inc.
 * DESCRIPTION:
 *    w2 Hardware Defines
 *
 *    2020-11-15: initial
 *--------------------------------------------------------------------*/
#ifndef __WDT_H__
#define __WDT_H__

/*********** Hardware addesses ***********/
#define WDT_CTRL_CLK_Pos               8U        //start location for WDT timer clk div
#define WDT_CTRL_CLK_Msk               (255U<<WDT_CTRL_CLK_Pos)
#define WDT_CTRL_IRQ_EN_Pos            2U        //bit to enable WDT irq
#define WDT_CTRL_IRQ_EN_Msk            (1U<<WDT_CTRL_IRQ_EN_Pos)
#define WDT_CTRL_RST_EN_Pos            1U        //bit to enable WDT reset
#define WDT_CTRL_RST_EN_Msk            (1U<<WDT_CTRL_RST_EN_Pos)
#define WDT_CTRL_EN_Pos                0U        //bit to enable WDT 
#define WDT_CTRL_EN_Msk                (1U<<WDT_CTRL_EN_Pos)

/*************** WDT Setup***************/
//********************************************************//
// void RT_WDT_Set(n, irq, rst);          			      //
//                                                        //
// Description:                                           //
// This function set the WDT app    				      //
// n:   the number of 1/8s   n=1~16                       //
// irq: trigger interrupt						          //
// reset: reset the system						          //
//********************************************************//
#define RT_WDT_Set(n, irq, rst)        {MCU_REG_WRITE(*(MCU_WDT_CTRL_TypeDef*)MCU_WDT_CTRL, \
                                        WDT_CTRL_CLK_Msk, WDT_CTRL_CLK_Pos, n); \
                                        MCU_REG_WRITE(*(MCU_WDT_CTRL_TypeDef*)MCU_WDT_CTRL, \
                                        WDT_CTRL_IRQ_EN_Msk, WDT_CTRL_IRQ_EN_Pos, irq); \
                                        MCU_REG_WRITE(*(MCU_WDT_CTRL_TypeDef*)MCU_WDT_CTRL, \
                                        WDT_CTRL_RST_EN_Msk, WDT_CTRL_RST_EN_Pos, rst); \
                                        MCU_REG_WRITE(MCU_WDT_CTRL, WDT_CTRL_EN_Msk, WDT_CTRL_EN_Pos, 1); }
#define RT_WDT_Clr()	         MCU_WDT_CLR = 0
#define RT_WDT_ReadCnt()	         MCU_WDT_READ

/**************** WDT End****************/

#endif //__WDT_H__
























