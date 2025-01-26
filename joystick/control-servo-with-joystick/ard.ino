#include <Servo.h>

int servoMotorReadPin = 9;
int servoAngle = 0; 
int xPin = A5;
int yPin = A4;
int switchPin = 4;
int xVal;
int yVal;
int switchVal;
int buzzerPin = 10;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);
  pinMode(switchPin,INPUT);
  digitalWrite(switchPin,HIGH);
  pinMode(buzzerPin,OUTPUT);
  myServo.attach(servoMotorReadPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  switchVal = digitalRead(switchPin);

  servoAngle = (180./1023.) * xVal;

  Serial.print("Servo Angle: ");
  Serial.println(servoAngle);

  myServo.write(servoAngle);

  if(switchVal == 0) {
    digitalWrite(buzzerPin,HIGH);
  } else{
    digitalWrite(buzzerPin,LOW);
  }

  Serial.print(xVal);
  Serial.print(" ");
  Serial.print(yVal);
  Serial.print(" ");
  Serial.println(switchVal);

  delay(300);
}

