#include <Arduino.h>
#include "Input.h"
#include "util/Comms.h"
#include "util/Serial.h"
#include "util/OLED.h"
#include "pins/buttonPins.h"

void initInput() {
    pinMode(BUTTON1, INPUT);
}

void inputListener() {
    int buttonState = digitalRead(BUTTON1);
    if(buttonState == HIGH) {
        sendLoRa("404");
        delay(250);
        srlInfo("LoRa TX: Sent 404 (Kill)");
        writeToDisplay("LoRa TX:","Sent 404 (Kill)");
    }
}
