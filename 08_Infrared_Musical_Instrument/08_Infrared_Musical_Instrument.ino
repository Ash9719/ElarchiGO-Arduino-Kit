//  Project 08: An Infrared Musical Instrument

// Define the pins for the IR sensors and the buzzer
const int leftSensorPin = 2;
const int rightSensorPin = 3;
const int buzzerPin = 8;

// Define the musical notes (frequencies in Hz)
// C4 = 261 Hz, E4 = 329 Hz. Feel free to change them!
const int note_C = 262; 
const int note_E = 330;

void setup() {
  // Set the pin modes for the sensors (input) and buzzer (output)
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the state of both sensors. 
  // On most modules, LOW (0) means an object (your hand) is detected.
  int leftState = digitalRead(leftSensorPin);
  int rightState = digitalRead(rightSensorPin);

  if (leftState == LOW) {
    // If hand is over the left sensor, play note C
    tone(buzzerPin, note_C);
  } else if (rightState == LOW) {
    // If hand is over the right sensor, play note E
    tone(buzzerPin, note_E);
  } else {
    // If no hand is detected, turn the buzzer off
    noTone(buzzerPin);
  }
}
