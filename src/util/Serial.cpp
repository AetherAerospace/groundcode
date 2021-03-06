#include <Arduino.h>
#include "Serial.h"
#include "settings/serialSet.h"

void srlInitFin() {
    Serial.println("> Setup:");
    Serial.println("> Initialization Sequence complete!");
    Serial.println(END_SEPERATOR);
}

void srlError(String errorMsg) {
    Serial.println("> Error Report:");
    Serial.println("> " + errorMsg);
    Serial.println(END_SEPERATOR);
}

void srlInfo(String infoMsg) {
    Serial.println("> Info:");
    Serial.println("> " + infoMsg);
    Serial.println(END_SEPERATOR);
}
