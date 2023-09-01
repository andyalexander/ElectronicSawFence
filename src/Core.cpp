#include "Core.h"

Core :: Core( Encoder *encoder, Stepper *stepper, UI *ui )
{
    this->encoder = encoder;
    this->stepper = stepper;
    this->ui = ui;
}

void Core :: ISR(void)
{
    this->stepper->ISR();               // call the stepper drive ISR
    this->ui->ISR();                    // call the UI ISR
}