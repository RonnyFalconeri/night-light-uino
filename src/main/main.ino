
int potPin = 2;
int potVal = 0;
int led1 = 11;
int led2 = 10;
byte full= 255;
byte low = 155;
byte dim = 55;

void setup(){
  pinMode(potPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);  
}

void loop(){
  potVal = analogRead(potPin);

  if (potVal>=0 && potVal<205) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }

  if (potVal>=205 && potVal<410) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }

  delay(100);
}