#ifndef __CORE_H
#define __CORE_H


#include "Stepper.h"
#include "Encoder.h"

class Core
{
    private:
        Encoder *encoder;
        Stepper *stepper;

    public:
        Core(Encoder *encoder, Stepper *stepper);
        void ISR(void);
};

#endif