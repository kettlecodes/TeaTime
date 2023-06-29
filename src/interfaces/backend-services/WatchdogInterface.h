#ifndef WATCHDOGINTERFACE_H
#define WATCHDOGINTERFACE_H


class WatchdogInterface {
public:

    enum class ResetReason {
        ResetPin,
        Watchdog,
        SoftReset,
        CpuLockup,
        SystemOff,
        LpComp,
        DebugInterface,
        NFC,
        HardReset
    };


    virtual ~WatchdogInterface() { }

    virtual ResetReason lastResetReason() const = 0;
};

#endif // WATCHDOGINTERFACE_H
