#ifndef MOCKUPBATTERY_H
#define MOCKUPBATTERY_H

#include "interfaces/backend-services/BatteryInterface.h"


class MockupBattery : public BatteryInterface {
public:

    MockupBattery();
    ~MockupBattery() override;

    uint8_t remainingPercentage() const override { return _remainingPercentage; }
    bool isPowerPresent() const override { return _isPowerPresent; }

    bool measure() override;

    void setRemainingPercentage(uint8_t percentage);
    void setIsPowerPresent(bool isPowerPresent);

private:

    uint8_t _remainingPercentage;
    bool _isPowerPresent;
};

#endif // MOCKUPBATTERY_H