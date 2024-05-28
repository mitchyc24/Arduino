#include "shapes.h"
#include "display.h"

// Function to draw shapes on the OLED display
void drawShapes() {
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
}

void drawFill(){
    display.clearDisplay();
    display.fillRect(0, 0, 128, 64, SSD1306_WHITE);
    display.display();
    delay(2000);
}