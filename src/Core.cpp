#include "Core.h"

Core :: Core( Encoder *encoder, Stepper *stepper )
{
    this->encoder = encoder;
    this->stepper = stepper;
}

void Core :: ISR(void)
{
    this->stepper->ISR();               // call the stepper drive ISR
}