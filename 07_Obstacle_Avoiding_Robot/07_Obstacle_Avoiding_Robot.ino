// Project 07: Obstacle Avoiding Robot
/*
 * COMPLETE ROBOT CODE (ELARCHIGO KIT)
 * -----------------------------------
 * Features:
 * - Simplified OLED display with big, readable text.
 * - DRV8833 Motor Driver
 * - Servo-mounted Ultrasonic Sensor (HC-SR04)
 */

// --- Include all necessary libraries ---
#include <Servo.h>              // For the servo motor
#include <Wire.h>               // For I2C communication (OLED)
#include <Adafruit_GFX.h>       // For OLED graphics
#include <Adafruit_SSD1306.h>   // For the OLED driver

// --- Define screen properties ---
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// --- Create Servo object ---
Servo headServo;

// --- Pin Definitions ---
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 11;
const int leftMotor_IN1 = 6;  // PWM pin
const int leftMotor_IN2 = 7;
const int rightMotor_IN3 = 5; // PWM pin
const int rightMotor_IN4 = 4;

// --- Robot Speed & Distance Settings ---
const int forwardSpeed = 130;
const int turnSpeed = 120;         // Matched to forward speed for smoother pivots
const int obstacleThreshold = 30;  // in cm
const int turnTime = 500;          // TUNE THIS: Adjust milliseconds for a 90-degree turn

// --- Global Variables ---
int servoAngle = 90; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(leftMotor_IN1, OUTPUT);
  pinMode(leftMotor_IN2, OUTPUT);
  pinMode(rightMotor_IN3, OUTPUT);
  pinMode(rightMotor_IN4, OUTPUT);

  headServo.attach(servoPin);
  headServo.write(90); 
  
  // Initialize the OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    // If it fails, just continue
  }
  
  // --- Boot-up Sequence ---
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(15, 25);
  display.print("HELLO!"); 
  display.display();
  delay(1500); 

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 10);
  display.print(" Welcome to your"); 
  display.setTextSize(2);
  display.setCursor(0, 30);
  display.print("ELARCHITEK"); 
  display.setTextSize(1);
  display.setCursor(25, 55);
  display.print("Robot Kit!"); 
  display.display();
  delay(2500);
}

void loop() {
  int distance = getDistance();
  delay(50); // Small delay to prevent ultrasonic echoes from bouncing around

  if (distance > obstacleThreshold) {
    // --- PATH IS CLEAR ---
    if (servoAngle != 90) {
      headServo.write(90);
      servoAngle = 90;
      delay(300); // Wait for servo to center
    }
    
    updateDisplay(" Moving", "(^_^)");
    moveForward();
    
  } else {
    // --- PATH IS BLOCKED ---
    moveStop();
    updateDisplay("  STOP!", "(o_O)");
    delay(500); // Let the robot come to a complete physical stop
    
    updateDisplay("Scanning...", "<(..)>");

    // Look left and right
    int leftDist = lookLeft();
    delay(200);
    int rightDist = lookRight();
    delay(200);
    
    // Look back forward
    headServo.write(90);
    servoAngle = 90;
    delay(300);

    // Decide which way to turn based on sensor readings
    if (leftDist > rightDist && leftDist > obstacleThreshold) {
      updateDisplay("Turn Left", "<('o')");
      turnLeft();       
      delay(turnTime);  // The Arduino ignores the sensor during this delay!
    } else if (rightDist >= leftDist && rightDist > obstacleThreshold) {
      updateDisplay("Turn Right", "('o')>");
      turnRight();      
      delay(turnTime);  // The Arduino ignores the sensor during this delay!
    } else {
      // If both sides are blocked, turn completely around!
      updateDisplay("Turn Back", "(>_<)");
      turnRight();
      delay(turnTime * 2); 
    }
    
    moveStop(); 
    delay(200); // CRITICAL: Let the chassis stop vibrating before the loop repeats and scans again
  }
}

// === Function to Update the OLED Display ===
void updateDisplay(String status, String face) {
  display.clearDisplay();
  display.setTextSize(2); 
  display.setCursor(0, 5);
  display.print(status);
  display.setTextSize(3); 
  display.setCursor(10, 30); 
  display.print(face);
  display.display(); 
}

// === Sensor Functions ===
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Added a 30000 microsecond timeout so it doesn't freeze looking for a wave
  long duration = pulseIn(echoPin, HIGH, 30000); 
  
  // FIX: If duration is 0, it means the path is totally clear to infinity.
  if (duration == 0) {
    return 999; 
  }
  
  return duration * 0.0343 / 2;
}

int lookLeft() {
  headServo.write(170);
  servoAngle = 170;
  delay(500);
  return getDistance();
}

int lookRight() {
  headServo.write(10);
  servoAngle = 10;
  delay(500);
  return getDistance();
}

// === DRV8833 Motor Control Functions (Pivot Turns) ===
void moveForward() {
  analogWrite(leftMotor_IN1, forwardSpeed);
  digitalWrite(leftMotor_IN2, LOW);
  analogWrite(rightMotor_IN3, forwardSpeed);
  digitalWrite(rightMotor_IN4, LOW);
}

void turnLeft() {
  analogWrite(leftMotor_IN1, 0);
  digitalWrite(leftMotor_IN2, LOW); 
  analogWrite(rightMotor_IN3, turnSpeed);
  digitalWrite(rightMotor_IN4, LOW);
}

void turnRight() {
  analogWrite(leftMotor_IN1, turnSpeed);
  digitalWrite(leftMotor_IN2, LOW);
  analogWrite(rightMotor_IN3, 0);
  digitalWrite(rightMotor_IN4, LOW);
}

void moveStop() {
  analogWrite(leftMotor_IN1, 0); 
  digitalWrite(leftMotor_IN2, LOW);
  analogWrite(rightMotor_IN3, 0); 
  digitalWrite(rightMotor_IN4, LOW);
}
