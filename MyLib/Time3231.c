#include "Time3231.h"
#include "string.h"
static I2C_HandleTypeDef *hi2c;
RTC_DS3231 *_buff ;
__weak void Time3231_handle_data_time(RTC_DS3231 *buff){
	
//		uint8_t buff_time[7];
//		buff_time[0] = buff->sec ;
//		buff_time[1] = buff->min ;
//		buff_time[2] = buff->hours ;
//		buff_time[3] = buff->day ;
//		buff_time[4] = buff->date ;
//		buff_time[5] = buff->month ;
//		buff_time[6] = buff->year ;
}

uint8_t Time3231_decToBCD( uint8_t num ){
   return (num/10)<<4|(num%10);
}
uint8_t Time3231_bcdToDec( uint8_t num ){
   return (num>>4)*10+(num&0x0F);
}

void Time3231_init_RTC(RTC_DS3231 *rtc ,uint8_t sec,uint8_t min,uint8_t hours,uint8_t day,uint8_t date,uint8_t month,uint8_t year){
	rtc->sec = sec;
	rtc->min = min;
	rtc->hours = hours ;
	rtc->day = day;
	rtc->date = date;
	rtc->month = month;
	rtc->year = year;
}
void Time3231_init_I2C(I2C_HandleTypeDef *_hi2c){
	hi2c = _hi2c;
}

void Time3231_write_RTC( RTC_DS3231 *rtc ){
	uint8_t buff[8];
	buff[0] = 0;
	buff[1] = Time3231_decToBCD(rtc->sec); 
	buff[2] = Time3231_decToBCD(rtc->min); 
	buff[3] = Time3231_decToBCD(rtc->hours); 
	buff[4] = Time3231_decToBCD(rtc->day); 
	buff[5] = Time3231_decToBCD(rtc->date); 
	buff[6] = Time3231_decToBCD(rtc->month); 
	buff[7] = Time3231_decToBCD(rtc->year); 
	HAL_I2C_Master_Transmit(hi2c , ADDRESS_DEVIDE , buff , 8 , 100);
}



void Time3231_read_RTC( RTC_DS3231 *rtc ){
	uint8_t address_res = 0;
	uint8_t buff[7];
	HAL_I2C_Master_Transmit(hi2c , ADDRESS_DEVIDE ,&address_res,1,100);
	HAL_I2C_Master_Receive(hi2c , ADDRESS_DEVIDE , buff , 7 , 100);
	rtc->sec = Time3231_bcdToDec(buff[0]);
	rtc->min = Time3231_bcdToDec(buff[1]);
	rtc->hours = Time3231_bcdToDec(buff[2]);
	rtc->day = Time3231_bcdToDec(buff[3]);
	rtc->date = Time3231_bcdToDec(buff[4]);
	rtc->month = Time3231_bcdToDec(buff[5]);
	rtc->year = Time3231_bcdToDec(buff[6]);
	Time3231_handle_data_time(rtc);
}
