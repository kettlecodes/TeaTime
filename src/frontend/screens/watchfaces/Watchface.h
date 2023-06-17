#ifndef WATCHFACE_H
#define WATCHFACE_H

#include <stdint.h>

#include "frontend/screens/Screen.h"
#include "frontend/ScreenManager.h"


class Watchface : public Screen {
public:

    Watchface(BackendInterface *backend, ScreenManager *screenManager, Settings *settings);

    void update() override;

    uint16_t year() const { return _year; }
    uint8_t month() const { return _month; }
    uint8_t day() const { return _day; }
    uint8_t dayOfWeek() const { return _dayOfWeek; }
        
    uint8_t hour() const { return _hour; }
    uint8_t minute() const { return _minute; }
    uint8_t second() const { return _second; }
    uint16_t milliSecond() const { return _milliSecond; }

    uint8_t batteryPercent() const { return _batteryPercent; }
    bool powerPresent() const { return _powerPresent; }
    bool bleConnected() const { return _bleConnected; }

    bool locked() const { return _locked; }

    bool handleButtonPress() override;
    bool handleTap() override;
    bool handleLongTap() override;
    bool handleDoubleTap() override;
    bool handleSwipeLeft() override;
    bool handleSwipeRight() override;
    bool handleSwipeUp() override;
    bool handleSwipeDown() override;

protected:

    virtual ScreenManager::ScreenId screenId() const = 0;

    virtual void timeChanged(bool hourChanged, bool minuteChanged, bool secondChanged) { (void)hourChanged; (void)minuteChanged; (void)secondChanged; }
    virtual void dayChanged(bool yearChanged, bool monthChanged) { (void)yearChanged; (void)monthChanged; }

    virtual void lockedStateChanged() { }
    virtual void batteryPercentChanged() { }
    virtual void powerPresentChanged() { }
    virtual void bleConnectedChanged() { }

private:

    uint16_t _year;
    uint8_t _month;
    uint8_t _day;
    uint8_t _dayOfWeek;
        
    uint8_t _hour;
    uint8_t _minute;
    uint8_t _second;
    uint16_t _milliSecond;

    bool _locked;
    uint8_t _batteryPercent;
    bool _powerPresent;
    bool _bleConnected;

    bool _firstUpdate;
};

#endif // WATCHFACE_H
