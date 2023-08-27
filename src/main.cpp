#include <Arduino.h>
#include "Stepper.h"
#include "Encoder.h"
#include "Core.h"



Stepper stepper;
Encoder encoder;
Core core(&encoder, &stepper);


void setup() {
  stepper.initHardware();
  encoder.initHardware();
}

void loop() {
  // put your main code here, to run repeatedly:

}

