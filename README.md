# 📄 **README.md** (EXACT MATCH to your structure)

# 🤖 **Gesture-Controlled Robot - Code & Structure ONLY**

## 📁 **PROJECT STRUCTURE**
```
Gesture_Controlled_Robot/
├── Arduino_Code/
│   ├── Gesture_Controlled_Robot.ino
│   ├── MPU6050_Handler.h
│   └── Motor_Driver.h
├── README.md
└── requirements.txt
```

---

## 📄 **ARDUINO CODE**

### **1. Main File** (`Gesture_Controlled_Robot.ino`)
```cpp
#include "MPU6050_Handler.h"
#include "Motor_Driver.h"

MPU6050_Handler mpu;
Motor_Driver motors;

void setup() {
  Serial.begin(9600);
  mpu.begin();
  motors.begin();
  Serial.println("Gesture Robot Ready");
}

void loop() {
  String gesture = mpu.detectGesture();
  
  if (gesture == "FORWARD") {
    motors.moveForward();
    Serial.println("Moving FORWARD");
  } 
  else if (gesture == "BACKWARD") {
    motors.moveBackward();
    Serial.println("Moving BACKWARD");
  }
  else if (gesture == "LEFT") {
    motors.turnLeft();
    Serial.println("Turning LEFT");
  }
  else if (gesture == "RIGHT") {
    motors.turnRight();
    Serial.println("Turning RIGHT");
  }
  else {
    motors.stop();
    Serial.println("STOPPED");
  }
  
  delay(100);
}
```

### **2. MPU6050 Handler** (`MPU6050_Handler.h`)
```cpp
#ifndef MPU6050_HANDLER_H
#define MPU6050_HANDLER_H

#include <Wire.h>
#include <MPU6050.h>

class MPU6050_Handler {
private:
  MPU6050 mpu;
  float accX, accY;
  
public:
  void begin() {
    Wire.begin();
    mpu.initialize();
  }
  
  String detectGesture() {
    // Read accelerometer values
    accX = mpu.getAccelerationX() / 16384.0;
    accY = mpu.getAccelerationY() / 16384.0;
    
    if (accY > 0.3) return "FORWARD";
    if (accY < -0.3) return "BACKWARD";
    if (accX > 0.3) return "RIGHT";
    if (accX < -0.3) return "LEFT";
    
    return "STOP";
  }
};

#endif
```

### **3. Motor Driver** (`Motor_Driver.h`)
```cpp
#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

class Motor_Driver {
private:
  int ENA = 5;
  int ENB = 6;
  int IN1 = 7;
  int IN2 = 8;
  int IN3 = 9;
  int IN4 = 10;
  
public:
  void begin() {
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    analogWrite(ENA, 200);
    analogWrite(ENB, 200);
  }
  
  void moveForward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  
  void moveBackward() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
  
  void turnLeft() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
  
  void turnRight() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  
  void stop() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
};

#endif
```

---

## 📄 **REQUIREMENTS** (`requirements.txt`)
```
Arduino IDE 1.8.19 or higher
MPU6050 library by Electronic Cats
Wire library (included)
```

---

