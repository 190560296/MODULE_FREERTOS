#ifndef __ledstrip_h
#define __ledstrip_h

#include "main.h"
#include "stm32f1xx_hal.h"
#include "cmsis_os.h"

#define TIMING_ZERO 21
#define TIMING_ONE  67

#define lednumber1 10
#define ledcnt1 (lednumber1*24 + 42)
static uint16_t LED1_BYTE_Buffer[ledcnt1] = {0x00};

#define lednumber2 10
#define ledcnt2 (lednumber2*24 + 42)
static uint16_t LED2_BYTE_Buffer[ledcnt2] = {0x00};

void ledstrip1_perframe(int num,int len,uint8_t (*color_led)[3],uint8_t (*color_bg)[3]);
void ledstrip1_backward(int len,int delayms,uint8_t (*color_led)[3],uint8_t (*color_bg)[3]);
void ledstrip1_forward(int len,int delayms,uint8_t (*color_led)[3],uint8_t (*color_bg)[3]);
void ledstrip1_alloff(void);

void ledstrip2_perframe(int num,int len,uint8_t (*color_led)[3],uint8_t (*color_bg)[3]);
void ledstrip2_backward(int len,int delayms,uint8_t (*color_led)[3],uint8_t (*color_bg)[3]);
void ledstrip2_forward(int len,int delayms,uint8_t (*color_led)[3],uint8_t (*color_bg)[3]);
void ledstrip2_alloff(void);

#endif
