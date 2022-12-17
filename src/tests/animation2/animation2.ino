/*
    Running light effect with dynamic brightness

*/

int led1 = 3;
int led2 = 5;
int led3 = 6;
int led4 = 9;
int led5 = 10;
int led6 = 11;

int del = 100;

int poti_max = 1023;
int amount_leds = 6;

int brightness_min = 50;
int brightness_max = 255;

int turn_point = (poti_max/5);

void setup(){
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT);  
  pinMode(led4, OUTPUT);  
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}

void loop(){
  int potVal = analogRead(A0);

  if(potVal <= turn_point) {
    int lauf = map(potVal, 0, turn_point, 0, amount_leds);

    lauflicht(lauf);
  } else {
    int brightness = map(potVal, turn_point, poti_max, brightness_min, brightness_max);
    
    analogWrite(led1, brightness);
    analogWrite(led2, brightness);
    analogWrite(led3, brightness);
    analogWrite(led4, brightness);
    analogWrite(led5, brightness);
    analogWrite(led6, brightness);
  }
  

}

void lauflicht(int scale) {
  if (scale==0) {
    analogWrite(led1, LOW);
    analogWrite(led2, LOW);
    analogWrite(led3, LOW);
    analogWrite(led4, LOW);
    analogWrite(led5, LOW);
    analogWrite(led6, LOW);
  }

  if (scale > 0) {
    analogWrite(led1, brightness_min);
    analogWrite(led2, LOW);
    analogWrite(led3, LOW);
    analogWrite(led4, LOW);
    analogWrite(led5, LOW);
    analogWrite(led6, LOW);
  }

  if (scale > 1) {
    analogWrite(led1, brightness_min);
    analogWrite(led2, brightness_min);
    analogWrite(led3, LOW);
    analogWrite(led4, LOW);
    analogWrite(led5, LOW);
    analogWrite(led6, LOW);
  }

  if (scale > 2) {
    analogWrite(led1, brightness_min);
    analogWrite(led2, brightness_min);
    analogWrite(led3, brightness_min);
    analogWrite(led4, LOW);
    analogWrite(led5, LOW);
    analogWrite(led6, LOW);
  }

  if (scale > 3) {
    analogWrite(led1, brightness_min);
    analogWrite(led2, brightness_min);
    analogWrite(led3, brightness_min);
    analogWrite(led4, brightness_min);
    analogWrite(led5, LOW);
    analogWrite(led6, LOW);
  }

  if (scale > 4) {
    analogWrite(led1, brightness_min);
    analogWrite(led2, brightness_min);
    analogWrite(led3, brightness_min);
    analogWrite(led4, brightness_min);
    analogWrite(led5, brightness_min);
    analogWrite(led6, LOW);
  }

  if (scale > 5) {
    analogWrite(led1, brightness_min);
    analogWrite(led2, brightness_min);
    analogWrite(led3, brightness_min);
    analogWrite(led4, brightness_min);
    analogWrite(led5, brightness_min);
    analogWrite(led6, brightness_min);
  }

  delay(del);
}