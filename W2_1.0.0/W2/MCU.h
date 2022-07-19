/*--------------------------------------------------------------------
 * TITLE: MCU Hardware Defines
 * AUTHOR: Weize 
 * DATE CREATED: 2020/01/27
 * FILENAME: MCU.h
 * PROJECT: w2
 * COPYRIGHT: Camel Microelectronics, Ltd.
 * DESCRIPTION:
 *    mcu Hardware Defines
 *
 *
 *    2020-01-27: initial
 *--------------------------------------------------------------------*/
 
#ifndef __MCU_H__
#define __MCU_H__
/*********** COMMUNICATION ***************/
//same as in "mcu.h", used as communication between studio/mcu and mcu, PAC_XXX is for RS485 type communication
//format: 
//<PAC_HEAD> <SEND_ID> <RECV_ID> <MSG> <PAC_TAIL>
//<MSG> could be:
// 1. <DATA_START> <DATA> <DATA_END>   //this is used to pass the mcu debbuger sending data back to studio, <DATA> is the data from debugger
// 2. <DBG_ACK>   //mcu entered debugger mode acknowledgement
// 3. <WRITE_ACK>  //mcu acknowledges command from sender is received
// 4. <MSG>  //string send by the program on mcu to receiver
#define SYNC_LEN 8
#define PAC_HEAD 0x1
#define PAC_TAIL 0x17
#define MAC_ID 0x1001f3f0
//#define MAC_ID 0x1001D00
#define DBG_ACK 0x5
#define MCU_KEY_DBG_ACK "\x05\x05"
#define WRITE_ACK 0x6
#define MCU_KEY_WRITE_ACK "\x06\x06"
#define DATA_START 0x2
#define MCU_KEY_DATA_START "\x02\x02"
#define DATA_END 0x3
#define MCU_KEY_DATA_END    "\x03\x03"
#define MCU_TRACEDATA_START             0xb
#define MCU_KEY_TRACEDATA_START         "\x0b\x0b"
#define MCU_TRACEDATA_END               0x10
#define MCU_KEY_TRACEDATA_END           "\x10\x10"
#define ERASE_FLASH_BLOCK_END     0x8
#define MCU_KEY_ERASE_FLASH_BLOCK_END    "\x08\x08"
#define MASTER_ID 0x20
#define STUDIO_ID 0x20
#define BROADCAST_ID 0x20
#define DATA_SIZE 256
/********** END of COMMUNICATION **************/

/********** Peripheral and SRAM/FLASH base address */
#define MCU_FLASH_BASE        0x10000000     //FLASH base address
#define MCU_SRAM_BASE         0x01000000     //SRAM base address
#define MCU_PERIPH_BASE        0x1F800000    //PERIPHERAL base address
#define MCU_SRAM_SIZE        8192            //8k byte sram
#define MCU_FLASH_SIZE       32768         //65536           //64k byte flash 
#define MCU_FLASH_END        0x10008000      //last of the 64k byte flash 
#define MCU_FLASH_BLOCK_SIZE    512          //size of block for erase
#define MCU_SRAM_END         0x01002000      //last of the 8k byte sram

/********** Peripherals base address*/
#define MCU_TIMER0_BASE     (MCU_PERIPH_BASE + 0x0100)
#define MCU_TIMER1_BASE     (MCU_PERIPH_BASE + 0x0800)
#define MCU_CCU0_BASE       (MCU_PERIPH_BASE + 0x0200)
#define MCU_CCU1_BASE       (MCU_PERIPH_BASE + 0x0300)
#define MCU_CCU2_BASE       (MCU_PERIPH_BASE + 0x0400)
#define MCU_CCUMX_BASE      (MCU_PERIPH_BASE + 0x0230)
#define MCU_EXINT_BASE      (MCU_PERIPH_BASE + 0x0500)
#define MCU_AFE_BASE        (MCU_PERIPH_BASE + 0x0600)
#define MCU_ADC_BASE        (MCU_PERIPH_BASE + 0x0601)
#define MCU_SYSTEM_BASE     (MCU_PERIPH_BASE + 0x0700)
#define MCU_GPIO0_BASE      (MCU_SYSTEM_BASE + 0x0005)
#define MCU_GPIO1_BASE      (MCU_SYSTEM_BASE + 0x0006)
#define MCU_UART0_BASE      (MCU_PERIPH_BASE + 0x0000)
#define MCU_UART1_BASE      (MCU_PERIPH_BASE + 0x0010)
#define MCU_SPI_BASE        (MCU_PERIPH_BASE + 0x0D00)
#define MCU_SD_BASE         (MCU_PERIPH_BASE + 0x0C00)
#define MCU_DMI_BASE        (MCU_PERIPH_BASE + 0x0D10)
#define MCU_WDT_BASE        (MCU_PERIPH_BASE + 0x0B00)

#define MCU_TIMER0           MCU_TIMER0_BASE
#define MCU_TIMER1           MCU_TIMER1_BASE
#define MCU_CCU0             MCU_CCU0_BASE
#define MCU_CCU1             MCU_CCU1_BASE
#define MCU_CCU2             MCU_CCU2_BASE
#define MCU_CCUMX            MCU_CCUMX_BASE
#define MCU_UART0            MCU_UART0_BASE
#define MCU_UART1            MCU_UART1_BASE

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed long int int32_t;
typedef unsigned long int uint32_t;


//for the following typedef, all the 8, 16 bit type has to use 32 bit def, 
//otherwise x = *(XXX_TypeDef *)addr won't assign the correct value
typedef uint32_t  MCU_CLRREG_TypeDef;  //8
typedef uint32_t MCU_CTRL_TypeDef;    //16
typedef uint32_t MCU_IRQ_TypeDef;    //16

typedef uint32_t MCU_GPIO_RW_TypeDef;
typedef uint32_t MCU_GPIO_VAL_TypeDef;

typedef uint32_t MCU_TIMER_CTRL_TypeDef;    //16
typedef uint32_t MCU_TIMER_REF_TypeDef;
typedef uint32_t MCU_TIMER_VAL_TypeDef;
typedef uint32_t MCU_TIMER_CLK_TypeDef;
typedef uint32_t MCU_TIMER_PWMPH_TypeDef;

typedef uint32_t MCU_CCU_CTRL_TypeDef;
typedef uint32_t MCU_CCU_REF_TypeDef;
typedef uint32_t MCU_CCU_CONF_TypeDef;
typedef uint32_t MCU_CCU_DT_TypeDef;
typedef uint32_t MCU_CCU_DUTY_TypeDef;
typedef uint32_t MCU_CCU_TRIG_TypeDef;
typedef uint32_t MCU_CCU_CLKDIV_TypeDef;

typedef uint32_t MCU_EXINT_EN_TypeDef;    //8
typedef uint32_t MCU_EXINT_STA_TypeDef;    //8
typedef uint32_t MCU_EXINT_SET_TypeDef;    //8
typedef uint32_t MCU_EXINT_CLR_TypeDef;    //8

typedef uint32_t MCU_AFE_CTRL_TypeDef;    //16

typedef uint32_t MCU_ADC_CTRL_TypeDef;    //16
typedef uint32_t MCU_ADC_VAL_TypeDef;    //16
typedef uint32_t  MCU_ADC_CS_TypeDef;    //8

typedef uint32_t MCU_UART_CTRL_TypeDef;    //16
typedef uint32_t  MCU_UART_VAL_TypeDef;    //8
typedef uint32_t  MCU_UART_RDY_TypeDef;    //8
typedef uint32_t  MCU_UART_BUSY_TypeDef;    //8
typedef uint32_t  MCU_UART_LINBRK_TypeDef;    //8
typedef uint32_t MCU_UART_BRP_TypeDef;    //16

typedef uint32_t  MCU_SPI_VAL_TypeDef;    //8
typedef uint32_t  MCU_SPI_RDY_TypeDef;    //8
typedef uint32_t  MCU_SPI_CTRL_TypeDef;    //8
typedef uint32_t  MCU_SPI_BUSY_TypeDef;    //8

typedef uint32_t MCU_SD_VAL_TypeDef;

typedef uint32_t MCU_DMI_VAL_TypeDef;
typedef uint32_t MCU_DMI_CTRL_TypeDef;
typedef uint32_t MCU_DMI_CMD_TypeDef;
typedef uint32_t MCU_DMI_RDY_TypeDef;    //8
typedef uint32_t MCU_DMI_BUSY_TypeDef;    //8

typedef uint32_t MCU_WDT_VAL_TypeDef;
typedef uint32_t MCU_WDT_CTRL_TypeDef;
typedef uint32_t MCU_WDT_CLR_TypeDef;

/*********** Peripheral declaration */
#define MCU_CTRL                  (*(MCU_CTRL_TypeDef *)(MCU_SYSTEM_BASE + 0x0000))
#define MCU_PLL_CTRL              (*(MCU_CTRL_TypeDef *)(MCU_SYSTEM_BASE + 0x0001))
#define MCU_VOLT_CTRL             (*(MCU_CTRL_TypeDef *)(MCU_SYSTEM_BASE + 0x0001))
#define MCU_CLK_CTRL              (*(MCU_CTRL_TypeDef *)(MCU_SYSTEM_BASE + 0x0002))
#define MCU_AUX_CTRL              (*(MCU_CTRL_TypeDef *)(MCU_SYSTEM_BASE + 0x0002))
#define MCU_IRQ_VAL               (*(MCU_IRQ_TypeDef *)(MCU_SYSTEM_BASE + 0x0007))

#define MCU_GPIO_RW               (*(MCU_GPIO_RW_TypeDef *)(MCU_SYSTEM_BASE + 0x0004))
#define MCU_GPIO_WRITE            (*(MCU_GPIO_VAL_TypeDef *)MCU_GPIO0_BASE)
#define MCU_GPIO_READ             (*(MCU_GPIO_VAL_TypeDef *)MCU_GPIO1_BASE)

#define MCU_TIMER_CTRL_Pos        0x0
#define MCU_TIMER_REF_Pos         0x1
#define MCU_TIMER_VAL_Pos         0x2
#define MCU_TIMER_CLRIRQ_Pos      0x3
#define MCU_TIMER_CLK_Pos         0x4
#define MCU_TIMER_CLRCNT_Pos      0x5
#define MCU_TIMER_PWMPH_Pos       0x6
#define MCU_TIMER_CLRPWM_Pos      0x7

#define MCU_TIMER0_CTRL           (*(MCU_TIMER_CTRL_TypeDef *)(MCU_TIMER0_BASE + MCU_TIMER_CTRL_Pos))
#define MCU_TIMER0_REF            (*(MCU_TIMER_REF_TypeDef *)(MCU_TIMER0_BASE + MCU_TIMER_REF_Pos))
#define MCU_TIMER0_VAL            (*(MCU_TIMER_VAL_TypeDef *)(MCU_TIMER0_BASE + MCU_TIMER_VAL_Pos))
#define MCU_TIMER0_CLRIRQ         (*(MCU_CLRREG_TypeDef *)(MCU_TIMER0_BASE + MCU_TIMER_CLRIRQ_Pos))
#define MCU_TIMER0_CLK            (*(MCU_TIMER_CLK_TypeDef *)(MCU_TIMER0_BASE + MCU_TIMER_CLK_Pos))
#define MCU_TIMER0_CLRCNT         (*(MCU_CLRREG_TypeDef *)(MCU_TIMER0_BASE + MCU_TIMER_CLRCNT_Pos))
#define MCU_TIMER0_PWMPH          (*(MCU_TIMER_PWMPH_TypeDef *)(MCU_TIMER0_BASE + MCU_TIMER_PWMPH_Pos))
#define MCU_TIMER0_CLRPWM         (*(MCU_CLRREG_TypeDef *)(MCU_TIMER0_BASE + MCU_TIMER_CLRPWM_Pos))

#define MCU_TIMER1_CTRL           (*(MCU_TIMER_CTRL_TypeDef *)(MCU_TIMER1_BASE + MCU_TIMER_CTRL_Pos))
#define MCU_TIMER1_REF            (*(MCU_TIMER_REF_TypeDef *)(MCU_TIMER1_BASE + MCU_TIMER_REF_Pos))
#define MCU_TIMER1_VAL            (*(MCU_TIMER_VAL_TypeDef *)(MCU_TIMER1_BASE + MCU_TIMER_VAL_Pos))
#define MCU_TIMER1_CLRIRQ         (*(MCU_CLRREG_TypeDef *)(MCU_TIMER1_BASE + MCU_TIMER_CLRIRQ_Pos))
#define MCU_TIMER1_CLK            (*(MCU_TIMER_CLK_TypeDef *)(MCU_TIMER1_BASE + MCU_TIMER_CLK_Pos))
#define MCU_TIMER1_CLRCNT         (*(MCU_CLRREG_TypeDef *)(MCU_TIMER1_BASE + MCU_TIMER_CLRCNT_Pos))
#define MCU_TIMER1_PWMPH          (*(MCU_TIMER_PWMPH_TypeDef *)(MCU_TIMER1_BASE + MCU_TIMER_PWMPH_Pos))
#define MCU_TIMER1_CLRPWM         (*(MCU_CLRREG_TypeDef *)(MCU_TIMER1_BASE + MCU_TIMER_CLRPWM_Pos))

#define MCU_CCU_CTRL_Pos            0x0
#define MCU_CCU_REF_Pos             0x1
#define MCU_CCU_CONF_Pos            0x2
#define MCU_CCU_CLRIRQ_Pos          0x3
#define MCU_CCU_DT_Pos              0x4
#define MCU_CCU_DUTY0_Pos           0x5
#define MCU_CCU_DUTY1_Pos           0x6
#define MCU_CCU_TRIG_Pos            0x7

#define MCU_CCU0_CTRL             (*(MCU_CCU_CTRL_TypeDef *)(MCU_CCU0_BASE + MCU_CCU_CTRL_Pos))
#define MCU_CCU0_REF              (*(MCU_CCU_REF_TypeDef *)(MCU_CCU0_BASE + MCU_CCU_REF_Pos))
#define MCU_CCU0_CONF             (*(MCU_CCU_CONF_TypeDef *)(MCU_CCU0_BASE + MCU_CCU_CONF_Pos))
#define MCU_CCU0_CLRIRQ           (*(MCU_CLRREG_TypeDef *)(MCU_CCU0_BASE + MCU_CCU_CLRIRQ_Pos)
#define MCU_CCU0_DT               (*(MCU_CCU_DT_TypeDef *)(MCU_CCU0_BASE + MCU_CCU_DT_Pos))
#define MCU_CCU0_DUTY0            (*(MCU_CCU_DUTY_TypeDef *)(MCU_CCU0_BASE + MCU_CCU_DUTY0_Pos))
#define MCU_CCU0_DUTY1            (*(MCU_CCU_DUTY_TypeDef *)(MCU_CCU0_BASE + MCU_CCU_DUTY1_Pos))
#define MCU_CCU0_TRIG             (*(MCU_CCU_TRIG_TypeDef *)(MCU_CCU0_BASE + MCU_CCU_TRIG_Pos))

#define MCU_CCU1_CTRL             (*(MCU_CCU_CTRL_TypeDef *)(MCU_CCU1_BASE + MCU_CCU_CTRL_Pos))
#define MCU_CCU1_REF              (*(MCU_CCU_REF_TypeDef *)(MCU_CCU1_BASE + MCU_CCU_REF_Pos))
#define MCU_CCU1_CONF             (*(MCU_CCU_CONF_TypeDef *)(MCU_CCU1_BASE + MCU_CCU_CONF_Pos))
#define MCU_CCU1_CLRIRQ           (*(MCU_CLRREG_TypeDef *)(MCU_CCU1_BASE + MCU_CCU_CLRIRQ_Pos)
#define MCU_CCU1_DT               (*(MCU_CCU_DT_TypeDef *)(MCU_CCU1_BASE + MCU_CCU_DT_Pos))
#define MCU_CCU1_DUTY0            (*(MCU_CCU_DUTY_TypeDef *)(MCU_CCU1_BASE + MCU_CCU_DUTY0_Pos))
#define MCU_CCU1_DUTY1            (*(MCU_CCU_DUTY_TypeDef *)(MCU_CCU1_BASE + MCU_CCU_DUTY1_Pos))
#define MCU_CCU1_TRIG             (*(MCU_CCU_TRIG_TypeDef *)(MCU_CCU1_BASE + MCU_CCU_TRIG_Pos))

#define MCU_CCU2_CTRL             (*(MCU_CCU_CTRL_TypeDef *)(MCU_CCU2_BASE + MCU_CCU_CTRL_Pos))
#define MCU_CCU2_REF              (*(MCU_CCU_REF_TypeDef *)(MCU_CCU2_BASE + MCU_CCU_REF_Pos))
#define MCU_CCU2_CONF             (*(MCU_CCU_CONF_TypeDef *)(MCU_CCU2_BASE + MCU_CCU_CONF_Pos))
#define MCU_CCU2_CLRIRQ           (*(MCU_CLRREG_TypeDef *)(MCU_CCU2_BASE + MCU_CCU_CLRIRQ_Pos)
#define MCU_CCU2_DT               (*(MCU_CCU_DT_TypeDef *)(MCU_CCU2_BASE + MCU_CCU_DT_Pos))
#define MCU_CCU2_DUTY0            (*(MCU_CCU_DUTY_TypeDef *)(MCU_CCU2_BASE + MCU_CCU_DUTY0_Pos))
#define MCU_CCU2_DUTY1            (*(MCU_CCU_DUTY_TypeDef *)(MCU_CCU2_BASE + MCU_CCU_DUTY1_Pos))
#define MCU_CCU2_TRIG             (*(MCU_CCU_TRIG_TypeDef *)(MCU_CCU2_BASE + MCU_CCU_TRIG_Pos))

#define MCU_CCUMX_CTRL_Pos          0x0
#define MCU_CCUMX_DUTY_Pos          0x1
#define MCU_CCUMX_CLRIRQ_Pos        0x3
#define MCU_CCUMX_CLKDIV_Pos        0x4

#define MCU_CCUMX_CTRL            (*(MCU_CCU_CTRL_TypeDef *)(MCU_CCUMX_BASE + MCU_CCUMX_CTRL_Pos))
#define MCU_CCUMX_DUTY            (*(MCU_CCU_DUTY_TypeDef *)(MCU_CCUMX_BASE + MCU_CCUMX_DUTY_Pos))
#define MCU_CCUMX_CLRIRQ          (*(MCU_CLRREG_TypeDef *)(MCU_CCUMX_BASE + MCU_CCUMX_CLRIRQ_Pos)
#define MCU_CCUMX_CLKDIV          (*(MCU_CCU_CLKDIV_TypeDef *)(MCU_CCUMX_BASE + MCU_CCUMX_CLKDIV_Pos))

#define MCU_EXINT_EN              (*(MCU_EXINT_EN_TypeDef *)(MCU_EXINT_BASE + 0x0))
#define MCU_EXINT_STA             (*(MCU_EXINT_STA_TypeDef *)(MCU_EXINT_BASE + 0x1))
#define MCU_EXINT_SET             (*(MCU_EXINT_SET_TypeDef *)(MCU_EXINT_BASE + 0x2))
#define MCU_EXINT_CLR             (*(MCU_EXINT_CLR_TypeDef *)(MCU_EXINT_BASE + 0x3))

#define MCU_AFE_CTRL              (*(MCU_AFE_CTRL_TypeDef *)(MCU_AFE_BASE + 0x0))

#define MCU_ADC_CTRL              (*(MCU_ADC_CTRL_TypeDef *)(MCU_ADC_BASE + 0x0))
#define MCU_ADC_VAL               (*(MCU_ADC_VAL_TypeDef *)(MCU_ADC_BASE + 0x1))
#define MCU_ADC_CLR               (*(MCU_CLRREG_TypeDef *)(MCU_ADC_BASE + 0x2))
#define MCU_ADC_CS                (*(MCU_ADC_CS_TypeDef *)(MCU_ADC_BASE + 0x3))

#define MCU_UART_READ_Pos         0x0
#define MCU_UART_TxBusy_Pos       0x1
#define MCU_UART_WRITE_Pos        0x2
#define MCU_UART_CLRIRQ_Pos       0x3
#define MCU_UART_CTRL_Pos         0x4
#define MCU_UART_RxRdy_Pos        0x5
#define MCU_UART_LINBRK_Pos       0x6
#define MCU_UART_BRP_Pos          0x7

#define MCU_UART0_READ            (*(MCU_UART_VAL_TypeDef *)(MCU_UART0_BASE + MCU_UART_READ_Pos))
#define MCU_UART0_TxBusy          (*(MCU_UART_BUSY_TypeDef *)(MCU_UART0_BASE + MCU_UART_TxBusy_Pos))
#define MCU_UART0_WRITE           (*(MCU_UART_VAL_TypeDef *)(MCU_UART0_BASE + MCU_UART_WRITE_Pos))
#define MCU_UART0_CLRIRQ          (*(MCU_CLRREG_TypeDef *)(MCU_UART0_BASE + MCU_UART_CLRIRQ_Pos))
#define MCU_UART0_CTRL            (*(MCU_UART_CTRL_TypeDef *)(MCU_UART0_BASE + MCU_UART_CTRL_Pos))
#define MCU_UART0_RxRdy           (*(MCU_UART_RDY_TypeDef *)(MCU_UART0_BASE + MCU_UART_RxRdy_Pos))
#define MCU_UART0_LINBRK          (*(MCU_UART_LINBRK_TypeDef *)(MCU_UART0_BASE + MCU_UART_LINBRK_Pos))
#define MCU_UART0_BRP             (*(MCU_UART_BRP_TypeDef *)(MCU_UART0_BASE + MCU_UART_BRP_Pos))

#define MCU_UART1_READ            (*(MCU_UART_VAL_TypeDef *)(MCU_UART1_BASE + MCU_UART_READ_Pos))
#define MCU_UART1_TxBusy          (*(MCU_UART_BUSY_TypeDef *)(MCU_UART1_BASE + MCU_UART_TxBusy_Pos))
#define MCU_UART1_WRITE           (*(MCU_UART_VAL_TypeDef *)(MCU_UART1_BASE + MCU_UART_WRITE_Pos))
#define MCU_UART1_CLRIRQ          (*(MCU_CLRREG_TypeDef *)(MCU_UART1_BASE + MCU_UART_CLRIRQ_Pos))
#define MCU_UART1_CTRL            (*(MCU_UART_CTRL_TypeDef *)(MCU_UART1_BASE + MCU_UART_CTRL_Pos))
#define MCU_UART1_RxRdy           (*(MCU_UART_RDY_TypeDef *)(MCU_UART1_BASE + MCU_UART_RxRdy_Pos))
#define MCU_UART1_LINBRK          (*(MCU_UART_LINBRK_TypeDef *)(MCU_UART1_BASE + MCU_UART_LINBRK_Pos))
#define MCU_UART1_BRP             (*(MCU_UART_BRP_TypeDef *)(MCU_UART1_BASE + MCU_UART_BRP_Pos))

#define MCU_SPI_WRITE             (*(MCU_SPI_VAL_TypeDef *)(MCU_SPI_BASE + 0x2))
#define MCU_SPI_READ              (*(MCU_SPI_VAL_TypeDef *)(MCU_SPI_BASE + 0x0))
#define MCU_SPI_RxRdy             (*(MCU_SPI_RDY_TypeDef *)(MCU_SPI_BASE + 0x5))
#define MCU_SPI_TxBusy            (*(MCU_SPI_BUSY_TypeDef *)(MCU_SPI_BASE + 0x1))
#define MCU_SPI_CLRIRQ            (*(MCU_CLRREG_TypeDef *)(MCU_SPI_BASE + 0x3))
#define MCU_SPI_CTRL              (*(MCU_SPI_CTRL_TypeDef *)(MCU_SPI_BASE +  0x4))

#define MCU_SD_BR0                (*(MCU_SD_VAL_TypeDef *)(MCU_SD_BASE + 0x4))
#define MCU_SD_BR1                (*(MCU_SD_VAL_TypeDef *)(MCU_SD_BASE + 0x5))
#define MCU_SD_CLRIRQ             (*(MCU_CLRREG_TypeDef *)(MCU_SD_BASE + 0x3))

#define MCU_DMI_ADDR_Pos          0x0
#define MCU_DMI_CMD_Pos           0x1
#define MCU_DMI_DATA_Pos          0x2
#define MCU_DMI_CLRIRQ_Pos        0x3
#define MCU_DMI_CTRL_Pos          0x4
#define MCU_DMI_STATUS_Pos        0x5

#define MCU_DMI_DATA              (*(MCU_DMI_VAL_TypeDef *)(MCU_DMI_BASE + MCU_DMI_DATA_Pos))
#define MCU_DMI_ADDR              (*(MCU_DMI_VAL_TypeDef *)(MCU_DMI_BASE + MCU_DMI_ADDR_Pos))
#define MCU_DMI_CMD               (*(MCU_DMI_CMD_TypeDef *)(MCU_DMI_BASE + MCU_DMI_CMD_Pos))
#define MCU_DMI_CLRIRQ            (*(MCU_CLRIRQ_TypeDef *)(MCU_DMI_BASE + MCU_DMI_CLRIRQ_Pos))
#define MCU_DMI_CTRL              (*(MCU_DMI_CTRL_TypeDef *)(MCU_DMI_BASE + MCU_DMI_CTRL_Pos))
#define MCU_DMI_STATUS            (*(MCU_DMI_VAL_TypeDef *)(MCU_DMI_BASE + MCU_DMI_STATUS_Pos))

#define MCU_WDT_CTRL              (*(MCU_WDT_CTRL_TypeDef *)(MCU_WDT_BASE +  0x0))
#define MCU_WDT_CLR               (*(MCU_WDT_CLR_TypeDef *)(MCU_WDT_BASE + 0x3))
#define MCU_WDT_READ              (*(MCU_WDT_VAL_TypeDef *)(MCU_WDT_BASE + 0x4))

/*********** Bitfield definition for System*/
#define CTRL_SLEEP1_EN_Pos             7U        //deep sleep mode enable bit, digital part off
#define CTRL_SLEEP1_EN_Msk             (1U<<CTRL_SLEEP1_EN_Pos)
#define CTRL_SLEEP0_EN_Pos             6U        //low power mode enable bit, clock to 16khz
#define CTRL_SLEEP0_EN_Msk             (1U<<CTRL_SLEEP0_EN_Pos)
#define CTRL_DBG_EN_Pos                1U        //system debug enable bit,
#define CTRL_DBG_EN_Msk                (1U<<CTRL_DBG_EN_Pos)
#define CTRL_IRQ_EN_Pos                0U        //system irq enable bit
#define CTRL_IRQ_EN_Msk                (1U<<CTRL_IRQ_EN_Pos)

#define XTAL_DIV_EN_Pos                12U        //divide the input xtal ref clk by 2 if enabled (bit set to 1)
#define XTAL_DIV_EN_Msk                (1U<<XTAL_DIV_EN_Pos)
#define PLL_REFDIV_Pos                 8U         //PLL clock period is ref clk period divided by this value
#define PLL_REFDIV_Msk                 (15U<<PLL_REFDIV_Pos)


#define VOLT_ADJ_Pos                   2U        //adjust the internal 1.5v supply voltage, only used by vendor
#define VOLT_ADJ_Msk                   (3U<<VOLT_ADJ_Pos)
#define VOLT_TRIM_Pos                  0U        //voltage trim ref? only used by vendor
#define VOLT_TRIM_Msk                  (3U<<VOLT_TRIM_Pos)

#define CLK_DIV_Pos                    12U       //main clock is derived from PLL clock base on this
#define CLK_DIV_Msk                    (3U<<CLK_DIV_Pos)

#define AUX_OPO2ADC_Pos                9U        //bit to enable OPO output to ADC input
#define AUX_OPO2ADC_Msk                (7U<<AUX_OPO2ADC_Pos)
#define AUX_DP2AOUT_Pos                5U        //mimic UART output D+ to USB output 3v/0.6v/0v
#define AUX_DP2AOUT_Msk                (7U<<AUX_DP2AOUT_Pos)
#define AUX_DP2ADC7_Pos                4U        //connecting UART output D+ to ADC chn 7
#define AUX_DP2ADC7_Msk                (1U<<AUX_DP2ADC7_Pos)
#define AUX_DM2AOUT_Pos                1U        //mimic UART output D- to USB output 3v/0.6v/0v
#define AUX_DM2AOUT_Msk                (7U<<AUX_DM2AOUT_Pos)
#define AUX_DM2ADC6_Pos                0U        //connecting UART output D- to ADC chn 6
#define AUX_DM2ADC6_Msk                (1U<<AUX_DM2ADC6_Pos)

#define IRQ_VAL_I2C_Pos                15U         //bit to check if irq from I2C
#define IRQ_VAL_I2C_Msk                (1U<<IRQ_VAL_I2C_Pos)
#define IRQ_VAL_CCU2_Pos               14U        //bit to check if irq from CCU2
#define IRQ_VAL_CCU2_Msk               (1U<<IRQ_VAL_CCU2_Pos)
#define IRQ_VAL_SPI_Pos                13U        //bit to check if irq from SPI
#define IRQ_VAL_SPI_Msk                (1U<<IRQ_VAL_SPI_Pos)
#define IRQ_VAL_UART_Pos               12U        //bit to ckeck if irq from UARTs
#define IRQ_VAL_UART_Msk               (1U<<IRQ_VAL_UART_Pos)
#define IRQ_VAL_U0_DBG_Pos             11U         //bit to check if irq from uart ctrl-c signal
#define IRQ_VAL_U0_DBG_Msk             (1U<<IRQ_VAL_U0_DBG_Pos)
#define IRQ_VAL_DMI_Pos                 10U         //bit to check if irq from DMI
#define IRQ_VAL_DMI_Msk                 (1U<<IRQ_VAL_DMI_Pos)
#define IRQ_VAL_ANA_Pos                8U        //bit to check if irq from Analog part
#define IRQ_VAL_ANA_Msk                (1U<<IRQ_VAL_ANA_Pos)
#define IRQ_VAL_CCU1_Pos               7U        //bit to ckeck if irq from CCU1
#define IRQ_VAL_CCU1_Msk               (1U<<IRQ_VAL_CCU1_Pos)
#define IRQ_VAL_WDT_Pos                6U        //bit to check if irq from WDT
#define IRQ_VAL_WDT_Msk                (1U<<IRQ_VAL_WDT_Pos)
#define IRQ_VAL_EXT_Pos                5U        //bit to check if irq from external interrput
#define IRQ_VAL_EXT_Msk                (1U<<IRQ_VAL_EXT_Pos)
#define IRQ_VAL_DBG_Pos                4U        //bit to check if irq from debbugger breakpoints
#define IRQ_VAL_DBG_Msk                (1U<<IRQ_VAL_DBG_Pos)
#define IRQ_VAL_CCU0_Pos               3U        //bit to check if irq from CCU0
#define IRQ_VAL_CCU0_Msk               (1U<<IRQ_VAL_CCU0_Pos)
#define IRQ_VAL_TIMER1_Pos             2U        //bit to check if irq from timer1
#define IRQ_VAL_TIMER1_Msk             (1U<<IRQ_VAL_TIMER1_Pos)
#define IRQ_VAL_TIMER0_Pos             1U        //bit to check if irq from timer0
#define IRQ_VAL_TIMER0_Msk             (1U<<IRQ_VAL_TIMER1_Pos)
#define IRQ_VAL_U0_CMD_Pos             0U        //bit to check if irq from UART0 cmd
#define IRQ_VAL_U0_CMD_Msk             (1U<<IRQ_VAL_U0_CMD_Pos)

/*********** Hardware addesses ***********/
#define USER_INT             0x01001FFC   //interrupt is from user code if [0] is 1
#define PC_LOC               0x01001FF8  //RAM address to store current program counter
#define INT_COUNT	         0x01001FF4  //RAM address to store current interrupt depth, number of interrupts


// for boot loader
#define FLASH_WRITE_CODE_ADDR     0x218    //0x2b4
#define FLASH_ERASE_CODE_ADDR     0x24C    //0x2e8
#define USER_CODE_ADDR            0x10200000    //use NVR sector 0 to store the USER_CODE_ADDR
#define USER_INTERRUPT_ADDR 	    0x10200004
#define XTAL_FREQ_ADDR            0x10200008    //use NVR sector 0 to store the xtal freq
#define XTAL_DIV_ADDR             0x1020000C    
#define PLL_REFDIV_ADDR           0x10200010
#define CLK_DIV_ADDR              0x10200014

#define LOAD_START	              0x4
#define LOAD_END		    0x13
#define DEBUG_START	              0x14
#define DEBUG_END		    0x15

#define MemoryRead8(A)         (*(volatile uint8_t*)(A))
#define MemoryRead16(A)        (*(volatile uint16_t*)(A))
#define MemoryRead32(A)        (*(volatile uint32_t*)(A))
#define MemoryRead(A)          (*(volatile uint32_t*)(A))
#define MemoryWrite8(A,V)      *(volatile uint8_t*)(A)=(V)
#define MemoryWrite16(A,V)     *(volatile uint16_t*)(A)=(V)
#define MemoryWrite32(A,V)     *(volatile uint32_t*)(A)=(V)
#define MemoryWrite(A,V)       MemoryWrite32(A,V)

#define MemoryOr8(A,V)         (*(volatile uint8_t*)(A)|=(V))
#define MemoryOr16(A,V)        (*(volatile uint16_t*)(A)|=(V))
#define MemoryOr32(A,V)        (*(volatile uint32_t*)(A)|=(V))
#define MemoryOr(A,V)          MemoryOr32(A,V)

#define MemoryAnd8(A,V)        (*(volatile uint8_t*)(A)&=(V))
#define MemoryAnd16(A,V)       (*(volatile uint16_t*)(A)&=(V))
#define MemoryAnd32(A,V)       (*(volatile uint32_t*)(A)&=(V))
#define MemoryAnd(A,V)         MemoryAnd32(A,V)

#define MCU_REG_READ(R,M,P)         ((R&M)>>P)
#define MCU_REG_WRITE(R,M,P,V)      R=((R&(~M))|(V<<P))

typedef void (*FuncPtr)(void);
typedef void (*FuncPtr2)(uint32_t, uint32_t);
typedef void (*FuncPtr1)(uint32_t);

#define flashWrite(address, value) {FuncPtr2 funcptr; funcptr = (FuncPtr2)FLASH_WRITE_CODE_ADDR; funcptr(value, address);}
#define flashErase(address) {uint32_t addr; FuncPtr1 funcptr; funcptr =  (FuncPtr1)FLASH_ERASE_CODE_ADDR; addr = (((((address>>16)&0xF)|0x1010)<<16) + (address&0xFFFF)); funcptr(addr);}

#define JumpTo(address) {FuncPtr funcptr; funcptr = (FuncPtr)address; funcptr();}

//extern char __mac_id;
#define getMAC() MemoryRead32(MAC_ID)
#define setMAC(id) flashWrite(id, MAC_ID)

extern uint32_t __XTAL_FREQ;
//void setMAC(char id);

#endif //__MCU_H__


































































































