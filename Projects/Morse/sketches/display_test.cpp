#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define OLED display parameters
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Define pin connections
#define OLED_MOSI   11
#define OLED_CLK    13
#define OLED_DC     8
#define OLED_CS     10
#define OLED_RESET  9

// Create an instance of the SSD1306 display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  // Initialize the display
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000);

  // Clear the buffer
  display.clearDisplay();

  // Display test message
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Hello, World!"));
  display.display();
  delay(2000);

  // Draw a rectangle
  display.clearDisplay();
  display.drawRect(10, 10, 50, 30, SSD1306_WHITE);
  display.display();
  delay(2000);

  // Draw a filled rectangle
  display.clearDisplay();
  display.fillRect(20, 20, 50, 30, SSD1306_WHITE);
  display.display();
  delay(2000);

  // Draw a circle
  display.clearDisplay();
  display.drawCircle(64, 32, 30, SSD1306_WHITE);
  display.display();
  delay(2000);

  // Draw a filled circle
  display.clearDisplay();
  display.fillCircle(64, 32, 30, SSD1306_WHITE);
  display.display();
  delay(2000);

  // Draw a triangle
  display.clearDisplay();
  display.drawTriangle(10, 10, 100, 10, 55, 60, SSD1306_WHITE);
  display.display();
  delay(2000);

  // Draw a filled triangle
  display.clearDisplay();
  display.fillTriangle(20, 20, 100, 20, 60, 70, SSD1306_WHITE);
  display.display();
  delay(2000);

  // Scroll text
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(F("Scrolling"));
  display.display();
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
}

void loop() {
  // Do nothing in loop
}
