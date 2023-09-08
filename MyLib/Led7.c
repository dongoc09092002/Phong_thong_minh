#include "Led7.h"

static uint8_t led7_state[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90} ;

void led7_anot_display_1(Led7 *LED , uint8_t number , uint8_t number_led){
			HAL_GPIO_WritePin(PORT_FOOT_LED1,PIN_FOOT_LED1,0);
			HAL_GPIO_WritePin(PORT_FOOT_LED2,PIN_FOOT_LED2,0);
			HAL_GPIO_WritePin(PORT_FOOT_LED3,PIN_FOOT_LED3,0);
			HAL_GPIO_WritePin(PORT_FOOT_LED4,PIN_FOOT_LED4,0);
	switch(number_led){
		case 1: 
			HAL_GPIO_WritePin(PORT_FOOT_LED1,PIN_FOOT_LED1,1);
			break ;
		case 2:
			HAL_GPIO_WritePin(PORT_FOOT_LED2,PIN_FOOT_LED2,1);
			break ;
		case 3:
			HAL_GPIO_WritePin(PORT_FOOT_LED3,PIN_FOOT_LED3,1);
			break ;
		case 4:
			HAL_GPIO_WritePin(PORT_FOOT_LED4,PIN_FOOT_LED4,1);
			break ;
		default :
			break;
	}
	LED->res = led7_state[number] ;
	HAL_GPIO_WritePin(PORT_FOOT_A,PIN_FOOT_A,LED->Led7_Number.PA);
	HAL_GPIO_WritePin(PORT_FOOT_B,PIN_FOOT_B,LED->Led7_Number.PB);
	HAL_GPIO_WritePin(PORT_FOOT_C,PIN_FOOT_C,LED->Led7_Number.PC);
	HAL_GPIO_WritePin(PORT_FOOT_D,PIN_FOOT_D,LED->Led7_Number.PD);
	HAL_GPIO_WritePin(PORT_FOOT_E,PIN_FOOT_E,LED->Led7_Number.PE);
	HAL_GPIO_WritePin(PORT_FOOT_F,PIN_FOOT_F,LED->Led7_Number.PF);
	HAL_GPIO_WritePin(PORT_FOOT_G,PIN_FOOT_G,LED->Led7_Number.PG);
	HAL_GPIO_WritePin(PORT_FOOT_DP,PIN_FOOT_DP,LED->Led7_Number.DP);
	HAL_Delay(3);
	
}
//2 led (tryen vao mot so co hai chu so) 
void led7_anot_display_2(Led7 *_LED1,Led7 *_LED2,uint8_t number){
	uint8_t chuc = number/10;
	uint8_t donvi = number%10;
	led7_anot_display_1(_LED1,chuc,1);
	led7_anot_display_1(_LED1,donvi,2);
}
//4 led (truyen vao mot so co 4 chu so)
void led7_anot_display_4(Led7 *_LED1,Led7 *_LED2,Led7 *_LED3,Led7 *_LED4,uint8_t number1 , uint8_t number2){
	uint8_t chuc1 = number1/10;
	uint8_t donvi1 = number1%10;
	uint8_t chuc2 = number2/10;
	uint8_t donvi2 = number2%10;
	led7_anot_display_1(_LED1,chuc1,1);
	led7_anot_display_1(_LED2,donvi1,2);
	led7_anot_display_1(_LED3,chuc2,3);
	led7_anot_display_1(_LED4,donvi2,4);
}