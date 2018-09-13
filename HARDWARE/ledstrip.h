#ifndef __ledstrip_h
#define __ledstrip_h

#include "main.h"
#include "stm32f1xx_hal.h"
#include "color.h"

#define TIMING_ONE  71
#define TIMING_ZERO 18

#define lednumber1 5
#define ledcnt1 ((lednumber1+43)*24)

static uint16_t LED1_BYTE_Buffer[ledcnt1] = {0x00};


void ledstrip1_perframe(int num,int len,uint8_t (*color_led)[3],uint8_t (*color_bg)[3]);
void ledstrip1_alloff(void);
void ledstrip1_forward(int len,int delayms,uint8_t (*color_led)[3],uint8_t (*color_bg)[3]);
void ledstrip1_backward(int len,int delayms,uint8_t (*color_led)[3],uint8_t (*color_bg)[3]);

#endif
