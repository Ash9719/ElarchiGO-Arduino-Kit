
// Project 11: Smartphone-Controlled Bluetooth Car

#include <SoftwareSerial.h>

// --- Bluetooth Pins (HC-05) ---
SoftwareSerial BTSerial(11, 12); // RX, TX

// --- Motor Pins (DRV8833 - PWM pins: 5, 6, 9, 10) ---
const int leftMotor_IN1 = 5;
const int leftMotor_IN2 = 6;
const int rightMotor_IN3 = 9;
const int rightMotor_IN4 = 10;

// --- Speed Variable ---
int currentSpeed = 255; // Start at max speed

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  
  pinMode(leftMotor_IN1, OUTPUT);
  pinMode(leftMotor_IN2, OUTPUT);
  pinMode(rightMotor_IN3, OUTPUT);
  pinMode(rightMotor_IN4, OUTPUT);

  stopMotors();

  Serial.println("ElarchiGO RC Car - Hold-to-Drive Mode Ready!");
}

void loop() {
  // Check for incoming Bluetooth commands
  if (BTSerial.available()) {
    char command = BTSerial.read();
    
    // Movement Logic
    if (command == 'F') {
      moveForward();
    } 
    else if (command == 'B') {
      moveBackward();
    } 
    else if (command == 'L') {
      turnLeft();
    } 
    else if (command == 'R') {
      turnRight();
    } 
    else if (command == 'S') {
      stopMotors(); // This is triggered the instant you lift your thumb!
    }
    
    // Speed Control Logic (Catches '0' through '9')
    else if (command >= '0' && command <= '9') {
      if (command == '0') {
        currentSpeed = 0;
      } else {
        // Map app speeds 1-9 to physical PWM speeds 120-255
        currentSpeed = map(command - '0', 1, 9, 120, 255); 
      }
      Serial.print("Speed updated to: ");
      Serial.println(currentSpeed);
    }
    else if (command == 'q') {
      currentSpeed = 255; // Max speed
    }
  }
}

// === MOTOR CONTROL FUNCTIONS ===

void moveForward() {
  analogWrite(leftMotor_IN1, currentSpeed);
  digitalWrite(leftMotor_IN2, LOW);
  analogWrite(rightMotor_IN3, currentSpeed);
  digitalWrite(rightMotor_IN4, LOW);
}

void moveBackward() {
  digitalWrite(leftMotor_IN1, LOW);
  analogWrite(leftMotor_IN2, currentSpeed);
  digitalWrite(rightMotor_IN3, LOW);
  analogWrite(rightMotor_IN4, currentSpeed);
}

void turnLeft() {
  digitalWrite(leftMotor_IN1, LOW);
  analogWrite(leftMotor_IN2, currentSpeed);
  analogWrite(rightMotor_IN3, currentSpeed);
  digitalWrite(rightMotor_IN4, LOW);
}

void turnRight() {
  analogWrite(leftMotor_IN1, currentSpeed);
  digitalWrite(leftMotor_IN2, LOW);
  digitalWrite(rightMotor_IN3, LOW);
  analogWrite(rightMotor_IN4, currentSpeed);
}

void stopMotors() {
  digitalWrite(leftMotor_IN1, LOW);
  digitalWrite(leftMotor_IN2, LOW);
  digitalWrite(rightMotor_IN3, LOW);
  digitalWrite(rightMotor_IN4, LOW);
}
