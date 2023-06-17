#include "MockupBackend.h"

#include "MockupBattery.h"
#include "MockupBluetooth.h"
#include "MockupDateTime.h"
#include "MockupDisplay.h"
#include "MockupFirmwareValidation.h"
#include "MockupMotion.h"


MockupBackend::MockupBackend() {
    _battery = new MockupBattery();
    _bluetooth = new MockupBluetooth();
    _dateTime = new MockupDateTime();
    _display = new MockupDisplay();
    _firmwareValidation = new MockupFirmwareValidation();
    _motion = new MockupMotion();
}


MockupBackend::~MockupBackend() {
    delete _battery;
    delete _bluetooth;
    delete _dateTime;
    delete _display;
    delete _firmwareValidation;
    delete _motion;
}