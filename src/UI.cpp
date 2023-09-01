// #include <Arduino.h>
#include "UI.h"
#include <ArduinoJson.h>
#include "Stepper.h"

#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>

UI :: UI(DynamicJsonDocument *config, Stepper *stepper)
{
    this->config = config;
    this->stepper = stepper;
}

void UI :: init(void)
{
    const char* mqtt_server = (*this->config)["mqtt_server"];
    String mqtt_port = (*this->config)["mqtt_port"];

    this->connectWifi();
    this->pubSubClient = PubSubClient(mqtt_server, mqtt_port.toInt(), this->callback, this->wifiClient);
}

void UI :: ISR(void)
{
  if (!this->pubSubClient.connected()) {
    reconnectWifi();
  }
  this->pubSubClient.loop();
}


void UI :: connectWifi(void)
{
    String ssid = (*this->config)["ssid"];
    String pwd = (*this->config)["password"];

    delay(10);

    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, pwd);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void UI :: reconnectWifi(void) {
    const char* mqtt_user = (*this->config)["mqtt_user"];
    const char* mqtt_password = (*this->config)["mqtt_password"];


  // Loop until we're reconnected
  while (!this->pubSubClient.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (this->pubSubClient.connect("ElectronicTableSaw", mqtt_user, mqtt_password)) {
      Serial.println("connected");
      this->pubSubClient.subscribe("ETS/output");
    } else {
      Serial.print("failed, rc=");
      Serial.print(this->pubSubClient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void UI :: callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // Check and decode message 
  if (String(topic) == "ETS/output") {
        Serial.print(messageTemp);
  }
}