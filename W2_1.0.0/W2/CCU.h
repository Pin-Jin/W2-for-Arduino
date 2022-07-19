/*--------------------------------------------------------------------
 * TITLE: CCU Defines
 * AUTHOR: Weize 
 * DATE CREATED: 2020/1/25
 * FILENAME: CCU.h
 * PROJECT: w2
 * COPYRIGHT: Camel Microelectronics, Inc.
 * DESCRIPTION:
 *    w2 Hardware Defines
 *
 *    2020-01-25: initial
 *--------------------------------------------------------------------*/
#ifndef __CCU_H__
#define __CCU_H__


/*****control bits*****/
#define CCU_CTRL_IRQ_Pos           31U        //bit for timer irq flag
#define CCU_CTRL_IRQ_Msk           (1U<<CCU_CTRL_IRQ_Pos)
#define CCU_CTRL_PWM_IRQ_Pos       30U        //bit for PWM irq flag
#define CCU_CTRL_PWM_IRQ_Msk       (1U<<CCU_CTRL_PWM_IRQ_Pos)
#define CCU_CTRL_PWM_MIX_Pos       16U        //bit for PWM mix flag, currently there is a bug, need to set it to 3 to get PWM output to pin 
#define CCU_CTRL_PWM_MIX_Msk       (2U<<CCU_CTRL_PWM_MIX_Pos)
#define CCU_CTRL_CLKDIV_Pos        8U        //bit for timer clock divider, PWM clock or Timer clock is their respect base clock (PLL clock or main clock) divided by this number 
#define CCU_CTRL_CLKDIV_Msk        (255U<<CCU_CTRL_CLKDIV_Pos)
#define CCU_CTRL_IRQ_EN_Pos        7U        //bit for enable Timer irq
#define CCU_CTRL_IRQ_EN_Msk        (1U<<CCU_CTRL_IRQ_EN_Pos)
#define CCU_CTRL_PWM_IRQ_EN_Pos    6U        //bit for pwm irq enable
#define CCU_CTRL_PWM_IRQ_EN_Msk    (1U<<CCU_CTRL_PWM_IRQ_EN_Pos)
#define CCU_CTRL_PWM2PAD_EN_Pos    5U        //bit to turn on pwm to output to pad, TIMER does not has this option, since CCU wants to be able to only send to pad after pwm setting are all done to avoid unstable signal sent to pad 
#define CCU_CTRL_PWM2PAD_EN_Msk    (1U<<CCU_CTRL_PWM2PAD_EN_Pos)
#define CCU_CTRL_PWM_EN_Pos        4U        //bit to turn on PWM 
#define CCU_CTRL_PWM_EN_Msk        (1U<<CCU_CTRL_PWM_EN_Pos)
#define CCU_CTRL_PWMM_EN_Pos       3U        //bit to turn on PWMM mode
#define CCU_CTRL_PWMM_EN_Msk       (1U<<CCU_CTRL_PWMM_EN_Pos)
#define CCU_CTRL_EDGESEL_Pos       2U        //PWMM and ECNT measurement starting edge select, 1 for rising edge
#define CCU_CTRL_EDGESEL_Msk       (1U<<CCU_CTRL_EDGESEL_Pos)
#define CCU_CTRL_TIMER_EN_Pos      1U        //bit to turn on timer mode, main clock is used as the base clock
#define CCU_CTRL_TIMER_EN_Msk      (1U<<CCU_CTRL_TIMER_EN_Pos) 
#define CCU_CTRL_ECNT_EN_Pos       0U        //bit to turn on ECNT mode
#define CCU_CTRL_ECNT_EN_Msk       (1U<<CCU_CTRL_ECNT_EN_Pos)   

/*****configuration bits*****/
#define CCU_CONF_TRIG_ADC_EN_Pos        14U        //bit to enable pwm trig adc
#define CCU_CONF_TRIG_ADC_EN_Msk        (1U<<CCU_CONF_TRIG_ADC_EN_Pos)
#define CCU_CONF_PWM_OSW_Pos            13U        //bit to switch the pad connected to pwm0/pwm1 to pwm1/pwm0
#define CCU_CONF_PWM_OSW_Msk            (1U<<CCU_CONF_PWM_OSW_Pos)
#define CCU_CONF_SYNC_ADC_EN_Pos        12U        //bit for pwm to sync to last stage's adc trig time
#define CCU_CONF_SYNC_ADC_EN_Msk        (1U<<CCU_CONF_SYNC_ADC_EN_Pos)
#define CCU_CONF_SYNC_PWM_EN_Pos        11U        //bit for pwm to sync to last stage's pwm 
#define CCU_CONF_SYNC_PWM_EN_Msk        (1U<<CCU_CONF_SYNC_PWM_EN_Pos)
#define CCU_CONF_IRQ_FREQ_Pos           8U        //bits for pwm flag/irq frequency, every pwm cycle, every 2 pwm cycles, 4,8,32,64,128 and 256 cycles
#define CCU_CONF_IRQ_FREQ_Msk           (7U<<CCU_CONF_IRQ_FREQ_Pos)
#define CCU_CONF_IPOL_Pos               7U        //used in complementary mode, 
#define CCU_CONF_IPOL_Msk               (1U<<CCU_CONF_IPOL_Pos)
#define CCU_CONF_ICC0_Pos               6U        //used in complementary mode, apply to center mode only
#define CCU_CONF_ICC0_Msk               (1U<<CCU_CONF_ICC0_Pos)
#define CCU_CONF_PWM1_VAL_Pos           5U        //start value of PWM1
#define CCU_CONF_PWM1_VAL_Msk           (1U<<CCU_CONF_PWM1_VAL_Pos)
#define CCU_CONF_PWM0_VAL_Pos           4U        //start value of PWM0
#define CCU_CONF_PWM0_VAL_Msk           (1U<<CCU_CONF_PWM0_VAL_Pos)
#define CCU_CONF_PWM1_NEG_Pos           3U        //pwm1 output negate 
#define CCU_CONF_PWM1_NEG_Msk           (1U<<CCU_CONF_PWM1_NEG_Pos)
#define CCU_CONF_PWM0_NEG_Pos           2U        //pwm1 output negate 
#define CCU_CONF_PWM0_NEG_Msk           (1U<<CCU_CONF_PWM0_NEG_Pos)
#define CCU_CONF_PWM_COMP_Pos           1U        //pwm complimentary enable bit 
#define CCU_CONF_PWM_COMP_Msk           (1U<<CCU_CONF_PWM_COMP_Pos)
#define CCU_CONF_PWM_ALIGNC_Pos         0U        //pwm center alignment enable bit 
#define CCU_CONF_PWM_ALIGNC_Msk         (1U<<CCU_CONF_PWM_ALIGNC_Pos)

/*****deadtime bits*****/
#define CCU_DT1_Pos                8U        //deadtime start bit for pwm1,3,5, [15:8]
#define CCU_DT1_Msk                (255U<<CCU_DT1_Pos)
#define CCU_DT0_Pos                0U        //deadtime start bit for pwm0,2,4, [7:0]
#define CCU_DT0_Msk                (255U<<CCU_DT0_Pos)

/*****mx control bits*****/
#define MX_CTRL_PWM_REF_Pos        4U        //bit for PWM resolution (PWM period count based on pwm base clock)
#define MX_CTRL_PWM_REF_Msk        (2U<<MX_CTRL_PWM_REF_Pos)
#define MX_CTRL_OUTPUT_Pos         3U        //bit for MX pin output value when PWM is not output on that pin, output high when 1 is used, output low when 0 is ussed
#define MX_CTRL_OUTPUT_Msk         (1U<<MX_CTRL_OUTPUT_Pos)
#define MX_CTRL_PWM_CLK_Pos        2U        //bit for pwm clk selection, 1 for using system clk, 0 for using PLL clock
#define MX_CTRL_PWM_CLK_Msk        (1U<<MX_CTRL_PWM_CLK_Pos)
#define MX_CTRL_PWM2PAD_EN_Pos     1U        //bit to turn on pwm to output to pad 
#define MX_CTRL_PWM2PAD_EN_Msk     (1U<<MX_CTRL_PWM2PAD_EN_Pos)
#define MX_CTRL_PWM_EN_Pos         0U        //bit to turn on PWM 
#define MX_CTRL_PWM_EN_Msk         (1U<<MX_CTRL_PWM_EN_Pos)

/*********** MX ************************/
#define RT_CCUMX_PWM_Start()	                     MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(MCU_CCUMX_BASE+MCU_CCUMX_CTRL_Pos), \
                                                                MX_CTRL_PWM_EN_Msk, MX_CTRL_PWM_EN_Pos, 1)
#define RT_CCUMX_PWM_Stop()	                     MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(MCU_CCUMX_BASE+MCU_CCUMX_CTRL_Pos), \
                                                                MX_CTRL_PWM_EN_Msk, MX_CTRL_PWM_EN_Pos, 0)
#define RT_CCUMX_PWM_OutPAD(state)                 MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(MCU_CCUMX_BASE+MCU_CCUMX_CTRL_Pos), \
                                                                MX_CTRL_PWM2PAD_EN_Msk, MX_CTRL_PWM2PAD_EN_Pos, state)
#define RT_CCUMX_PWM_SetBaseCLK(p)                 MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(MCU_CCUMX_BASE+MCU_CCUMX_CTRL_Pos), \
                                                                MX_CTRL_CLK_Msk, MX_CTRL_CLK_Pos, p)
#define RT_CCUMX_PWM_SetOutput(v)                  MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(MCU_CCUMX_BASE+MCU_CCUMX_CTRL_Pos), \
                                                                MX_CTRL_OUTPUT_Msk, MX_CTRL_OUTPUT_Pos, v)                                                                
#define RT_CCUMX_PWM_SetPeriod(d)                  MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(MCU_CCUMX_BASE+MCU_CCUMX_CTRL_Pos), \
                                                                MX_CTRL_PWM_REF_Msk, MX_CTRL_PWM_REF_Pos, d)
#define RT_CCUMX_PWM_GetPeriod()                   MCU_REG_READ(*(MCU_CCU_CTRL_TypeDef *)(MCU_CCUMX_BASE+MCU_CCUMX_CTRL_Pos), \
                                                                MX_CTRL_PWM_REF_Msk, MX_CTRL_PWM_REF_Pos)
#define RT_CCUMX_PWM_SetDUTY(d)                    (*(MCU_CCU_DUTY_TypeDef *)(MCU_CCUMX_BASE+MCU_CCUMX_DUTY_Pos))=d
#define RT_CCUMX_PWM_ClrIRQ()                      (*(MCU_CLRREG_TypeDef*)(MCU_CCUMX_BASE+MCU_CCUMX_CLRIRQ_Pos)) = 0
#define RT_CCUMX_SetCLKDiv(divider)                (*(MCU_CCU_CLKDIV_TypeDef *)(MCU_CCUMX_BASE+MCU_CCUMX_CLKDIV_Pos))=divider

/*********** end of MX *****************/

/***** Timer clr stop and flag Setup******/
#define RT_CCU_Start(ccu)		        MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(ccu+MCU_CCU_CTRL_Pos), \
                                                                CCU_CTRL_TIMER_EN_Msk, CCU_CTRL_TIMER_EN_Pos, 1)
#define RT_CCU_Stop(ccu)		        MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(ccu+MCU_CCU_CTRL_Pos), \
                                                                CCU_CTRL_TIMER_EN_Msk, CCU_CTRL_TIMER_EN_Pos, 0)
#define RT_CCU_Clr(ccu)		        {*(MCU_CLRREG_TypeDef *)(ccu + MCU_CCU_CLRIRQ_Pos) = 0;  \
                                                 *(MCU_CLRREG_TypeDef *)(ccu + MCU_CCU_REF_Pos) = 0; }
#define RT_CCU_SetIRQ(ccu, state)	        MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(ccu+MCU_CCU_CTRL_Pos), \
                                                                CCU_CTRL_IRQ_EN_Msk, CCU_CTRL_IRQ_EN_Pos, state)
#define RT_CCU_GetIRQ(ccu)                      MCU_REG_READ(*(MCU_CCU_CTRL_TypeDef *)(ccu+MCU_CCU_CTRL_Pos), \
                                                                CCU_CTRL_IRQ_Msk, CCU_CTRL_IRQ_Pos)
#define RT_CCU_SetCLKDiv(ccu, divider)          MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(ccu+MCU_CCU_CTRL_Pos), \
                                                                CCU_CTRL_CLKDIV_Msk, CCU_CTRL_CLKDIV_Pos, divider)

/*********** CCU PWM Setup*************/
//********************************************************//
// void RT_CCU_PWM(ccu, div, ref, irq)                    //
//                                                        //
// Description:                                           //
// This function set the PWM function of tc0              //
// div: the clock freq divider                            //
// ref: 255-0, the clock high length                      //
// irq: when 1, the interrupt is enabled; when 0, disabled// 
//********************************************************//
/***** PWM start, stop and irq Setup*****/

#define RT_CCU_PWM_Start(ccu)	                        MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(ccu+MCU_CCU_CTRL_Pos), \
                                                                CCU_CTRL_PWM_EN_Msk, CCU_CTRL_PWM_EN_Pos, 1); \
                                                      MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(ccu+MCU_CCU_CTRL_Pos), \
                                                                CCU_CTRL_PWM_MIX_Msk, CCU_CTRL_PWM_MIX_Pos, 3);  \
                                                      RT_CCUMX_PWM_SetOutput(1)
#define RT_CCU_PWM_Stop(ccu)	                        MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(ccu+MCU_CCU_CTRL_Pos), \
                                                                CCU_CTRL_PWM_EN_Msk, CCU_CTRL_PWM_EN_Pos, 0)
#define RT_CCU_PWM_SetIRQ(ccu, state)                 MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(ccu+MCU_CCU_CTRL_Pos), \
                                                                CCU_CTRL_PWM_IRQ_EN_Msk, CCU_CTRL_PWM_IRQ_EN_Pos, state)
#define RT_CCU_PWM_ClrIRQ(ccu)                        *(MCU_CLRREG_TypeDef*)(ccu+MCU_CCU_CLRIRQ_Pos) = 0
#define RT_CCU_PWM_GetIRQ(ccu)                        MCU_REG_READ(*(MCU_CCU_CTRL_TypeDef *)(ccu+MCU_CCU_CTRL_Pos), \
                                                                CCU_CTRL_PWM_IRQ_Msk, CCU_CTRL_PWM_IRQ_Pos)
#define RT_CCU_PWM_OutPAD(ccu, state)                 MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(ccu+MCU_CCU_CTRL_Pos), \
                                                                CCU_CTRL_PWM2PAD_EN_Msk, CCU_CTRL_PWM2PAD_EN_Pos, state)
#define RT_CCU_PWM_SetPeriod(ccu, d)                  (*(MCU_CCU_REF_TypeDef *)(ccu + MCU_CCU_REF_Pos))=d
#define RT_CCU_PWM_GetPeriod(ccu)                     (*(MCU_CCU_REF_TypeDef *)(ccu + MCU_CCU_REF_Pos))
#define RT_CCU_PWM_SetDUTY0(ccu, d)                   (*(MCU_CCU_DUTY_TypeDef *)(ccu + MCU_CCU_DUTY0_Pos))=d
#define RT_CCU_PWM_SetDUTY1(ccu, d)                   (*(MCU_CCU_DUTY_TypeDef *)(ccu + MCU_CCU_DUTY1_Pos))=d
#define RT_CCU_PWM_SetDT(ccu, dt0, dt1)               (*(MCU_CCU_DT_TypeDef *)(ccu + MCU_CCU_DT_Pos)) = ((dt0<<CCU_DT0_Pos)|(dt1<<CCU_DT1_Pos))
#define RT_CCU_PWM_SetBaseCLK(ccu, p)                 MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef *)(ccu+MCU_CCU_CTRL_Pos), \
                                                                CCU_CTRL_CLKDIV_Msk, CCU_CTRL_CLKDIV_Pos, p)
//above base clk period range from 0 t0 255
#define RT_CCU_PWM_CFG_Clr(ccu)                       (*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos))=0
#define RT_CCU_PWM_CFG_TrigADC(ccu,s)                 MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_TRIG_ADC_EN_Msk, CCU_CONF_TRIG_ADC_EN_Pos, s)
#define RT_CCU_PWM_CFG_SwitchPAIR(ccu, s)             MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_PWM_OSW_Msk, CCU_CONF_PWM_OSW_Pos, s)
#define RT_CCU_PWM_CFG_SyncADC(ccu, s)                MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_SYNC_ADC_EN_Msk, CCU_CONF_SYNC_ADC_EN_Pos, s)
#define RT_CCU_PWM_CFG_SyncPWM(ccu, s)                MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_SYNC_PWM_EN_Msk, CCU_CONF_SYNC_PWM_EN_Pos, s)
#define RT_CCU_PWM_CFG_SetIRQ1CYC(ccu)                MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_IRQ_FREQ_Msk, CCU_CONF_IRQ_FREQ_Pos, 0)
#define RT_CCU_PWM_CFG_SetIRQ2CYC(ccu)                MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_IRQ_FREQ_Msk, CCU_CONF_IRQ_FREQ_Pos, 1)
#define RT_CCU_PWM_CFG_SetIRQ4CYC(ccu)                MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_IRQ_FREQ_Msk, CCU_CONF_IRQ_FREQ_Pos, 2)
#define RT_CCU_PWM_CFG_SetIRQ8CYC(ccu)                MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_IRQ_FREQ_Msk, CCU_CONF_IRQ_FREQ_Pos, 3)
#define RT_CCU_PWM_CFG_SetIRQ32CYC(ccu)               MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_IRQ_FREQ_Msk, CCU_CONF_IRQ_FREQ_Pos, 4)
#define RT_CCU_PWM_CFG_SetIRQ64CYC(ccu)               MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_IRQ_FREQ_Msk, CCU_CONF_IRQ_FREQ_Pos, 5)
#define RT_CCU_PWM_CFG_SetIRQ128CYC(ccu)              MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_IRQ_FREQ_Msk, CCU_CONF_IRQ_FREQ_Pos, 6)
#define RT_CCU_PWM_CFG_SetIRQ256CYC(ccu)              MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_IRQ_FREQ_Msk, CCU_CONF_IRQ_FREQ_Pos, 7)
#define RT_CCU_PWM_CFG_PWM1_SetVAL(ccu, s)            MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_PWM1_VAL_Msk, CCU_CONF_PWM1_VAL_Pos, s)
#define RT_CCU_PWM_CFG_PWM0_SetVAL(ccu, s)            MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_PWM0_VAL_Msk, CCU_CONF_PWM0_VAL_Pos, s)
#define RT_CCU_PWM_CFG_PWM1_SetNEG(ccu, s)            MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_PWM1_NEG_Msk, CCU_CONF_PWM1_NEG_Pos, s)
#define RT_CCU_PWM_CFG_PWM0_SetNEG(ccu, s)            MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_PWM0_NEG_Msk, CCU_CONF_PWM0_NEG_Pos, s)
#define RT_CCU_PWM_CFG_SetCOMP(ccu, s)                MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_PWM_COMP_Msk, CCU_CONF_PWM_COMP_Pos, s)
#define RT_CCU_PWM_CFG_AlignC(ccu, s)                 MCU_REG_WRITE(*(MCU_CCU_CONF_TypeDef *)(ccu + MCU_CCU_CONF_Pos), \
                                                                CCU_CONF_PWM_ALIGNC_Msk, CCU_CONF_PWM_ALIGNC_Pos, s)
#define RT_CCU_PWM_CFG_SetTrigDelay(ccu, s)           (*(MCU_CCU_TRIG_TypeDef *)(ccu + MCU_CCU_TRIG_Pos)) = (s&0x7FFF)
#define RT_CCU_PWM_CFG_SetTrigUpDelay(ccu, s)         (*(MCU_CCU_TRIG_TypeDef *)(ccu + MCU_CCU_TRIG_Pos)) = (s&0x7FFF)
#define RT_CCU_PWM_CFG_SetTrigDownDelay(ccu, s)       (*(MCU_CCU_TRIG_TypeDef *)(ccu + MCU_CCU_TRIG_Pos)) = ((s&0x7FFF)|0x8000)
#define RT_CCU_PWM_Init(ccu, div, period, duty0, duty1, dt0, dt1, irq, out)  \
                                                        {RT_CCU_PWM_SetBaseCLK(ccu, div);	\
                                                        RT_CCU_PWM_SetPeriod(ccu, period);   \
                                                        RT_CCU_PWM_SetDUTY0(ccu, duty0);     \
                                                        RT_CCU_PWM_SetDUTY1(ccu, duty1);     \
                                                        RT_CCU_PWM_SetIRQ(ccu, irq);        \
                                                        RT_CCU_PWM_OutPAD(ccu, out);        \
                                                        RT_CCU_PWM_SetDT(ccu, dt0, dt1);    \
                                                        RT_CCU_PWM_Start(ccu);}
/*********** CCU PWM End***************/

/*********** CCU timer Setup*************/
//********************************************************//
// void RT_CCU_TIMER_Init(ccu, n, irq)                    //
// Description:                                           //
// This function set the cnt function of CCU              //
// "n" is times of clock tickle for timer to cou          //
// When "irq" = 1, enable the event count interrupt       // 
//********************************************************//

#define RT_CCU_SetTimer(ccu, n, irq)	{RT_CCU_SetCLKDiv(ccu, n);	\
                                         RT_CCU_SetIRQ(ccu, irq);	\
                                         MCU_REG_WRITE(MCU_CTRL, CTRL_IRQ_EN_Msk, CTRL_IRQ_EN_Pos, irq); \
                                         RT_CCU_Start();}
                                         
/*********** CCU timer End***************/

/*********** CCU ECNT Setup*************/
//********************************************************//
// void RT_CCU_ECNT_Init(ccu, n, pos, irq)                //
// Description:                                           //
// This function set the ecm function of CCU              //
// "n" is count value, "pos" is set to count when posedge //
// When "irq" = 1, enable the event count interrupt       // 
//********************************************************//

#define RT_CCU_ECNT_Init(ccu, n, pos, irq)	{*(MCU_CCU_REF_TypeDef *)(ccu+MCU_CCU_REF_Pos) = n;	\
                                                   MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef*)(ccu+MCU_CCU_CTRL_Pos), \
                                                   CCU_CTRL_IRQ_EN_Msk, CCU_CTRL_IRQ_EN_Pos, irq); \
                                                   MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef*)(ccu+MCU_CCU_CTRL_Pos), \
                                                   CCU_CTRL_EDGESEL_Msk, CCU_CTRL_EDGESEL_Pos, pos); \
                                                   MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef*)(ccu+MCU_CCU_CTRL_Pos), \
                                                   CCU_CTRL_ECNT_EN_Msk, CCU_CTRL_ECNT_EN_Pos, 1); \
                                                   MCU_REG_WRITE(MCU_CTRL, CTRL_IRQ_EN_Msk, CTRL_IRQ_EN_Pos, irq); }
/*********** CCU ECNT End***************/

/*********** CCU PWMM Setup*************/
//********************************************************//
// void RT_CCU_PWMM_Init(ccu, rise, irq)                  //
//                                                        //
// Description:                                           //
// This function set the Pulse width measure for CCU      //
//                                                        //
// rise: 1:= positive pulse  0:= negative pulse           //
// irq: when 1, the interrupt is enabled; when 0, disabled// 
//********************************************************//

#define RT_CCU_PWMM_Init(ccu, rise, irq)	{MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef*)(ccu+MCU_CCU_CTRL_Pos), \
                                                   CCU_CTRL_IRQ_EN_Msk, CCU_CTRL_IRQ_EN_Pos, irq); \
                                                   MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef*)(ccu+MCU_CCU_CTRL_Pos), \
                                                   CCU_CTRL_EDGESEL_Msk, CCU_CTRL_EDGESEL_Pos, rise); \
                                                   MCU_REG_WRITE(*(MCU_CCU_CTRL_TypeDef*)(ccu+MCU_CCU_CTRL_Pos), \
                                                   CCU_CTRL_PWMM_EN_Msk, CCU_CTRL_PWMM_EN_Pos, 1); \
                                                   MCU_REG_WRITE(MCU_CTRL, CTRL_IRQ_EN_Msk, CTRL_IRQ_EN_Pos, irq); }

#define RT_CCU_ReadCnt(ccu) 	                     (*(MCU_CCU_REF_TypeDef *)(ccu + MCU_CCU_REF_Pos))
/*********** CCU PWMM End***************/


#endif








































