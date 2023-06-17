#ifndef BLUETOOTHINTERFACE_H
#define BLUETOOTHINTERFACE_H

#include <stdint.h>


class BluetoothInterface {
public:

    enum class FirmwareUpdateStatus {
        Idle,
        Running,
        Validated,
        Failed
    };

    virtual ~BluetoothInterface() { }

    virtual const char *macAddress() const = 0;
    virtual bool isConnected() const = 0;
    virtual FirmwareUpdateStatus firmwareUpdateStatus() const = 0;
    virtual uint32_t firmwareUpdateBytesTotal() const = 0;
    virtual uint32_t firmwareUpdateBytesReceived() const = 0;
};

#endif // BLUETOOTHINTERFACE_H