#ifndef MOCKUPFIRMWAREVALIDATION_H
#define MOCKUPFIRMWAREVALIDATION_H

#include "interfaces/backend-services/FirmwareValidationInterface.h"


class MockupFirmwareValidation : public FirmwareValidationInterface {
public:

    MockupFirmwareValidation();
    ~MockupFirmwareValidation() override;

    bool isValidated() const override { return _isValidated; }
    
    void validate() override;
    void reset() override;

private:

    bool _isValidated;
};

#endif // MOCKUPFIRMWAREVALIDATION_H