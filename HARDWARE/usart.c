#include "usart.h"
#include "stdio.h"

#ifdef __GNUC__
    #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
    #define PUTCHAR_PROTOTYPE int fputc(int ch,FILE *f)
#endif
    
PUTCHAR_PROTOTYPE
{
    huart1.Instance->DR = (uint8_t)ch;
    
    while(__HAL_UART_GET_FLAG(&huart1,UART_FLAG_TC) == RESET){}
        
    return ch;
}
