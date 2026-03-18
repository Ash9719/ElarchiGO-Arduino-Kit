/*
 Project 09: Line Following Robot
 * Track Type: THIN LINE (Sensors straddle the black tape)
 * Sensor Type: ACTIVE-LOW (White/LED ON = LOW | Black/LED OFF = HIGH)
 * Features: Soft Pivot Turning & Active Braking for Intersections
 */

const int leftSensor = 2;
const int rightSensor = 3;

const int leftMotor_IN1 = 5;  
const int leftMotor_IN2 = 6;  
const int rightMotor_IN3 = 9; 
const int rightMotor_IN4 = 10;

const int baseSpeed = 120; 
const int turnSpeed = 140; 

// --- Braking Variable ---
// How many milliseconds to fire the reverse thrusters. 
const int brakeTime = 60; // TUNE THIS: 40 to 80 is usually the sweet spot

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  pinMode(leftMotor_IN1, OUTPUT);
  pinMode(leftMotor_IN2, OUTPUT);
  pinMode(rightMotor_IN3, OUTPUT);
  pinMode(rightMotor_IN4, OUTPUT);

  delay(2000); 
}

void loop() {
  int leftState = digitalRead(leftSensor);
  int rightState = digitalRead(rightSensor);

  // 1. Both on WHITE (LOW) -> Move Forward
  if (leftState == LOW && rightState == LOW) {
    analogWrite(leftMotor_IN1, baseSpeed);
    digitalWrite(leftMotor_IN2, LOW);
    analogWrite(rightMotor_IN3, baseSpeed);
    digitalWrite(rightMotor_IN4, LOW);
  }
  
  // 2. Left hits BLACK (HIGH) -> SOFT TURN LEFT
  else if (leftState == HIGH && rightState == LOW) {
    digitalWrite(leftMotor_IN1, LOW);
    digitalWrite(leftMotor_IN2, LOW); 
    
    analogWrite(rightMotor_IN3, turnSpeed); 
    digitalWrite(rightMotor_IN4, LOW);
  }
  
  // 3. Right hits BLACK (HIGH) -> SOFT TURN RIGHT
  else if (leftState == LOW && rightState == HIGH) {
    analogWrite(leftMotor_IN1, turnSpeed);  
    digitalWrite(leftMotor_IN2, LOW);
    
    digitalWrite(rightMotor_IN3, LOW);
    digitalWrite(rightMotor_IN4, LOW); 
  }
  
  // 4. Both hit BLACK (HIGH) -> T-Intersection -> ACTIVE BRAKE & STOP
  else if (leftState == HIGH && rightState == HIGH) {
    activeBrake();
    
    // Trap the Arduino in an infinite loop so it stays stopped forever
    while(true) {
      // Do nothing. Press the reset button on the Arduino to restart.
    }
  }
}

// === ACTIVE BRAKING FUNCTION ===
void activeBrake() {
  // 1. Fire full power in REVERSE
  digitalWrite(leftMotor_IN1, LOW);
  analogWrite(leftMotor_IN2, 255); 
  digitalWrite(rightMotor_IN3, LOW);
  analogWrite(rightMotor_IN4, 255);
  
  // 2. Wait just long enough to kill forward momentum
  delay(brakeTime);
  
  // 3. Shut motors off completely
  digitalWrite(leftMotor_IN1, LOW);
  digitalWrite(leftMotor_IN2, LOW);
  digitalWrite(rightMotor_IN3, LOW);
  digitalWrite(rightMotor_IN4, LOW);
}
