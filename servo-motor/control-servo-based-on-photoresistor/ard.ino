#include <Servo.h>

int servoMotorReadPin = 9;
int servoAngle = 0; 
int photoResistorReadPin = A5;
int photoResistorValue;
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoMotorReadPin);
  pinMode(photoResistorReadPin,INPUT);
  Serial.println("Enter a servo angle (0-180):");
}

void loop() {
  photoResistorValue = analogRead(photoResistorReadPin);

  // Map the photoresistor range (915 to 985) to the servo range (0 to 180)
  if (photoResistorValue >= 915 && photoResistorValue <= 985) {
    servoAngle = ((photoResistorValue - 915) * 180) / 70; // Custom mapping formula
  } else if (photoResistorValue < 915) {
    servoAngle = 0; // Clamp to 0° for values below 915
  } else if (photoResistorValue > 985) {
    servoAngle = 180; // Clamp to 180° for values above 985
  }
  myServo.write(servoAngle);

  Serial.println(servoAngle);
 
  delay(400);
}

