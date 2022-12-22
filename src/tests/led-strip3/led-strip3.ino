/*
    LED Strip controlled by potentiometer with animations

*/

#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 144
#define LED_DATA_PIN 6

Adafruit_NeoPixel pixels(NUMPIXELS, LED_DATA_PIN, NEO_GRB + NEO_KHZ800);

#define POT_DATA_PIN A0
#define POT_SWITCH_PIN 7
#define DELAYVAL 10

#define STAGE_1_BRIGHTNESS 10
#define STAGE_2_BRIGHTNESS 255

bool is_switched_off = true;

void setup() {
  Serial.begin(9600);

  pinMode(POT_SWITCH_PIN, INPUT_PULLUP);
  
  pixels.begin();
}

void loop() {
  
  if(isSwitchedOn()) {
    turnOnIfNeeded();

    // control pot
    potController();
    
  } else {
    turnOffIfNeeded();
  }

  delay(DELAYVAL);
}

void potController() {
  int lauf = map(analogRead(POT_DATA_PIN), 0, 1023, 0, NUMPIXELS);

  for(int i=0; i < lauf; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
  }

  for(int i=lauf; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 10));
  }

  pixels.show();
}

bool isSwitchedOn() {
  // because of INPUT_PULLUP, the values LOW and HIGH are switched
  return digitalRead(POT_SWITCH_PIN) == LOW;
}

void turnOnIfNeeded() {
  if(is_switched_off) {
      turnOn();
      is_switched_off = false;
    }
}

void turnOffIfNeeded() {
  if(!is_switched_off) {
    turnOff();
    is_switched_off = true;
  }
}

void turnOn() {
  Serial.println("turning on.");
  for(int i=0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 10));
    pixels.show();
  }
}

void turnOff() {
  Serial.println("turning off.");
  for(int i=NUMPIXELS-1; i >= 0; i--) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
  }
}
