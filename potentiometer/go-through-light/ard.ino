int analogPin = A0;
int readVal;
float v2;
int redDiodePin = 8;
int yellowDiodePin = 7;
int greenDiodePin = 6;

void setup() {
    Serial.begin(9600);
    pinMode(analogPin,INPUT);
    pinMode(redDiodePin,OUTPUT);
    pinMode(yellowDiodePin,OUTPUT);
    pinMode(greenDiodePin,OUTPUT);
}

void loop() {
  readVal = analogRead(analogPin);
  v2 = (5. / 1023.) * readVal;
  Serial.println(v2);

  if(v2 > 4) {
    digitalWrite(redDiodePin,HIGH);
    digitalWrite(yellowDiodePin,LOW);
    digitalWrite(greenDiodePin,LOW);
  }else if (v2 < 4 && v2 >2) {
    digitalWrite(yellowDiodePin,HIGH);
    digitalWrite(redDiodePin,LOW);
    digitalWrite(greenDiodePin,LOW);
  } else if (v2 < 2 && v2 >0) {
    digitalWrite(greenDiodePin,HIGH);
    digitalWrite(yellowDiodePin,LOW);
    digitalWrite(redDiodePin,LOW);
  }
  delay(500);
}


