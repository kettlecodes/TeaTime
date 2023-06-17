#include "Frontend.h"

#include "settings/Settings.h"
#include "ScreenManager.h"


Frontend::Frontend(BackendInterface *backend, Settings *settings) {
    _backend = backend;
    _settings = settings;
    _screenManager = nullptr;
}


Frontend::~Frontend() {
    if (_screenManager) {
        delete _screenManager;
    }
}


bool Frontend::init() {
    if (!_screenManager) {
        _screenManager = new ScreenManager(_backend, _settings);
    }
    else {
        _screenManager->reset();
    }
    return true;
}


void Frontend::update() {
    if (_screenManager) {
        _screenManager->updateScreen();
    }
}


bool Frontend::handleButtonPress() {
    if (_screenManager) {
        return _screenManager->handleButtonPress();
    }
    return false;
}


bool Frontend::handleTap() {
    if (_screenManager) {
        return _screenManager->handleTap();
    }
    return false;
}


bool Frontend::handleLongTap() {
    if (_screenManager) {
        return _screenManager->handleLongTap();
    }
    return false;
}


bool Frontend::handleDoubleTap() {
    if (_screenManager) {
        return _screenManager->handleDoubleTap();
    }
    return false;
}


bool Frontend::handleSwipeLeft() {
    if (_screenManager) {
        return _screenManager->handleSwipeLeft();
    }
    return false;
}


bool Frontend::handleSwipeRight() {
    if (_screenManager) {
        return _screenManager->handleSwipeRight();
    }
    return false;
}


bool Frontend::handleSwipeUp() {
    if (_screenManager) {
        return _screenManager->handleSwipeUp();
    }
    return false;
}


bool Frontend::handleSwipeDown() {
    if (_screenManager) {
        return _screenManager->handleSwipeDown();
    }
    return false;
}


bool Frontend::handlePowerPresentChange() {
    if (_screenManager) {
        // make sure the screen gets updated accordingly
        _screenManager->updateScreen();
        return true;
    }
    return false;
}


bool Frontend::handleBluetoothConnectedChange() {
    if (_screenManager) {
        // make sure the screen gets updated accordingly
        _screenManager->updateScreen();
        return true;
    }
    return false;
}


bool Frontend::handleFirmwareUpdateStart() {
    if (_screenManager) {
        // show the firmware update screen during the upload
        _screenManager->activateScreen(ScreenManager::ScreenId::FirmwareUpdateScreen);
        return true;
    }
    return false;
}