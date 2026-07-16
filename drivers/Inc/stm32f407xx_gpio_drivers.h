/*
 * stm32f407xx_gpio_drivers.h
 *
 *  Created on: Jun 5, 2026
 *      Author: nomul
 */

#ifndef INC_STM32F407XX_GPIO_DRIVERS_H_
#define INC_STM32F407XX_GPIO_DRIVERS_H_

#include "stm32407xx.h"

typedef struct
{
    uint8_t GPIO_PinNumber; //Specifies which pin of the GPIO port to configure (0–15).
    uint8_t GPIO_PinMode;   // 00-> Input ;01 → General purpose output;10 → Alternate function;11 → Analog mode
    uint8_t GPIO_PinSpeed;  //00 → Low speed;01 → Medium speed 10 → High speed 11 → Very high speed
    uint8_t GPIO_PinPuPdControl; //00 → No pull-up, no pull-down 01 → Pull-up 10 → Pull-down
    uint8_t GPIO_PinOPType;
    uint8_t GPIO_PinAltFunMode;
} GPIO_PinConfig_t;



typedef struct
{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_Pinconfig;
}GPIO_Handle_t;


/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0       0
#define GPIO_PIN_NO_1       1
#define GPIO_PIN_NO_2       2
#define GPIO_PIN_NO_3       3
#define GPIO_PIN_NO_4       4
#define GPIO_PIN_NO_5       5
#define GPIO_PIN_NO_6       6
#define GPIO_PIN_NO_7       7
#define GPIO_PIN_NO_8       8
#define GPIO_PIN_NO_9       9
#define GPIO_PIN_NO_10      10
#define GPIO_PIN_NO_11      11
#define GPIO_PIN_NO_12      12
#define GPIO_PIN_NO_13      13
#define GPIO_PIN_NO_14      14



/*
 * GPIO pin possible modes
 */
#define GPIO_MODE_IN        0
#define GPIO_MODE_OUT       1
#define GPIO_MODE_ALTFN     2
#define GPIO_MODE_ANALOG    3
#define GPIO_MODE_IT_FT     4
#define GPIO_MODE_IT_RT     5
#define GPIO_MODE_IT_RFT    6




/*
 * @GPIO_PIN_OUTPUT_TYPE
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP     0 /* GPIO Output type push-pull mode  */
#define GPIO_OP_TYPE_OD     1 /* GPIO Output type open-drain mode */


/*
 * Data read and write
 */
uint8_t  GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void     GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void     GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void     GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);


#endif /* INC_STM32F407XX_GPIO_DRIVERS_H_ */
