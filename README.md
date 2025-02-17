# Robotics-Obstacle-Avoidance-Robot-Ultrasonic-Navigation


![Obstacle Avoidance Robot Car](https://files.oaiusercontent.com/file-BPxSFu3E2o7BGiZBaswzGw?se=2025-02-17T20%3A28%3A01Z&sp=r&sv=2024-08-04&sr=b&rscc=max-age%3D604800%2C%20immutable%2C%20private&rscd=attachment%3B%20filename%3Db9cdf0e9-c940-4284-9582-238528805ecc.webp&sig=H5DpWuxGqNrgQ8R2lkc8bVVAK6j0haFFX%2BnkYK7bwf0%3D)

## Project Overview

The Obstacle Avoidance Robot Car is an Arduino-based project designed for autonomous navigation. It uses an ultrasonic sensor mounted on a servo to detect obstacles and adjust its path accordingly. The robot moves forward until an obstacle is detected, then stops, reverses, and scans left and right to determine the best direction to continue.

## Features

- **Autonomous Navigation:**  
  The robot continuously drives forward and automatically avoids obstacles.
  
- **Ultrasonic Sensing:**  
  An ultrasonic sensor measures the distance to obstacles accurately.
  
- **Servo-Driven Scanning:**  
  The sensor, mounted on a servo, scans left and right to identify the clearest path.
  
- **Dual Motor Control:**  
  A motor driver (H-bridge) is used to control two DC motors for precise movement.
  
- **Customizable Parameters:**  
  Easily adjust detection thresholds, motor speeds, and timing to fit different environments.

## Hardware Requirements

- **Arduino Uno** (or a compatible board)
- **Ultrasonic Sensor** (e.g., HC-SR04)
- **Servo Motor** (for sensor scanning)
- **H-Bridge Motor Driver** (e.g., L298N)
- **2 DC Motors with Wheels**
- **Jumper Wires, Breadboard, and a Suitable Power Supply**

## Wiring Overview

- **Ultrasonic Sensor:**  
  - *Trig* → Arduino digital pin **A3**  
  - *Echo* → Arduino digital pin **A4**
  
- **Servo Motor:**  
  - Connected to Arduino digital pin **3**
  
- **Motor Driver:**  
  - *ENA* → Arduino digital pin **6**  
  - *ENB* → Arduino digital pin **5**  
  - *IN1* → Arduino digital pin **7**  
  - *IN2* → Arduino digital pin **8**  
  - *IN3* → Arduino digital pin **9**  
  - *IN4* → Arduino digital pin **11**

Refer to the image above for a visual layout of the project.

## Setup and Usage

1. **Install the Arduino IDE:**  
   Download and install the [Arduino IDE](https://www.arduino.cc/en/software).

2. **Connect the Hardware:**  
   Wire the ultrasonic sensor, servo motor, and motor driver with the motors according to the wiring overview.

3. **Upload the Code:**  
   Open the Arduino IDE, paste the code provided below into a new sketch, compile, and upload it to your Arduino board.

4. **Power On:**  
   After uploading the code and connecting your components, power on your robot car. It will begin navigating autonomously while avoiding obstacles.

