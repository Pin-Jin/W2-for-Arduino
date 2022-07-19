#include "MCU.h"
#include "AFE.h"

uint32_t RT_ADC_Read()
{
    register uint32_t ready;
    if (MCU_REG_READ(MCU_ADC_CTRL, ADC_CTRL_OTC_Msk, ADC_CTRL_OTC_Pos)) {
        RT_ADC_Start();
    }
    ready = RT_ADC_RxRdy();
    while (!ready) //check if rdy bit is ok
        ready = RT_ADC_RxRdy();
    return RT_ADC_NONBLOCK_Read();
}

















