#ifndef FIRMWAREVALIDATIONSCREEN_H
#define FIRMWAREVALIDATIONSCREEN_H

#include "frontend/screens/Screen.h"
#include "frontend/ScreenManager.h"


class FirmwareValidationScreen : public Screen {
public:

    FirmwareValidationScreen(BackendInterface *backend, ScreenManager *screenManager, Settings *settings);

private:

    lv_obj_t *_descriptionLabel;
    lv_obj_t *_button;

    void handleButtonClick();

    static void buttonEventCallback(lv_obj_t *object, lv_event_t event);
};

#endif // FIRMWAREVALIDATIONSCREEN_H
