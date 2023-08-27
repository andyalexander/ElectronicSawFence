#include <Arduino.h>

#ifndef __ENCODER_H
#define __ENCODER_H

#define PIN_A      D8
#define PIN_B      D8

class Encoder
{
    private:
        int pin_A;
        int pin_B;

    public:
        Encoder();
        void initHardware(void);

};

#endif