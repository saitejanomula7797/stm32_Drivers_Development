/*
 * stm32f407xx_spi_drivers.h
 *
 *  Created on: Jun 13, 2026
 *      Author: nomul
 */

#ifndef INC_STM32F407XX_SPI_DRIVERS_H_
#define INC_STM32F407XX_SPI_DRIVERS_H_


#include "stm32407xx.h"

/*
 * Configuration structure for SPIx peripheral
 */
typedef struct
{
    uint8_t SPI_DeviceMode;
    uint8_t SPI_BusConfig;
    uint8_t SPI_SclkSpeed;
    uint8_t SPI_DFF;
    uint8_t SPI_CPOL;
    uint8_t SPI_CPHA;
    uint8_t SPI_SSM;
}SPI_Config_t;


/*
 * Handle structure for SPIx peripheral
 */
typedef struct
{
    SPI_RegDef_t *pSPIx;        /* This holds the base address of SPIx(x:0,1,2) peripheral */
    SPI_Config_t SPIConfig;
    uint8_t      *pTxBuffer;    /* Store application Tx buffer address                     */
    uint8_t      *pRxBuffer;    /* Store application Rx buffer address                     */
    uint32_t     TxLen;         /* Store Tx length                                         */
    uint32_t     RxLen;         /* Store Rx length                                         */
    uint32_t     TxState;       /* Store Tx state                                          */
    uint32_t     RxState;       /* Store Rx state                                          */
}SPI_Handle_t;


/*
 * @SPI_DeviceMode
 */
#define SPI_DEVICE_MODE_MASTER      1
#define SPI_DEVICE_MODE_SLAVE       0


/*
 * @SPI_BusConfig
 */
#define SPI_BUS_CONFIG_FD               1 /* SPI Full-duplex bus configuration          */
#define SPI_BUS_CONFIG_HD               2 /* SPI Half-duplex bus configuration          */
#define SPI_BUS_CONFIG_SIMPLEX_RX_ONLY  3 /* SPI Simplex bux receive only configuration */


/*
 * @SPI_SclkSpeed
 */
#define SPI_SCLK_SPEED_DIV2         0 /* Baud rate control: fPCLK/2   */
#define SPI_SCLK_SPEED_DIV4         1 /* Baud rate control: fPCLK/4   */
#define SPI_SCLK_SPEED_DIV8         2 /* Baud rate control: fPCLK/8   */
#define SPI_SCLK_SPEED_DIV16        3 /* Baud rate control: fPCLK/16  */
#define SPI_SCLK_SPEED_DIV32        4 /* Baud rate control: fPCLK/32  */
#define SPI_SCLK_SPEED_DIV64        5 /* Baud rate control: fPCLK/64  */
#define SPI_SCLK_SPEED_DIV128       6 /* Baud rate control: fPCLK/128 */
#define SPI_SCLK_SPEED_DIV256       7 /* Baud rate control: fPCLK/256 */



/*
 * @SPI_DFF
 */
#define SPI_DFF_8BITS       0 /* 8-bit DFF is selected for transmission/reception  */
#define SPI_DFF_16BITS      1 /* 16-bit DFF is selected for transmission/reception */






/*
 * @SPI_CPOL
 */
#define SPI_CPOL_HIGH       1 /* Clock polarity to 1 when IDLE */
#define SPI_CPOL_LOW        0 /* Clock polarity to 0 when IDLE */

/*
 * @SPI_CPHA
 */
#define SPI_CPHA_HIGH       1 /* Second clock transition <=> First data capture edge */
#define SPI_CPHA_LOW        0 /* First clock transition <=> First data capture edge  */


/*
 * Bit position definitions SPI_SR
 */
#define SPI_SR_RXNE         0
#define SPI_SR_TXE          1
#define SPI_SR_CHSIDE       2
#define SPI_SR_UDR          3
#define SPI_SR_CRC_ERR      4
#define SPI_SR_MODF         5
#define SPI_SR_OVR          6
#define SPI_SR_BSY          7
#define SPI_SR_FRE          8

#endif /* INC_STM32F407XX_SPI_DRIVERS_H_ */
