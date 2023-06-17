#ifndef SETTINGS_H
#define SETTINGS_H

#include "interfaces/SettingsInterface.h"

class BackendInterface;


class Settings : public SettingsInterface {
public:

    Settings(BackendInterface *backend);
    ~Settings() override;

    uint32_t dailyStepsGoal() const override { return _dailyStepsGoal; }

    uint8_t displayBrightness() const override { return _displayBrightness; }

    bool wakeDisplayOnTap() const override;
    bool wakeDisplayOnDoubleTap() const override;
    bool wakeDisplayOnRaiseWrist() const override;
    bool wakeDisplayOnShakeWrist() const override;

    void setDailyStepsGoal(uint32_t steps);

    void setDisplayBrightness(uint8_t brightness);

    void setWakeDisplayOnTap(bool wake);
    void setWakeDisplayOnDoubleTap(bool wake);
    void setWakeDisplayOnRaiseWrist(bool wake);
    void setWakeDisplayOnShakeWrist(bool wake);

private:

    BackendInterface *_backend;
    uint32_t _dailyStepsGoal;
    uint8_t _displayBrightness;
    uint8_t _displayWakeFlags;

    void loadSettings();
    void saveSettings();
};

#endif // SETTINGS_H