#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include "util/Comms.h"
#include "pins/loraPins.h"

String LoRaData;
unsigned long prevMillis = 0;
int intvl = 100;   

void initLora(){
    SPI.begin(SCK, MISO, MOSI, SS);
    LoRa.setPins(SS, RST, DIO0);
    if (!LoRa.begin(BAND)) {
        Serial.println("wasnt able to start lora");
        while (1);
    }
    LoRa.setSyncWord(0xF3);
}

void sendLora(String msg) {
    unsigned long currMillis = millis();
    if(currMillis - prevMillis > intvl) {
        prevMillis = currMillis;
        LoRa.beginPacket();
        LoRa.print(msg);
        LoRa.endPacket();
    }
}

void handleLora() {
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
        while ( LoRa.available() ) {
            LoRaData = LoRa.readString();
            Serial.println(LoRaData);
            if (LoRaData == "Onboard Hello") {
                Serial.println("ACK");
            }
        }
    }
}
