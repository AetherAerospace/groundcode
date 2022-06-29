#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include "util/Serial.h"
#include "settings/wifiSet.h"
#include "WiFi.h"

void initWiFi() {
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
    srlInfo("WiFi initialized");
}
