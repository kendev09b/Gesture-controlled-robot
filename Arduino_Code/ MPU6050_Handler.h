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