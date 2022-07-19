#include "CORE.h"
#include "MCU.h"


uint32_t RT_SYS_Get_PLL_Freq()
{
    register uint32_t freq, ref_bit, pll_bits, n;
    freq = __XTAL_FREQ;
    ref_bit = MCU_REG_READ(MCU_PLL_CTRL, XTAL_DIV_EN_Msk, XTAL_DIV_EN_Pos);
    if (ref_bit == 1) {
        freq = (freq>>1);
    }
    pll_bits = MCU_REG_READ(MCU_PLL_CTRL, PLL_REFDIV_Msk, PLL_REFDIV_Pos);
    switch (pll_bits) {
    case 0x0 :
        n = 5;
        break;
    case 0x1 :
        n = 4;
        break;
    case 0x2 :
        n = 7;
        break;
    case 0x3 :
        n = 6;
        break;
    case 0x4 :
        n = 1;
        break;
    case 0x5 :
        n = 0; //not allowed
        break;
    case 0x6 :
        n = 3;
        break;
    case 0x7 :
        n = 2;
        break;
    case 0x8 :
        n = 13;
        break;
    case 0x9 :
        n = 12;
        break;
    case 0xa :
        n = 15;
        break;
    case 0xb :
        n = 14;
        break;
    case 0xc :
        n = 9;
        break;
    case 0xd :
        n = 8;
        break;
    case 0xe :
        n = 11;
        break;
    case 0xf :
        n = 10;
        break;
    default :
        break;
    }
    freq = (freq*((n+1)<<1));
    return freq;
}

void RT_SYS_Set_PLL_Freq(uint32_t freq)  //freq in MHz
{
    register uint32_t n, ref_bit, pll_bits;
    ref_bit = 0;
    pll_bits = 0;
   /*  n = freq/__XTAL_FREQ;
    //we can only get PLL freq in the range 2xXTAL_FREQ and 32xXTAL_FREQ
    if (n < 2) {
        n = 2;
    } else if (n > 32) {
        n = 32;
    }
    if ((n - ((n>>1)<<1)) == 1) {//n is odd
        ref_bit = 1; //need to divide the xtal freq by 2 to get ref clk freq first
    } else {
        n = (n>>1);
    }
    n = (n-1);
    if (n == 0 && ref_bit == 0) { //can create the PLL by divide the ref clk by 2, then adjust (n+1) to 4
        n = 3;
    }
    switch (n) {
    case 0 :
        //not allowed
        break;
    case 1 :
        pll_bits = 0x4;
        break;
    case 2 :
        pll_bits = 0x7;
        break;
    case 3 :
        pll_bits = 0x6;
        break;
    case 4 :
        pll_bits = 0x1;
        break;
    case 5 :
        pll_bits = 0x0;
        break;
    case 6 :
        pll_bits = 0x3;
        break;
    case 7 :
        pll_bits = 0x2;
        break;
    case 8 :
        pll_bits = 0xd;
        break;
    case 9 :
        pll_bits = 0xc;
        break;
    case 10 :
        pll_bits = 0xf;
        break;
    case 11 :
        pll_bits = 0xe;
        break;
    case 12 :
        pll_bits = 0x9;
        break;
    case 13 :
        pll_bits = 0x8;
        break;
    case 14 :
        pll_bits = 0xb;
        break;
    case 15 :
        pll_bits = 0xa;
        break;
    default :
        break;
    } */
    MCU_REG_WRITE(MCU_PLL_CTRL, XTAL_DIV_EN_Msk, XTAL_DIV_EN_Pos, ref_bit);
    MCU_REG_WRITE(MCU_PLL_CTRL, PLL_REFDIV_Msk, PLL_REFDIV_Pos, pll_bits);
}

uint32_t RT_SYS_Get_CLK_Freq()
{
    //register int pll, clk_bit;  //note if register is declared, the clk_bit result won't be right due to the & operator, the reason is unkown
    uint32_t pll, clk_bit;
    pll = RT_SYS_Get_PLL_Freq();
    clk_bit = MCU_REG_READ(MCU_CLK_CTRL, CLK_DIV_Msk, CLK_DIV_Pos);
    switch (clk_bit) {
    case 0x3 :
        return (pll>>1);
    case 0x2 :
        return (pll>>2);
    case 0x1 :
        return (pll>>3);
    case 0x0 :
        return (pll>>4);
    }
}

void RT_SYS_Set_CLK2PLL(uint32_t n)
{
    register uint32_t clk_bit;
    switch (n) {
    case 1 :
        clk_bit = 0x3;
        break;
    case 2 :
        clk_bit = 0x2;
        break;
    case 4 :
        clk_bit = 0x1;
        break;
    case 16 :
        clk_bit = 0x0;
        break;
    default:
        clk_bit = 0x00;
        break;
    }
    MCU_REG_WRITE(MCU_CLK_CTRL, CLK_DIV_Msk, CLK_DIV_Pos, clk_bit);
}

void RT_SYS_Init(uint32_t xtal_freq, uint32_t pll_freq, uint32_t pll2clk_div)
{
    MCU_EXINT_SET = 0xff;    // ex int high enable set
    MCU_EXINT_CLR = 0xff;    // ex int clear
    MCU_EXINT_EN = 0;        // ex int DISABLE set
    MCU_GPIO_RW = 0;         // This 16-bit reg is used as menu record pointer
    MCU_CTRL = 0;
    MemoryWrite(INT_COUNT, 0x0); //initialize the reg for recording number of interrupts in the path,
                                 //it determines where SP is stored for each interrupt
    MemoryWrite(USER_INT, 0x0); //initialize the reg to choose gdb() or user interrupt function when interrupt is generated
    __XTAL_FREQ = xtal_freq;
    RT_SYS_Set_PLL_Freq(pll_freq);
    RT_SYS_Set_CLK2PLL(pll2clk_div);
}

void RT_Delay_ms(unsigned long ms)
{	
    register uint32_t i;
    while(ms--)
    {
        for (i = 0; i < 200; i++)
            asm("nop");
    }
}

/***********************************************************
 * clear SRAM
 **********************************************************/
void RT_Clr_Ram()  
{
    register uint32_t i;
    for(i=0;i<MCU_SRAM_SIZE;i = i + 4)
    {
      (*(volatile uint32_t *)(MCU_SRAM_BASE + i)) = 0; 
    }
}

uint32_t __XTAL_FREQ = 8;

















