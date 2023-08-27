#ifndef __UI_H
#define __UI_H

#include <EEPROM.h>
#include <ESPUI.h>
#include <WiFi.h>
#include <ESPmDNS.h>

//Settings
#define SLOW_BOOT               0
#define HOSTNAME                "ESF"
#define FORCE_USE_HOTSPOT       0 

#define WIFI_SSID               "homenet"
#define WIFI_PASSWORD           "OrangeTiger11"
#define DNS_PORT                53
#define CONNECT_TIMEOUT         28  // seconds * 4

class UI
{
    private:
        void connectWifi(void);

    public:
        UI();
        void init(void);
        void ISR(void);
};

#endif