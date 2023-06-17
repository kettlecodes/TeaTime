#ifndef SETTINGSINTERFACE_H
#define SETTINGSINTERFACE_H

#include <stdint.h>


class SettingsInterface {
public:

    virtual ~SettingsInterface() { }

    virtual uint32_t dailyStepsGoal() const = 0;

    virtual uint8_t displayBrightness() const = 0;

    virtual bool wakeDisplayOnTap() const = 0;
    virtual bool wakeDisplayOnDoubleTap() const = 0;
    virtual bool wakeDisplayOnRaiseWrist() const = 0;
    virtual bool wakeDisplayOnShakeWrist() const = 0;
};

#endif // SETTINGSINTERFACE_H