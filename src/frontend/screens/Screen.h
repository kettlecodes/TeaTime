#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>
#include <lvgl/lvgl.h>

class BackendInterface;
class ScreenManager;
class Settings;



class Screen
{
public:

    Screen(BackendInterface *backend, ScreenManager *screenManager, Settings *settings);
    virtual ~Screen();

    bool isRunning() const { return _isRunning; }

    virtual lv_color_t backgroundColor() const { return lv_color_hex(0x000000); }
    virtual lv_color_t foregroundColor() const { return lv_color_hex(0xffffff); }

    virtual bool isMultiPageScreen() const { return false; }
    virtual uint8_t pageCount() const { return 1; }
    uint8_t currentPage() const { return _currentPage; }
    bool setCurrentPage(uint8_t value);

    virtual void update();

    virtual bool handleButtonPress();
    virtual bool handleTap();
    virtual bool handleLongTap();
    virtual bool handleDoubleTap();
    virtual bool handleSwipeLeft();
    virtual bool handleSwipeRight();
    virtual bool handleSwipeUp();
    virtual bool handleSwipeDown();

protected:

        bool _isRunning;

        BackendInterface *backend() { return _backend; }
        ScreenManager *screenManager() { return _screenManager; }
        Settings *settings() { return _settings; }

        lv_obj_t *createLabel(const lv_font_t *font, lv_color_t color, lv_label_align_t align, bool autoAlign);
        lv_obj_t *createLabel(lv_obj_t *parent, const lv_font_t *font, lv_color_t color, lv_label_align_t align, bool autoAlign);

        lv_obj_t *createTitleLabel(const char *title);

        lv_obj_t *createButton(lv_coord_t width = 64, lv_coord_t height = 48);
        lv_obj_t *createButton(lv_obj_t *parent, lv_coord_t width = 64, lv_coord_t height = 48);
        lv_obj_t *createButton(const lv_font_t *iconFont, const char *icon, lv_coord_t width = 64, lv_coord_t height = 48);
        lv_obj_t *createButton(lv_obj_t *parent, const lv_font_t *iconFont, const char *icon, lv_coord_t width = 64, lv_coord_t height = 48);

        virtual void handleCurrentPageChange();
        virtual void addPageNumberWidgets();

private:

    BackendInterface *_backend;
    ScreenManager *_screenManager;
    Settings *_settings;

    uint8_t _currentPage;

    lv_style_t _buttonStyle;
};

#endif // SCREEN_H
