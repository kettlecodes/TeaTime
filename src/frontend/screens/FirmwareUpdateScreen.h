#ifndef FIRMWAREUPDATESCREEN_H
#define FIRMWAREUPDATESCREEN_H

#include "frontend/screens/Screen.h"
#include "frontend/ScreenManager.h"

#include "interfaces/BackendInterface.h"


class FirmwareUpdateScreen : public Screen {
public:

    FirmwareUpdateScreen(BackendInterface *backend, ScreenManager *screenManager, Settings *settings);

    void update() override;

private:

    lv_obj_t *_titleLabel;
    lv_obj_t *_progressBar;
    lv_obj_t *_percentageLabel;

    uint32_t _ticksAtStart;
    BluetoothInterface::FirmwareUpdateStatus _status;

    void displayProgress();
    void updateValidated();
    void updateError();
};

#endif // FIRMWAREUPDATESCREEN_H
