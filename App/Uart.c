#include "Uart.h"



#define uart_buffer_max   100
static unsigned char uart_buffer[uart_buffer_max];
static uint8_t uart_leng = 0;
static uint8_t uart_flag = 0;



void uart_receive(unsigned char buff_rx){
	
	if(buff_rx == '\n'){
		uart_buffer[uart_leng] = '\0';
		uart_flag = 1;
	}
	else{
		uart_buffer[uart_leng] = buff_rx;
		uart_leng++;
	}

}

void uart_handle(){
	
	if(uart_flag == 1){
		cli_command_execute(uart_buffer , uart_leng);
		uart_leng = 0;
		uart_flag = 0;
	
	}
	
}


void uart_init(){
}


