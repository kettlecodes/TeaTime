#ifndef INFOGRAPHWATCHFACE_H
#define INFOGRAPHWATCHFACE_H

#include <stdint.h>

#include "Watchface.h"



class InfographWatchface : public Watchface {
public:

    InfographWatchface(BackendInterface *backend, ScreenManager *screenManager, Settings *settings);

protected:

    ScreenManager::ScreenId screenId() const override { return ScreenManager::ScreenId::InfographWatchface; }

    void dayChanged(bool yearChanged, bool monthChanged) override;
    void timeChanged(bool hourChanged, bool minuteChanged, bool secondChanged) override;

    void lockedStateChanged() override;
    void batteryPercentChanged() override;
    void powerPresentChanged() override { updatePowerAndBleSymbols(); }
    void bleConnectedChanged() override { updatePowerAndBleSymbols(); }

private:

    uint32_t _prevSteps;
    uint32_t _prevStepsGoal;

    lv_obj_t *_dayOfWeekLabel;
    lv_obj_t *_dayOfMonthLabel;
    lv_obj_t *_weatherSymbol;
    lv_obj_t *_stepsArc;
    lv_obj_t *_batteryArc;
    lv_obj_t *_batteryLabel;
    lv_obj_t *_hourHandInner;
    lv_point_t _hourHandInnerPoints[2];
    lv_obj_t *_hourHandOuter;
    lv_point_t _hourHandOuterPoints[2];
    lv_obj_t *_minuteHandInner;
    lv_point_t _minuteHandInnerPoints[2];
    lv_obj_t *_minuteHandOuter;
    lv_point_t _minuteHandOuterPoints[2];
    lv_obj_t *_secondHand;
    lv_point_t _secondHandPoints[2];
    lv_obj_t *_secondTail;
    lv_point_t _secondTailPoints[2];
    lv_obj_t *_powerPresentSymbol;
    lv_obj_t *_bleSymbol;
    lv_obj_t *_lockSymbol;

    lv_style_t _basicArcStyle;

    void updateHands(bool hourChanged, bool minuteChanged);
    void updatePowerAndBleSymbols();

    int16_t roundedCoord(double value);
    uint16_t stepsEndAngle(uint32_t steps);

    const char *dayOfWeekText();
};

#endif // INFOGRAPHWATCHFACE_H
