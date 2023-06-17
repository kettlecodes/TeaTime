#include <SDL2/SDL.h>
#include <stdio.h>
#include "lvgl.h"

#include "frontend/Frontend.h"
#include "backend-mockup/MockupBackend.h"
#include "backend-mockup/MockupBluetooth.h"
#include "backend-mockup/MockupDateTime.h"
#include "settings/Settings.h"


#define DISPLAY_ZOOM   2


static SDL_Texture *texture;
static int redOfs;
static int greenOfs;
static int blueOfs;
static lv_disp_buf_t displayBufferInfo;
static lv_color_t displayBuffer[240 * 240];
static lv_disp_drv_t displayDriver;
static lv_indev_drv_t inputDriver;


void sdl_flush_cb(lv_disp_drv_t *dispDriver, const lv_area_t *area, lv_color_t *colors) {
    void *pixels = nullptr;
    int pitch = 0;
    if (SDL_LockTexture(texture, nullptr, &pixels, &pitch) == 0) {
        Uint8 *buffer = reinterpret_cast<Uint8 *>(pixels);
        for (int y = area->y1; y <= area->y2; y++) {
            int ofs = y * pitch + 3 * area->x1;
            for (int x = area->x1; x <= area->x2; x++) {
                Uint32 color32 = lv_color_to32(*colors);
                buffer[ofs + redOfs] = (color32 >> 16) & 0xff;
                buffer[ofs + greenOfs] = (color32 >> 8) & 0xff;
                buffer[ofs + blueOfs] = color32 & 0xff;
                ofs += 3;
                colors++;
            }
        }
        SDL_UnlockTexture(texture);
    }
    else {
        fprintf(stderr, "Could not lock texture: %s\n", SDL_GetError());
    }
    lv_disp_flush_ready(dispDriver);
}


bool sdl_input_read_cb(lv_indev_drv_t *driver, lv_indev_data_t *data) {
    int mouseX = 0;
    int mouseY = 0;
    Uint32 mouseButtons = SDL_GetMouseState(&mouseX, &mouseY);
    data->point.x = (mouseX - 8) / DISPLAY_ZOOM;
    data->point.y = (mouseY - 8) / DISPLAY_ZOOM;
    data->state = (mouseButtons & SDL_BUTTON_LMASK) ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;
    return false;
}


int main(int argc, char *argv[]) {
    int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    if (result != 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return -1;
    }

    int edgeLength = 16 + 240 * DISPLAY_ZOOM;
    SDL_Window *window = SDL_CreateWindow("SDL Test Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, edgeLength, edgeLength, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Could not open SDL window: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Could not create SDL renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, 240, 240);
    if (!texture) {
        fprintf(stderr, "Could not create SDL texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    Uint32 textureFormat = 0;
    SDL_QueryTexture(texture, &textureFormat, nullptr, nullptr, nullptr);
    if (SDL_PIXELORDER(textureFormat) == SDL_ARRAYORDER_BGR) {
        redOfs = 2;
        greenOfs = 1;
        blueOfs = 0;
    } else {
        redOfs = 0;
        greenOfs = 1;
        blueOfs = 2;
    }

    lv_init();
    lv_disp_buf_init(&displayBufferInfo, displayBuffer, nullptr, 240 * 240);
    lv_disp_drv_init(&displayDriver);
    displayDriver.buffer = &displayBufferInfo;
    displayDriver.flush_cb = sdl_flush_cb;
    lv_disp_t *display = lv_disp_drv_register(&displayDriver);
    lv_disp_set_default(display);
    lv_indev_drv_init(&inputDriver);
    inputDriver.type = LV_INDEV_TYPE_POINTER;
    inputDriver.read_cb = sdl_input_read_cb;
    lv_indev_t *input = lv_indev_drv_register(&inputDriver);

    MockupBackend backend;
    Settings settings(&backend);
    Frontend frontend(&backend, &settings);
    frontend.init();

    bool firmwareUpdating = false;
    double firmwareUpdateProgress = 0.0;

    bool running = true;
    Uint32 lastTicks = SDL_GetTicks();
    while (running) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Rect dstRect;
        dstRect.x = 8;
        dstRect.y = 8;
        dstRect.w = 240 * DISPLAY_ZOOM;
        dstRect.h = 240 * DISPLAY_ZOOM;
        SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN: {
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            running = false;
                            break;
                        case SDLK_b:
                            frontend.handleButtonPress();
                            break;
                        case SDLK_RIGHT:
                            frontend.handleSwipeRight();
                            break;
                        case SDLK_LEFT:
                            frontend.handleSwipeLeft();
                            break;
                        case SDLK_UP:
                            frontend.handleSwipeUp();
                            break;
                        case SDLK_DOWN:
                            frontend.handleSwipeDown();
                            break;
                        case SDLK_f:
                            if (!firmwareUpdating) {
                                firmwareUpdating = true;
                                firmwareUpdateProgress = -10.0;
                                MockupBluetooth *mbt = reinterpret_cast<MockupBluetooth *>(backend.bluetooth());
                                mbt->setFirmwareUpdateStatus(BluetoothInterface::FirmwareUpdateStatus::Idle);
                                mbt->setFirmwareUpdateBytesTotal(100000);
                                mbt->setFirmwareUpdateBytesReceived(0);
                                frontend.handleFirmwareUpdateStart();
                            }
                        default:
                            break;
                    }
                }
                default:
                    break;
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(10);

        MockupDateTime *dateTime = reinterpret_cast<MockupDateTime *>(backend.dateTime());
        dateTime->setToSystemTime();
        if (firmwareUpdating) {
            firmwareUpdateProgress += 0.05;
            MockupBluetooth *mbt = reinterpret_cast<MockupBluetooth *>(backend.bluetooth());
            if ((firmwareUpdateProgress > 0.0) && (firmwareUpdateProgress < 100.0)) {
                mbt->setFirmwareUpdateStatus(BluetoothInterface::FirmwareUpdateStatus::Running);
                Uint32 bytesReceived = static_cast<Uint32>(firmwareUpdateProgress * 100000.0 * 0.01);
                if (bytesReceived < 0) {
                    bytesReceived = 0;
                }
                else if (bytesReceived > 100000) {
                    bytesReceived = 100000;
                }
                mbt->setFirmwareUpdateBytesReceived(bytesReceived);
            }
            else if (firmwareUpdateProgress >= 100.0) {
                if (firmwareUpdateProgress < 110.0) {
                    mbt->setFirmwareUpdateStatus(BluetoothInterface::FirmwareUpdateStatus::Validated);
                    mbt->setFirmwareUpdateBytesReceived(100000);
                }
                else {
                    firmwareUpdating = false;
                    mbt->setFirmwareUpdateBytesTotal(0);
                    mbt->setFirmwareUpdateBytesReceived(0);
                    mbt->setFirmwareUpdateStatus(BluetoothInterface::FirmwareUpdateStatus::Idle);
                    frontend.init();
                }
            }
        }

        frontend.update();
        Uint32 nowTicks = SDL_GetTicks();
        lv_tick_inc(nowTicks - lastTicks);
        lv_task_handler();
        lastTicks = nowTicks;
    }
    
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}