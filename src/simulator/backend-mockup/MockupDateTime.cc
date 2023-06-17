#include "MockupDateTime.h"

#include <time.h>


MockupDateTime::MockupDateTime() {
    setToSystemTime();
}


MockupDateTime::~MockupDateTime() {
}


void MockupDateTime::setToSystemTime() {

    time_t theTime = time(nullptr);
    struct tm currentTime = *localtime(&theTime);

    _year = 1900 + currentTime.tm_year;
    _month = currentTime.tm_mon + 1;
    _day = currentTime.tm_mday;
    _dayOfWeek = currentTime.tm_wday;

    _hour = currentTime.tm_hour;
    _minute = currentTime.tm_min;
    _second = currentTime.tm_sec;
    _milliSecond = 0;

    _uptimeSeconds = 3600 * currentTime.tm_hour + 60 * currentTime.tm_min + currentTime.tm_sec;
}


void MockupDateTime::setDate(uint16_t year, uint8_t month, uint8_t day, uint8_t dayOfWeek) {
    _year = year;
    _month = month;
    _day = day;
    _dayOfWeek = dayOfWeek;
}


void MockupDateTime::setTime(uint8_t hour, uint8_t minute, uint8_t second) {
    _hour = hour;
    _minute = minute;
    _second = second;
    _milliSecond = 0;
}