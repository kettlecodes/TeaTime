#ifndef BRIGHTNESSSCREEN_H
#define BRIGHTNESSSCREEN_H

#include <vector>

#include "frontend/screens/Screen.h"
#include "frontend/ScreenManager.h"


class BrightnessScreen : public Screen {
public:

    BrightnessScreen(BackendInterface *backend, ScreenManager *screenManager, Settings *settings);
    ~BrightnessScreen() override;

private:

    struct OptionInfo {
    public:
        BrightnessScreen *screen;
        uint8_t row;
        lv_obj_t *checkBoxLabel;
    };

    std::vector<OptionInfo *> _optionInfos;

    void addOption(lv_font_t *iconFont, const char *icon, const char *text);
    void updateCheckBoxes();
    void optionClicked(int row);

    static void buttonCallback(lv_obj_t *object, lv_event_t event);
};

#endif // BRIGHTNESSSCREEN_H
