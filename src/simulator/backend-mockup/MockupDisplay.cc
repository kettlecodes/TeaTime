#include "MockupDisplay.h"


MockupDisplay::MockupDisplay() {
    _brightness = BrightnessLevel::Medium;
    _fullRefreshDirection = FullRefreshDirection::None;
}


MockupDisplay::~MockupDisplay() {
}


void MockupDisplay::setBrightness(BrightnessLevel brightness) {
    _brightness = brightness;
}


void MockupDisplay::setFullRefreshDirection(FullRefreshDirection direction) {
    _fullRefreshDirection = direction;
}