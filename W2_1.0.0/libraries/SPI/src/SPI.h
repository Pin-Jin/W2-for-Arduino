/*--------------------------------------------------------------------
 * TITLE: SPI Defines
 * AUTHOR: Weize 
 * DATE CREATED: 2020/1/25
 * FILENAME: SPI.h
 * PROJECT: w2
 * COPYRIGHT: Camel Microelectronics, Inc.
 * DESCRIPTION:
 *    w2 Hardware Defines
 *
 *    2020-01-25: initial
 *--------------------------------------------------------------------*/
#ifndef __SPI_H__
#define __SPI_H__

/*********** Hardware addesses ***********/

#define SPI_CTRL_CLKSEL_Pos            6U        //bit for selecting spi clock
#define SPI_CTRL_CLKSEL_Msk            (3U<<SPI_CTRL_CLKSEL_Pos)
#define SPI_CTRL_CPOL_Pos              5U        //bit for cpol value
#define SPI_CTRL_CPOL_Msk              (1U<<SPI_CTRL_CPOL_Pos)
#define SPI_CTRL_CPHA_Pos              4U        //bit for cpha value
#define SPI_CTRL_CPHA_Msk              (1U<<SPI_CTRL_CPHA_Pos)
#define SPI_CTRL_EN_Pos                3U        //bit for SPI on/off enable
#define SPI_CTRL_EN_Msk                (1U<<SPI_CTRL_EN_Pos)
#define SPI_CTRL_MASTER_Pos            2U        //bit for SPI master/slave select
#define SPI_CTRL_MASTER_Msk            (1U<<SPI_CTRL_MASTER_Pos)
#define SPI_CTRL_CS_Pos                1U        //bit for SPI CS (only for master mode)
#define SPI_CTRL_CS_Msk                (1U<<SPI_CTRL_CS_Pos)
#define SPI_CTRL_IRQ_EN_Pos            0U        //bit to enable SPI irq
#define SPI_CTRL_IRQ_EN_Msk            (1U<<SPI_CTRL_IRQ_EN_Pos)

/*************** SPI Setup***************/
#define RT_SPI_SetMaster(on)           MCU_REG_WRITE(MCU_SPI_CTRL, SPI_CTRL_MASTER_Msk, SPI_CTRL_MASTER_Pos, on)
#define RT_SPI_Write(val)	         MCU_SPI_WRITE = val
#define RT_SPI_RxRdy()	         MCU_SPI_RxRdy
#define RT_SPI_Read()	         MCU_SPI_READ
#define RT_SPI_TxRdy()                 MCU_SPI_TxBusy&0x00000001
#define RT_SPI_BlockWrite(val)         { while (!RT_SPI_TxRdy()); RT_SPI_Write(val); }
#define RT_SPI_EN(on)                   MCU_REG_WRITE(MCU_SPI_CTRL, SPI_CTRL_EN_Msk, SPI_CTRL_EN_Pos, on)
#define RT_SPI_SetCs(on)                MCU_REG_WRITE(MCU_SPI_CTRL, SPI_CTRL_CS_Msk, SPI_CTRL_CS_Pos, on)
#define RT_SPI_CLRIRQ()                 MCU_REG_WRITE(MCU_SPI_CLRIRQ,SPI_CTRL_CS_Msk, SPI_CTRL_CS_Pos, 1)
#define RT_SPI_ClkSel(div)           MCU_REG_WRITE(MCU_SPI_CTRL, SPI_CTRL_CLKSEL_Msk, SPI_CTRL_CLKSEL_Pos, div)
/**************** SPI End****************/

#endif //__SPI_H__








