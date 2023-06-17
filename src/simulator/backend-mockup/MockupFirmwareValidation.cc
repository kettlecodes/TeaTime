#include "MockupFirmwareValidation.h"


MockupFirmwareValidation::MockupFirmwareValidation() {
    _isValidated = false;
}


MockupFirmwareValidation::~MockupFirmwareValidation() {
}


void MockupFirmwareValidation::validate() {
    _isValidated = true;
}


void MockupFirmwareValidation::reset() {
    _isValidated = false;
}