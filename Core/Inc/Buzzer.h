/*
 * Buzzer.h
 *
 *  Created on: May 27, 2025
 *      Author: Dell
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "main.h"

void Buzzer_PWM_Init(void);         // Khởi tạo timer cho PWM
void Buzzer_PWM_On(uint32_t freq);  // Bật buzzer
void Buzzer_PWM_Off(void);          // Tắt buzzer

#endif /* INC_BUZZER_H_ */
