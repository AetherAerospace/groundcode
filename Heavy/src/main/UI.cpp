#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "util/Comms.h"
#include "pins/oledPins.h"

//button pin
const int buttonPin = 19;

// run once
bool once = false;

// display size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

void initDisplay() {
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW);
  delay(20);
  digitalWrite(OLED_RST, HIGH);

  Wire.begin(OLED_SDA, OLED_SCL);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) {
    Serial.println(F("Display nicht gefunden."));
    for(;;);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Starting up");
  display.display();

}

void initButton(){
  pinMode(buttonPin,INPUT);
}

void loopDisplay() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("AETHER GROUND STATION");
  display.setCursor(0,20);
  display.setTextSize(1);
  display.display();
}

void loopButton(){
  sendLora("Ground Hello");
  while (1) {
    handleLora();
  }
}
