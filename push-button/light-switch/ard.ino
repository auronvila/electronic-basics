int buttonReadPin = 12;
int redLightPin = 9;
int buttonReadVal;
int buttonOldVal = 1;
bool ledState = false;


void setup() {
  Serial.begin(9600);
  pinMode(redLightPin,OUTPUT);
  pinMode(buttonReadPin,INPUT);
}

void loop() {
 buttonReadVal = digitalRead(buttonReadPin);
 Serial.println(buttonReadVal);

 if (buttonOldVal == 0 && buttonReadVal == 1) {
    if (!ledState) {
      digitalWrite(redLightPin, HIGH);
      ledState = true;
    } else {
       digitalWrite(redLightPin, LOW);
      ledState = false;
    }
 }
 buttonOldVal = buttonReadVal;

 delay(100);

 
}
