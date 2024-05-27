const int speakerPin = 3; // Digital pin D3 for the speaker
const int ledPin = 13;    // Built-in LED on Arduino Nano

// Define the notes and their corresponding frequencies
const int NOTE_G4 = 392;
const int NOTE_A4 = 440;
const int NOTE_B4 = 494;
const int NOTE_C5 = 523;
const int NOTE_D5 = 587;
const int NOTE_E5 = 659;
const int NOTE_F5 = 698;
const int NOTE_G5 = 784;

// Define the notes and their durations (in milliseconds) for "Happy Birthday"
int happyBirthdayNotes[] = {
  NOTE_G4, 400, NOTE_G4, 400, NOTE_A4, 800,
  NOTE_G4, 400, NOTE_C5, 400, NOTE_B4, 800,
  NOTE_G4, 400, NOTE_G5, 400, NOTE_F5, 800,
  NOTE_D5, 400, NOTE_C5, 400, NOTE_A4, 400, NOTE_F5, 400,
  NOTE_E5, 400, NOTE_C5, 800
};

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void playTone(int frequency, int duration) {
  tone(speakerPin, frequency, duration);
  delay(duration);
  noTone(speakerPin);
}

void loop() {
  // Play "Happy Birthday"
  for (int i = 0; i < sizeof(happyBirthdayNotes) / sizeof(happyBirthdayNotes[0]); i += 2) {
    int noteDuration = happyBirthdayNotes[i + 1];
    playTone(happyBirthdayNotes[i], noteDuration);
    digitalWrite(ledPin, HIGH); // Turn on the LED
    delay(noteDuration); // Delay for note duration
    digitalWrite(ledPin, LOW); // Turn off the LED
    delay(50); // Pause between notes
  }

  delay(5000); // Delay between repetitions (5 seconds)
}
