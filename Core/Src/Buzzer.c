/*
 * Buzzer.c
 *
 *  Created on: May 27, 2025
 *      Author: Dell
 */
#include "buzzer.h"

extern TIM_HandleTypeDef htim2;

void Buzzer_PWM_Init(void) {
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

void Buzzer_PWM_On(uint32_t freq) {
    uint32_t timer_clock = 639;
    uint32_t prescaler = 0;
    uint32_t period = (timer_clock / freq) - 1;

    __HAL_TIM_SET_PRESCALER(&htim2, prescaler);
    __HAL_TIM_SET_AUTORELOAD(&htim2, period);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, period / 2);  // duty 50%
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

void Buzzer_PWM_Off(void) {
    HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
}

