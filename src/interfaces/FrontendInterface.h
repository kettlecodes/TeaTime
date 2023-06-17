#ifndef FRONTENDINTERFACE_H
#define FRONTENDINTERFACE_H


class FrontendInterface {
public:

    virtual ~FrontendInterface() { }

    virtual bool init() = 0;
    virtual void update() = 0;

    virtual bool handleButtonPress() = 0;
    virtual bool handleTap() = 0;
    virtual bool handleLongTap() = 0;
    virtual bool handleDoubleTap() = 0;
    virtual bool handleSwipeLeft() = 0;
    virtual bool handleSwipeRight() = 0;
    virtual bool handleSwipeUp() = 0;
    virtual bool handleSwipeDown() = 0;

    virtual bool handlePowerPresentChange() = 0;
    virtual bool handleBluetoothConnectedChange() = 0;
    virtual bool handleFirmwareUpdateStart() = 0;
};

#endif // FRONTENDINTERFACE_H