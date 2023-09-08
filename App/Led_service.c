#include "Led_service.h"
#include "Response.h"

void led_on(){
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12 , 1) ;
}

void led_off(){
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12 , 0) ;
}

void led_service_turn_on(char **argv , uint8_t argv_leng){
	if( argv_leng > 1 || argv_leng < 1){
		response_printf("Excessing data");
	}
	else{
		response_printf("LED ON");
	  led_on();
		
	}
}


void led_service_turn_off(char **argv , uint8_t argv_leng){
	if( argv_leng > 1 || argv_leng < 1){
		response_printf("Excessing data");
	}
	else{
		response_printf("LED OFF");
	  led_off();
		
	}
}

