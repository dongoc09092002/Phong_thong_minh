#include "Time_service.h"
#include "Time3231.h"
#include "string.h"
#include <stdlib.h>
//***************CAC HAM PHU THUOC**********************
/*
1.[getTime 0]: lay du lieu phut 	
2.[getTime 1]: lay du lieu gio/phut
3.[getTime 2]: lay du lieu ngay/gio/phut
4.[getTime 3]: lay du lieu thang/ngay/gio/phut
5.[getTime 4]: lay du lieu nam/thang/ngay/gio/phut
6.[settime giay phut gio thu ngay thang nam] : ghi du lieu
*/
RTC_DS3231 *data_time ;  
I2C_HandleTypeDef *hi2c;
void Time3231_handle_data_time(RTC_DS3231 *buff){
	data_time = buff ; 
}
//void time_service_set_i2c_init(I2C_HandleTypeDef *_hi2c){
//	hi2c = _hi2c ;
//}




//***************CAC HAM XU LY**********************
void time_service_get_response(char **argv){
	if(strcmp( "0" ,argv[1]) == 0){
		response_printf("phut:%d",data_time->min);
	}
	else if(strcmp( "1" ,argv[1]) == 0){
		response_printf("gio:%d/phut:%d",data_time->hours,data_time->min);
	}
	else if(strcmp( "2" ,argv[1]) == 0){
		response_printf("ngay:%d/gio:%d/phut:%d",data_time->date,data_time->hours,data_time->min);
	}
	else if(strcmp( "3" ,argv[1]) == 0){
		response_printf("thang:%d/ngay:%d/gio:%d/phut:%d",data_time->month,data_time->date,data_time->hours,data_time->min);
	}
	else if(strcmp( "4" ,argv[1]) == 0){
		response_printf("nam:%d/thang:%d/ngay:%d/gio:%d/phut:%d",data_time->year,data_time->month,data_time->date,data_time->hours,data_time->min);
	}
	else{
		response_printf("dont exist");
	}
}

void time_service_set_response(char **argv){
		uint8_t set_time_data[7];
		RTC_DS3231 new_ds3231;
		set_time_data[0] = atoi(argv[1]);
		set_time_data[1] = atoi(argv[2]);
		set_time_data[2] = atoi(argv[3]);
		set_time_data[3] = atoi(argv[4]);
		set_time_data[4] = atoi(argv[5]);
		set_time_data[5] = atoi(argv[6]);
		set_time_data[6] = atoi(argv[7]);
	  Time3231_init_RTC(&new_ds3231,set_time_data[0],set_time_data[1],set_time_data[2],set_time_data[3],set_time_data[4],set_time_data[5],set_time_data[6]);
	  Time3231_write_RTC(&new_ds3231);
		response_printf("Change success");
}


	
//*************CAC HAM CHINH****************************
void time_service_getTime(char **argv , uint8_t argv_leng){
	if( argv_leng < 2){
		response_printf("Missing data");
	}
	else if(argv_leng>2){
		response_printf("Excessing data");
	}
	else{
		time_service_get_response(argv);
	}
}
void time_service_setTime(char **argv , uint8_t argv_leng){
	if( argv_leng != 8){
		response_printf("Missing data or Excessing data");
	}
	else{
		time_service_set_response(argv);
	}
}
