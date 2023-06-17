#ifndef DATETIMEINTERFACE_H
#define DATETIMEINTERFACE_H

#include <stdint.h>


class DateTimeInterface {
public:

    virtual ~DateTimeInterface() { }

    virtual uint16_t year() const = 0;
    virtual uint8_t month() const = 0;
    virtual uint8_t day() const = 0;
    virtual uint8_t dayOfWeek() const = 0;

    virtual uint8_t hour() const = 0;
    virtual uint8_t minute() const = 0;
    virtual uint8_t second() const = 0;
    virtual uint16_t milliSecond() const = 0;

    virtual uint32_t uptimeSeconds() const = 0;
};

#endif // DATETIMEINTERFACE_H