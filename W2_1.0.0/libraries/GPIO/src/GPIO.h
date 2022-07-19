/*--------------------------------------------------------------------
 * TITLE: GPIO Defines
 * AUTHOR: Weize 
 * DATE CREATED: 2020/1/25
 * FILENAME: GPIO.h
 * PROJECT: w2
 * COPYRIGHT: Camel Microelectronics, Inc.
 * DESCRIPTION:
 *    w2 Hardware Defines
 *
 *    2020-01-25: initial
 *--------------------------------------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__
#include "MCU.h"


/*********** Hardware addesses ***********/
#define SYS_IOCTL_REG     0x1f800704  // 0=in; 1-out (16-bit), was IO config
#define SYS_GPIO0_REG     0x1f800705  // GPIO (16-bit) to pad content 
#define SYS_GPIO1_REG     0x1f800706  // GPIO (16_bit) from pad read 

#define SET_GPIO0_BIT_ON(A) {MemoryOr32(SYS_IOCTL_REG, (1<<A)); MemoryOr32(SYS_GPIO0_REG, (1<<A)); }
#define SET_GPIO0_BIT_OFF(A) {MemoryOr32(SYS_IOCTL_REG, (1<<A)); MemoryAnd32(SYS_GPIO0_REG, ~(1<<A)); }
#define GET_GPIO1_BIT(A) MemoryBitAt(SYS_GPIO1_REG, A)

/*************** IO Setup***************/
#define RT_GPIO_EnWriteBit(n, oe) 	MCU_REG_WRITE(MCU_GPIO_RW, 1<<n, n, oe)
#define RT_GPIO_EnWrite(oe)		MCU_GPIO_RW = oe
#define RT_GPIO_WriteBit(n, v)	          MCU_REG_WRITE(MCU_GPIO_WRITE, 1<<n, n, v)
#define RT_GPIO_Write(v)		MCU_GPIO_WRITE = v
#define RT_GPIO_ReadBit(n)		MCU_REG_READ(MCU_GPIO_READ, 1<<n, n)
#define RT_GPIO_Read()		MCU_GPIO_READ
#define RT_GPIO_ReadWriteBit(n)		MCU_REG_READ(MCU_GPIO_WRITE, 1<<n, n)
#define RT_GPIO_ReadWrite()		MCU_GPIO_WRITE
/**************** IO End****************/

#endif //__GPIO_H__
























