#include "Fan_service.h"
#include "Response.h"
#include <stdlib.h>
static handle_motor *motor ;
void fan_on(uint8_t speed){
	
	motor_control(motor , STATE_FORWARD ,speed);
}


void fan_off(){
	motor_control(motor , STATE_STOP ,0);
}

void fan_init(handle_motor *_motor,uint32_t _channel,TIM_HandleTypeDef *_htim , uint32_t GPIO_Pin_output , GPIO_TypeDef  *GPIOx_output){
	
	motor_init(_motor,_channel,_htim,GPIO_Pin_output , GPIOx_output);
	motor = _motor ;

}


//******************CAC HAM CHINH************************
void fan_service_turn_on(char **argv , uint8_t argv_leng){
	if( argv_leng > 2 || argv_leng < 2){
		response_printf("Excessing data");
	}
	else{
		response_printf("FAN ON");
	
		fan_on( atoi(argv[1]) ) ;
	}
}

void fan_service_turn_off(char **argv , uint8_t argv_leng){
	if( argv_leng > 1 || argv_leng < 1){
		response_printf("Excessing data");
	}
	else{
		response_printf("FAN OFF");
		fan_off() ;
	}
}