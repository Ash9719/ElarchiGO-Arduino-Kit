# ElarchiGO ARDUINO KIT-1.0
[cite_start]Codes for all the projects present in the ElarchiGO Arduino kit[cite: 3, 4].

# Arduino Project Kit for Students: Official Code Repository

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)

[cite_start]Welcome to the official code repository for the **ElarchiGO Arduino Kit 1.0** by ELARCHITEK[cite: 2, 3, 4]. This repository contains all the Arduino sketches (`.ino` files) needed to complete the projects in the kit's manual.

[cite_start]This kit is designed for beginners and school students to get a hands-on introduction to electronics, programming, robotics, and wireless communication with the Arduino platform[cite: 5].

## Table of Contents

1.  [Hardware & Software Requirements](#hardware--software-requirements)
2.  [How to Use This Code](#how-to-use-this-code)
3.  [Projects Overview & Direct Code Links](#projects-overview--direct-code-links)
4.  [Troubleshooting](#troubleshooting)
5.  [Support and Contact](#support-and-contact)

---

## Hardware & Software Requirements

### Hardware ⚙️

To build all the projects in this kit, you will need the components listed below. Please refer to the full manual for a detailed wiring list for each specific project.
* [cite_start]Arduino Uno [cite: 65] & Arduino Nano
* [cite_start]Breadboards & Jumper Wires [cite: 53, 495]
* [cite_start]USB Cable [cite: 74]
* [cite_start]LEDs (Red, Yellow, Green) [cite: 56, 521]
* [cite_start]0.96" I2C OLED Display [cite: 774]
* [cite_start]Resistors (220Ω, 10kΩ) [cite: 79, 522, 645]
* [cite_start]Potentiometer & LDR (Light Dependent Resistor) [cite: 80, 85]
* [cite_start]Buzzer [cite: 86]
* [cite_start]Push Buttons / Switches [cite: 88, 579]
* [cite_start]Ultrasonic Sensor (HC-SR04) [cite: 91]
* [cite_start]IR Sensors (Infrared Sensors) [cite: 95]
* [cite_start]Photoelectric Count Slot Sensors (Optical Encoders) [cite: 271]
* [cite_start]NRF24L01 2.4GHz Wireless Transceiver Modules [cite: 277]
* [cite_start]HC-05 Bluetooth Module [cite: 289]
* [cite_start]APDS-9960 Gesture Sensor [cite: 297]
* HW504 Joystick Module
* [cite_start]DC Motors with Wheels [cite: 72, 770]
* [cite_start]Servo Motor (SG90) [cite: 105, 772]
* [cite_start]DRV8833 Motor Driver [cite: 101, 102]
* [cite_start]Robot Chassis [cite: 778]
* [cite_start]Power Sources: 9V Battery [cite: 67, 650] [cite_start]& 18650 2S 7.4V Battery Pack [cite: 1082]

### Software 💻

* **Arduino IDE:** You need the official Arduino IDE to upload the code to your boards.
    * [Download the latest Arduino IDE here](https://www.arduino.cc/en/software).
    * [cite_start]Follow the installation instructions in Chapter 02 of the kit manual to configure the IDE[cite: 23].
* **Required Libraries:** Some advanced projects require external libraries. Install these via the Arduino IDE Library Manager (`Sketch` -> `Include Library` -> `Manage Libraries...`):
    * `RF24` by TMRh20 (For NRF24L01 wireless projects)
    * `SparkFun APDS9960` (For the gesture sensor project)

---

## How to Use This Code

1.  **Download the Code:**
    * Click the green **Code** button on the main repository page.
    * Select **Download ZIP**.
    * Unzip the downloaded file to a location on your computer.

2.  **Open a Project Sketch:**
    * Navigate into the unzipped folder.
    * You can click the direct links in the section below, or open the folders manually. *Note: Projects using two Arduinos will have separate sub-folders for the Transmitter and Receiver.*
    * Double-click the `.ino` file to open it in the Arduino IDE.

3.  **Upload to Arduino:**
    * [cite_start]Connect your Arduino to your computer with the USB cable[cite: 74, 363].
    * [cite_start]In the Arduino IDE, ensure the correct Board (**Arduino Uno** or **Arduino Nano**) and **Port** are selected under the `Tools` menu[cite: 385, 386].
    * [cite_start]Click the **Upload** button (the right-arrow icon) to send the code to your board[cite: 412].

---

## Projects Overview & Direct Code Links

Click on any of the `.ino` file links below to jump directly to the code for that specific project!

### 02: Blinking LED (Test Sketch)
* **Description:** Found in the IDE installation chapter, this is the "Hello, World!" of electronics. [cite_start]This code blinks an external LED on and off every second to verify your board works[cite: 458].
* **💻 Code:** [`02_Blinking_LED.ino`](./02_Blinking_LED/02_Blinking_LED.ino)

### 03: Traffic Light System
* [cite_start]**Description:** Simulates a real-world traffic light by controlling red, yellow, and green LEDs in a timed sequence[cite: 31, 517].
* **💻 Code:** [`03_Traffic_Light_System.ino`](./03_Traffic_Light_System/03_Traffic_Light_System.ino)

### 04: Door Alarm System
* [cite_start]**Description:** Uses a push button to simulate a door opening, triggering a buzzer to sound an alarm[cite: 32, 574].
* **💻 Code:** [`04_Door_Alarm_System.ino`](./04_Door_Alarm_System/04_Door_Alarm_System.ino)

### 05: Battery Voltage Meter
* [cite_start]**Description:** Reads the voltage from a battery using an analog input and a voltage divider, displaying the result in the Serial Monitor[cite: 33, 641].
* **💻 Code:** [`05_Battery_Voltage_Meter.ino`](./05_Battery_Voltage_Meter/05_Battery_Voltage_Meter.ino)

### 06: Ultrasonic Distance Meter
* [cite_start]**Description:** Measures the precise distance to an object using the HC-SR04 ultrasonic sound wave sensor[cite: 34, 35, 707].
* **💻 Code:** [`06_Ultrasonic_Distance_Meter.ino`](./06_Ultrasonic_Distance_Meter/06_Ultrasonic_Distance_Meter.ino)

### 07: Obstacle Avoiding Robot
* [cite_start]**Description:** An autonomous robot that uses an ultrasonic sensor and a servo motor to "look" around, detect obstacles, and navigate a clear path[cite: 36, 765].
* **💻 Code:** [`07_Obstacle_Avoiding_Robot.ino`](./07_Obstacle_Avoiding_Robot/07_Obstacle_Avoiding_Robot.ino)

### 08: An Infrared Musical Instrument
* [cite_start]**Description:** A touchless instrument that uses IR sensors to detect hand movements and play different musical notes on a buzzer[cite: 37, 829].
* **💻 Code:** [`08_Infrared_Musical_Instrument.ino`](./08_Infrared_Musical_Instrument/08_Infrared_Musical_Instrument.ino)

### 09: Line Following Robot
* [cite_start]**Description:** An autonomous robot that uses two downward-facing IR sensors to detect and follow a continuous black line on the floor[cite: 38, 898].
* **💻 Code:** [`09_Line_Following_Robot.ino`](./09_Line_Following_Robot/09_Line_Following_Robot.ino)

### 10: Self-Correcting Straight-Line Robot
* [cite_start]**Description:** Uses optical slot sensors and PID control logic to count wheel rotations and keep the robot driving in a perfectly straight line without drifting[cite: 45, 940, 941].
* **💻 Code:** [`10_Self_Correcting_Straight_Line_Robot.ino`](./10_Self_Correcting_Straight_Line_Robot/10_Self_Correcting_Straight_Line_Robot.ino)

### 11: Smartphone-Controlled Bluetooth Car
* [cite_start]**Description:** Connect an HC-05 Bluetooth module to your robot and use a free smartphone app as a wireless steering wheel to control its movements[cite: 46, 995].
* **💻 Code:** [`11_Smartphone_Controlled_Bluetooth_Car.ino`](./11_Smartphone_Controlled_Bluetooth_Car/11_Smartphone_Controlled_Bluetooth_Car.ino)

### 12: Wireless RC Car
* **Description:** A dual-board project! [cite_start]Build a joystick remote control using an Arduino Nano, and use NRF24L01 radio modules to drive an Arduino Uno robot car wirelessly[cite: 47, 1046].
* **💻 Transmitter Code (Nano):** [`Transmitter_Nano.ino`](./12_Wireless_RC_Car/Transmitter_Nano/Transmitter_Nano.ino)
* **💻 Receiver Code (Uno):** [`Receiver_Uno.ino`](./12_Wireless_RC_Car/Receiver_Uno/Receiver_Uno.ino)

### 13: Gesture-Controlled Wireless RC Car
* **Description:** The ultimate upgrade! [cite_start]Use the APDS-9960 sensor on your remote to control your wireless RC car using Jedi-like hand swipes (Up, Down, Left, Right)[cite: 48, 1130].
* **💻 Transmitter Code (Nano):** [`Transmitter_Nano.ino`](./13_Gesture_Controlled_Wireless_RC_Car/Transmitter_Nano/Transmitter_Nano.ino)
* **💻 Receiver Code (Uno):** [`Receiver_Uno.ino`](./13_Gesture_Controlled_Wireless_RC_Car/Receiver_Uno/Receiver_Uno.ino)

---

## Troubleshooting

[cite_start]If you encounter any issues with your circuits or code, please refer to Chapter 14 **Troubleshooting** in the main PDF manual included with your kit[cite: 49]. It covers common problems related to:
* [cite_start]Code upload errors (Check your Port and Board settings!) [cite: 1234]
* [cite_start]Missing "Common Ground" connections [cite: 1224]
* [cite_start]Component orientation (Polarity) [cite: 1228]
* [cite_start]Sensor calibration [cite: 1230]

---

## Support and Contact

[cite_start]For any inquiries about the ElarchiGO kit or if you need further assistance, please feel free to reach out to us! [cite: 1276]
* [cite_start]**Whatsapp:** +91 86268 32606 [cite: 1277]
* [cite_start]**Email:** elarchitek.contact@gmail.com [cite: 1278]
