// Project 03: Traffic Light System
void setup() {
  pinMode(12, OUTPUT); // Green
  pinMode(11, OUTPUT); // Yellow
  pinMode(10, OUTPUT); // Red
}

void loop() {
  // Green light on for 5 seconds
  digitalWrite(12, HIGH);
  delay(5000);
  digitalWrite(12, LOW);

  // Yellow light on for 2 seconds
  digitalWrite(11, HIGH);
  delay(2000);
  digitalWrite(11, LOW);

  // Red light on for 5 seconds
  digitalWrite(10, HIGH);
  delay(5000);
  digitalWrite(10, LOW);
}
