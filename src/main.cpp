#include <Arduino.h>
#include "Stepper.h"
#include "Encoder.h"
#include "Core.h"
#include "UI.h"

// #include <LittleFS.h>

#define CS_USE_LITTLEFS true
#include "ConfigStorage.h"
#include <ArduinoJson.h>
ConfigStorage CS("/prefs.json");
DynamicJsonDocument config = CS.get();


Stepper stepper;
Encoder encoder;
UI ui(&config, &stepper);
Core core(&encoder, &stepper, &ui);





void setup() {
  stepper.initHardware();
  encoder.initHardware();
  ui.init();
}

void loop() {
  core.ISR();

}

