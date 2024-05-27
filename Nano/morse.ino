#include <SPI.h>
#include <SD.h>

const int speakerPin = 3; // Digital pin D3 for the speaker
const int ledPin = 13;    // Built-in LED on Arduino Nano
const int chipSelect = 10; // Chip select pin for the SD card module

// Morse code mapping
String morseCode[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    return;
  }
  Serial.println("SD card initialized.");

  File messageFile = SD.open("message.txt");
  if (!messageFile) {
    Serial.println("Failed to open message.txt!");
    return;
  }

  String message = "";
  while (messageFile.available()) {
    message += (char)messageFile.read();
  }
  messageFile.close();

  Serial.println("Message read from file:");
  Serial.println(message);

  playMorseCode(message);
}

void loop() {
  // Do nothing in loop
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
