
#include "MCU.h"
#include "uartstr.h"


void uart_putch(uint8_t c)// 
{
    register uint32_t uart0_ctrl = MCU_UART0_CTRL;
    MCU_REG_WRITE(MCU_UART0_CTRL, UART_CTRL_IRQ_EN_Msk, UART_CTRL_IRQ_EN_Pos, 0);
            //added on 9/27/2019 to fix interrupt caused random char print from uart
            //disable interrupt
    RT_UART_WriteChar(MCU_UART0, c);	
    MCU_UART0_CTRL = uart0_ctrl;   //added on 9/27/2019 to fix interrupt caused random char print from uart
}	

void uart_puts(const uint8_t *string)
{
    register uint32_t uart0_ctrl = MCU_UART0_CTRL;
    MCU_REG_WRITE(MCU_UART0_CTRL, UART_CTRL_IRQ_EN_Msk, UART_CTRL_IRQ_EN_Pos, 0);
            //added on 9/27/2019 to fix interrupt caused random char print from uart
            //disable interrupt
    while(*string)
    {
        if(*string == '\n')
            uart_putch('\r');
        uart_putch(*string++);
    }
    MCU_UART0_CTRL = uart0_ctrl;    //added on 9/27/2019 to fix interrupt caused random char print from uart
}

uint32_t uart_getnum(void)
{
    register uint8_t i;
    register uint8_t ch;
    register uint32_t value=0;

    for(i = 0; i < 16; )   // why 16 ? not 8?
    {
        ch  = uart_getch();
        if(ch == '\r')
            break;
        if(ch == '\n' || ch == '\r' || ch == ' ')
            break;
        if('0' <= ch && ch <= '9')
            ch -= '0';
        else if('A' <= ch && ch <= 'Z')
            ch = ch - 'A' + 10;
        else if('a' <= ch && ch <= 'z')
            ch = ch - 'a' + 10;
        else if(ch == 8)  // ^H  or \b  backspace  ???
        {
            if(i > 0)
                --i;
            value >>= 4;
            continue;
        }
        value = (value << 4) + ch;
        ++i;
    }
    return value;
}

















