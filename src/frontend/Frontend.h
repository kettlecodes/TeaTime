#ifndef FRONTEND_H
#define FRONTEND_H

#include "interfaces/FrontendInterface.h"

class BackendInterface;
class Settings;
class ScreenManager;


class Frontend : public FrontendInterface {
public:

    Frontend(BackendInterface *backend, Settings *settings);
    ~Frontend() override;

    bool init() override;
    void update() override;

    bool handleButtonPress() override;
    bool handleTap() override;
    bool handleLongTap() override;
    bool handleDoubleTap() override;
    bool handleSwipeLeft() override;
    bool handleSwipeRight() override;
    bool handleSwipeUp() override;
    bool handleSwipeDown() override;

    bool handlePowerPresentChange() override;
    bool handleBluetoothConnectedChange() override;
    bool handleFirmwareUpdateStart() override;

private:

    BackendInterface *_backend;
    ScreenManager *_screenManager;
    Settings *_settings;
};

#endif // FRONTEND_H