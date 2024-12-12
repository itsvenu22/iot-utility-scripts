#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "credentials.h"

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("WiFi connected.");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_POST, []() {
    if (server.hasArg("data")) {
      String data = server.arg("data");
      Serial.println(data);
      server.send(200, "text/plain", "Data received: " + data);
    } else {
      server.send(400, "text/plain", "No data sent");
    }
  });

  server.begin();
  Serial.println("HTTP server started.");
}

void loop() {
  server.handleClient();
}
