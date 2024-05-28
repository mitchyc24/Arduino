#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 9
#define OLED_DC 8
#define OLED_CS 10

Adafruit_SSD1306 screen(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

void executeCommand(String command);
void displayText(String text);

void setup() {
  Serial.begin(9600);

  // Initialize the OLED display
  if (!screen.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  screen.display();
  delay(2000);
  screen.clearDisplay();
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    executeCommand(command);
  }
}

void executeCommand(String command) {
  if (command.startsWith("TEXT")) {
    displayText(command.substring(5));
  } else if (command == "CLEAR") {
    screen.clearDisplay();
    screen.display();
  }
}

void displayText(String text) {
  screen.clearDisplay();
  screen.setTextSize(1);
  screen.setTextColor(SSD1306_WHITE);
  screen.setCursor(0, 0);
  screen.println(text);
  screen.display();
}
