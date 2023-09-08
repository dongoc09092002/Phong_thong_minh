#ifndef RESPONSE_H
#define RESPONSE_H
#include "stm32f1xx_hal.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
void response_printf(const char *str , ...);
void response_init(UART_HandleTypeDef *_response_uart);

#endif