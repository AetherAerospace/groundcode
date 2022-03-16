#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Comms.h"

//button pin
const int buttonPin = 19;

// display pins
#define OLED_SDA 21
#define OLED_SCL 22
#define OLED_RST 16

// display size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

int counter = 0;

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
  display.print("Status: ");
  display.print(readLora());      
  display.display();
}

void writeDisplay(String messageToDisplay){
    display.println(messageToDisplay);
}

void loopButton(){
    int buttonState;
    buttonState = digitalRead(buttonPin);
    if(buttonState == HIGH){
        /* 
          TODO:
          Reimplement engine kill based on new flightcode
        */
    }
}