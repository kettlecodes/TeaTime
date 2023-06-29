#include "MockupWatchdog.h"


MockupWatchdog::MockupWatchdog() {
    _lastResetReason = ResetReason::HardReset;
}


MockupWatchdog::~MockupWatchdog() {
}


void MockupWatchdog::setLastResetReason(ResetReason resetReason) {
    _lastResetReason = resetReason;
}
