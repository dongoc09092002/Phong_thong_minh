#ifndef UART_H
#define UART_H
//************ADD THU VIEN**********************
#include "stm32f1xx_hal.h"
#include "string.h"
#include "Cli_commands.h"
//************NGUYEN MAU HAM********************
void uart_receive(unsigned char buff_rx);

void uart_handle();

void uart_init();

#endif