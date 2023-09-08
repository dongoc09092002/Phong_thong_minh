#include "Response.h"
UART_HandleTypeDef *response_uart;
void response_init(UART_HandleTypeDef *_response_uart){
	response_uart = _response_uart;
}
void response_printf(const char *str , ...){
	  char a[100];
    va_list ap;
    va_start(ap , str);
    vsprintf(a , str , ap);
    va_end(ap);
    HAL_UART_Transmit(response_uart , (uint8_t *)a ,strlen(a),100);
}
