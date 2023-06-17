#ifndef MOTIONINTERFACE_H
#define MOTIONINTERFACE_H

#include <stdint.h>


class MotionInterface {
public:

    enum class DeviceType {
        Unknown,
        BMA421,
        BMA425
    };

    virtual ~MotionInterface() { }

    virtual DeviceType deviceType() const = 0;

    virtual uint32_t steps() const = 0;
};

#endif // MOTIONINTERFACE_H