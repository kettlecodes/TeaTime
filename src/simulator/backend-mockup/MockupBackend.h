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
    FileSystemInterface *fileSystem() override { return _fileSystem; }
    FirmwareValidationInterface *firmwareValidation() override { return _firmwareValidation; }
    MotionInterface *motion() override { return _motion; }
    WatchdogInterface *watchdog() override { return _watchdog; }

private:

    BatteryInterface *_battery;
    BluetoothInterface *_bluetooth;
    DateTimeInterface *_dateTime;
    DisplayInterface *_display;
    FileSystemInterface *_fileSystem;
    FirmwareValidationInterface *_firmwareValidation;
    MotionInterface *_motion;
    WatchdogInterface *_watchdog;
};

#endif // MOCKUPBACKEND_H
