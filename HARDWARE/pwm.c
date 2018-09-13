#include "pwm.h"

void USER_PWM_SetRatio(TIM_HandleTypeDef *htim,uint32_t Channel, uint8_t value)
{
  TIM_OC_InitTypeDef sConfigOC;
  
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = value;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  
  HAL_TIM_PWM_ConfigChannel(htim,&sConfigOC,Channel);
  HAL_TIM_PWM_Start(htim,Channel);
}
