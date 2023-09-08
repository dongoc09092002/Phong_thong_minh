#ifndef TIME_SERVICE_H
#define TIME_SERVICE_H
#include "stm32f1xx_hal.h"
#include "Response.h"
void time_service_getTime(char **argv , uint8_t argv_leng);
void time_service_setTime(char **argv , uint8_t argv_leng);




#endif