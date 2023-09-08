#ifndef LED7_H
#define LED7_H

#define PORT_FOOT_A GPIOA
#define PORT_FOOT_B GPIOA
#define PORT_FOOT_C GPIOA
#define PORT_FOOT_D GPIOA
#define PORT_FOOT_E GPIOA
#define PORT_FOOT_F GPIOA
#define PORT_FOOT_G GPIOA
#define PORT_FOOT_DP GPIOA
#define PORT_FOOT_LED1 GPIOB
#define PORT_FOOT_LED2 GPIOB
#define PORT_FOOT_LED3 GPIOB
#define PORT_FOOT_LED4 GPIOB

#define PIN_FOOT_A GPIO_PIN_0
#define PIN_FOOT_B GPIO_PIN_1
#define PIN_FOOT_C GPIO_PIN_2
#define PIN_FOOT_D GPIO_PIN_3
#define PIN_FOOT_E GPIO_PIN_4
#define PIN_FOOT_F GPIO_PIN_5
#define PIN_FOOT_G GPIO_PIN_6
#define PIN_FOOT_DP GPIO_PIN_7
#define PIN_FOOT_LED1 GPIO_PIN_0
#define PIN_FOOT_LED2 GPIO_PIN_1
#define PIN_FOOT_LED3 GPIO_PIN_3
#define PIN_FOOT_LED4 GPIO_PIN_4

#include "stm32f1xx_hal.h"	
typedef union{
	uint8_t res     :8;
	struct {
		GPIO_PinState PA    :1;
		GPIO_PinState PB    :1;
		GPIO_PinState PC    :1;
		GPIO_PinState PD    :1;
		GPIO_PinState PE    :1;
		GPIO_PinState PF    :1;
		GPIO_PinState PG    :1;
		GPIO_PinState DP    :1;
	}Led7_Number;
}Led7;

void led7_anot_display_2(Led7 *_LED1,Led7 *_LED2,uint8_t number);
void led7_anot_display_1(Led7 *LED , uint8_t number , uint8_t number_led);
void led7_anot_display_4(Led7 *_LED1,Led7 *_LED2,Led7 *_LED3,Led7 *_LED4,uint8_t number1 , uint8_t number2);
#endif

