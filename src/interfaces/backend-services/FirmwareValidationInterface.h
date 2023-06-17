#ifndef FIRMWAREVALIDATIONINTERFACE_H
#define FIRMWAREVALIDATIONINTERFACE_H


class FirmwareValidationInterface {
public:

    virtual ~FirmwareValidationInterface() { }

    virtual bool isValidated() const = 0;

    virtual void validate() = 0;
    virtual void reset() = 0;
};

#endif // FIRMWAREVALIDATIONINTERFACE_H