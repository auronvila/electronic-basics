int redLighPin = 6;
int readVal;
int inputedNum;
String message = "please enter a number: ";

void setup() {
  Serial.begin(9600);
  pinMode(redLighPin,OUTPUT);
}

void loop() {
   Serial.println(message);
   while (Serial.available() == 0) {
   }

  inputedNum = Serial.parseInt();
  Serial.println(inputedNum);
  
  for(int i = 0; i < inputedNum;i++) {
    digitalWrite(redLighPin,HIGH);
    delay(500);
    digitalWrite(redLighPin,LOW);
    delay(500);
  }
  digitalWrite(redLighPin,LOW);
}
