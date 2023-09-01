#ifndef __UI_H
#define __UI_H

#include "Stepper.h"
#include <ArduinoJson.h>

#include <WiFi.h>
#include <PubSubClient.h>

class UI
{
    private:
        void connectWifi(void);
        void reconnectWifi(void);
        static void callback(char* topic, byte* message, unsigned int length);
        
        DynamicJsonDocument *config;
        Stepper *stepper;

        WiFiClient wifiClient;
        PubSubClient pubSubClient;


    public:
        UI(DynamicJsonDocument *config, Stepper *stepper);
        void init(void);
        void ISR(void);
};

#endif