#ifndef BATTERYINTERFACE_H
#define BATTERYINTERFACE_H

#include <stdint.h>


class BatteryInterface {
public:

    virtual ~BatteryInterface() { }

    virtual uint8_t remainingPercentage() const = 0;
    virtual bool isPowerPresent() const = 0;

    virtual bool measure() = 0;
};

#endif // BATTERYINTERFACE_H