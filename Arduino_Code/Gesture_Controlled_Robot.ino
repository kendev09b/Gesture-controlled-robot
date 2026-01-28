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