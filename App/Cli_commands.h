#ifndef CLI_COMMANDS_H
#define CLI_COMMANDS_H
#include "stm32f1xx_hal.h"
#include "Time_service.h"
#include <string.h>
#include "Cli_type.h"
//xu ly tach du lieu uart thanh cac phan tu
void cli_command_execute(unsigned char *uart_buffer ,uint8_t uart_leng);

#endif