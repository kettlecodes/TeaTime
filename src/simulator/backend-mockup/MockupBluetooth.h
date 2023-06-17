#ifndef MOCKUPBLUETOOTH_H
#define MOCKUPBLUETOOTH_H

#include "interfaces/backend-services/BluetoothInterface.h"


class MockupBluetooth : public BluetoothInterface {
public:

    MockupBluetooth();
    ~MockupBluetooth() override;

    const char *macAddress() const override { return _macAddress; }
    bool isConnected() const override { return _isConnected; }
    FirmwareUpdateStatus firmwareUpdateStatus() const override { return _firmwareUpdateStatus; }
    uint32_t firmwareUpdateBytesTotal() const override { return _firmwareUpdateBytesTotal; }
    uint32_t firmwareUpdateBytesReceived() const override { return _firmwareUpdateBytesReceived; }

    void setMacAddress(const char *address);
    void setIsConnected(bool isConnected);
    void setFirmwareUpdateStatus(FirmwareUpdateStatus status);
    void setFirmwareUpdateBytesTotal(uint32_t bytes);
    void setFirmwareUpdateBytesReceived(uint32_t bytes);

private:

    char _macAddress[24];
    bool _isConnected;
    FirmwareUpdateStatus _firmwareUpdateStatus;
    uint32_t _firmwareUpdateBytesTotal;
    uint32_t _firmwareUpdateBytesReceived;
};

#endif // MOCKUPBLUETOOTH_H