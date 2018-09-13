#ifndef __can_h
#define __can_h

#include "main.h"
#include "stm32f1xx_hal.h"
#include "usart.h"

//extern CAN_HandleTypeDef hcan;

void Config_CanFilter(void);

void sendCanData(uint32_t id,uint8_t * buf,uint32_t len);

#endif
