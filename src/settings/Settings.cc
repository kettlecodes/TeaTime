#include "Settings.h"


#define WAKE_MASK_TAP           0x01
#define WAKE_MASK_DOUBLE_TAP    0x02
#define WAKE_MASK_RAISE_WRIST   0x04
#define WAKE_MASK_SHAKE_WRIST   0x08


Settings::Settings(BackendInterface *backend) {
    _backend = backend;
    loadSettings();
}


Settings::~Settings() {
}


bool Settings::wakeDisplayOnTap() const {
    return (_displayWakeFlags & WAKE_MASK_TAP);
}


bool Settings::wakeDisplayOnDoubleTap() const {
    return (_displayWakeFlags & WAKE_MASK_DOUBLE_TAP);
}


bool Settings::wakeDisplayOnRaiseWrist() const {
    return (_displayWakeFlags & WAKE_MASK_RAISE_WRIST);
}


bool Settings::wakeDisplayOnShakeWrist() const {
    return (_displayWakeFlags & WAKE_MASK_SHAKE_WRIST);
}


void Settings::setDailyStepsGoal(uint32_t steps) {
    _dailyStepsGoal = steps;
    saveSettings();
}


void Settings::setDisplayBrightness(uint8_t brightness) {
    _displayBrightness = brightness;
    saveSettings();
}


void Settings::setWakeDisplayOnTap(bool wake) {
    if (wake) {
        _displayWakeFlags |= WAKE_MASK_TAP;
    }
    else {
        _displayWakeFlags &= (0xff ^ WAKE_MASK_TAP);
    }
    saveSettings();
}


void Settings::setWakeDisplayOnDoubleTap(bool wake) {
    if (wake) {
        _displayWakeFlags |= WAKE_MASK_DOUBLE_TAP;
    }
    else {
        _displayWakeFlags &= (0xff ^ WAKE_MASK_DOUBLE_TAP);
    }
    saveSettings();
}


void Settings::setWakeDisplayOnRaiseWrist(bool wake) {
    if (wake) {
        _displayWakeFlags |= WAKE_MASK_RAISE_WRIST;
    }
    else {
        _displayWakeFlags &= (0xff ^ WAKE_MASK_RAISE_WRIST);
    }
    saveSettings();
}


void Settings::setWakeDisplayOnShakeWrist(bool wake) {
    if (wake) {
        _displayWakeFlags |= WAKE_MASK_SHAKE_WRIST;
    }
    else {
        _displayWakeFlags &= (0xff ^ WAKE_MASK_SHAKE_WRIST);
    }
    saveSettings();
}


void Settings::loadSettings() {
    //TODO
}


void Settings::saveSettings() {
    //TODO
}