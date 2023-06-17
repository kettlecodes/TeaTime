#include "ScreenManager.h"

#include "interfaces/BackendInterface.h"
#include "settings/Settings.h"
#include "screens/Screen.h"
#include "screens/watchfaces/UtilityWatchface.h"
#include "screens/watchfaces/InfographWatchface.h"
#include "screens/settings/SettingsScreen.h"
#include "screens/settings/BrightnessScreen.h"
#include "screens/settings/WakeUpModeScreen.h"
#include "screens/settings/StepsGoalScreen.h"
#include "screens/settings/SystemInfoScreen.h"
#include "screens/settings/FirmwareValidationScreen.h"
#include "screens/FirmwareUpdateScreen.h"


#define MAX_PREVIOUS_SCREENS    4


ScreenManager::ScreenManager(BackendInterface *backend, Settings *settings) {
    // initialize
    _backend = backend;
    _settings = settings;
    _currentScreen = nullptr;
    reset();
}


void ScreenManager::reset() {
    // clean up
    if (_currentScreen) {
        delete _currentScreen;
        _currentScreen = nullptr;
    }
    _currentId = ScreenId::Undefined;
    _nextId = ScreenId::Undefined;
    _nextPageNumber = 1;
    _nextEffect = TransitionEffect::None;
    _transitions.clear();
    _previousScreens.clear();

    // set up all possible transitions
    addTransition(ScreenId::UtilityWatchface, TransitionTrigger::SwipeUp, ScreenId::SettingsScreen);
    addTransition(ScreenId::UtilityWatchface, TransitionTrigger::SwipeLeft, ScreenId::InfographWatchface);
    addTransition(ScreenId::InfographWatchface, TransitionTrigger::SwipeUp, ScreenId::SettingsScreen);
    addTransition(ScreenId::InfographWatchface, TransitionTrigger::SwipeLeft, ScreenId::UtilityWatchface);
    addTransition(ScreenId::SettingsScreen, TransitionTrigger::ButtonPress, ScreenId::DefaultWatchface);
    addTransition(ScreenId::SettingsScreen, TransitionTrigger::SwipeDown, ScreenId::DefaultWatchface);
    addTransition(ScreenId::BrightnessScreen, TransitionTrigger::ButtonPress, ScreenId::DefaultWatchface);
    addTransition(ScreenId::BrightnessScreen, TransitionTrigger::SwipeRight, ScreenId::Previous);
    addTransition(ScreenId::WakeUpModeScreen, TransitionTrigger::ButtonPress, ScreenId::DefaultWatchface);
    addTransition(ScreenId::WakeUpModeScreen, TransitionTrigger::SwipeRight, ScreenId::Previous);
    addTransition(ScreenId::StepsGoalScreen, TransitionTrigger::ButtonPress, ScreenId::DefaultWatchface);
    addTransition(ScreenId::StepsGoalScreen, TransitionTrigger::SwipeRight, ScreenId::Previous);
    addTransition(ScreenId::SystemInfoScreen, TransitionTrigger::ButtonPress, ScreenId::DefaultWatchface);
    addTransition(ScreenId::SystemInfoScreen, TransitionTrigger::SwipeRight, ScreenId::Previous);
    addTransition(ScreenId::FirmwareValidationScreen, TransitionTrigger::ButtonPress, ScreenId::DefaultWatchface);
    addTransition(ScreenId::FirmwareValidationScreen, TransitionTrigger::SwipeRight, ScreenId::Previous);

    // set initial screen
    switchScreen(ScreenId::DefaultWatchface, 1, TransitionEffect::None);
}


ScreenManager::~ScreenManager() {
    // delete the current screen
    if (_currentScreen) {
        delete _currentScreen;
    }
}


void ScreenManager::addTransition(ScreenId fromScreenId, TransitionTrigger trigger,
                                  ScreenId toScreenId,
                                  TransitionEffect effect) {
    addTransition(fromScreenId, trigger, toScreenId, 1, effect);
}


void ScreenManager::addTransition(ScreenId fromScreenId, TransitionTrigger trigger,
                                  ScreenId toScreenId, int toPageNumber,
                                  TransitionEffect effect) {
    // guards
    if ((fromScreenId == ScreenId::Undefined)
        || (fromScreenId == ScreenId::Previous)
        || (toScreenId == ScreenId::Undefined)) {
        return;
    }

    // create the transition record
    Transition transition;
    transition.fromScreenId = fromScreenId;
    transition.trigger = trigger;
    transition.toScreenId = toScreenId;
    transition.toPageNumber = toPageNumber;
    transition.effect = effect;

    // swipe transitions always have an effect
    if (transition.effect == TransitionEffect::None) {
        switch (trigger) {
            case TransitionTrigger::SwipeLeft:
                transition.effect = TransitionEffect::MoveLeft;
                break;
            case TransitionTrigger::SwipeRight:
                transition.effect = TransitionEffect::MoveRight;
                break;
            case TransitionTrigger::SwipeUp:
                transition.effect = TransitionEffect::MoveUp;
                break;
            case TransitionTrigger::SwipeDown:
                transition.effect = TransitionEffect::MoveDown;
                break;
            default:
                break;
        }
    }

    // add the transition to the list
    _transitions.push_back(transition);
}


void ScreenManager::activateScreen(ScreenId screenId, TransitionEffect effect) {
    activateScreen(screenId, 1, effect);
}


void ScreenManager::activateScreen(ScreenId screenId, int pageNumber, TransitionEffect effect) {
    // the screen will be switched during the next update
    _nextId = screenId;
    _nextPageNumber = pageNumber;
    _nextEffect = effect;
}


void ScreenManager::updateScreen() {
    // do we need to switch the screen?
    if (_nextId != ScreenId::Undefined) {
        switchScreen(_nextId, _nextPageNumber, _nextEffect);
    }
    else {
        // forward the update to the current screen
        if (_currentScreen) {
            _currentScreen->update();
        }
    }
}


bool ScreenManager::handleButtonPress() {
    // check of the current screen wants to handle the event
    if (_currentScreen) {
        if (_currentScreen->handleButtonPress()) {
            return true;
        }
    }

    // check if there's a matching transition
    for (Transition transition : _transitions) {
        if ((transition.trigger == TransitionTrigger::ButtonPress) && (transition.fromScreenId == _currentId)) {
            switchScreen(transition.toScreenId, transition.toPageNumber, transition.effect);
            return true;
        }
    }

    // unhandled
    return false;
}


bool ScreenManager::handleTap() {
    // check of the current screen wants to handle the event
    if (_currentScreen) {
        if (_currentScreen->handleTap()) {
            return true;
        }
    }

    // check if there's a matching transition
    for (Transition transition : _transitions) {
        if ((transition.trigger == TransitionTrigger::Tap) && (transition.fromScreenId == _currentId)) {
            switchScreen(transition.toScreenId, transition.toPageNumber, transition.effect);
            return true;
        }
    }

    // unhandled
    return false;
}


bool ScreenManager::handleLongTap() {
    // check of the current screen wants to handle the event
    if (_currentScreen) {
        if (_currentScreen->handleLongTap()) {
            return true;
        }
    }

    // check if there's a matching transition
    for (Transition transition : _transitions) {
        if ((transition.trigger == TransitionTrigger::LongTap) && (transition.fromScreenId == _currentId)) {
            switchScreen(transition.toScreenId, transition.toPageNumber, transition.effect);
            return true;
        }
    }

    // unhandled
    return false;
}


bool ScreenManager::handleDoubleTap() {
    // check of the current screen wants to handle the event
    if (_currentScreen) {
        if (_currentScreen->handleDoubleTap()) {
            return true;
        }
    }

    // check if there's a matching transition
    for (Transition transition : _transitions) {
        if ((transition.trigger == TransitionTrigger::DoubleTap) && (transition.fromScreenId == _currentId)) {
            switchScreen(transition.toScreenId, transition.toPageNumber, transition.effect);
            return true;
        }
    }

    // unhandled
    return false;
}


bool ScreenManager::handleSwipeLeft() {
    // check of the current screen wants to handle the event
    if (_currentScreen) {
        if (_currentScreen->handleSwipeLeft()) {
            return true;
        }
    }

    // check if there's a matching transition
    for (Transition transition : _transitions) {
        if ((transition.trigger == TransitionTrigger::SwipeLeft) && (transition.fromScreenId == _currentId)) {
            switchScreen(transition.toScreenId, transition.toPageNumber, transition.effect);
            return true;
        }
    }

    // unhandled
    return false;
}


bool ScreenManager::handleSwipeRight() {
    // check of the current screen wants to handle the event
    if (_currentScreen) {
        if (_currentScreen->handleSwipeRight()) {
            return true;
        }
    }

    // check if there's a matching transition
    for (Transition transition : _transitions) {
        if ((transition.trigger == TransitionTrigger::SwipeRight) && (transition.fromScreenId == _currentId)) {
            switchScreen(transition.toScreenId, transition.toPageNumber, transition.effect);
            return true;
        }
    }

    // unhandled
    return false;
}


bool ScreenManager::handleSwipeUp() {
    // check of the current screen wants to handle the event
    if (_currentScreen) {
        if (_currentScreen->handleSwipeUp()) {
            return true;
        }
    }

    // check if there's a matching transition
    for (Transition transition : _transitions) {
        if ((transition.trigger == TransitionTrigger::SwipeUp) && (transition.fromScreenId == _currentId)) {
            switchScreen(transition.toScreenId, transition.toPageNumber, transition.effect);
            return true;
        }
    }

    // unhandled
    return false;
}


bool ScreenManager::handleSwipeDown() {
    // check of the current screen wants to handle the event
    if (_currentScreen) {
        if (_currentScreen->handleSwipeDown()) {
            return true;
        }
    }

    // check if there's a matching transition
    for (Transition transition : _transitions) {
        if ((transition.trigger == TransitionTrigger::SwipeDown) && (transition.fromScreenId == _currentId)) {
            switchScreen(transition.toScreenId, transition.toPageNumber, transition.effect);
            return true;
        }
    }

    // unhandled
    return false;
}


void ScreenManager::switchScreen(ScreenId screenId, int pageNumber, TransitionEffect effect) {
    // clear the "next screen" information
    _nextId = ScreenId::Undefined;
    _nextPageNumber = 1;
    _nextEffect = TransitionEffect::None;

    // guards
    if (screenId == ScreenId::Undefined) {
        return;
    }

    // handle special case: ID == Previous
    if (screenId == ScreenId::Previous) {
        // the screens stack must not be empty for this to work
        if (_previousScreens.empty()) {
            return;
        }

        // update destination ID and page number
        ScreenInfo prevScreen = _previousScreens.back();
        screenId = prevScreen.id;
        pageNumber = prevScreen.pageNumber;

        // remove that screen from the stack
        _previousScreens.pop_back();
    }
    else {
        // make sure that the screens stack doesn't exceed its maximum size
        while (static_cast<int>(_previousScreens.size()) >= MAX_PREVIOUS_SCREENS) {
            _previousScreens.erase(_previousScreens.begin());
        }

        // remember the current screen
        ScreenInfo screen;
        screen.id = _currentId;
        screen.pageNumber = _currentScreen ? _currentScreen->currentPage() : 1;
        _previousScreens.push_back(screen);
    }

    // handle another special case: ID == DefaultWatchface
    if (screenId == ScreenId::DefaultWatchface) {
        //TODO ... get from frontend settings
        screenId = ScreenId::UtilityWatchface;

        // stay on the current screen if no valid ID has been returned
        if (screenId == ScreenId::Undefined) {
            _previousScreens.pop_back();
            return;
        }
    }

    // apply the transition effect
    switch (effect) {
        case TransitionEffect::MoveLeft:
            _backend->display()->setFullRefreshDirection(DisplayInterface::FullRefreshDirection::Right);
            break;
        case TransitionEffect::MoveRight:
            _backend->display()->setFullRefreshDirection(DisplayInterface::FullRefreshDirection::Left);
            break;
        case TransitionEffect::MoveUp:
            _backend->display()->setFullRefreshDirection(DisplayInterface::FullRefreshDirection::Up);
            break;
        case TransitionEffect::MoveDown:
            _backend->display()->setFullRefreshDirection(DisplayInterface::FullRefreshDirection::Down);
            break;
        default:
            break;
    }

    // delete the old screen and create the new one
    if (_currentScreen) {
        delete _currentScreen;
    }
    _currentScreen = createScreen(screenId);
    if (_currentScreen) {
        _currentId = screenId;
        _currentScreen->setCurrentPage(pageNumber);
    }
}


Screen* ScreenManager::createScreen(ScreenId screenId) {
    switch (screenId) {
        case ScreenId::UtilityWatchface:
            return new UtilityWatchface(_backend, this, _settings);
        case ScreenId::InfographWatchface:
            return new InfographWatchface(_backend, this, _settings);
        case ScreenId::SettingsScreen:
            return new SettingsScreen(_backend, this, _settings);
        case ScreenId::BrightnessScreen:
            return new BrightnessScreen(_backend, this, _settings);
        case ScreenId::WakeUpModeScreen:
            return new WakeUpModeScreen(_backend, this, _settings);
        case ScreenId::StepsGoalScreen:
            return new StepsGoalScreen(_backend, this, _settings);
        case ScreenId::SystemInfoScreen:
            return new SystemInfoScreen(_backend, this, _settings);
        case ScreenId::FirmwareValidationScreen:
            return new FirmwareValidationScreen(_backend, this, _settings);
        case ScreenId::FirmwareUpdateScreen:
            return new FirmwareUpdateScreen(_backend, this, _settings);
        default:
            return nullptr;
    }
}