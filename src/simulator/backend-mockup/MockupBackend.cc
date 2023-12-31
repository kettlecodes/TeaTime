#include "MockupBackend.h"

#include "MockupBattery.h"
#include "MockupBluetooth.h"
#include "MockupDateTime.h"
#include "MockupDisplay.h"
#include "MockupFileSystem.h"
#include "MockupFirmwareValidation.h"
#include "MockupMotion.h"
#include "MockupWatchdog.h"


MockupBackend::MockupBackend() {
    _battery = new MockupBattery();
    _bluetooth = new MockupBluetooth();
    _dateTime = new MockupDateTime();
    _display = new MockupDisplay();
    _fileSystem = new MockupFileSystem();
    _firmwareValidation = new MockupFirmwareValidation();
    _motion = new MockupMotion();
    _watchdog = new MockupWatchdog();
}


MockupBackend::~MockupBackend() {
    delete _battery;
    delete _bluetooth;
    delete _dateTime;
    delete _display;
    delete _fileSystem;
    delete _firmwareValidation;
    delete _motion;
    delete _watchdog;
}
