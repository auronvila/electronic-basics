String userAnswer;
int redDiodePin = 6;
int greenDiodePin = 7;
int blueDiodePin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(redDiodePin,OUTPUT);
  pinMode(greenDiodePin,OUTPUT);
  pinMode(blueDiodePin,OUTPUT);
}

void loop() {
  Serial.println("Which diode would you like to ligh up: red, green, blue");
  while (Serial.available() == 0) {  }

  userAnswer = Serial.readString();
  userAnswer.trim();
   Serial.print("You entered: ");
  Serial.println(userAnswer);
  if (userAnswer == "red") {
    digitalWrite(redDiodePin, HIGH);
    digitalWrite(greenDiodePin, LOW);
    digitalWrite(blueDiodePin, LOW);
  } else if (userAnswer == "green") {
    digitalWrite(greenDiodePin, HIGH);
    digitalWrite(blueDiodePin, LOW);
    digitalWrite(redDiodePin, LOW);
  } else if (userAnswer == "blue") {
    digitalWrite(blueDiodePin, HIGH);
    digitalWrite(redDiodePin, LOW);
    digitalWrite(greenDiodePin, LOW);
  } else {
    Serial.println("Your choice is incorrect. Take the punishment :) ");
    digitalWrite(redDiodePin, HIGH);
    digitalWrite(greenDiodePin, HIGH);
    digitalWrite(blueDiodePin, HIGH);
  }
  
  Serial.println(userAnswer);
  delay(1000);
}
