/*
 * motor_test.h
 *
 *  Created on: May 27, 2025
 *      Author: Dell
 */

#ifndef INC_TESTMOTOR_H_
#define INC_TESTMOTOR_H_

#include "main.h"

void Motor_Init(void);
void Motor_SetSpeed(uint8_t motor_id, uint8_t speed_percent);  // 0–100%
void Motor_SetDirection(uint8_t motor_id, uint8_t direction);  // 0: CW, 1: CCW
void Motor_Test(void);

#endif /* INC_TESTMOTOR_H_ */
