#include "UI.h"

UI :: UI(void)
{

}

void UI :: init(void)
{
    this->connectWifi();
}

void UI :: ISR(void)
{

}

void UI :: connectWifi(void)
{
    WiFi.setHostname(HOSTNAME);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    int connect_timeout = CONNECT_TIMEOUT;

    while (WiFi.status() != WL_CONNECTED && connect_timeout > 0)
    {
        delay(250);
        connect_timeout--;
    }
}