/*
 * stm32407xx.h
 *
 *  Created on: Jun 2, 2026
 *      Author: nomul
 *
 *  Register structs sourced from:
 *    - RM0090 Rev 21: STM32F405/407/415/417/427/429/437/439 Reference Manual
 *    - DS8626 Rev 12: STM32F405xx / STM32F407xx Datasheet
 */

#ifndef STM32407XX_H_
#define STM32407XX_H_

#include <stdint.h>

/*===========================================================================
 * 0. BASE ADDRESSES OF FLASH AND SRAM MEMORIES
 *    Source: RM0090 §2.3 / DS8626 Fig.18 memory map
 *===========================================================================*/





/**********************************START:Processor Specific Details **********************************/
/*
 * ARM Cortex Mx Processor NVIC ISERx Register Addresses
 */
#define NVIC_ISER0      ( (__vo uint32_t*)0xE000E100 )
#define NVIC_ISER1      ( (__vo uint32_t*)0xE000E104 )
#define NVIC_ISER2      ( (__vo uint32_t*)0xE000E108 )
#define NVIC_ISER3      ( (__vo uint32_t*)0xE000E10C )
#define NVIC_ISER4      ( (__vo uint32_t*)0xE000E110 )
#define NVIC_ISER5      ( (__vo uint32_t*)0xE000E114 )
#define NVIC_ISER6      ( (__vo uint32_t*)0xE000E118 )
#define NVIC_ISER7      ( (__vo uint32_t*)0xE000E11C )


/*
 * ARM Cortex Mx Processor NVIC ICERx Register Addresses
 */
#define NVIC_ICER0      ( (__vo uint32_t*)0XE000E180 )
#define NVIC_ICER1      ( (__vo uint32_t*)0XE000E184 )
#define NVIC_ICER2      ( (__vo uint32_t*)0XE000E188 )
#define NVIC_ICER3      ( (__vo uint32_t*)0XE000E18C )
#define NVIC_ICER4      ( (__vo uint32_t*)0XE000E190 )
#define NVIC_ICER5      ( (__vo uint32_t*)0XE000E194 )
#define NVIC_ICER6      ( (__vo uint32_t*)0XE000E198 )
#define NVIC_ICER7      ( (__vo uint32_t*)0XE000E19C )


/*
 * ARM Cortex Mx Processor Priority Register Address Calculation
 */
#define NVIC_PR_BASE_ADDR   ( (__vo uint32_t*)0XE000E400


/*
 * ARM Cortex Mx Processor number of priority bits implemented in Priority Register
 */
#define NO_PR_BITS_IMPLEMENTED  4
/*
 * FLASH_BASEADDR (0x0800 0000)
 *   Main Flash memory — up to 1 MB on STM32F407xx.
 *   Accessed via ICode/DCode buses.
 */
#define FLASH_BASEADDR          0x08000000U

/*
 * SRAM1_BASEADDR (0x2000 0000)
 *   Main embedded SRAM, 112 KB. Accessible by all AHB masters.
 */
#define SRAM1_BASEADDR          0x20000000U

/*
 * SRAM2_BASEADDR (0x2001 C000)
 *   Auxiliary embedded SRAM, 16 KB.
 *   Follows SRAM1 immediately (112 KB = 0x1C000 bytes).
 */
#define SRAM2_BASEADDR          0x2001C000U

/*
 * ROM_BASEADDR (0x1FFF 0000)  — System Memory / Bootloader
 *   Factory-programmed read-only bootloader + 512 bytes OTP.
 *   Selected as boot space when BOOT1=0, BOOT0=1.
 */
#define ROM_BASEADDR            0x1FFF0000U

/* Convenience alias */
#define SRAM                    SRAM1_BASEADDR


/*===========================================================================
 * 1. BUS BASE ADDRESSES
 *===========================================================================*/
#define PERIPH_BASE             0x40000000U
#define APB1PERIPH_BASE         PERIPH_BASE             /* 0x4000 0000 */
#define APB2PERIPH_BASE         0x40010000U             /* 0x4001 0000 */
#define AHB1PERIPH_BASE         0x40020000U             /* 0x4002 0000 */
#define AHB2PERIPH_BASE         0x50000000U             /* 0x5000 0000 */


/*===========================================================================
 * 2. AHB1 PERIPHERAL BASE ADDRESSES
 *===========================================================================*/
#define GPIOA_BASEADDR          (AHB1PERIPH_BASE + 0x0000U)   /* 0x4002 0000 */
#define GPIOB_BASEADDR          (AHB1PERIPH_BASE + 0x0400U)   /* 0x4002 0400 */
#define GPIOC_BASEADDR          (AHB1PERIPH_BASE + 0x0800U)   /* 0x4002 0800 */
#define GPIOD_BASEADDR          (AHB1PERIPH_BASE + 0x0C00U)   /* 0x4002 0C00 */
#define GPIOE_BASEADDR          (AHB1PERIPH_BASE + 0x1000U)   /* 0x4002 1000 */
#define GPIOF_BASEADDR          (AHB1PERIPH_BASE + 0x1400U)   /* 0x4002 1400 */
#define GPIOG_BASEADDR          (AHB1PERIPH_BASE + 0x1800U)   /* 0x4002 1800 */
#define GPIOH_BASEADDR          (AHB1PERIPH_BASE + 0x1C00U)   /* 0x4002 1C00 */
#define GPIOI_BASEADDR          (AHB1PERIPH_BASE + 0x2000U)   /* 0x4002 2000 */

#define CRC_BASEADDR            (AHB1PERIPH_BASE + 0x3000U)   /* 0x4002 3000 */
#define RCC_BASEADDR            (AHB1PERIPH_BASE + 0x3800U)   /* 0x4002 3800 */
#define FLASH_IF_BASEADDR       (AHB1PERIPH_BASE + 0x3C00U)   /* 0x4002 3C00 */
#define BKPSRAM_BASEADDR        (AHB1PERIPH_BASE + 0x4000U)   /* 0x4002 4000 */
#define DMA1_BASEADDR           (AHB1PERIPH_BASE + 0x6000U)   /* 0x4002 6000 */
#define DMA2_BASEADDR           (AHB1PERIPH_BASE + 0x6400U)   /* 0x4002 6400 */
#define ETHERNET_MAC_BASEADDR   (AHB1PERIPH_BASE + 0x8000U)   /* 0x4002 8000 */
#define USB_OTG_HS_BASEADDR     0x40040000U                   /* 0x4004 0000 */


/*===========================================================================
 * 3. AHB2 PERIPHERAL BASE ADDRESSES
 *===========================================================================*/
#define USB_OTG_FS_BASEADDR     (AHB2PERIPH_BASE + 0x00000U)  /* 0x5000 0000 */
#define DCMI_BASEADDR           (AHB2PERIPH_BASE + 0x50000U)  /* 0x5005 0000 */
#define CRYP_BASEADDR           (AHB2PERIPH_BASE + 0x60000U)  /* 0x5006 0000 */
#define HASH_BASEADDR           (AHB2PERIPH_BASE + 0x60400U)  /* 0x5006 0400 */
#define RNG_BASEADDR            (AHB2PERIPH_BASE + 0x60800U)  /* 0x5006 0800 */


/*===========================================================================
 * 4. APB1 PERIPHERAL BASE ADDRESSES  (max 42 MHz)
 *===========================================================================*/
#define TIM2_BASEADDR           (APB1PERIPH_BASE + 0x0000U)
#define TIM3_BASEADDR           (APB1PERIPH_BASE + 0x0400U)
#define TIM4_BASEADDR           (APB1PERIPH_BASE + 0x0800U)
#define TIM5_BASEADDR           (APB1PERIPH_BASE + 0x0C00U)
#define TIM6_BASEADDR           (APB1PERIPH_BASE + 0x1000U)
#define TIM7_BASEADDR           (APB1PERIPH_BASE + 0x1400U)
#define TIM12_BASEADDR          (APB1PERIPH_BASE + 0x1800U)
#define TIM13_BASEADDR          (APB1PERIPH_BASE + 0x1C00U)
#define TIM14_BASEADDR          (APB1PERIPH_BASE + 0x2000U)
#define RTC_BKP_BASEADDR        (APB1PERIPH_BASE + 0x2800U)
#define WWDG_BASEADDR           (APB1PERIPH_BASE + 0x2C00U)
#define IWDG_BASEADDR           (APB1PERIPH_BASE + 0x3000U)
#define I2S2EXT_BASEADDR        (APB1PERIPH_BASE + 0x3400U)
#define SPI2_I2S2_BASEADDR      (APB1PERIPH_BASE + 0x3800U)
#define SPI3_I2S3_BASEADDR      (APB1PERIPH_BASE + 0x3C00U)
#define I2S3EXT_BASEADDR        (APB1PERIPH_BASE + 0x4000U)
#define USART2_BASEADDR         (APB1PERIPH_BASE + 0x4400U)
#define USART3_BASEADDR         (APB1PERIPH_BASE + 0x4800U)
#define UART4_BASEADDR          (APB1PERIPH_BASE + 0x4C00U)
#define UART5_BASEADDR          (APB1PERIPH_BASE + 0x5000U)
#define I2C1_BASEADDR           (APB1PERIPH_BASE + 0x5400U)
#define I2C2_BASEADDR           (APB1PERIPH_BASE + 0x5800U)
#define I2C3_BASEADDR           (APB1PERIPH_BASE + 0x5C00U)
#define CAN1_BASEADDR           (APB1PERIPH_BASE + 0x6400U)
#define CAN2_BASEADDR           (APB1PERIPH_BASE + 0x6800U)
#define PWR_BASEADDR            (APB1PERIPH_BASE + 0x7000U)
#define DAC_BASEADDR            (APB1PERIPH_BASE + 0x7400U)
#define UART7_BASEADDR          (APB1PERIPH_BASE + 0x7800U)
#define UART8_BASEADDR          (APB1PERIPH_BASE + 0x7C00U)


/*===========================================================================
 * 5. APB2 PERIPHERAL BASE ADDRESSES  (max 84 MHz)
 *===========================================================================*/
#define TIM1_BASEADDR           (APB2PERIPH_BASE + 0x0000U)
#define TIM8_BASEADDR           (APB2PERIPH_BASE + 0x0400U)
#define USART1_BASEADDR         (APB2PERIPH_BASE + 0x1000U)
#define USART6_BASEADDR         (APB2PERIPH_BASE + 0x1400U)
#define ADC1_ADC2_ADC3_BASEADDR (APB2PERIPH_BASE + 0x2000U)
#define SDIO_BASEADDR           (APB2PERIPH_BASE + 0x2C00U)
#define SPI1_BASEADDR           (APB2PERIPH_BASE + 0x3000U)
#define SPI4_BASEADDR           (APB2PERIPH_BASE + 0x3400U)
#define SYSCFG_BASEADDR         (APB2PERIPH_BASE + 0x3800U)
#define EXTI_BASEADDR           (APB2PERIPH_BASE + 0x3C00U)
#define TIM9_BASEADDR           (APB2PERIPH_BASE + 0x4000U)
#define TIM10_BASEADDR          (APB2PERIPH_BASE + 0x4400U)
#define TIM11_BASEADDR          (APB2PERIPH_BASE + 0x4800U)
#define SPI5_BASEADDR           (APB2PERIPH_BASE + 0x5000U)
#define SPI6_BASEADDR           (APB2PERIPH_BASE + 0x5400U)
#define SAI1_BASEADDR           (APB2PERIPH_BASE + 0x5800U)


/*===========================================================================
 * 6. CONVENIENCE ALIASES
 *===========================================================================*/
#define SPI2_BASEADDR           SPI2_I2S2_BASEADDR
#define SPI3_BASEADDR           SPI3_I2S3_BASEADDR


/*===========================================================================
 * 7. PERIPHERAL REGISTER STRUCTURE DEFINITIONS
 *    Source: RM0090 Rev 21 register map tables
 *===========================================================================*/

/*---------------------------------------------------------------------------
 * 7.1  GPIO  (RM0090 Table 40, §8.4.11, p.290)
 *      Each GPIOx peripheral is 0x400 bytes; registers are 32-bit.
 *---------------------------------------------------------------------------*/
typedef struct
{
    volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00 */
    volatile uint32_t OTYPER;   /*!< GPIO port output type register,         Address offset: 0x04 */
    volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,        Address offset: 0x08 */
    volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,   Address offset: 0x0C */
    volatile uint32_t IDR;      /*!< GPIO port input data register,          Address offset: 0x10 */
    volatile uint32_t ODR;      /*!< GPIO port output data register,         Address offset: 0x14 */
    volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,       Address offset: 0x18 */
    volatile uint32_t LCKR;     /*!< GPIO port configuration lock register,  Address offset: 0x1C */
    volatile uint32_t AFR[2];   /*!< AFR[0]: GPIO alternate function low register  (offset 0x20)
                                     AFR[1]: GPIO alternate function high register (offset 0x24) */
} GPIO_RegDef_t;


/*---------------------------------------------------------------------------
 * 7.2  RCC  (RM0090 Table 35, §7.3.24, p.267-269)
 *      RCC peripheral base: 0x4002 3800
 *---------------------------------------------------------------------------*/
typedef struct
{
    volatile uint32_t CR;           /*!< RCC clock control register,                          offset: 0x00 */
    volatile uint32_t PLLCFGR;      /*!< RCC PLL configuration register,                      offset: 0x04 */
    volatile uint32_t CFGR;         /*!< RCC clock configuration register,                    offset: 0x08 */
    volatile uint32_t CIR;          /*!< RCC clock interrupt register,                        offset: 0x0C */
    volatile uint32_t AHB1RSTR;     /*!< RCC AHB1 peripheral reset register,                  offset: 0x10 */
    volatile uint32_t AHB2RSTR;     /*!< RCC AHB2 peripheral reset register,                  offset: 0x14 */
    volatile uint32_t AHB3RSTR;     /*!< RCC AHB3 peripheral reset register,                  offset: 0x18 */
    uint32_t          RESERVED0;    /*!< Reserved,                                            offset: 0x1C */
    volatile uint32_t APB1RSTR;     /*!< RCC APB1 peripheral reset register,                  offset: 0x20 */
    volatile uint32_t APB2RSTR;     /*!< RCC APB2 peripheral reset register,                  offset: 0x24 */
    uint32_t          RESERVED1[2]; /*!< Reserved,                                    offsets: 0x28, 0x2C */
    volatile uint32_t AHB1ENR;      /*!< RCC AHB1 peripheral clock enable register,           offset: 0x30 */
    volatile uint32_t AHB2ENR;      /*!< RCC AHB2 peripheral clock enable register,           offset: 0x34 */
    volatile uint32_t AHB3ENR;      /*!< RCC AHB3 peripheral clock enable register,           offset: 0x38 */
    uint32_t          RESERVED2;    /*!< Reserved,                                            offset: 0x3C */
    volatile uint32_t APB1ENR;      /*!< RCC APB1 peripheral clock enable register,           offset: 0x40 */
    volatile uint32_t APB2ENR;      /*!< RCC APB2 peripheral clock enable register,           offset: 0x44 */
    uint32_t          RESERVED3[2]; /*!< Reserved,                                    offsets: 0x48, 0x4C */
    volatile uint32_t AHB1LPENR;    /*!< RCC AHB1 peripheral clock enable in low power mode,  offset: 0x50 */
    volatile uint32_t AHB2LPENR;    /*!< RCC AHB2 peripheral clock enable in low power mode,  offset: 0x54 */
    volatile uint32_t AHB3LPENR;    /*!< RCC AHB3 peripheral clock enable in low power mode,  offset: 0x58 */
    uint32_t          RESERVED4;    /*!< Reserved,                                            offset: 0x5C */
    volatile uint32_t APB1LPENR;    /*!< RCC APB1 peripheral clock enable in low power mode,  offset: 0x60 */
    volatile uint32_t APB2LPENR;    /*!< RCC APB2 peripheral clock enable in low power mode,  offset: 0x64 */
    uint32_t          RESERVED5[2]; /*!< Reserved,                                    offsets: 0x68, 0x6C */
    volatile uint32_t BDCR;         /*!< RCC backup domain control register,                  offset: 0x70 */
    volatile uint32_t CSR;          /*!< RCC clock control & status register,                 offset: 0x74 */
    uint32_t          RESERVED6[2]; /*!< Reserved,                                    offsets: 0x78, 0x7C */
    volatile uint32_t SSCGR;        /*!< RCC spread spectrum clock generation register,       offset: 0x80 */
    volatile uint32_t PLLI2SCFGR;   /*!< RCC PLLI2S configuration register,                  offset: 0x84 */
} RCC_RegDef_t;


/*---------------------------------------------------------------------------
 * 7.3  EXTI  (RM0090 Table 64, §12.3.7, p.390)
 *      EXTI peripheral base: 0x4001 3C00
 *---------------------------------------------------------------------------*/
typedef struct
{
    volatile uint32_t IMR;    /*!< Interrupt mask register,            Address offset: 0x00 */
    volatile uint32_t EMR;    /*!< Event mask register,                Address offset: 0x04 */
    volatile uint32_t RTSR;   /*!< Rising trigger selection register,  Address offset: 0x08 */
    volatile uint32_t FTSR;   /*!< Falling trigger selection register, Address offset: 0x0C */
    volatile uint32_t SWIER;  /*!< Software interrupt event register,  Address offset: 0x10 */
    volatile uint32_t PR;     /*!< Pending register,                   Address offset: 0x14 */
} EXTI_RegDef_t;


/*---------------------------------------------------------------------------
 * 7.4  SYSCFG  (RM0090 Table 41, §9.2.8, p.292-296)
 *      SYSCFG peripheral base: 0x4001 3800
 *---------------------------------------------------------------------------*/
typedef struct
{
    volatile uint32_t MEMRMP;       /*!< SYSCFG memory remap register,                         offset: 0x00 */
    volatile uint32_t PMC;          /*!< SYSCFG peripheral mode configuration register,         offset: 0x04 */
    volatile uint32_t EXTICR[4];    /*!< SYSCFG external interrupt config registers 1-4,
                                         EXTICR[0] = EXTICR1 offset 0x08,
                                         EXTICR[1] = EXTICR2 offset 0x0C,
                                         EXTICR[2] = EXTICR3 offset 0x10,
                                         EXTICR[3] = EXTICR4 offset 0x14               offsets: 0x08-0x14 */
    uint32_t          RESERVED[2];  /*!< Reserved,                                     offsets: 0x18, 0x1C */
    volatile uint32_t CMPCR;        /*!< Compensation cell control register,                    offset: 0x20 */
} SYSCFG_RegDef_t;


/*---------------------------------------------------------------------------
 * 7.5  SPI / I2S  (RM0090 Table 130, §28.5.10, p.928)
 *      Applies to: SPI1, SPI2/I2S2, SPI3/I2S3, SPI4
 *---------------------------------------------------------------------------*/
typedef struct
{
    volatile uint32_t CR1;      /*!< SPI control register 1 (not used in I2S mode),  offset: 0x00 */
    volatile uint32_t CR2;      /*!< SPI control register 2,                          offset: 0x04 */
    volatile uint32_t SR;       /*!< SPI status register,                             offset: 0x08 */
    volatile uint32_t DR;       /*!< SPI data register,                               offset: 0x0C */
    volatile uint32_t CRCPR;    /*!< SPI CRC polynomial register (not in I2S mode),   offset: 0x10 */
    volatile uint32_t RXCRCR;   /*!< SPI RX CRC register (not in I2S mode),           offset: 0x14 */
    volatile uint32_t TXCRCR;   /*!< SPI TX CRC register (not in I2S mode),           offset: 0x18 */
    volatile uint32_t I2SCFGR;  /*!< SPI_I2S configuration register,                 offset: 0x1C */
    volatile uint32_t I2SPR;    /*!< SPI_I2S prescaler register,                      offset: 0x20 */
} SPI_RegDef_t;



/******************************************************************************************
 *			Bit position definitions of SPI peripheral
 ******************************************************************************************/
/*
 * Bit position definitions SPI_CR1
 */
#define SPI_CR1_CPHA        0
#define SPI_CR1_CPOL        1
#define SPI_CR1_MSTR        2
#define SPI_CR1_BR          3
#define SPI_CR1_SPE         6
#define SPI_CR1_LSB_FIRST   7
#define SPI_CR1_SSI         8
#define SPI_CR1_SSM         9
#define SPI_CR1_RX_ONLY     10
#define SPI_CR1_DFF         11
#define SPI_CR1_CRC_NEXT    12
#define SPI_CR1_CRC_EN      13
#define SPI_CR1_BIDI_OE     14
#define SPI_CR1_BIDI_MODE   15


/*---------------------------------------------------------------------------
 * 7.6  I2C  (RM0090 Table 126, §27.6.11, p.875)
 *      Applies to: I2C1, I2C2, I2C3
 *---------------------------------------------------------------------------*/
typedef struct
{
    volatile uint32_t CR1;    /*!< I2C control register 1,     Address offset: 0x00 */
    volatile uint32_t CR2;    /*!< I2C control register 2,     Address offset: 0x04 */
    volatile uint32_t OAR1;   /*!< I2C own address register 1, Address offset: 0x08 */
    volatile uint32_t OAR2;   /*!< I2C own address register 2, Address offset: 0x0C */
    volatile uint32_t DR;     /*!< I2C data register,          Address offset: 0x10 */
    volatile uint32_t SR1;    /*!< I2C status register 1,      Address offset: 0x14 */
    volatile uint32_t SR2;    /*!< I2C status register 2,      Address offset: 0x18 */
    volatile uint32_t CCR;    /*!< I2C clock control register, Address offset: 0x1C */
    volatile uint32_t TRISE;  /*!< I2C TRISE register,         Address offset: 0x20 */
    volatile uint32_t FLTR;   /*!< I2C FLTR register,          Address offset: 0x24 */
} I2C_RegDef_t;


/*---------------------------------------------------------------------------
 * 7.7  USART / UART  (RM0090 Table 150, §30.6.8, p.1021)
 *      Applies to: USART1, USART2, USART3, UART4, UART5, USART6
 *---------------------------------------------------------------------------*/
typedef struct
{
    volatile uint32_t SR;    /*!< USART status register,                   Address offset: 0x00 */
    volatile uint32_t DR;    /*!< USART data register,                     Address offset: 0x04 */
    volatile uint32_t BRR;   /*!< USART baud rate register,                Address offset: 0x08 */
    volatile uint32_t CR1;   /*!< USART control register 1,                Address offset: 0x0C */
    volatile uint32_t CR2;   /*!< USART control register 2,                Address offset: 0x10 */
    volatile uint32_t CR3;   /*!< USART control register 3,                Address offset: 0x14 */
    volatile uint32_t GTPR;  /*!< USART guard time and prescaler register, Address offset: 0x18 */
} USART_RegDef_t;


/*===========================================================================
 * 8. PERIPHERAL DECLARATIONS  (pointer-cast to base address)
 *===========================================================================*/

/* GPIO */
#define GPIOA   ((GPIO_RegDef_t *)  GPIOA_BASEADDR)
#define GPIOB   ((GPIO_RegDef_t *)  GPIOB_BASEADDR)
#define GPIOC   ((GPIO_RegDef_t *)  GPIOC_BASEADDR)
#define GPIOD   ((GPIO_RegDef_t *)  GPIOD_BASEADDR)
#define GPIOE   ((GPIO_RegDef_t *)  GPIOE_BASEADDR)
#define GPIOF   ((GPIO_RegDef_t *)  GPIOF_BASEADDR)
#define GPIOG   ((GPIO_RegDef_t *)  GPIOG_BASEADDR)
#define GPIOH   ((GPIO_RegDef_t *)  GPIOH_BASEADDR)
#define GPIOI   ((GPIO_RegDef_t *)  GPIOI_BASEADDR)

/* RCC */
#define RCC     ((RCC_RegDef_t *)   RCC_BASEADDR)

/* EXTI */
#define EXTI    ((EXTI_RegDef_t *)  EXTI_BASEADDR)

/* SYSCFG */
#define SYSCFG  ((SYSCFG_RegDef_t *)SYSCFG_BASEADDR)

/* SPI */
#define SPI1    ((SPI_RegDef_t *)   SPI1_BASEADDR)
#define SPI2    ((SPI_RegDef_t *)   SPI2_BASEADDR)
#define SPI3    ((SPI_RegDef_t *)   SPI3_BASEADDR)
#define SPI4    ((SPI_RegDef_t *)   SPI4_BASEADDR)

/* I2C */
#define I2C1    ((I2C_RegDef_t *)   I2C1_BASEADDR)
#define I2C2    ((I2C_RegDef_t *)   I2C2_BASEADDR)
#define I2C3    ((I2C_RegDef_t *)   I2C3_BASEADDR)

/* USART / UART */
#define USART1  ((USART_RegDef_t *) USART1_BASEADDR)
#define USART2  ((USART_RegDef_t *) USART2_BASEADDR)
#define USART3  ((USART_RegDef_t *) USART3_BASEADDR)
#define UART4   ((USART_RegDef_t *) UART4_BASEADDR)
#define UART5   ((USART_RegDef_t *) UART5_BASEADDR)
#define USART6  ((USART_RegDef_t *) USART6_BASEADDR)


/*===========================================================================
 * 9. RCC CLOCK ENABLE MACROS  (RCC_AHB1ENR / APB1ENR / APB2ENR)
 *    Source: RM0090 §7.3.10, 7.3.13, 7.3.14
 *===========================================================================*/

/* AHB1 — GPIO clock enables */
#define GPIOA_PCLK_EN()     (RCC->AHB1ENR |= (1U << 0))
#define GPIOB_PCLK_EN()     (RCC->AHB1ENR |= (1U << 1))
#define GPIOC_PCLK_EN()     (RCC->AHB1ENR |= (1U << 2))
#define GPIOD_PCLK_EN()     (RCC->AHB1ENR |= (1U << 3))
#define GPIOE_PCLK_EN()     (RCC->AHB1ENR |= (1U << 4))
#define GPIOF_PCLK_EN()     (RCC->AHB1ENR |= (1U << 5))
#define GPIOG_PCLK_EN()     (RCC->AHB1ENR |= (1U << 6))
#define GPIOH_PCLK_EN()     (RCC->AHB1ENR |= (1U << 7))
#define GPIOI_PCLK_EN()     (RCC->AHB1ENR |= (1U << 8))

/* APB1 — I2C clock enables */
#define I2C1_PCLK_EN()      (RCC->APB1ENR |= (1U << 21))
#define I2C2_PCLK_EN()      (RCC->APB1ENR |= (1U << 22))
#define I2C3_PCLK_EN()      (RCC->APB1ENR |= (1U << 23))

/* APB1 — SPI clock enables */
#define SPI2_PCLK_EN()      (RCC->APB1ENR |= (1U << 14))
#define SPI3_PCLK_EN()      (RCC->APB1ENR |= (1U << 15))

/* APB2 — SPI clock enables */
#define SPI1_PCLK_EN()      (RCC->APB2ENR |= (1U << 12))
#define SPI4_PCLK_EN()      (RCC->APB2ENR |= (1U << 13))

/* APB1 — USART/UART clock enables */
#define USART2_PCLK_EN()    (RCC->APB1ENR |= (1U << 17))
#define USART3_PCLK_EN()    (RCC->APB1ENR |= (1U << 18))
#define UART4_PCLK_EN()     (RCC->APB1ENR |= (1U << 19))
#define UART5_PCLK_EN()     (RCC->APB1ENR |= (1U << 20))

/* APB2 — USART clock enables */
#define USART1_PCLK_EN()    (RCC->APB2ENR |= (1U << 4))
#define USART6_PCLK_EN()    (RCC->APB2ENR |= (1U << 5))

/* APB2 — SYSCFG clock enable */
#define SYSCFG_PCLK_EN()    (RCC->APB2ENR |= (1U << 14))


/*===========================================================================
 * 10. RCC CLOCK DISABLE MACROS
 *===========================================================================*/


/*
 * IRQ(Interrupt Request) Numbers of STM32F446x MCU
 * NOTE: Update these macros with valid values according to your MCU
 */
#define IRQ_NO_WWDG                 0   /* Window Watchdog interrupt                                            */
#define IRQ_NO_PVD                  1   /* PVD through EXTI line detection interrupt                            */
#define IRQ_NO_TAMP_STAMP           2   /* Tamper and Time stamp interrupts through EXTI line                   */
#define IRQ_NO_RTC_WKUP             3   /* RTC Wakeup interrupt through EXTI line                               */
#define IRQ_NO_FLASH                4   /* Flash global interrupt                                               */
#define IRQ_NO_RCC                  5   /* RCC global interrupt                                                 */
#define IRQ_NO_EXTI0                6   /* EXTI Line0 interrupt                                                 */
#define IRQ_NO_EXTI1                7   /* EXTI Line1 interrupt                                                 */
#define IRQ_NO_EXTI2                8   /* EXTI Line2 interrupt                                                 */
#define IRQ_NO_EXTI3                9   /* EXTI Line3 interrupt                                                 */
#define IRQ_NO_EXTI4                10  /* EXTI Line4 interrupt                                                 */
#define IRQ_NO_DMA1_STREAM0         11  /* DMA1 Stream0 interrupt                                               */
#define IRQ_NO_DMA1_STREAM1         12  /* DMA1 Stream1 interrupt                                               */
#define IRQ_NO_DMA1_STREAM2         13  /* DMA1 Stream2 interrupt                                               */
#define IRQ_NO_DMA1_STREAM3         14  /* DMA1 Stream3 interrupt                                               */
#define IRQ_NO_DMA1_STREAM4         15  /* DMA1 Stream4 interrupt                                               */
#define IRQ_NO_DMA1_STREAM5         16  /* DMA1 Stream5 interrupt                                               */
#define IRQ_NO_DMA1_STREAM6         17  /* DMA1 Stream6 interrupt                                               */
#define IRQ_NO_ADC                  18  /* ADC1, ADC2 and ADC3 global interrupts                                */
#define IRQ_NO_CAN1_TX              19  /* CAN1 TX interrupts                                                   */
#define IRQ_NO_CAN1_RX0             20  /* CAN1 RX0 interrupts                                                  */
#define IRQ_NO_CAN1_RX1             21  /* CAN1 RX1 interrupts                                                  */
#define IRQ_NO_CAN1_SCE             22  /* CAN1 SCE interrupts                                                  */
#define IRQ_NO_EXTI9_5              23  /* EXTI Line[9:5] interrupts                                            */
#define	IRQ_NO_TIM1_BRK_TIM9        24  /* TIM1 Break interrupt and TIM9 global interrupt                       */
#define	IRQ_NO_TIM1_UP_TIM10        25  /* TIM1 Update interrupt and TIM10 global interrupt                     */
#define IRQ_NO_TIM1_TRG_COM_TIM11   26  /* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt   */
#define IRQ_NO_TIM1_CC              27  /* TIM1 Capture Compare interrupt                                       */
#define IRQ_NO_TIM2                 28  /* TIM2 global interrupt                                                */
#define IRQ_NO_TIM3                 29  /* TIM3 global interrupt                                                */
#define IRQ_NO_TIM4                 30  /* TIM4 global interrupt                                                */
#define IRQ_NO_I2C1_EV              31  /* I2C1 event interrupt                                                 */
#define IRQ_NO_I2C1_ER              32  /* I2C1 error interrupt                                                 */
#define IRQ_NO_I2C2_EV              33  /* I2C2 event interrupt                                                 */
#define IRQ_NO_I2C2_ER              34  /* I2C2 error interrupt                                                 */
#define IRQ_NO_SPI1                 35  /* SPI1 global interrupt                                                */
#define IRQ_NO_SPI2                 36  /* SPI2 global interrupt                                                */
#define IRQ_NO_USART1               37  /* USART1 global interrupt                                              */
#define IRQ_NO_USART2               38  /* USART2 global interrupt                                              */
#define IRQ_NO_USART3               39  /* USART3 global interrupt                                              */
#define IRQ_NO_EXTI15_10            40  /* EXTI Line[15:10] interrupts                                          */
#define IRQ_NO_RTC_ALARM            41  /* RTC Alarms (A and B) through EXTI line interrupts                    */
#define IRQ_NO_OTG_FS_WKUP          42  /* USB On-The-Go FS Wakeup through EXTI line interrupt                  */
#define IRQ_NO_TIM8_BRK_TIM12       43  /* TIM8 Break interrupt and TIM12 global interrupt                      */
#define IRQ_NO_TIM8_UP_TIM13        44  /* TIM8 Update and TIM13 global interrupt                               */
#define IRQ_NO_TIM8_TRG_COM_TIM14   45  /* TIM8 Trigger and Commutation interrupts and TIM14 global interrupt   */
#define IRQ_NO_TIM8_CC              46  /* TIM8 Capture Compare interrupt                                       */
#define IRQ_NO_DMA1_STREAM7         47  /* DMA1 Stream7 global interrupt                                        */
#define IRQ_NO_FMC                  48  /* FMC global interrupt                                                 */
#define IRQ_NO_SDIO                 49  /* SDIO global interrupt                                                */
#define IRQ_NO_TIM5                 50  /* TIM5 global interrupt                                                */
#define IRQ_NO_SPI3                 51  /* SPI3 global interrupt                                                */
#define IRQ_NO_UART4                52  /* UART4 global interrupt                                               */
#define IRQ_NO_UART5                53  /* UART5 global interrupt                                               */
#define IRQ_NO_TIM6_DAC             54  /* TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts       */
#define IRQ_NO_TIM7                 55  /* TIM7 global interrupt                                                */
#define IRQ_NO_DMA2_STREAM0         56  /* DMA2 Stream0 global interrupt                                        */
#define IRQ_NO_DMA2_STREAM1         57  /* DMA2 Stream1 global interrupt                                        */
#define IRQ_NO_DMA2_STREAM2         58  /* DMA2 Stream2 global interrupt                                        */
#define IRQ_NO_DMA2_STREAM3         59  /* DMA2 Stream3 global interrupt                                        */
#define IRQ_NO_DMA2_STREAM4         60  /* DMA2 Stream4 global interrupt                                        */
#define IRQ_NO_CAN2_TX              63  /* CAN2 TX interrupts                                                   */
#define IRQ_NO_CAN2_RX0             64  /* CAN2 RX0 interrupts                                                  */
#define IRQ_NO_CAN2_RX1             65  /* CAN2 RX1 interrupts                                                  */
#define IRQ_NO_CAN2_SCE             66  /* CAN2 SCE interrupts                                                  */
#define IRQ_NO_CAN2_OTG             67  /* USB On The Go FS global interrupt                                    */
#define IRQ_NO_DMA2_STREAM5         68  /* DMA2 Stream5 global interrupt                                        */
#define IRQ_NO_DMA2_STREAM6         69  /* DMA2 Stream6 global interrupt                                        */
#define IRQ_NO_DMA2_STREAM7         70  /* DMA2 Stream7 global interrupt                                        */
#define IRQ_NO_USART6               71  /* USART6 global interrupt                                              */
#define IRQ_NO_I2C3_EV              72  /* I2C3 event interrupt                                                 */
#define IRQ_NO_I2C3_ER              73  /* I2C3 error interrupt                                                 */
#define IRQ_NO_OTG_HS_EP1_OUT       74  /* USB On The Go HS End Point 1 Out global interrupt                    */
#define IRQ_NO_OTG_HS_EP1_IN        75  /* USB On The Go HS End Point 1 In global interrupt                     */
#define IRQ_NO_OTG_HS_WKUP          76  /* USB On The Go HS Wakeup through EXTI interrupt                       */
#define IRQ_NO_OTG_HS               77  /* USB On The Go HS global interrupt                                    */
#define IRQ_NO_DCMI                 78  /* DCMI global interrupt                                                */
#define IRQ_NO_FPU                  81  /* FPU global interrupt                                                 */
#define IRQ_NO_SPI4                 84  /* SPI4 global interrupt                                                */
#define IRQ_NO_SAI1                 87  /* SAI1 global interrupt                                                */
#define IRQ_NO_SAI2                 91  /* SAI2 global interrupt                                                */
#define IRQ_NO_QUADSPI              92  /* QuadSPI global interrupt                                             */
#define IRQ_NO_HDMI_CEC             93  /* HDMI-CEC global interrupt                                            */
#define IRQ_NO_SPDIF_RX             94  /* SPDIF-Rx global interrupt                                            */
#define IRQ_NO_FMPI2C1_EV           95  /* FMPI2C1 event interrupt                                              */
#define IRQ_NO_FMPI2C1_ER           96  /* FMPI2C1 error interrupt                                              */



/* AHB1 — GPIO clock disables */
#define GPIOA_PCLK_DI()     (RCC->AHB1ENR &= ~(1U << 0))
#define GPIOB_PCLK_DI()     (RCC->AHB1ENR &= ~(1U << 1))
#define GPIOC_PCLK_DI()     (RCC->AHB1ENR &= ~(1U << 2))
#define GPIOD_PCLK_DI()     (RCC->AHB1ENR &= ~(1U << 3))
#define GPIOE_PCLK_DI()     (RCC->AHB1ENR &= ~(1U << 4))
#define GPIOF_PCLK_DI()     (RCC->AHB1ENR &= ~(1U << 5))
#define GPIOG_PCLK_DI()     (RCC->AHB1ENR &= ~(1U << 6))
#define GPIOH_PCLK_DI()     (RCC->AHB1ENR &= ~(1U << 7))
#define GPIOI_PCLK_DI()     (RCC->AHB1ENR &= ~(1U << 8))

/* APB1 — I2C clock disables */
#define I2C1_PCLK_DI()      (RCC->APB1ENR &= ~(1U << 21))
#define I2C2_PCLK_DI()      (RCC->APB1ENR &= ~(1U << 22))
#define I2C3_PCLK_DI()      (RCC->APB1ENR &= ~(1U << 23))

/* APB1 — SPI clock disables */
#define SPI2_PCLK_DI()      (RCC->APB1ENR &= ~(1U << 14))
#define SPI3_PCLK_DI()      (RCC->APB1ENR &= ~(1U << 15))

/* APB2 — SPI clock disables */
#define SPI1_PCLK_DI()      (RCC->APB2ENR &= ~(1U << 12))
#define SPI4_PCLK_DI()      (RCC->APB2ENR &= ~(1U << 13))

/* APB1 — USART/UART clock disables */
#define USART2_PCLK_DI()    (RCC->APB1ENR &= ~(1U << 17))
#define USART3_PCLK_DI()    (RCC->APB1ENR &= ~(1U << 18))
#define UART4_PCLK_DI()     (RCC->APB1ENR &= ~(1U << 19))
#define UART5_PCLK_DI()     (RCC->APB1ENR &= ~(1U << 20))

/* APB2 — USART clock disables */
#define USART1_PCLK_DI()    (RCC->APB2ENR &= ~(1U << 4))
#define USART6_PCLK_DI()    (RCC->APB2ENR &= ~(1U << 5))

/* APB2 — SYSCFG clock disable */
#define SYSCFG_PCLK_DI()    (RCC->APB2ENR &= ~(1U << 14))


/*===========================================================================
 * 11. GPIO PERIPHERAL RESET MACROS  (via RCC_AHB1RSTR)
 *     Usage: call the macro, then clear the reset bit immediately after.
 *===========================================================================*/
#define GPIOA_REG_RESET()   do { (RCC->AHB1RSTR |= (1U << 0)); (RCC->AHB1RSTR &= ~(1U << 0)); } while(0)
#define GPIOB_REG_RESET()   do { (RCC->AHB1RSTR |= (1U << 1)); (RCC->AHB1RSTR &= ~(1U << 1)); } while(0)
#define GPIOC_REG_RESET()   do { (RCC->AHB1RSTR |= (1U << 2)); (RCC->AHB1RSTR &= ~(1U << 2)); } while(0)
#define GPIOD_REG_RESET()   do { (RCC->AHB1RSTR |= (1U << 3)); (RCC->AHB1RSTR &= ~(1U << 3)); } while(0)
#define GPIOE_REG_RESET()   do { (RCC->AHB1RSTR |= (1U << 4)); (RCC->AHB1RSTR &= ~(1U << 4)); } while(0)
#define GPIOF_REG_RESET()   do { (RCC->AHB1RSTR |= (1U << 5)); (RCC->AHB1RSTR &= ~(1U << 5)); } while(0)
#define GPIOG_REG_RESET()   do { (RCC->AHB1RSTR |= (1U << 6)); (RCC->AHB1RSTR &= ~(1U << 6)); } while(0)
#define GPIOH_REG_RESET()   do { (RCC->AHB1RSTR |= (1U << 7)); (RCC->AHB1RSTR &= ~(1U << 7)); } while(0)
#define GPIOI_REG_RESET()   do { (RCC->AHB1RSTR |= (1U << 8)); (RCC->AHB1RSTR &= ~(1U << 8)); } while(0)


/*===========================================================================
 * 12. GENERIC UTILITY MACROS
 *===========================================================================*/
#define ENABLE          1
#define DISABLE         0
#define SET             ENABLE
#define RESET           DISABLE
#define GPIO_PIN_SET    SET
#define GPIO_PIN_RESET  RESET
#define FLAG_SET        SET
#define FLAG_RESET      RESET

#endif /* STM32407XX_H_ */
