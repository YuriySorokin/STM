/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_dma.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define REG_INPUT_START 1000
#define REG_INPUT_NREGS 8





/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Signal_Pin LL_GPIO_PIN_2
#define Signal_GPIO_Port GPIOE
#define Echo_Pin LL_GPIO_PIN_4
#define Echo_GPIO_Port GPIOE
#define PC14_OSC32_IN_Pin LL_GPIO_PIN_14
#define PC14_OSC32_IN_GPIO_Port GPIOC
#define PC15_OSC32_OUT_Pin LL_GPIO_PIN_15
#define PC15_OSC32_OUT_GPIO_Port GPIOC
#define LCD_on_Pin LL_GPIO_PIN_4
#define LCD_on_GPIO_Port GPIOF
#define SPI5_SCK_Pin LL_GPIO_PIN_7
#define SPI5_SCK_GPIO_Port GPIOF
#define SPI5_MISO_Pin LL_GPIO_PIN_8
#define SPI5_MISO_GPIO_Port GPIOF
#define SPI5_MOSI_Pin LL_GPIO_PIN_9
#define SPI5_MOSI_GPIO_Port GPIOF
#define PH0_OSC_IN_Pin LL_GPIO_PIN_0
#define PH0_OSC_IN_GPIO_Port GPIOH
#define PH1_OSC_OUT_Pin LL_GPIO_PIN_1
#define PH1_OSC_OUT_GPIO_Port GPIOH
#define NCS_MEMS_SPI_Pin LL_GPIO_PIN_1
#define NCS_MEMS_SPI_GPIO_Port GPIOC
#define CS_Pin LL_GPIO_PIN_2
#define CS_GPIO_Port GPIOC
#define button_Pin LL_GPIO_PIN_0
#define button_GPIO_Port GPIOA
#define button_EXTI_IRQn EXTI0_IRQn
#define MEMS_INT1_Pin LL_GPIO_PIN_1
#define MEMS_INT1_GPIO_Port GPIOA
#define VSYNC_Pin LL_GPIO_PIN_4
#define VSYNC_GPIO_Port GPIOA
#define G2_Pin LL_GPIO_PIN_6
#define G2_GPIO_Port GPIOA
#define ACP_RST_Pin LL_GPIO_PIN_7
#define ACP_RST_GPIO_Port GPIOA
#define OTG_FS_PSO_Pin LL_GPIO_PIN_4
#define OTG_FS_PSO_GPIO_Port GPIOC
#define OTG_FS_OC_Pin LL_GPIO_PIN_5
#define OTG_FS_OC_GPIO_Port GPIOC
#define R6_Pin LL_GPIO_PIN_1
#define R6_GPIO_Port GPIOB
#define BOOT1_Pin LL_GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB
#define SDNRAS_Pin LL_GPIO_PIN_11
#define SDNRAS_GPIO_Port GPIOF
#define A6_Pin LL_GPIO_PIN_12
#define A6_GPIO_Port GPIOF
#define A7_Pin LL_GPIO_PIN_13
#define A7_GPIO_Port GPIOF
#define A8_Pin LL_GPIO_PIN_14
#define A8_GPIO_Port GPIOF
#define A9_Pin LL_GPIO_PIN_15
#define A9_GPIO_Port GPIOF
#define A10_Pin LL_GPIO_PIN_0
#define A10_GPIO_Port GPIOG
#define A11_Pin LL_GPIO_PIN_1
#define A11_GPIO_Port GPIOG
#define D4_Pin LL_GPIO_PIN_7
#define D4_GPIO_Port GPIOE
#define D5_Pin LL_GPIO_PIN_8
#define D5_GPIO_Port GPIOE
#define D6_Pin LL_GPIO_PIN_9
#define D6_GPIO_Port GPIOE
#define D7_Pin LL_GPIO_PIN_10
#define D7_GPIO_Port GPIOE
#define D8_Pin LL_GPIO_PIN_11
#define D8_GPIO_Port GPIOE
#define D9_Pin LL_GPIO_PIN_12
#define D9_GPIO_Port GPIOE
#define D10_Pin LL_GPIO_PIN_13
#define D10_GPIO_Port GPIOE
#define D11_Pin LL_GPIO_PIN_14
#define D11_GPIO_Port GPIOE
#define D12_Pin LL_GPIO_PIN_15
#define D12_GPIO_Port GPIOE
#define G4_Pin LL_GPIO_PIN_10
#define G4_GPIO_Port GPIOB
#define G5_Pin LL_GPIO_PIN_11
#define G5_GPIO_Port GPIOB
#define OTG_HS_ID_Pin LL_GPIO_PIN_12
#define OTG_HS_ID_GPIO_Port GPIOB
#define VBUS_HS_Pin LL_GPIO_PIN_13
#define VBUS_HS_GPIO_Port GPIOB
#define OTG_HS_DM_Pin LL_GPIO_PIN_14
#define OTG_HS_DM_GPIO_Port GPIOB
#define OTG_HS_DP_Pin LL_GPIO_PIN_15
#define OTG_HS_DP_GPIO_Port GPIOB
#define D13_Pin LL_GPIO_PIN_8
#define D13_GPIO_Port GPIOD
#define D14_Pin LL_GPIO_PIN_9
#define D14_GPIO_Port GPIOD
#define D15_Pin LL_GPIO_PIN_10
#define D15_GPIO_Port GPIOD
#define TE_Pin LL_GPIO_PIN_11
#define TE_GPIO_Port GPIOD
#define RDX_Pin LL_GPIO_PIN_12
#define RDX_GPIO_Port GPIOD
#define WRX_Pin LL_GPIO_PIN_13
#define WRX_GPIO_Port GPIOD
#define D0_Pin LL_GPIO_PIN_14
#define D0_GPIO_Port GPIOD
#define D1_Pin LL_GPIO_PIN_15
#define D1_GPIO_Port GPIOD
#define BA0_Pin LL_GPIO_PIN_4
#define BA0_GPIO_Port GPIOG
#define BA1_Pin LL_GPIO_PIN_5
#define BA1_GPIO_Port GPIOG
#define R7_Pin LL_GPIO_PIN_6
#define R7_GPIO_Port GPIOG
#define DOTCLK_Pin LL_GPIO_PIN_7
#define DOTCLK_GPIO_Port GPIOG
#define SDCLK_Pin LL_GPIO_PIN_8
#define SDCLK_GPIO_Port GPIOG
#define HSYNC_Pin LL_GPIO_PIN_6
#define HSYNC_GPIO_Port GPIOC
#define G6_Pin LL_GPIO_PIN_7
#define G6_GPIO_Port GPIOC
#define I2C3_SDA_Pin LL_GPIO_PIN_9
#define I2C3_SDA_GPIO_Port GPIOC
#define I2C3_SCL_Pin LL_GPIO_PIN_8
#define I2C3_SCL_GPIO_Port GPIOA
#define STLINK_RX_Pin LL_GPIO_PIN_9
#define STLINK_RX_GPIO_Port GPIOA
#define STLINK_TX_Pin LL_GPIO_PIN_10
#define STLINK_TX_GPIO_Port GPIOA
#define R4_Pin LL_GPIO_PIN_11
#define R4_GPIO_Port GPIOA
#define R5_Pin LL_GPIO_PIN_12
#define R5_GPIO_Port GPIOA
#define SWDIO_Pin LL_GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin LL_GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define TP_INT1_Pin LL_GPIO_PIN_15
#define TP_INT1_GPIO_Port GPIOA
#define R2_Pin LL_GPIO_PIN_10
#define R2_GPIO_Port GPIOC
#define D2_Pin LL_GPIO_PIN_0
#define D2_GPIO_Port GPIOD
#define D3_Pin LL_GPIO_PIN_1
#define D3_GPIO_Port GPIOD
#define G7_Pin LL_GPIO_PIN_3
#define G7_GPIO_Port GPIOD
#define B2_Pin LL_GPIO_PIN_6
#define B2_GPIO_Port GPIOD
#define G3_Pin LL_GPIO_PIN_10
#define G3_GPIO_Port GPIOG
#define B3_Pin LL_GPIO_PIN_11
#define B3_GPIO_Port GPIOG
#define B4_Pin LL_GPIO_PIN_12
#define B4_GPIO_Port GPIOG
#define LD3_Pin LL_GPIO_PIN_13
#define LD3_GPIO_Port GPIOG
#define LD4_Pin LL_GPIO_PIN_14
#define LD4_GPIO_Port GPIOG
#define SDNCAS_Pin LL_GPIO_PIN_15
#define SDNCAS_GPIO_Port GPIOG
#define SDCKE1_Pin LL_GPIO_PIN_5
#define SDCKE1_GPIO_Port GPIOB
#define SDNE1_Pin LL_GPIO_PIN_6
#define SDNE1_GPIO_Port GPIOB
#define B6_Pin LL_GPIO_PIN_8
#define B6_GPIO_Port GPIOB
#define B7_Pin LL_GPIO_PIN_9
#define B7_GPIO_Port GPIOB
#define NBL0_Pin LL_GPIO_PIN_0
#define NBL0_GPIO_Port GPIOE
#define NBL1_Pin LL_GPIO_PIN_1
#define NBL1_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
