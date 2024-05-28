#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "ESP32_SSID_01";  // Set your desired SSID
const char *password = "esp32";  // Set your desired password
const int ledPin = 2;  // GPIO pin where the LED is connected (ESP32 built-in LED is usually on GPIO 2)

WebServer server(80);

void handleRoot() {
  String html = "<html><body><h1>ESP32 LED Control</h1>";
  html += "<form action=\"/LEDOn\"><input type=\"submit\" value=\"Turn On LED\"></form>";
  html += "<form action=\"/LEDOff\"><input type=\"submit\" value=\"Turn Off LED\"></form>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleLEDOn() {
  digitalWrite(ledPin, HIGH);  // Turn the LED on
  server.send(200, "text/html", "<html><body><h1>LED is ON</h1><a href=\"/\">Go Back</a></body></html>");
}

void handleLEDOff() {
  digitalWrite(ledPin, LOW);  // Turn the LED off
  server.send(200, "text/html", "<html><body><h1>LED is OFF</h1><a href=\"/\">Go Back</a></body></html>");
}

void setup() {
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
  Serial.begin(115200);

  WiFi.softAP(ssid, password);  // Initialize the WiFi as an access point
  Serial.println();
  Serial.print("WiFi AP SSID: ");
  Serial.println(ssid);

  IPAddress IP = WiFi.softAPIP();  // Get the IP address of the AP
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", handleRoot);  // Define the root handler
  server.on("/LEDOn", handleLEDOn);  // Define the LED on handler
  server.on("/LEDOff", handleLEDOff);  // Define the LED off handler

  server.begin();  // Start the web server
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();  // Handle client requests
}
