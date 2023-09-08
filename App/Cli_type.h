#ifndef CLI_TYPE_H
#define CLI_TYPE_H
#include "stdint.h"
//void time_service_setTime(char **argv , uint8_t argv_leng);
typedef void (*pointer_function)(char **argv , uint8_t argv_leng) ; 

typedef struct {
	char *name; 
	char *help;
	pointer_function CLI_function;
}Cli_typedef;

#endif