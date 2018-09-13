#ifndef __pwm_h
#define __pwm_h

#include "main.h"
#include "stm32f1xx_hal.h"

void USER_PWM_SetRatio(TIM_HandleTypeDef *htim,uint32_t Channel, uint8_t value);

#endif
