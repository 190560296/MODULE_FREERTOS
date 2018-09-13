#include "pwr.h"

void Enter_Sleep_Mode(void)
{
    HAL_SuspendTick();
    HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON,PWR_SLEEPENTRY_WFI);
    
    HAL_ResumeTick();
}

void Enter_Stop_Mode(void)
{

}
 
void Enter_Standby_Mode(void)
{
    HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);
    
//    __HAL_PWR_CLEAR_WAKEUP_FLAG();
    
    HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
    
    HAL_PWR_EnterSTANDBYMode();
}
