#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "config.h"
#include "uart.h"
#include "gpio.h"
#include "pit.h"
#define DEV_PLMT             AE250_PLMT
#define DEV_DMA              AE250_DMA
#define DEV_SMU              AE250_SMU
#define DEV_UART1            AE250_UART1
#define DEV_UART2            AE250_UART2
#define DEV_PIT              AE250_PIT
#define DEV_RTC              AE250_RTC
#define DEV_GPIO             AE250_GPIO
#define DEV_I2C              AE250_I2C
#define DEV_SPI1             AE250_SPI1
#define DEV_SPI2             AE250_SPI2
#define DEV_L2C              AE250_L2C

/*****************************************************************************
 * Board specified
 ****************************************************************************/
#define GPIO_USED_MASK       0x7F    /* Which GPIOs to use */

#ifdef __cplusplus
}
#endif

#endif	/* __PLATFORM_H__ */
