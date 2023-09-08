#include "Cli_commands.h"

char *argv[10];
uint8_t argv_leng = 0 ;
extern Cli_typedef cli_table[] ;
Cli_typedef *pt_find ; 
//find a appropriate function 
 Cli_typedef cli_command_find(char *cmd){
	pt_find = cli_table ;
	while(pt_find->name != NULL){
		
		if(strcmp(pt_find->name,cmd) == 0){
			return *pt_find;
		}	
		pt_find++;
	}
	
	return *pt_find ;
}

void cli_command_execute(unsigned char *uart_buffer,uint8_t uart_leng){
	char *pt;
	pt = strtok((char *)uart_buffer , " " );
	while(pt != NULL){
		argv[argv_leng++] = pt ;
		pt = strtok(NULL, " " );
	}	
	
	Cli_typedef function_execute = cli_command_find(argv[0]);
	if(function_execute.name != NULL){
			function_execute.CLI_function(argv,argv_leng);
	}
	else{
			response_printf("Error !!!");
	}
	argv_leng = 0 ;
}