#include "MockupMotion.h"


MockupMotion::MockupMotion() {
    _deviceType = DeviceType::BMA425;
    _steps = 0;
}


MockupMotion::~MockupMotion() {
}


void MockupMotion::setDeviceType(DeviceType deviceType) {
    _deviceType = deviceType;
}


void MockupMotion::setSteps(uint32_t steps) {
    _steps = steps;
}