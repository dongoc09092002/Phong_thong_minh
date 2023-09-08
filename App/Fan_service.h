#ifndef FAN_SERVICE_H
#define FAN_SERVICE_H
#include "Motor.h"
#include "stm32f1xx_hal.h"

void fan_on(uint8_t speed);


void fan_off();
void fan_init(handle_motor *_motor,uint32_t _channel,TIM_HandleTypeDef *_htim , uint32_t GPIO_Pin_output , GPIO_TypeDef  *GPIOx_output) ;
void fan_service_turn_on(char **argv , uint8_t argv_leng);
void fan_service_turn_off(char **argv , uint8_t argv_leng);
#endif

