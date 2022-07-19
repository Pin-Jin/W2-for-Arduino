#include "UART.h"
#include "CORE.h"
#include "MCU.h"

//########################################################//
//  Title:Sub-function for UART app	                  //
//  AUTHER:lilb                                           //
//  PROJECT:w2                                            //
//########################################################//

void RT_UART_WriteChar(uint32_t uart, uint8_t value)
{
    register MCU_UART_BUSY_TypeDef writeBusy = 1;
    do {
        writeBusy =*(uint32_t *)(uart + MCU_UART_TxBusy_Pos);
    } while (writeBusy);	
    *(MCU_UART_VAL_TypeDef *)(uart + MCU_UART_WRITE_Pos) = value;
}

void RT_UART_WriteShort(uint32_t uart, uint16_t value)
{
    register MCU_UART_BUSY_TypeDef writeBusy = 1;
    for (register uint32_t i = 0; i < 2; i++)
    {
        do {
            writeBusy =*(uint32_t *)(uart + MCU_UART_TxBusy_Pos);
        } while (writeBusy);	
        *(MCU_UART_VAL_TypeDef *)(uart + MCU_UART_WRITE_Pos) = value;
        value = (value>>8);
    }	
}

void RT_UART_WriteInt(uint32_t uart, uint32_t value)
{	
    register MCU_UART_BUSY_TypeDef writeBusy = 1;
    for (register uint32_t i = 0; i < 4; i++)
    {
        do {
            writeBusy =*(uint32_t *)(uart + MCU_UART_TxBusy_Pos);
        } while (writeBusy);	
        *(MCU_UART_VAL_TypeDef *)(uart + MCU_UART_WRITE_Pos) = value;
        value = (value>>8);
    }	
}

void RT_UART_WriteString(uint32_t uart, uint8_t * string)
{
    register MCU_UART_BUSY_TypeDef writeBusy = 1;
    while(*string) {
        do {
            writeBusy =*(uint32_t *)(uart + MCU_UART_TxBusy_Pos);
        } while (writeBusy);
        *(MCU_UART_VAL_TypeDef *)(uart + MCU_UART_WRITE_Pos) = *string++;
    }
}

void RT_UART_WriteIntArray(uint32_t uart, uint32_t * data, uint32_t num)
{
    register MCU_UART_BUSY_TypeDef writeBusy = 1;
    for (register uint32_t j = 0; j < num; j++) {
        register uint32_t value = data[j];
        for (register uint32_t i = 0; i < 4; i++) {
            do {
                writeBusy =*(uint32_t *)(uart + MCU_UART_TxBusy_Pos);
            } while (writeBusy);		
            *(MCU_UART_VAL_TypeDef *)(uart + MCU_UART_WRITE_Pos) = value;
            value = (value>>8);
        }
    }
}


uint8_t RT_UART_WaitRead(uint32_t uart)
{
    register uint8_t val;
    register MCU_UART_RDY_TypeDef readRdy = 0;
    do {
        readRdy=((*(uint32_t *)(uart + MCU_UART_RxRdy_Pos))&0x1);
    } while (readRdy == 0);
    val =  *(uint32_t *)(uart + MCU_UART_READ_Pos);
    return val;
}


/* void RT_UART_SetBR(uint32_t uart, uint32_t baudrate)
{
    uint32_t clk, brp;
    //find the main clock freq
    clk = RT_SYS_Get_CLK_Freq();
    //based on the main clock freq and baudrate, calculate UART0_BRP value
    brp = (clk*1000000)/baudrate*2;
    *(MCU_UART_BRP_TypeDef *)(uart + MCU_UART_BRP_Pos) = brp;
}
 */
























































