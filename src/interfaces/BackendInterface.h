#ifndef BACKENDINTERFACE_H
#define BACKENDINTERFACE_H

#include "backend-services/BatteryInterface.h"
#include "backend-services/BluetoothInterface.h"
#include "backend-services/DateTimeInterface.h"
#include "backend-services/DisplayInterface.h"
#include "backend-services/FirmwareValidationInterface.h"
#include "backend-services/MotionInterface.h"
#include "backend-services/WatchdogInterface.h"


class BackendInterface {
public:

    virtual ~BackendInterface() { }

    virtual BatteryInterface *battery() = 0;
    virtual BluetoothInterface *bluetooth() = 0;
    virtual DateTimeInterface *dateTime() = 0;
    virtual DisplayInterface *display() = 0;
    virtual FirmwareValidationInterface *firmwareValidation() = 0;
    virtual MotionInterface *motion() = 0;
    virtual WatchdogInterface *watchdog() = 0;
};

#endif // BACKENDINTERFACE_H
