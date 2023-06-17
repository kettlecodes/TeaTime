#ifndef MOCKUPDISPLAY_H
#define MOCKUPDISPLAY_H

#include "interfaces/backend-services/DisplayInterface.h"


class MockupDisplay : public DisplayInterface {
public:

    MockupDisplay();
    ~MockupDisplay() override;

    BrightnessLevel brightness() const override { return _brightness; }
    FullRefreshDirection fullRefreshDirection() const override { return _fullRefreshDirection; }

    void setBrightness(BrightnessLevel brightness) override;
    void setFullRefreshDirection(FullRefreshDirection direction) override;

private:

    BrightnessLevel _brightness;
    FullRefreshDirection _fullRefreshDirection;
};

#endif // MOCKUPDISPLAY_H