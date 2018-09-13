#include "input_interrupt.h"
#include "ledstrip.h"

extern osSemaphoreId myBinarySem01Handle;
extern osSemaphoreId myBinarySem02Handle;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
//    if(GPIO_Pin == KEY1_Pin)
//    {
//        xSemaphoreGiveFromISR(myBinarySem01Handle,NULL);
//    }
//    
//    else if(GPIO_Pin == KEY2_Pin)
//    {
//        xSemaphoreGiveFromISR(myBinarySem02Handle,NULL);
//    }
}
