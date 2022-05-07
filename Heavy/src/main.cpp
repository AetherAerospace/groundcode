#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include "main/Web.h"
#include "main/Input.h"
#include "util/WiFi.h"
#include "util/Comms.h"
#include "util/Serial.h"
#include "util/Logs.h"
#include "util/OLED.h"

void setup() {
    Serial.begin(115200);
    initOLED();
    initInput();
    initLoRa();
    initWiFi();
    initWeb();
    srlInitFin();
    delay(2000);
    while (!checkComm());
}

void loop() {
    inputListener();
}
