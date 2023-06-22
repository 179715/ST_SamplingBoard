/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* �û�LED GPIO���� */
#define USERLED_PIN	        LL_GPIO_PIN_13
#define USERLED_GPIO        GPIOC

/* �û����� GPIO���� */
#define USERKEY_PIN	        LL_GPIO_PIN_0
#define USERKEY_GPIO        GPIOA

/* ��ѡͨ���� GPIO���� */
#define GATE_C0_PIN         LL_GPIO_PIN_3
#define GATE_C0_GPIO        GPIOB
#define GATE_C1_PIN         LL_GPIO_PIN_15
#define GATE_C1_GPIO        GPIOA
#define GATE_C2_PIN         LL_GPIO_PIN_0
#define GATE_C2_GPIO        GPIOB

/* ��ѡͨ���� GPIO���� */
#define GATE_R0_PIN         LL_GPIO_PIN_1
#define GATE_R0_GPIO        GPIOB
#define GATE_R1_PIN         LL_GPIO_PIN_10
#define GATE_R1_GPIO        GPIOB
#define GATE_R2_PIN         LL_GPIO_PIN_12
#define GATE_R2_GPIO        GPIOB
#define GATE_R3_PIN         LL_GPIO_PIN_14
#define GATE_R3_GPIO        GPIOB
#define GATE_R4_PIN         LL_GPIO_PIN_15
#define GATE_R4_GPIO        GPIOB
#define GATE_R5_PIN         LL_GPIO_PIN_6
#define GATE_R5_GPIO        GPIOB

/* ѡͨ��ʹ�� GPIO���� */
#define EN_INH1_PIN         LL_GPIO_PIN_5
#define EN_INH1_GPIO        GPIOB
#define EN_INH2_PIN         LL_GPIO_PIN_4
#define EN_INH2_GPIO        GPIOB
#define EN_INH3_PIN         LL_GPIO_PIN_8
#define EN_INH3_GPIO        GPIOA

/* ��������ѡͨ������ GPIO */
#define MUX_GPIOA           GPIOA
#define MUX_PINA            LL_GPIO_PIN_8|LL_GPIO_PIN_15
#define MUX_GPIOB           GPIOB
#define MUX_PINB            LL_GPIO_PIN_1|LL_GPIO_PIN_3|LL_GPIO_PIN_4 |LL_GPIO_PIN_5|LL_GPIO_PIN_6|LL_GPIO_PIN_8|\
                            LL_GPIO_PIN_10|LL_GPIO_PIN_12|LL_GPIO_PIN_14|LL_GPIO_PIN_15
/* LED�Ƶ�ƽ��ת */
#define LED_Toggle()        LL_GPIO_TogglePin(USERLED_GPIO,USERLED_PIN)

/* USER CODE END Private defines */
/**
 * @brief LED_SetPin ����LED���ŵ�ƽ
 * @param bool pin  ���ŵ�ƽ
 */
static inline void LED_SetPin(bool pin)
{
    WRITE_REG(USERLED_GPIO->BSRR, (USERLED_PIN << 16 * pin));
}
/**
 * @brief MUX_SetPin ���ö�·�������������ŵ�ƽ
 * @param PIO_TypeDef *GPIOx  GPIO
 * @param uint32_t PinMask  �������
 * @param bool pin  ���ŵ�ƽ
 */
static inline void MUX_SetPin(GPIO_TypeDef *GPIOx, uint32_t PinMask, bool pin)
{
    WRITE_REG(GPIOx->BSRR, (PinMask << 16 * pin));
}

void MX_GPIO_Init(void);    //GPIO��ʼ��

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */
