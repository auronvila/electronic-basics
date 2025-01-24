int analogPin = A0;
int greenLighPin = 7;
int redLightPin = 8;


void setup() {
  Serial.begin(9600);
  pinMode(analogPin,INPUT);
  pinMode(greenLighPin,OUTPUT);
  pinMode(redLightPin,OUTPUT);
}

 // 50,300
void loop() {
  int lightVal = analogRead(analogPin);
  Serial.println(lightVal);
  if (lightVal < 50) {
    Serial.println("Lights are turned off");
    digitalWrite(redLightPin, HIGH);
    digitalWrite(greenLighPin, LOW);
  } 
  if (lightVal > 300) {
    Serial.println("Lights are turned on");
    digitalWrite(redLightPin, LOW);
    digitalWrite(greenLighPin, HIGH);
  }
 delay(500);
}
