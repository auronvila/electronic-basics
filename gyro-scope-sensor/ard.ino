#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("Failed to connect to MPU6050!");
    mpu.initialize();
  }

  Serial.println("MPU6050 initialized successfully!");
}

void loop() {
  int16_t ax, ay, az; // Accelerometer data
  int16_t gx, gy, gz; // Gyroscope data

  ax = mpu.getAccelerationX();
  ay = mpu.getAccelerationY();
  az = mpu.getAccelerationZ();

  gx = mpu.getRotationX();
  gy = mpu.getRotationY();
  gz = mpu.getRotationZ();

  Serial.print("Accelerometer: X = ");
  Serial.print(ax);
  Serial.print(" | Y = ");
  Serial.print(ay);
  Serial.print(" | Z = ");
  Serial.println(az);

  Serial.print("Gyroscope: X = ");
  Serial.print(gx);
  Serial.print(" | Y = ");
  Serial.print(gy);
  Serial.print(" | Z = ");
  Serial.println(gz);

  delay(500);
}

