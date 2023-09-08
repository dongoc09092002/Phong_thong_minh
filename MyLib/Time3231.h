#ifndef TIME3231_H
#define TIME3231_H
#include "stm32f1xx_hal.h"
#define ADDRESS_DEVIDE 0x68<<1
typedef struct {
	uint8_t sec;
	uint8_t min;
	uint8_t hours;
	uint8_t day;
	uint8_t date;
	uint8_t month;
	uint8_t year;
}RTC_DS3231;

void Time3231_init_RTC(RTC_DS3231 *rtc,uint8_t sec,uint8_t min,uint8_t hours,uint8_t day,uint8_t date,uint8_t month,uint8_t year);
void Time3231_write_RTC( RTC_DS3231 *rtc );
void Time3231_read_RTC( RTC_DS3231 *rtc );
void Time3231_init_I2C(I2C_HandleTypeDef *_hi2c);
#endif