/*
 * testMotor.c
 *
 *  Created on: May 27, 2025
 *      Author: Dell
 */


#include "testMotor.h"

extern TIM_HandleTypeDef htim8;

#define M1_DIR_PORT GPIOC
#define M1_DIR_PIN  GPIO_PIN_13
#define M2_DIR_PORT GPIOC
#define M2_DIR_PIN  GPIO_PIN_14

void Motor_Init(void) {
    HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_3);  // M2
    HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_4);  // M1
}

void Motor_SetSpeed(uint8_t motor_id, uint8_t speed_percent) {
    uint32_t period = __HAL_TIM_GET_AUTORELOAD(&htim8);
    uint32_t pulse = speed_percent * period / 100;

    if (motor_id == 1) {
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_4, pulse); // M1: PC9
    } else if (motor_id == 2) {
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_3, pulse); // M2: PC8
    }
}

void Motor_SetDirection(uint8_t motor_id, uint8_t direction) {
    if (motor_id == 1) {
        HAL_GPIO_WritePin(M1_DIR_PORT, M1_DIR_PIN, direction);
    } else if (motor_id == 2) {
        HAL_GPIO_WritePin(M2_DIR_PORT, M2_DIR_PIN, direction);
    }
}

void Motor_Test(void) {
    // Quay motor 1 thuận 70%
    Motor_SetDirection(1, 0);
    Motor_SetSpeed(1, 70);
    HAL_Delay(2000);

    // Quay ngược 50%
    Motor_SetDirection(1, 1);
    Motor_SetSpeed(1, 50);
    HAL_Delay(2000);

    Motor_SetSpeed(1, 0); // Dừng
}
