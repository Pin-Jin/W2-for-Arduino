/*--------------------------------------------------------------------
 * TITLE: uart Defines
 * AUTHOR: Weize 
 * DATE CREATED: 2020/1/25
 * FILENAME: UART.h
 * PROJECT: w2
 * COPYRIGHT: Camel Microelectronics, Inc.
 * DESCRIPTION:
 *    w2 Hardware Defines
 *
 *    2020-01-25: initial
 *--------------------------------------------------------------------*/
#ifndef __UART_H__
#define __UART_H__
#include<MCU.h>

/*********** Hardware addesses ***********/
#define UART_CTRL_CMP_Pos        8U        //bits to store the UART compare key word for the Ctrl-c from Sutdio
#define UART_CTRL_CMP_Msk        (0xFF<<UART_CTRL_CMP_Pos)
#define UART_CTRL_LINSTOP_Pos    7U        //bit indicates LIN RX break flag
#define UART_CTRL_LINSTOP_Msk    (1U<<UART_CTRL_LINSTOP_Pos)
#define UART_CTRL_LINBRK_Pos     5U        //bit indicates LIN brk enable
#define UART_CTRL_LINBRK_Msk     (1U<<UART_CTRL_LINBRK_Pos)
#define UART_CTRL_LINEN_Pos      4U        //bit to enable LIN
#define UART_CTRL_LINEN_Msk      (1U<<UART_CTRL_LINEN_Pos)
#define UART_CTRL_LINSYNC_Pos    3U        //bit for LIN sync enable
#define UART_CTRL_LINSYNC_Msk    (1U<<UART_CTRL_LINSYNC_Pos)
#define UART_CTRL_LINIRQ_Pos     2U        //bit to enable LIN irq
#define UART_CTRL_LINIRQ_Msk     (1U<<UART_CTRL_LINIRQ_Pos)
#define UART_CTRL_CMP_EN_Pos     1U        //bit to enable uart comparator
#define UART_CTRL_CMP_EN_Msk     (1U<<UART_CTRL_CMP_EN_Pos)
#define UART_CTRL_IRQ_EN_Pos     0U        //bit to enable uart irq
#define UART_CTRL_IRQ_EN_Msk     (1U<<UART_CTRL_IRQ_EN_Pos)

/*************** UART0 Setup***************/
#define RT_UART0_TxBusy()	MCU_UART0_TxBusy
#define RT_UART0_RxRdy() 	MCU_UART0_RxRdy
#define RT_UART0_Read()	MCU_UART0_READ
#define RT_UART0_IRQ()	MCU_REG_READ(MCU_UART0_CTRL, UART_CTRL_IRQ_Msk, UART_CTRL_IRQ_Pos)
#define RT_UART0_CLRIRQ()	MCU_UART0_CLRIRQ=1
/*************** UART1 Setup***************/
#define RT_UART1_TxBusy()	MCU_UART1_TxBusy
#define RT_UART1_RxRdy() 	MCU_UART1_RxRdy
#define RT_UART1_Read()	MCU_UART1_READ
#define RT_UART1_IRQ()	MCU_REG_READ(MCU_UART1_CTRL, UART_CTRL_IRQ_Msk, UART_CTRL_IRQ_Pos)
#define RT_UART1_CLRIRQ()	MCU_UART1_CLRIRQ=1

void RT_UART_WriteChar(uint32_t uart, uint8_t value);
#if 1 //no need for bootloader
void RT_UART_WriteShort(uint32_t uart, uint16_t value);
void RT_UART_WriteInt(uint32_t uart, uint32_t value);
void RT_UART_WriteString(uint32_t uart, uint8_t * string);
void RT_UART_WriteIntArray(uint32_t uart, uint32_t * data, uint32_t num);
#endif
uint8_t RT_UART_WaitRead(uint32_t uart);
#if 1 //no need for bootloader
void RT_UART_SetBR(uint32_t uart, uint32_t baudrate);
#endif 

/**************** UART End****************/

#endif //__UART_H__
































































