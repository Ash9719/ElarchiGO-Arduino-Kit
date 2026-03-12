// Project 04: Basic Door Alarm

const int buttonPin = 2;
const int buzzerPin = 8;

int buttonState = 0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Read the state of the push button
  buttonState = digitalRead(buttonPin);

  // If the button is pressed (HIGH), the "door is open"
  if (buttonState == HIGH) {
    // Sound the alarm
    tone(buzzerPin, 1000); // Play a 1000Hz tone
  } else {
    // If the button is not pressed, turn the alarm off
    noTone(buzzerPin);
  }
}
