int analogPin = A0;
int readVal;
float v2;
int blueDiodePin = 6;

void setup() {
    Serial.begin(9600);
    pinMode(analogPin,INPUT);
    pinMode(blueDiodePin,OUTPUT);
}

void loop() {
  readVal = analogRead(analogPin);
  v2 = (255. / 1023.) * readVal;
  Serial.println(v2);
  analogWrite(blueDiodePin,v2);
  delay(500);
}


