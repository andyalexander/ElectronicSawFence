#include "AccelStepper.h"               // https://www.airspayce.com/mikem/arduino/AccelStepper/

#ifndef __STEPPER_H
#define __STEPPER_H


#define PIN_STEP        D5
#define PIN_DIRECTION   D6
#define PIN_ENABLE      D7

#define STEPS_PER_MM    50

#define MAXSPEED        100
#define ACCLERATION     50

class Stepper
{
    private:
        unsigned long currentPosition;
        unsigned long desiredPosition;
        bool enabled;
        AccelStepper accelStepper;
        long distToSteps(float distance);

    public:
        Stepper();
        void initHardware(void);

        void setEnabled(bool);

        void ISR(void);

        void move(float distance);
        void moveTo(float position);
        long distanceToGo(void);
};

#endif