#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "credentials.h"

WiFiClient wifiClient;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi connected.");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "http://" + String(SERVER_IP) + "/";
    http.begin(wifiClient, url);

    int randomValue = random(0, 21);     // Generate random data in the range 0-20

    String postData = "data=" + String(randomValue);

    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpResponseCode = http.POST(postData);

    if (httpResponseCode > 0) {
      Serial.println("Response: " + http.getString());
    } else {
      Serial.println("Error: " + String(httpResponseCode));
    }

    http.end();
  }

  delay(5000); // Send data every 5 seconds
}