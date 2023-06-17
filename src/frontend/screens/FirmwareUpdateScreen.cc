#include "FirmwareUpdateScreen.h"

#include <lvgl/lvgl.h>

#include "frontend/fonts/font_dvs_ascii_16.h"


#define BG_COLOR           0x000000
#define BG_COLOR_BAR       0x404040
#define FG_COLOR_DEFAULT   0xe0e0e0
#define FG_COLOR_SUCCESS   0x00b000
#define FG_COLOR_ERROR     0xff0000



FirmwareUpdateScreen::FirmwareUpdateScreen(BackendInterface *backend, ScreenManager *screenManager, Settings *settings)
        : Screen(backend, screenManager, settings) {
    // set background color
    lv_obj_set_style_local_bg_color(lv_scr_act(), LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(BG_COLOR));

    // create title label
    _titleLabel = createLabel(&font_dvs_ascii_16, lv_color_hex(FG_COLOR_DEFAULT), LV_LABEL_ALIGN_CENTER, false);
    lv_label_set_text_static(_titleLabel, "Firmware update");
    lv_obj_align(_titleLabel, nullptr, LV_ALIGN_IN_TOP_MID, 0, 50);

    // create the progress bar
    _progressBar = lv_bar_create(lv_scr_act(), nullptr);
    lv_obj_set_size(_progressBar, 200, 24);
    lv_obj_align(_progressBar, nullptr, LV_ALIGN_CENTER, 0, 0);
    lv_bar_set_anim_time(_progressBar, 10);
    lv_bar_set_range(_progressBar, 0, 100);
    lv_bar_set_value(_progressBar, 0, LV_ANIM_OFF);
    lv_obj_set_style_local_bg_color(_progressBar, LV_BAR_PART_BG, LV_STATE_DEFAULT, lv_color_hex(BG_COLOR_BAR));
    lv_obj_set_style_local_bg_opa(_progressBar, LV_BAR_PART_BG, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_obj_set_style_local_radius(_progressBar, LV_BAR_PART_BG, LV_STATE_DEFAULT, 12);
    lv_obj_set_style_local_bg_color(_progressBar, LV_BAR_PART_INDIC, LV_STATE_DEFAULT, lv_color_hex(FG_COLOR_DEFAULT));
    lv_obj_set_style_local_bg_opa(_progressBar, LV_BAR_PART_INDIC, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_obj_set_style_local_radius(_progressBar, LV_BAR_PART_INDIC, LV_STATE_DEFAULT, 12);

    // create the percentage label
    _percentageLabel = createLabel(&font_dvs_ascii_16, lv_color_hex(FG_COLOR_DEFAULT), LV_LABEL_ALIGN_CENTER, true);
    lv_label_set_text_static(_percentageLabel, "Waiting...");
    lv_obj_align(_percentageLabel, _progressBar, LV_ALIGN_OUT_TOP_MID, 0, 60);

    // remember when the screen's come up
    _ticksAtStart = lv_tick_get();
    _status = BluetoothInterface::FirmwareUpdateStatus::Idle;
}


void FirmwareUpdateScreen::update() {
    switch (this->backend()->bluetooth()->firmwareUpdateStatus()) {
        default:
            // Idle
            // This condition makes sure that the app is exited if somehow it got
            // launched without a firmware update. This should never happen.
            if (_status != BluetoothInterface::FirmwareUpdateStatus::Failed) {
                if ((lv_tick_get() - _ticksAtStart) > (60 * 1024)) {
                    updateError();
                    _status = BluetoothInterface::FirmwareUpdateStatus::Failed;
                }
            }
            else if ((lv_tick_get() - _ticksAtStart) > (5 * 1024)) {
                _isRunning = false;
            }
            break;
        case BluetoothInterface::FirmwareUpdateStatus::Running:
            if (_status != BluetoothInterface::FirmwareUpdateStatus::Running) {
                _status = BluetoothInterface::FirmwareUpdateStatus::Running;
            }
            displayProgress();
            break;
        case BluetoothInterface::FirmwareUpdateStatus::Validated:
            if (_status != BluetoothInterface::FirmwareUpdateStatus::Validated) {
                updateValidated();
                _status = BluetoothInterface::FirmwareUpdateStatus::Validated;
            }
            break;
        case BluetoothInterface::FirmwareUpdateStatus::Failed:
            if (_status != BluetoothInterface::FirmwareUpdateStatus::Failed) {
                updateError();
                _status = BluetoothInterface::FirmwareUpdateStatus::Failed;
            }
            if ((lv_tick_get() - _ticksAtStart) > (5 * 1024)) {
                _isRunning = false;
            }
            break;
    }
}


void FirmwareUpdateScreen::displayProgress() {
    float current = static_cast<float>(this->backend()->bluetooth()->firmwareUpdateBytesReceived()) / 1024.0f;
    float total = static_cast<float>(this->backend()->bluetooth()->firmwareUpdateBytesTotal()) / 1024.0f;
    int16_t pc = static_cast<int16_t>((current / total) * 100.0f);
    lv_obj_set_style_local_text_color(_percentageLabel, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(FG_COLOR_DEFAULT));
    lv_label_set_text_fmt(_percentageLabel, "%d%%", pc);
    lv_bar_set_value(_progressBar, pc, LV_ANIM_OFF);
}


void FirmwareUpdateScreen::updateValidated() {
    lv_obj_set_style_local_text_color(_percentageLabel, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(FG_COLOR_SUCCESS));
    lv_label_set_text_static(_percentageLabel, "Image ok!");
}


void FirmwareUpdateScreen::updateError() {
    lv_obj_set_style_local_text_color(_percentageLabel, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(FG_COLOR_ERROR));
    lv_label_set_text_static(_percentageLabel, "Update failed!");
    _ticksAtStart = lv_tick_get();
}
