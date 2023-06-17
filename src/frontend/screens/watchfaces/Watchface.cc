#include "Watchface.h"

#include <lvgl/lvgl.h>

#include "interfaces/BackendInterface.h"


Watchface::Watchface(BackendInterface *backend, ScreenManager *screenManager, Settings *settings)
        : Screen(backend, screenManager, settings) {
    // initialize
    DateTimeInterface *dateTime = this->backend()->dateTime();
    _year = dateTime->year();
    _month = dateTime->month();
    _dayOfWeek = dateTime->dayOfWeek();
    _day = dateTime->day();
    _hour = dateTime->hour();
    _minute = dateTime->minute();
    _second = dateTime->second();
    _milliSecond = dateTime->milliSecond();

    _locked = false;
    _batteryPercent = this->backend()->battery()->remainingPercentage();
    _powerPresent = this->backend()->battery()->isPowerPresent();
    _bleConnected = this->backend()->bluetooth()->isConnected();

    _firstUpdate = true;
}


void Watchface::update() {
    // store the current watch face as default on the first call
    if (_firstUpdate) {
        //TODO ... screenGraph()->setDefaultWatchFace(screenTag());
        _firstUpdate = false;
    }

    // get current date and time
    DateTimeInterface *dateTime = this->backend()->dateTime();
    uint16_t year = dateTime->year();
    uint8_t month = dateTime->month();
    uint8_t day = dateTime->day();
    uint8_t dayOfWeek = dateTime->dayOfWeek();
    uint8_t hour = dateTime->hour();
    uint8_t minute = dateTime->minute();
    uint8_t second = dateTime->second();
    uint16_t milliSecond = dateTime->milliSecond();

    // get current power / connection status
    uint8_t batteryPercent = this->backend()->battery()->remainingPercentage();
    bool powerPresent = this->backend()->battery()->isPowerPresent();
    bool bleConnected = this->backend()->bluetooth()->isConnected();

    // find out if something's changed
    bool yearHasChanged = (year != _year);
    bool monthHasChanged = (month != _month);
    bool dayHasChanged = ((day != _day) || monthHasChanged || yearHasChanged);
    bool hourHasChanged = (hour != _hour);
    bool minuteHasChanged = (minute != _minute);
    bool secondHasChanged = (second != _second);
    bool timeHasChanged = (hourHasChanged || minuteHasChanged || secondHasChanged || (milliSecond != _milliSecond));
    bool batteryPercentHasChanged = (batteryPercent != _batteryPercent);
    bool powerPresentHasChanged = (powerPresent != _powerPresent);
    bool bleConnectedHasChanged = (bleConnected != _bleConnected);

    // update the stored values
    _year = year;
    _month = month;
    _dayOfWeek = dayOfWeek;
    _day = day;
    _hour = hour;
    _minute = minute;
    _second = second;
    _batteryPercent = batteryPercent;
    _powerPresent = powerPresent;
    _bleConnected = bleConnected;

    // call the handlers
    if (dayHasChanged) {
        dayChanged(yearHasChanged, monthHasChanged);
    }
    if (timeHasChanged) {
        timeChanged(hourHasChanged, minuteHasChanged, secondHasChanged);
    }
    if (batteryPercentHasChanged) {
        batteryPercentChanged();
    }
    if (powerPresentHasChanged) {
        powerPresentChanged();
    }
    if (bleConnectedHasChanged) {
        bleConnectedChanged();
    }
}


bool Watchface::handleButtonPress() {
    _locked = !_locked;
    lockedStateChanged();
    return true;
}


bool Watchface::handleTap() {
    // ignore the event if the screen is locked
    return _locked;
}


bool Watchface::handleLongTap() {
    // ignore the event if the screen is locked
    return _locked;
}


bool Watchface::handleDoubleTap() {
    // ignore the event if the screen is locked
    return _locked;
}


bool Watchface::handleSwipeLeft() {
    // ignore the event if the screen is locked
    return _locked;
}


bool Watchface::handleSwipeRight() {
    // ignore the event if the screen is locked
    return _locked;
}


bool Watchface::handleSwipeUp() {
    // ignore the event if the screen is locked
    return _locked;
}


bool Watchface::handleSwipeDown() {
    // ignore the event if the screen is locked
    return _locked;
}
