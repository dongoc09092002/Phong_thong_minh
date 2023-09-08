#ifndef LED_SERVICE_H
#define LED_SERVICE_H
#include "stm32f1xx_hal.h"

void led_service_turn_on(char **argv , uint8_t argv_leng);
void led_service_turn_off(char **argv , uint8_t argv_leng);
#endif