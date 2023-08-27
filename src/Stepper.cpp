#include "Stepper.h"

Stepper :: Stepper(void)
{
    this->currentPosition = 0;
    this->desiredPosition = 0;
}

void Stepper :: initHardware(void)
{
    this->accelStepper = AccelStepper(AccelStepper::DRIVER, PIN_STEP, PIN_DIRECTION);
    this->accelStepper.setMaxSpeed(MAXSPEED);
    this->accelStepper.setAcceleration(ACCLERATION);
}

void Stepper :: ISR(void)
{
    if (this->enabled)
    {
        if (!this->accelStepper.run())
        {
            // update the UI to say movement is done
        }
        else
        {
            // update the UI to say we are moving
        }
    }
}
