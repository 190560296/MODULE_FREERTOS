#include "ledstrip.h"

extern TIM_HandleTypeDef htim3;
extern DMA_HandleTypeDef hdma_tim3_ch3;

void ledstrip1_perframe(int num,int len,uint8_t (*color_led)[3],uint8_t (*color_bg)[3])
{
    int i = 0;
    int lednum = 0;
    int cnt = 0;
    
    while(lednum < len)
    {
        if(lednum <= num)
        {
            for(i=0;i<8;i++)
            {
                LED1_BYTE_Buffer[cnt] = ((*color_led)[0]<<i)&0x0080?TIMING_ONE:TIMING_ZERO;
                cnt++;
            }
            for(i=0;i<8;i++)
            {
                LED1_BYTE_Buffer[cnt] = ((*color_led)[1]<<i)&0x0080?TIMING_ONE:TIMING_ZERO;
                cnt++;
            }
            for(i=0;i<8;i++)
            {
                LED1_BYTE_Buffer[cnt] = ((*color_led)[2]<<i)&0x0080?TIMING_ONE:TIMING_ZERO;
                cnt++;
            }
        }
        else
        {
            for(i=0;i<8;i++)
            {
                LED1_BYTE_Buffer[cnt] = ((*color_bg)[0]<<i)&0x0080?TIMING_ONE:TIMING_ZERO;
                cnt++;
            }
            for(i=0;i<8;i++)
            {
                LED1_BYTE_Buffer[cnt] = ((*color_bg)[1]<<i)&0x0080?TIMING_ONE:TIMING_ZERO;
                cnt++;
            }
            for(i=0;i<8;i++)
            {
                LED1_BYTE_Buffer[cnt] = ((*color_bg)[2]<<i)&0x0080?TIMING_ONE:TIMING_ZERO;
                cnt++;
            }
        }
        
        lednum++;
    }
    
    while(cnt<ledcnt1)
    {
        cnt++;
        LED1_BYTE_Buffer[cnt] = 0x00;
    }
    
    HAL_TIM_PWM_Start_DMA(&htim3,TIM_CHANNEL_3,(uint32_t *)LED1_BYTE_Buffer,cnt);
}

void ledstrip1_alloff(void)
{
    ledstrip1_perframe(lednumber1,lednumber1,&color_null,&color_null);
}

void ledstrip1_forward(int len,int delayms,uint8_t (*color_led)[3],uint8_t (*color_bg)[3])
{
    int i;
    
    for(i = 0; i < len; i++)
    {
        ledstrip1_perframe(i,len,color_led,color_bg);
        HAL_Delay(delayms);
    }
}

void ledstrip1_backward(int len,int delayms,uint8_t (*color_led)[3],uint8_t (*color_bg)[3])
{
    int i = len;
    
    for(;i >= 0; i--)
    {
        ledstrip1_perframe(i,len,color_led,color_bg);
        HAL_Delay(delayms);
    }
    ledstrip1_perframe(len,len,color_bg,color_bg);
}
