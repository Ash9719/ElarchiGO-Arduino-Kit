# ElarchiGO ARDUINO KIT-1.0
Codes for all the projects present in the ElarchiGO Arduino kit.

# Arduino Project Kit for Students: Official Code Repository

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)

Welcome to the official code repository for the **ElarchiGO Arduino Kit 1.0** by ELARCHITEK. This repository contains all the Arduino sketches (`.ino` files) needed to complete the projects in the kit's manual.

This kit is designed for beginners and school students to get a hands-on introduction to electronics, programming, robotics, and wireless communication with the Arduino platform.

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
* Arduino Uno & Arduino Nano
* Breadboards & Jumper Wires
* USB Cable
* LEDs (Red, Yellow, Green)
* 0.96" I2C OLED Display
* Resistors (220Ω, 10kΩ)
* Buzzer
* Push Buttons / Switches
* Ultrasonic Sensor (HC-SR04)
* IR Sensors (Infrared Sensors)
* Photoelectric Count Slot Sensors (Optical Encoders)
* NRF24L01 2.4GHz Wireless Transceiver Modules
* HC-05 Bluetooth Module
* APDS-9960 Gesture Sensor
* HW504 Joystick Module
* DC Motors with Wheels
* Servo Motor (SG90)
* DRV8833 Motor Driver
* Robot Chassis
* Power Sources: 9V Battery & 18650 2S 7.4V Battery Pack

### Software 💻

* **Arduino IDE:** You need the official Arduino IDE to upload the code to your boards.
    * [Download the latest Arduino IDE here](https://www.arduino.cc/en/software).
    * Follow the installation instructions in Chapter 02 of the kit manual to configure the IDE.
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
    * Connect your Arduino to your computer with the USB cable.
    * In the Arduino IDE, ensure the correct Board (**Arduino Uno** or **Arduino Nano**) and **Port** are selected under the `Tools` menu.
    * Click the **Upload** button (the right-arrow icon) to send the code to your board.

---

## Projects Overview & Direct Code Links

Click on any of the `.ino` file links below to jump directly to the code for that specific project!

### 02: Blinking LED (Test Sketch)
* **Description:** Found in the IDE installation chapter, this is the "Hello, World!" of electronics. This code blinks an external LED on and off every second to verify your board works.
* **💻 Code:** [`02_Blinking_LED.ino`](./02_Blinking_LED/02_Blinking_LED.ino)

### 03: Traffic Light System
* **Description:** Simulates a real-world traffic light by controlling red, yellow, and green LEDs in a timed sequence.
* **💻 Code:** [`03_Traffic_Light_System.ino`](./03_Traffic_Light_System/03_Traffic_Light_System.ino)

### 04: Door Alarm System
* **Description:** Uses a push button to simulate a door opening, triggering a buzzer to sound an alarm.
* **💻 Code:** [`04_Door_Alarm_System.ino`](./04_Door_Alarm_System/04_Door_Alarm_System.ino)

### 05: Battery Voltage Meter
* **Description:** Reads the voltage from a battery using an analog input and a voltage divider, displaying the result in the Serial Monitor.
* **💻 Code:** [`05_Battery_Voltage_Meter.ino`](./05_Battery_Voltage_Meter/05_Battery_Voltage_Meter.ino)

### 06: Ultrasonic Distance Meter
* **Description:** Measures the precise distance to an object using the HC-SR04 ultrasonic sound wave sensor.
* **💻 Code:** [`06_Ultrasonic_Distance_Meter.ino`](./06_Ultrasonic_Distance_Meter/06_Ultrasonic_Distance_Meter.ino)

### 07: Obstacle Avoiding Robot
* **Description:** An autonomous robot that uses an ultrasonic sensor and a servo motor to "look" around, detect obstacles, and navigate a clear path.
* **💻 Code:** [`07_Obstacle_Avoiding_Robot.ino`](./07_Obstacle_Avoiding_Robot/07_Obstacle_Avoiding_Robot.ino)

### 08: An Infrared Musical Instrument
* **Description:** A touchless instrument that uses IR sensors to detect hand movements and play different musical notes on a buzzer.
* **💻 Code:** [`08_Infrared_Musical_Instrument.ino`](./08_Infrared_Musical_Instrument/08_Infrared_Musical_Instrument.ino)

### 09: Line Following Robot
* **Description:** An autonomous robot that uses two downward-facing IR sensors to detect and follow a continuous black line on the floor.
* **💻 Code:** [`09_Line_Following_Robot.ino`](./09_Line_Following_Robot/09_Line_Following_Robot.ino)

### 10: Self-Correcting Straight-Line Robot
* **Description:** Uses optical slot sensors and PID control logic to count wheel rotations and keep the robot driving in a perfectly straight line without drifting.
* **💻 Code:** [`10_Self_Correcting_Straight_Line_Robot.ino`](./10_Self_Correcting_Straight_Line_Robot/10_Self_Correcting_Straight_Line_Robot.ino)

### 11: Smartphone-Controlled Bluetooth Car
* **Description:** Connect an HC-05 Bluetooth module to your robot and use a free smartphone app as a wireless steering wheel to control its movements.
* **💻 Code:** [`11_Smartphone_Controlled_Bluetooth_Car.ino`](./11_Smartphone_Controlled_Bluetooth_Car/11_Smartphone_Controlled_Bluetooth_Car.ino)

### 12: Wireless RC Car
* **Description:** A dual-board project! Build a joystick remote control using an Arduino Nano, and use NRF24L01 radio modules to drive an Arduino Uno robot car wirelessly.
* **💻 Transmitter Code (Nano):** [`Transmitter_Nano.ino`](./12_Wireless_RC_Car/Transmitter_Nano/Transmitter_Nano.ino)
* **💻 Receiver Code (Uno):** [`Receiver_Uno.ino`](./12_Wireless_RC_Car/Receiver_Uno/Receiver_Uno.ino)

### 13: Gesture-Controlled Wireless RC Car
* **Description:** The ultimate upgrade! Use the APDS-9960 sensor on your remote to control your wireless RC car using Jedi-like hand swipes (Up, Down, Left, Right).
* **💻 Transmitter Code (Nano):** [`Transmitter_Nano.ino`](./13_Gesture_Controlled_Wireless_RC_Car/Transmitter_Nano/Transmitter_Nano.ino)
* **💻 Receiver Code (Uno):** [`Receiver_Uno.ino`](./13_Gesture_Controlled_Wireless_RC_Car/Receiver_Uno/Receiver_Uno.ino)

---

## Troubleshooting

If you encounter any issues with your circuits or code, please refer to Chapter 14 **Troubleshooting** in the main PDF manual included with your kit. It covers common problems related to:
* Code upload errors (Check your Port and Board settings!)
* Missing "Common Ground" connections
* Component orientation (Polarity)
* Sensor calibration

---

## Support and Contact

For any inquiries about the ElarchiGO kit or if you need further assistance, please feel free to reach out to us!
* **Whatsapp:** +91 86268 32606
* **Email:** elarchitek.contact@gmail.com
