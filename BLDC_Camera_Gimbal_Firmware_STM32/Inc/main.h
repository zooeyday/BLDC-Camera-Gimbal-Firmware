/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

typedef struct EulerAngles_t
{
	float pitch;
	float yaw;
	float roll;
} EulerAngles_t;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

#ifdef DEBUG
	#define ASSERT_PRINT(__cond__, __str__) 	do { if ( !(__cond__) ){ printf(__str__); while(1); } } while(0)
#else
	#define ASSERT_PRINT(__cond__, __str__)		((void)0)
#endif
/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MOTOR1_IN1_Pin GPIO_PIN_0
#define MOTOR1_IN1_GPIO_Port GPIOC
#define MOTOR1_IN2_Pin GPIO_PIN_1
#define MOTOR1_IN2_GPIO_Port GPIOC
#define MOTOR1_IN3_Pin GPIO_PIN_2
#define MOTOR1_IN3_GPIO_Port GPIOC
#define CURR_MON_5V_Pin GPIO_PIN_3
#define CURR_MON_5V_GPIO_Port GPIOC
#define RC_PITCH_IN_Pin GPIO_PIN_0
#define RC_PITCH_IN_GPIO_Port GPIOA
#define CURR_MON_12V_Pin GPIO_PIN_1
#define CURR_MON_12V_GPIO_Port GPIOA
#define UART_TX_Pin GPIO_PIN_2
#define UART_TX_GPIO_Port GPIOA
#define UART_RX_Pin GPIO_PIN_3
#define UART_RX_GPIO_Port GPIOA
#define MOTOR2_IN2_Pin GPIO_PIN_4
#define MOTOR2_IN2_GPIO_Port GPIOA
#define MOTOR2_IN1_Pin GPIO_PIN_6
#define MOTOR2_IN1_GPIO_Port GPIOA
#define MOTOR2_EN1_Pin GPIO_PIN_7
#define MOTOR2_EN1_GPIO_Port GPIOA
#define MOTOR2_IN3_Pin GPIO_PIN_0
#define MOTOR2_IN3_GPIO_Port GPIOB
#define MOTOR1_EN1_Pin GPIO_PIN_1
#define MOTOR1_EN1_GPIO_Port GPIOB
#define MOTOR1_EN3_Pin GPIO_PIN_2
#define MOTOR1_EN3_GPIO_Port GPIOB
#define MOTOR2_NRESET_Pin GPIO_PIN_10
#define MOTOR2_NRESET_GPIO_Port GPIOB
#define AXIS_IMU_INT_Pin GPIO_PIN_12
#define AXIS_IMU_INT_GPIO_Port GPIOB
#define AXIS_IMU_INT_EXTI_IRQn EXTI15_10_IRQn
#define MOTOR1_NFAULT_Pin GPIO_PIN_13
#define MOTOR1_NFAULT_GPIO_Port GPIOB
#define RC_MODE_IN_Pin GPIO_PIN_14
#define RC_MODE_IN_GPIO_Port GPIOB
#define RC_YAW_IN_Pin GPIO_PIN_6
#define RC_YAW_IN_GPIO_Port GPIOC
#define MOTOR2_EN3_Pin GPIO_PIN_7
#define MOTOR2_EN3_GPIO_Port GPIOC
#define BASE_IMU_INT_Pin GPIO_PIN_8
#define BASE_IMU_INT_GPIO_Port GPIOC
#define MOTOR3_NRESET_Pin GPIO_PIN_9
#define MOTOR3_NRESET_GPIO_Port GPIOC
#define MOTOR2_NFAULT_Pin GPIO_PIN_8
#define MOTOR2_NFAULT_GPIO_Port GPIOA
#define MOTOR3_IN1_Pin GPIO_PIN_11
#define MOTOR3_IN1_GPIO_Port GPIOA
#define MOTOR3_IN2_Pin GPIO_PIN_12
#define MOTOR3_IN2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define MOTOR3_EN3_Pin GPIO_PIN_10
#define MOTOR3_EN3_GPIO_Port GPIOC
#define MOTOR3_EN2_Pin GPIO_PIN_11
#define MOTOR3_EN2_GPIO_Port GPIOC
#define MOTOR3_EN1_Pin GPIO_PIN_2
#define MOTOR3_EN1_GPIO_Port GPIOD
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define MOTOR1_EN2_Pin GPIO_PIN_4
#define MOTOR1_EN2_GPIO_Port GPIOB
#define MOTOR1_NRESET_Pin GPIO_PIN_5
#define MOTOR1_NRESET_GPIO_Port GPIOB
#define MOTOR2_EN2_Pin GPIO_PIN_6
#define MOTOR2_EN2_GPIO_Port GPIOB
#define MOTOR3_IN3_Pin GPIO_PIN_8
#define MOTOR3_IN3_GPIO_Port GPIOB
#define MOTOR3_NFAULT_Pin GPIO_PIN_9
#define MOTOR3_NFAULT_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

// IMU GLOBAL CONFIGS
#define IMU_I2C_CHANNEL			hi2c2
#define AXIS_IMU_ADDR			(0x68)
#define BASE_IMU_ADDR			(0x69)
#define IMU_DMP_FIFO_OUTPUT_RATE (1) // HZ: min 1, max 200
#define AXIS_IMU_EXTI_LINE		EXTI15_10_IRQn


// ENCODER GLOBAL CONFIGS
#define ENCODER_I2C_CHANNEL		hi2c1

// CONTROL LOOP GLOBAL CONFIGS
#define ENABLED(__mode__)		((__mode__) == 1)
#define DISABLED(__mode__)		((__mode__) == 0)

#define MODE_2AXIS				(1)
#define MODE_3AXIS				(0)

#if MODE_2AXIS == MODE_3AXIS
#error Gimbal cannot be in both 3-axis mode and 2-axis mode simultaneously; choose ONE!
#endif

// if in MODE_2AXIS, which 2 axes are being used?
#if ENABLED(MODE_2AXIS)
#define MODE_2AXIS_PITCH_ROLL		(1)
#define MODE_2AXIS_PITCH_YAW		(0)
#define MODE_2AXIS_YAW_ROLL			(0)
#endif


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
