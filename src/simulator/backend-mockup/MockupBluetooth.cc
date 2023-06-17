#include "MockupBluetooth.h"

#include <string.h>



MockupBluetooth::MockupBluetooth() {
    strcpy(_macAddress, "00:00:00:00:00:00");
    _isConnected = false;
    _firmwareUpdateStatus = FirmwareUpdateStatus::Idle;
    _firmwareUpdateBytesTotal = 0;
    _firmwareUpdateBytesReceived = 0;
}


MockupBluetooth::~MockupBluetooth() {
}


void MockupBluetooth::setMacAddress(const char *address) {
    if (address) {
        strncpy(_macAddress, address, 23);
    }
}


void MockupBluetooth::setIsConnected(bool isConnected) {
    _isConnected = isConnected;
}


void MockupBluetooth::setFirmwareUpdateStatus(FirmwareUpdateStatus status) {
    _firmwareUpdateStatus = status;
}


void MockupBluetooth::setFirmwareUpdateBytesTotal(uint32_t bytes) {
    _firmwareUpdateBytesTotal = bytes;
}


void MockupBluetooth::setFirmwareUpdateBytesReceived(uint32_t bytes) {
    _firmwareUpdateBytesReceived = bytes;
}