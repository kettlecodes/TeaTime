#ifndef MOCKUPBACKEND_H
#define MOCKUPBACKEND_H

#include "interfaces/BackendInterface.h"


class MockupBackend : public BackendInterface {
public:

    MockupBackend();
    ~MockupBackend() override;

    BatteryInterface *battery() override { return _battery; }
    BluetoothInterface *bluetooth() override { return _bluetooth; }
    DateTimeInterface *dateTime() override { return _dateTime; }
    DisplayInterface *display() override { return _display; }
    FirmwareValidationInterface *firmwareValidation() override { return _firmwareValidation; }
    MotionInterface *motion() override { return _motion; }

private:

    BatteryInterface *_battery;
    BluetoothInterface *_bluetooth;
    DateTimeInterface *_dateTime;
    DisplayInterface *_display;
    FirmwareValidationInterface *_firmwareValidation;
    MotionInterface *_motion;
};

#endif // MOCKUPBACKEND_H