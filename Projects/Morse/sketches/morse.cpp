#include <Wire.h>
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

const int speakerPin = 3; // Digital pin D3 for the speaker
const int ledPin = 13;    // Built-in LED on Arduino Nano

// Morse code mapping
String morseCode[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

// Function prototypes
void playMorseCode(String message);
void playDot();
void playDash();
void blinkWaiting();
void displayMessage(String message);

bool messageReceived = false;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
  // Initialize OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000); // Pause for 2 seconds
  display.clearDisplay();
  
  Serial.println("Waiting for message...");
}

void loop() {
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    Serial.println("Message received:");
    Serial.println(message);
    displayMessage(message);
    messageReceived = true;
    playMorseCode(message);
    messageReceived = false;
    Serial.println("Waiting for next message...");
  }
  
  if (!messageReceived) {
    blinkWaiting();
  }
}

void playMorseCode(String message) {
  for (int i = 0; i < message.length(); i++) {
    char c = tolower(message[i]);
    if (c >= 'a' && c <= 'z') {
      String code = morseCode[c - 'a'];
      Serial.print(c);
      Serial.print(": ");
      Serial.println(code);
      for (int j = 0; j < code.length(); j++) {
        if (code[j] == '.') {
          playDot();
        } else if (code[j] == '-') {
          playDash();
        }
        delay(200); // Inter-element gap
      }
    }
    delay(600); // Space between letters
  }
}

void playDot() {
  tone(speakerPin, 1000, 200); // 1000 Hz for 200 ms
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
}

void playDash() {
  tone(speakerPin, 1000, 600); // 1000 Hz for 600 ms
  digitalWrite(ledPin, HIGH);
  delay(600);
  digitalWrite(ledPin, LOW);
  delay(200);
}

void blinkWaiting() {
  digitalWrite(ledPin, HIGH);
  delay(1000); // LED on for 1 second
  digitalWrite(ledPin, LOW);
  delay(1000); // LED off for 1 second
}

void displayMessage(String message) {
  display.clearDisplay();
  display.setTextSize(1);      
  display.setTextColor(SSD1306_WHITE);  
  display.setCursor(0,0);     
  display.println(message);  
  display.display();
}
