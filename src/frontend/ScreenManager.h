#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <vector>

class BackendInterface;
class Settings;
class Screen;


class ScreenManager {
public:

    enum class ScreenId {
        Undefined,
        Previous,
        DefaultWatchface,
        UtilityWatchface,
        InfographWatchface,
        SettingsScreen,
        BrightnessScreen,
        WakeUpModeScreen,
        StepsGoalScreen,
        SystemInfoScreen,
        FirmwareValidationScreen,
        FirmwareUpdateScreen
    };

    enum class TransitionTrigger {
        ButtonPress,
        ButtonPressLong,
        ButtonPressLonger,
        SwipeLeft,
        SwipeRight,
        SwipeUp,
        SwipeDown,
        Tap,
        LongTap,
        DoubleTap,
        Inactivity
    };

    enum class TransitionEffect {
        None,
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown
    };

    ScreenManager(BackendInterface *backend, Settings *settings);
    virtual ~ScreenManager();

    Screen *currentScreen() const { return _currentScreen; }

    void reset();

    void activateScreen(ScreenId screenId, TransitionEffect effect = TransitionEffect::None);
    void activateScreen(ScreenId screenId, int pageNumber, TransitionEffect effect = TransitionEffect::None);

    void updateScreen();

    bool handleButtonPress();
    bool handleTap();
    bool handleLongTap();
    bool handleDoubleTap();
    bool handleSwipeLeft();
    bool handleSwipeRight();
    bool handleSwipeUp();
    bool handleSwipeDown();

protected:

    struct Transition {
    public:
        TransitionTrigger trigger;
        ScreenId fromScreenId;
        ScreenId toScreenId;
        int toPageNumber;
        TransitionEffect effect;
    };

    struct ScreenInfo {
    public:
        ScreenId id;
        int pageNumber;
    };

    BackendInterface *_backend;
    Settings *_settings;
    ScreenId _currentId;
    Screen *_currentScreen;
    ScreenId _nextId;
    int _nextPageNumber;
    TransitionEffect _nextEffect;
    std::vector<Transition> _transitions;
    std::vector<ScreenInfo> _previousScreens;

    void addTransition(ScreenId fromScreenId, TransitionTrigger trigger,
                       ScreenId toScreenId,
                       TransitionEffect effect = TransitionEffect::None);
    void addTransition(ScreenId fromScreenId, TransitionTrigger trigger,
                       ScreenId toScreenId, int toPageNumber,
                       TransitionEffect effect = TransitionEffect::None);

    void switchScreen(ScreenId screenId, int pageNumber, TransitionEffect effect);

    Screen *createScreen(ScreenId screenId);
};

#endif // SCREENMANAGER_H