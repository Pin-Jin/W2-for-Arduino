/*--------------------------------------------------------------------
 * TITLE: Analog Defines
 * AUTHOR: Weize 
 * DATE CREATED: 2020/1/25
 * FILENAME: AFE.h
 * PROJECT: w2
 * COPYRIGHT: Camel Microelectronics, Inc.
 * DESCRIPTION:
 *    w2 Hardware Defines
 *
 *    2020-01-25: initial for adc, opo, CMP, D+-
 *--------------------------------------------------------------------*/
#ifndef __AFE_H__
#define __AFE_H__

// this is AFE/ADC
#define A_OPO_CMP_REG       0x1f800600  // OPO and CMP control (16-bit)
#define A_SAR_CTL_REG       0x1f800601  // SAR control reg
#define A_SAR_READ_REG      0x1f800602  // SAR Read reg
#define A_CLR_REG           0x1f800603  // write to clear SAR result
#define A_SAR_CS_REG        0x1f800604  // write to start SAR conversion

/******AFE control bits */
#define AFE_CTRL_CMP_VAL_Pos         13U        //bits for comparator results
#define AFE_CTRL_CMP_VAL_Msk         (7U<<AFE_CTRL_CMP_VAL_Pos)
#define AFE_CTRL_CMP_CLK_Pos         12U        //bits for comparator sample clock selection
#define AFE_CTRL_CMP_CLK_Msk         (3U<<AFE_CTRL_CMP_CLK_Pos)
#define AFE_CTRL_CMP_EN_Pos          4U        //bits for comparator enable
#define AFE_CTRL_CMP_EN_Msk          (7U<<AFE_CTRL_CMP_EN_Pos)
#define AFE_CTRL_OPO_EN_Pos          0U        //bits for OPO enable
#define AFE_CTRL_OPO_EN_Msk          (7U<<AFE_CTRL_OPO_EN_Pos)

/******ADC control bits */
#define ADC_CTRL_CLK_Pos             12U        //bits for sar adc clock 
#define ADC_CTRL_CLK_Msk             (3U<<ADC_CTRL_CLK_Pos)
#define ADC_CTRL_CH_Pos              4U         //bits for ADC channel selection
#define ADC_CTRL_CH_Msk              (7U<<ADC_CTRL_CH_Pos)
#define ADC_CTRL_PWM_TRIG_Pos        1U        //bit for ADC triggered by PWM
#define ADC_CTRL_PWM_TRIG_Msk        (1U<<ADC_CTRL_PWM_TRIG_Pos)
#define ADC_CTRL_OTC_Pos             1U        //bit for ADC one time converstion mode
#define ADC_CTRL_OTC_Msk             (1U<<ADC_CTRL_OTC_Pos)
#define ADC_CTRL_IRQ_EN_Pos          1U        //bit for ADC irq enable
#define ADC_CTRL_IRQ_EN_Msk          (1U<<ADC_CTRL_IRQ_EN_Pos)
#define ADC_CTRL_EN_Pos              1U        //bit to enable ADC
#define ADC_CTRL_EN_Msk              (1U<<ADC_CTRL_EN_Pos)

#define ADC_READ_Pos                 0U
#define ADC_READ_Msk                 (0x7FFF<<ADC_READ_Pos)
#define ADC_READ_READY_Pos           15U        //bit for ADC_READ ready
#define ADC_READ_READY_Msk           (1U<<ADC_READ_READY_Pos)

/***** OPO setup******/
//select the channels to be used, 1 for use, 0 for not use
#define RT_OPO_SetCh(ch0, ch1, ch2, ch3)            MCU_REG_WRITE(MCU_AFE_CTRL, AFE_CTRL_OPO_EN_Msk, AFE_CTRL_OPO_EN_Pos, \
                                                            (ch0+(ch1<<1)+(ch2<<2)+(ch3<<3)))                                                            
#define RT_OPO_ConnADC(ch0, ch1, ch2, ch3)          MCU_REG_WRITE(MCU_AUX_CTRL, AUX_OPO2ADC_Msk, AUX_OPO2ADC_Pos, \
                                                            (ch0+(ch1<<1)+(ch2<<2)+(ch3<<3)))
                                                            //connect opo0/1/2/3 to adc4/5/6/7

/****D+- setup****/
#define RT_DP_3V_On()                               MCU_REG_WRITE(MCU_AUX_CTRL, AUX_DP2AOUT_Msk, AUX_DP2AOUT_Pos, (1<<2))
#define RT_DP_P6V_On()                              MCU_REG_WRITE(MCU_AUX_CTRL, AUX_DP2AOUT_Msk, AUX_DP2AOUT_Pos, (1<<1))
#define RT_DP_0V_On()                               MCU_REG_WRITE(MCU_AUX_CTRL, AUX_DP2AOUT_Msk, AUX_DP2AOUT_Pos, 1)
#define RT_DP_Off()                                 MCU_REG_WRITE(MCU_AUX_CTRL, AUX_DP2AOUT_Msk, AUX_DP2AOUT_Pos, 0)
#define RT_DP_ADC7_On()                             MCU_REG_WRITE(MCU_AUX_CTRL, AUX_DP2ADC7_Msk, AUX_DP2ADC7_Pos, 1)
#define RT_DP_ADC7_Off()                            MCU_REG_WRITE(MCU_AUX_CTRL, AUX_DP2ADC7_Msk, AUX_DP2ADC7_Pos, 0)
#define RT_DM_3V_On()                               MCU_REG_WRITE(MCU_AUX_CTRL, AUX_DM2AOUT_Msk, AUX_DM2AOUT_Pos, (1<<2))
#define RT_DM_P6V_On()                              MCU_REG_WRITE(MCU_AUX_CTRL, AUX_DM2AOUT_Msk, AUX_DM2AOUT_Pos, (1<<1))
#define RT_DM_0V_On()                               MCU_REG_WRITE(MCU_AUX_CTRL, AUX_DM2AOUT_Msk, AUX_DM2AOUT_Pos, 1)
#define RT_DM_Off()                                 MCU_REG_WRITE(MCU_AUX_CTRL, AUX_DM2AOUT_Msk, AUX_DM2AOUT_Pos, 0)
#define RT_DM_ADC6_On()                             MCU_REG_WRITE(MCU_AUX_CTRL, AUX_DM2ADC6_Msk, AUX_DM2ADC6_Pos, 1)
#define RT_DM_ADC6_Off()                            MCU_REG_WRITE(MCU_AUX_CTRL, AUX_DM2ADC6_Msk, AUX_DM2ADC6_Pos, 0)

/***** CMP setup******/
//select the channels to be used, 1 for use, 0 for not use
#define RT_CMP_SetCh(ch0, ch1, ch2) 	            MCU_REG_WRITE(MCU_AFE_CTRL, AFE_CTRL_CMP_EN_Msk, AFE_CTRL_CMP_EN_Pos, \
                                                            (ch0+(ch1<<1)+(ch2<<2)))                                                            
#define RT_CMP_SetCLKDiv4()                         MCU_REG_WRITE(MCU_AFE_CTRL, AFE_CTRL_CMP_CLK_Msk, AFE_CTRL_CMP_CLK_Pos, 0)     //default sample clock
#define RT_CMP_SetCLKDiv16()                        MCU_REG_WRITE(MCU_AFE_CTRL, AFE_CTRL_CMP_CLK_Msk, AFE_CTRL_CMP_CLK_Pos, 1)
#define RT_CMP_SetCLKDiv64()                        MCU_REG_WRITE(MCU_AFE_CTRL, AFE_CTRL_CMP_CLK_Msk, AFE_CTRL_CMP_CLK_Pos, 2)
#define RT_CMP_SetCLKDiv1024()                      MCU_REG_WRITE(MCU_AFE_CTRL, AFE_CTRL_CMP_CLK_Msk, AFE_CTRL_CMP_CLK_Pos, 3)
#define RT_CMP_Read0()                              MCU_REG_WRITE(MCU_AFE_CTRL, AFE_CTRL_CMP_VAL_Msk, AFE_CTRL_CMP_VAL_Pos, 1)
#define RT_CMP_Read1()                              MCU_REG_WRITE(MCU_AFE_CTRL, AFE_CTRL_CMP_VAL_Msk, AFE_CTRL_CMP_VAL_Pos, (1<<1))
#define RT_CMP_Read2()                              MCU_REG_WRITE(MCU_AFE_CTRL, AFE_CTRL_CMP_VAL_Msk, AFE_CTRL_CMP_VAL_Pos, (1<<2))

//Enable/Disable SAR ADC
#define RT_ADC_On() 	                      MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_EN_Msk, ADC_CTRL_EN_Pos, 1)
#define RT_ADC_Off() 	                      MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_EN_Msk, ADC_CTRL_EN_Pos, 0)
#define RT_ADC_IRQ_On()                             MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_IRQ_EN_Msk, ADC_CTRL_IRQ_EN_Pos, 1)
#define RT_ADC_IRQ_Off()                            MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_IRQ_EN_Msk, ADC_CTRL_IRQ_EN_Pos, 0)
#define RT_ADC_OTR_On()                             MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_OTC_Msk, ADC_CTRL_OTC_Pos, 1)
#define RT_ADC_OTR_Off()                            MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_OTC_Msk, ADC_CTRL_OTC_Pos, 0)
#define RT_ADC_PWM_TRIG_On()                        MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_PWM_TRIG_Msk, ADC_CTRL_PWM_TRIG_Pos, 1)
#define RT_ADC_PWM_TRIG_Off()                       MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_PWM_TRIG_Msk, ADC_CTRL_PWM_TRIG_Pos, 0)
#define RT_ADC_SetCh0()                             MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_CH_Msk, ADC_CTRL_CH_Pos, 0)
#define RT_ADC_SetCh1()                             MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_CH_Msk, ADC_CTRL_CH_Pos, 1)
#define RT_ADC_SetCh2()                             MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_CH_Msk, ADC_CTRL_CH_Pos, 2)
#define RT_ADC_SetCh3()                             MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_CH_Msk, ADC_CTRL_CH_Pos, 3)
#define RT_ADC_SetCh4()                             MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_CH_Msk, ADC_CTRL_CH_Pos, 4)
#define RT_ADC_SetCh5()                             MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_CH_Msk, ADC_CTRL_CH_Pos, 5)
#define RT_ADC_SetCh6()                             MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_CH_Msk, ADC_CTRL_CH_Pos, 6)
#define RT_ADC_SetCh7()                             MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_CH_Msk, ADC_CTRL_CH_Pos, 7)
#define RT_ADC_SetCLKDiv32()                        MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_CLK_Msk, ADC_CTRL_CLK_Pos, 0)
#define RT_ADC_SetCLKDiv16()                        MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_CLK_Msk, ADC_CTRL_CLK_Pos, 1)
#define RT_ADC_SetCLKDiv8()                         MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_CLK_Msk, ADC_CTRL_CLK_Pos, 2)
#define RT_ADC_SetCLKDiv4()                         MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_CLK_Msk, ADC_CTRL_CLK_Pos, 3)

#define RT_ADC_Clr()                                MCU_ADC_CLR = 1
#define RT_ADC_Start()                              MCU_ADC_CS = 1
#define RT_ADC_RxRdy()                              (MCU_ADC_VAL&ADC_READ_READY_Msk)
#define RT_ADC_NONBLOCK_Read()                      (MCU_ADC_VAL&ADC_READ_Msk)

#define RT_ADC_Init(en, otr, irq, pwmtrig)          {MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_EN_Msk, ADC_CTRL_EN_Pos, en); \
                                                     MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_OTC_Msk, ADC_CTRL_OTC_Pos, otr); \
                                                     MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_IRQ_EN_Msk, ADC_CTRL_IRQ_EN_Pos, irq); \
                                                     MCU_REG_WRITE(MCU_ADC_CTRL, ADC_CTRL_PWM_TRIG_Msk, ADC_CTRL_PWM_TRIG_Pos, pwmtrig);}
                                                     
uint32_t RT_ADC_Read();
#endif  //__AFE_H__








































