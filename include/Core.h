#ifndef __CORE_H
#define __CORE_H


#include "Stepper.h"
#include "Encoder.h"
#include "UI.h"

class Core
{
    private:
        Encoder *encoder;
        Stepper *stepper;
        UI *ui;

    public:
        Core(Encoder *encoder, Stepper *stepper, UI *ui);
        void ISR(void);

        void move(float distance);
};

#endif