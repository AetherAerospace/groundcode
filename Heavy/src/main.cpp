#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include "util/Comms.h"
#include "util/Logs.h"
#include "main/Web.h"
#include "main/UI.h"

void setup() {
  Serial.begin(115200);
  //initLog();
  initLora();
  Serial.println("initLora done");
  initDisplay();
  Serial.println("initDisplay done");
  //initWeb();
  initButton();
}

void loop() {
  loopButton();
  loopDisplay();
  //loopLog();
}