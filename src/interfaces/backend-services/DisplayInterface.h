#ifndef DISPLAYINTERFACE_H
#define DISPLAYINTERFACE_H


class DisplayInterface {
public:

    enum class BrightnessLevel {
        Low,
        Medium,
        High
    };

    enum class FullRefreshDirection {
        None,
        Left,
        Right,
        Up,
        Down
    };

    virtual ~DisplayInterface() { }

    virtual BrightnessLevel brightness() const = 0;
    virtual FullRefreshDirection fullRefreshDirection() const = 0;

    virtual void setBrightness(BrightnessLevel brightness) = 0;
    virtual void setFullRefreshDirection(FullRefreshDirection direction) = 0;
};

#endif // DISPLAYINTERFACE_H