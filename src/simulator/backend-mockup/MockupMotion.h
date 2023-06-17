#ifndef MOCKUPMOTION_H
#define MOCKUPMOTION_H

#include "interfaces/backend-services/MotionInterface.h"


class MockupMotion : public MotionInterface {
public:

    MockupMotion();
    ~MockupMotion() override;

    DeviceType deviceType() const override { return _deviceType; }
    uint32_t steps() const override { return _steps; }

    void setDeviceType(DeviceType deviceType);
    void setSteps(uint32_t steps);

private:

    DeviceType _deviceType;
    uint32_t _steps;
};

#endif // MOCKUPMOTION_H