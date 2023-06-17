#include "MockupBattery.h"


MockupBattery::MockupBattery() {
    _remainingPercentage = 80;
    _isPowerPresent = false;
}


MockupBattery::~MockupBattery() {
}


bool MockupBattery::measure() {
    return true;
}


void MockupBattery::setRemainingPercentage(uint8_t percentage) {
    _remainingPercentage = percentage;
}


void MockupBattery::setIsPowerPresent(bool isPowerPresent) {
    _isPowerPresent = isPowerPresent;
}