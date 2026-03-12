// Project 02: Blinking LED

void setup() {
  // Initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);   // Turn the LED on (HIGH is the voltage level)
  delay(1000);              // Wait for a second (1000 milliseconds)
  digitalWrite(13, LOW);    // Turn the LED off by making the voltage LOW
  delay(1000);              // Wait for a second
}
