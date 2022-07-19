/*--------------------------------------------------------------------
 * TITLE: uart str Defines
 * AUTHOR: Weize 
 * DATE CREATED: 2020/1/25
 * FILENAME: uartstr.h
 * PROJECT: w2
 * COPYRIGHT: Camel Microelectronics, Inc.
 * DESCRIPTION:
 *    w2 Hardware Defines
 *
 *    2020-01-25: initial
 *--------------------------------------------------------------------*/
#ifndef __UARTSTR_H__
#define __UARTSTR_H__
#include "UART.h"

#define uart_read()              RT_UART0_Read()
#define uart_kbhit()             RT_UART0_RxRdy()
#define uart_getch()             RT_UART_WaitRead(MCU_UART0)
void uart_putch(uint8_t c);
void uart_puts(const uint8_t *string);
uint32_t uart_getnum(void);
#endif //__UARTSTR_H__
































































