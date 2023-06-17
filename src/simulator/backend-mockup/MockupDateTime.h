#ifndef MOCKUPDATETIME_H
#define MOCKUPDATETIME_H

#include "interfaces/backend-services/DateTimeInterface.h"


class MockupDateTime : public DateTimeInterface {
public:

    MockupDateTime();
    ~MockupDateTime() override;

    uint16_t year() const override { return _year; }
    uint8_t month() const override { return _month; }
    uint8_t day() const override { return _day; }
    uint8_t dayOfWeek() const override { return _dayOfWeek; }

    uint8_t hour() const override { return _hour; }
    uint8_t minute() const override { return _minute; }
    uint8_t second() const override { return _second; }
    uint16_t milliSecond() const override { return _milliSecond; }

    uint32_t uptimeSeconds() const override { return _uptimeSeconds; }

    void setToSystemTime();
    void setDate(uint16_t year, uint8_t month, uint8_t day, uint8_t dayOfWeek);
    void setTime(uint8_t hour, uint8_t minute, uint8_t second);

private:

    uint16_t _year;
    uint8_t _month;
    uint8_t _day;
    uint8_t _dayOfWeek;
    uint8_t _hour;
    uint8_t _minute;
    uint8_t _second;
    uint16_t _milliSecond;
    uint32_t _uptimeSeconds;
};

#endif // MOCKUPDATETIME_H