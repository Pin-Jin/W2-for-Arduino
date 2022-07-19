/*--------------------------------------------------------------------
 * TITLE: timer Defines
 * AUTHOR: Weize 
 * DATE CREATED: 2020/1/25
 * FILENAME: TIMER.h
 * PROJECT: w2
 * COPYRIGHT: Camel Microelectronics, Inc.
 * DESCRIPTION:
 *    w2 Hardware Defines
 *
 *    2020-01-25: initial
 *--------------------------------------------------------------------*/
#ifndef __TIMER_H__
#define __TIMER_H__

#define TIMER_CTRL_IRQ_Pos           31U        //bit for timer irq flag
#define TIMER_CTRL_IRQ_Msk           (1U<<TIMER_CTRL_IRQ_Pos)
#define TIMER_CTRL_PWM_IRQ_Pos       30U        //bit for PWM irq flag
#define TIMER_CTRL_PWM_IRQ_Msk       (1U<<TIMER_CTRL_PWM_IRQ_Pos)
#define TIMER_CTRL_PWMVAL_Pos        10U        //bit for PWM val
#define TIMER_CTRL_PWMVAL_Msk        (1U<<TIMER_CTRL_PWMVAL_Pos)
#define TIMER_CTRL_PWM_CLK_Pos       9U        //bit for PWM base clock, 1 use PLL for PWM clk base, 0 use timer clock for PWM clock base
#define TIMER_CTRL_PWM_CLK_Msk       (1U<<TIMER_CTRL_PWM_CLK_Pos)
#define TIMER_CTRL_CLK_Pos           8U        //bit for timer clock, 1 use 40kHz as base to generate TIMER clock
#define TIMER_CTRL_CLK_Msk           (1U<<TIMER_CTRL_CLK_Pos)
#define TIMER_CTRL_IRQ_EN_Pos        7U        //bit for enable Timer irq
#define TIMER_CTRL_IRQ_EN_Msk        (1U<<TIMER_CTRL_IRQ_EN_Pos)
#define TIMER_CTRL_PWM_IRQ_EN_Pos    6U        //bit for pwm irq enable
#define TIMER_CTRL_PWM_IRQ_EN_Msk    (1U<<TIMER_CTRL_PWM_IRQ_EN_Pos)
#define TIMER_CTRL_CMP_EN_Pos        5U        //bit to turn on output comparison 
#define TIMER_CTRL_CMP_EN_Msk        (1U<<TIMER_CTRL_CMP_EN_Pos)
#define TIMER_CTRL_PWM_EN_Pos        4U        //bit to turn on PWM 
#define TIMER_CTRL_PWM_EN_Msk        (1U<<TIMER_CTRL_PWM_EN_Pos)
#define TIMER_CTRL_PWMM_EN_Pos       3U        //bit to turn on PWMM mode
#define TIMER_CTRL_PWMM_EN_Msk       (1U<<TIMER_CTRL_PWMM_EN_Pos)
#define TIMER_CTRL_EDGESEL_Pos       2U        //PWMM and ECNT measurement starting edge select, 1 for rising edge
#define TIMER_CTRL_EDGESEL_Msk       (1U<<TIMER_CTRL_EDGESEL_Pos)
#define TIMER_CTRL_TIMER_EN_Pos      1U        //bit to turn on timer mode
#define TIMER_CTRL_TIMER_EN_Msk      (1U<<TIMER_CTRL_TIMER_EN_Pos) 
#define TIMER_CTRL_ECNT_EN_Pos       0U        //bit to turn on ECNT mode
#define TIMER_CTRL_ECNT_EN_Msk       (1U<<TIMER_CTRL_ECNT_EN_Pos)   

#define TIMER_CLKBASE_SYS      0           // use system clock as base to generate Timer clock
#define TIMER_CLKBASE_40KHZ    1           // use 40kHz generated from crystal as base to generate Timer clock
#define TIMER_PWMCLKBASE_TIMER    0           // use Timer clk as base to generate PWM clk
#define TIMER_PWMCLKBASE_PLL   1           // use PLL clk as base to generate PWM clk


/***** Timer clr stop and flag Setup******/
#define RT_TIMER_Stop(timer)		        MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef *)(timer+MCU_TIMER_CTRL_Pos), \
                                                                TIMER_CTRL_TIMER_EN_Msk, TIMER_CTRL_TIMER_EN_Pos, 0)
#define RT_TIMER_Clr(timer)		        {*(MCU_CLRREG_TypeDef *)(timer + MCU_TIMER_CLRIRQ_Pos) = 0;  \
                                                 *(MCU_CLRREG_TypeDef *)(timer + MCU_TIMER_CLRCNT_Pos) = 0; }
#define RT_TIMER_SetIRQ(timer, state)	        MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef *)(timer+MCU_TIMER_CTRL_Pos), \
                                                                TIMER_CTRL_IRQ_EN_Msk, TIMER_CTRL_IRQ_EN_Pos, state)
#define RT_TIMER_GetIRQ(timer)                  MCU_REG_READ(*(MCU_TIMER_CTRL_TypeDef *)(timer+MCU_TIMER_CTRL_Pos), \
                                                                TIMER_CTRL_IRQ_Msk, TIMER_CTRL_IRQ_Pos)
#define RT_TIMER_SetCLKBase(timer, state)       MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef *)(timer+MCU_TIMER_CTRL_Pos), \
                                                                TIMER_CTRL_CLK_Msk, TIMER_CTRL_CLK_Pos, state)
#define RT_TIMER_PWM_SetCLKBase(timer, state)   MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef *)(timer+MCU_TIMER_CTRL_Pos), \
                                                                TIMER_CTRL_PWM_CLK_Msk, TIMER_CTRL_PWM_CLK_Pos, state)

/***** PWM start, stop and irq Setup*****/
#define RT_TIMER_PWM_Start(timer)	        MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef *)(timer+MCU_TIMER_CTRL_Pos), \
                                                                TIMER_CTRL_PWM_EN_Msk, TIMER_CTRL_PWM_EN_Pos, 1)
#define RT_TIMER_PWM_Stop(timer)	        MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef *)(timer+MCU_TIMER_CTRL_Pos), \
                                                                TIMER_CTRL_PWM_EN_Msk, TIMER_CTRL_PWM_EN_Pos, 0)
#define RT_TIMER_PWM_SetIRQ(timer, state)       MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef *)(timer+MCU_TIMER_CTRL_Pos), \
                                                                TIMER_CTRL_PWM_IRQ_EN_Msk, TIMER_CTRL_PWM_IRQ_EN_Pos, state)
#define RT_TIMER_PWM_Clr(timer)                 *(MCU_CLRREG_TypeDef*)(timer+MCU_TIMER_CLRPWM_Pos) = 0
#define RT_TIMER_PWM_GetIRQ(timer) 	        MCU_REG_READ(*(MCU_TIMER_CTRL_TypeDef *)(timer+MCU_TIMER_CTRL_Pos), \
                                                                TIMER_CTRL_PWM_IRQ_Msk, TIMER_CTRL_PWM_IRQ_Pos)

/****************** end*******************/

/*********** Timer cnt Setup*************/
//********************************************************//
// void RT_TIMER_Set1u(timer, n, irq)                     //
// Description:                                           //
// This function set the cnt function of tc1              //
// "n" is times of 1us for timer to count                 //
// When "irq" = 1, enable the event count interrupt       // 
//********************************************************//

#define RT_TIMER_Set1u(timer, n, irq)	{*(MCU_TIMER_CLK_TypeDef *)(timer+MCU_TIMER_CLK_Pos) = RT_SYS_Get_CLK_Freq()-1;	\
                                         *(MCU_TIMER_REF_TypeDef *)(timer+MCU_TIMER_REF_Pos) = n;	\
                                         MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef*)(timer+MCU_TIMER_CTRL_Pos), \
                                         TIMER_CTRL_IRQ_EN_Msk, TIMER_CTRL_IRQ_EN_Pos, irq); \
                                         MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef*)(timer+MCU_TIMER_CTRL_Pos), \
                                         TIMER_CTRL_TIMER_EN_Msk, TIMER_CTRL_TIMER_EN_Pos, 1); \
                                         MCU_REG_WRITE(MCU_CTRL, CTRL_IRQ_EN_Msk, CTRL_IRQ_EN_Pos, irq); }

//********************************************************//
// void RT_TIMER_Set100u(timer, n, irq)                   //
// Description:                                           //
// This function set the cnt function of tc1              //
// "n" is times of 100us for timer to count               //
// When "irq" = 1, enable the event count interrupt       // 
//********************************************************//

#define RT_TIMER_Set100u(timer, n, irq)	{*(MCU_TIMER_CLK_TypeDef *)(timer+MCU_TIMER_CLK_Pos) = 100*(RT_SYS_Get_CLK_Freq()-1);	\
                                         *(MCU_TIMER_REF_TypeDef *)(timer+MCU_TIMER_REF_Pos) = n;	\
                                         MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef*)(timer+MCU_TIMER_CTRL_Pos), \
                                         TIMER_CTRL_IRQ_EN_Msk, TIMER_CTRL_IRQ_EN_Pos, irq); \
                                         MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef*)(timer+MCU_TIMER_CTRL_Pos), \
                                         TIMER_CTRL_TIMER_EN_Msk, TIMER_CTRL_TIMER_EN_Pos, 1); \
                                         MCU_REG_WRITE(MCU_CTRL, CTRL_IRQ_EN_Msk, CTRL_IRQ_EN_Pos, irq); }
/*********** Timer cnt End***************/

/*********** Timer PWM Setup*************/
//********************************************************//
// void RT_TIMER_PWM_Init(timer, div, ref, irq)           //
//                                                        //
// Description:                                           //
// This function set the PWM function of tc0              //
// div: the clock freq divider                            //
// ref: 255-0, the clock high length                      //
// irq: when 1, the interrupt is enabled; when 0, disabled// 
//********************************************************//

#define RT_TIMER_PWM_Init(timer, div, ref, irq)        {*(MCU_TIMER_CLK_TypeDef *)(timer+MCU_TIMER_CLK_Pos) = div;	\
                                                   *(MCU_TIMER_REF_TypeDef *)(timer+MCU_TIMER_REF_Pos) = ref;	\
                                                   MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef*)(timer+MCU_TIMER_CTRL_Pos), \
                                                   TIMER_CTRL_IRQ_EN_Msk, TIMER_CTRL_IRQ_EN_Pos, irq); \
                                                   MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef*)(timer+MCU_TIMER_CTRL_Pos), \
                                                   TIMER_CTRL_PWM_EN_Msk, TIMER_CTRL_PWM_EN_Pos, 1); \
                                                   MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef*)(timer+MCU_TIMER_CTRL_Pos), \
                                                   TIMER_CTRL_PWM_IRQ_EN_Msk, TIMER_CTRL_PWM_IRQ_EN_Pos, irq); \
                                                   MCU_REG_WRITE(MCU_CTRL, CTRL_IRQ_EN_Msk, CTRL_IRQ_EN_Pos, irq); }

/*********** Timer PWM End***************/

/*********** Timer ECM Setup*************/
//********************************************************//
// void RT_TIMER_ECNT_Init(timer, n, pos, irq             //
// Description:                                           //
// This function set the ecm function of tc1              //
// "n" is count value, "pos" is set to count when posedge //
// When "irq" = 1, enable the event count interrupt       // 
//********************************************************//

#define RT_TIMER_ECNT_Init(timer, n, pos, irq)	{*(MCU_TIMER_REF_TypeDef *)(timer+MCU_TIMER_REF_Pos) = n;	\
                                                   MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef*)(timer+MCU_TIMER_CTRL_Pos), \
                                                   TIMER_CTRL_IRQ_EN_Msk, TIMER_CTRL_IRQ_EN_Pos, irq); \
                                                   MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef*)(timer+MCU_TIMER_CTRL_Pos), \
                                                   TIMER_CTRL_EDGESEL_Msk, TIMER_CTRL_EDGESEL_Pos, pos); \
                                                   MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef*)(timer+MCU_TIMER_CTRL_Pos), \
                                                   TIMER_CTRL_ECNT_EN_Msk, TIMER_CTRL_ECNT_EN_Pos, 1); \
                                                   MCU_REG_WRITE(MCU_CTRL, CTRL_IRQ_EN_Msk, CTRL_IRQ_EN_Pos, irq); }

/*********** Timer ECM End***************/

/*********** Timer PWMM Setup*************/
//********************************************************//
// void RT_TIMER_PWMM_Init(timer, rise, irq)              //
//                                                        //
// Description:                                           //
// This function set the Pulse width measure for T0       //
//                                                        //
// rise: 1:= positive pulse  0:= negative pulse           //
// irq: when 1, the interrupt is enabled; when 0, disabled// 
//********************************************************//

#define RT_TIMER_PWMM_Init(timer, rise, irq)	{MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef*)(timer+MCU_TIMER_CTRL_Pos), \
                                                   TIMER_CTRL_IRQ_EN_Msk, TIMER_CTRL_IRQ_EN_Pos, irq); \
                                                   MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef*)(timer+MCU_TIMER_CTRL_Pos), \
                                                   TIMER_CTRL_EDGESEL_Msk, TIMER_CTRL_EDGESEL_Pos, rise); \
                                                   MCU_REG_WRITE(*(MCU_TIMER_CTRL_TypeDef*)(timer+MCU_TIMER_CTRL_Pos), \
                                                   TIMER_CTRL_PWMM_EN_Msk, TIMER_CTRL_PWMM_EN_Pos, 1); \
                                                   MCU_REG_WRITE(MCU_CTRL, CTRL_IRQ_EN_Msk, CTRL_IRQ_EN_Pos, irq); }

#define RT_TIMER_ReadCnt(timer) 	          (*(MCU_TIMER_VAL_TypeDef *)(timer + MCU_TIMER_VAL_Pos))

/*********** Timer PWMM End***************/

#endif  //__TIMER_H__
















