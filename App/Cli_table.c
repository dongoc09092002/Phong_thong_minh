#include "Cli_table.h"

Cli_typedef cli_table[] = {
	
	{ "getTime" , "get time from clock" , time_service_getTime },
	{ "setTime" , "set time to clock" , time_service_setTime },
	{ "fanon" , "turn on the fan" , fan_service_turn_on },
	{ "fanoff" , "turn off the fan" , fan_service_turn_off },
	{ "ledon" , "turn off the led" , led_service_turn_on },
	{ "ledoff" , "turn off the led" , led_service_turn_off },
	
	{NULL , NULL , NULL},
};