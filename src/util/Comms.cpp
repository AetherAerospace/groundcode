#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include "util/Comms.h"
#include "util/Serial.h"
#include "util/OLED.h"
#include "pins/loraPins.h"
#include "settings/loraSet.h"
#include "Comms.h"

String LoRaData;
int responseTimeout = 5000;
unsigned long now = 0;
unsigned long startTime = 0;
bool initialSend = true;

// initialize
void initLoRa() {
    SPI.begin(SCK, MISO, MOSI, SS);
    LoRa.setPins(SS, RST, DIO0);
    if (!LoRa.begin(BAND)) {
        srlError("Unable to start LoRa!");
        while (1);
    }
    LoRa.setSyncWord(LORA_SYNC_WORD);
    srlInfo("LoRa initialized!");
}

// send packet
void sendLoRa(String msg) {
    LoRa.beginPacket();
    LoRa.print(msg);
    LoRa.endPacket();
}

// initial comm check
bool checkComm() {
    if (initialSend) {
        initialSend = false;
        sendLoRa("Ground Hello");
        srlInfo("LoRa TX: Sent test Packet");
        writeToDisplay("LoRa TX:", "Sent test Packet");
        startTime = millis();
    }
    now = millis();
    if ( (now - startTime) <= responseTimeout) {
        int packetSize = LoRa.parsePacket();
        if (packetSize) {
            while ( LoRa.available() ) {
                LoRaData = LoRa.readString();
                if (LoRaData == "Onboard Hello") {
                    srlInfo("LoRa TX/RX: Comm Check Success");
                    writeToDisplay("LoRa TX/RX:", "Comm Check Success");
                    return true;
                }
            }
        }
    } else {
        srlInfo("LoRa RX: Response Timeout");
        writeToDisplay("LoRa RX:", "Response Timeout");
        delay(2000);
        initialSend = true;
    }
    return false;
}
