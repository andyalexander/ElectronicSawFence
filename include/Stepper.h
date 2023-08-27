#include "AccelStepper.h"

#ifndef __STEPPER_H
#define __STEPPER_H


#define PIN_STEP        D5
#define PIN_DIRECTION   D6
#define PIN_ENABLE      D7

#define MAXSPEED        100
#define ACCLERATION     50

class Stepper
{
    private:
        unsigned long currentPosition;
        unsigned long desiredPosition;
        bool enabled;
        AccelStepper accelStepper;

    public:
        Stepper();
        void initHardware(void);

        void setEnabled(bool);

        void ISR(void);
};

#endif