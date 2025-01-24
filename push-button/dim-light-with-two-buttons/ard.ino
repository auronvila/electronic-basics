int increaseLightButtonReadPin = 12;
int decreaseLightButtonReadPin= 7;
int redLightPin = 9;
int increaseLightButtonReadVal;
int decreaseLightButtonReadVal;
int redLightAmount = 0;



void setup() {
  Serial.begin(9600);
  pinMode(redLightPin,OUTPUT);
  pinMode(increaseLightButtonReadPin,INPUT);
  pinMode(decreaseLightButtonReadPin,INPUT);
}

void loop() {
 increaseLightButtonReadVal = digitalRead(increaseLightButtonReadPin);
 decreaseLightButtonReadVal = digitalRead(decreaseLightButtonReadPin);
 Serial.print("increase light button val: ");
 Serial.println(increaseLightButtonReadVal);

 Serial.print("decrease light button val: ");
 Serial.println(decreaseLightButtonReadVal);

 if (increaseLightButtonReadVal) {
  redLightAmount = min(redLightAmount + 10, 235);
  redLightAmount += 10;
  analogWrite(redLightPin, redLightAmount);
 }

 if (decreaseLightButtonReadVal) {
  redLightAmount = max(redLightAmount - 10, 0);
  analogWrite(redLightPin, redLightAmount);
 }

 delay(100);
}
