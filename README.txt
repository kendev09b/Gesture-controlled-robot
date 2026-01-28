GESTURE CONTROLLED ROBOT
Bells University ICT215 Project

Components:
- Arduino Uno
- MPU6050 Sensor
- L298N Motor Driver
- 2x DC Motors
- 12V Battery

Connections:
MPU6050 -> Arduino:
  VCC -> 5V
  GND -> GND
  SDA -> A4
  SCL -> A5

L298N -> Arduino:
  IN1 -> D7
  IN2 -> D8
  IN3 -> D9
  IN4 -> D10
  ENA -> D5
  ENB -> D6

How to run:
1. Upload Gesture_Controlled_Robot.ino
2. Tilt MPU6050 to control robot
3. Check Serial Monitor for status