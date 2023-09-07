/*
  --------------------------------
  ESPConnect - AutoConnect Example
  --------------------------------

  Initializes ESPConnect and attaches itself to AsyncWebServer.
  
  Github & WiKi: https://github.com/ayushsharma82/ESPConnect
  Works with both ESP8266 & ESP32
*/

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include <ESPConnect.h>

AsyncWebServer server(80);


void setup(){
  Serial.begin(115200);
  Serial.println();

  /*
    AutoConnect AP
    Configure SSID and password for Captive Portal
  */
  ESPConnect.autoConnect("ESPConfig");

  /* 
    Begin connecting to previous WiFi
    or start autoConnect AP if unable to connect
  */
  if(ESPConnect.begin(&server)){
    Serial.println("Connected to WiFi");
    Serial.println("IPAddress: "+WiFi.localIP().toString());
  }else{
    Serial.println("Failed to connect to WiFi");
  }

  server.on("/", HTTP_GET, [&](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello from ESP");
  });

  server.begin();
}


void loop(){ }