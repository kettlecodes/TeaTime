#ifndef MOCKUPWATCHDOG_H
#define MOCKUPWATCHDOG_H

#include "interfaces/backend-services/WatchdogInterface.h"


class MockupWatchdog : public WatchdogInterface {
public:

    MockupWatchdog();
    ~MockupWatchdog() override;

    ResetReason lastResetReason() const override { return _lastResetReason; }

    void setLastResetReason(ResetReason resetReason);

private:

    ResetReason _lastResetReason;
};

#endif // MOCKUPWATCHDOG_H
