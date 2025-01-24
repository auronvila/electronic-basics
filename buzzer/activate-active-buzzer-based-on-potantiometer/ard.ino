int analogPin = A0;
int buzzerPin = 8;
void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin,OUTPUT);
}

void loop() {
  int readVal = analogRead(analogPin);

  if(readVal > 1000) {
    Serial.println("in");
    digitalWrite(buzzerPin,HIGH);
  } else {
    Serial.println("out");
    digitalWrite(buzzerPin,LOW);
  }
 
 delay(500);
}
