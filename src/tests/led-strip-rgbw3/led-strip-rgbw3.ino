/*
    LED Strip controlled by potentiometer with animations and dynamic brightness

*/

#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 144
#define LED_DATA_PIN 5
#define POT_DATA_PIN A0
#define POT_SWITCH_PIN 7
#define LOW_BRIGHTNESS 5
#define DELAYVAL 10

Adafruit_NeoPixel pixels(NUMPIXELS, LED_DATA_PIN, NEO_RGBW + NEO_KHZ800);

bool isSwitchedOff = true;

void setup() {
  Serial.begin(9600);

  pinMode(POT_SWITCH_PIN, INPUT_PULLUP);
  
  pixels.begin();

  startUpAnimation();
}

void loop() {
  
  if(isSwitchedOn()) {
    
    turnOnIfNeeded();

    processCurrentInput();
    
  } else {
    turnOffIfNeeded();
  }

  delay(DELAYVAL);
}

void processCurrentInput() {
  int pivot = map(analogRead(POT_DATA_PIN), 0, 1023, 0, NUMPIXELS);
  int dynamicBrightness = map(analogRead(POT_DATA_PIN), 0, 1023, LOW_BRIGHTNESS, 255);

  for(int i=0; i < pivot; i++) {
    pixels.setPixelColor(i, getColor(dynamicBrightness));
  }

  for(int i=pivot; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, getColor(LOW_BRIGHTNESS));
  }

  pixels.show();
}

bool isSwitchedOn() {
  // because of INPUT_PULLUP, the values LOW and HIGH are switched
  return digitalRead(POT_SWITCH_PIN) == LOW;
}

void turnOnIfNeeded() {
  if(isSwitchedOff) {
      turnOn();
      isSwitchedOff = false;
    }
}

void turnOffIfNeeded() {
  if(!isSwitchedOff) {
    turnOff();
    isSwitchedOff = true;
  }
}

void turnOn() {
  Serial.println("turning on.");
  for(int i=0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, getColor(LOW_BRIGHTNESS));
  }
  pixels.show();
}

void turnOff() {
  Serial.println("turning off.");
  for(int i=NUMPIXELS-1; i >= 0; i--) {
    pixels.setPixelColor(i, getColor(0));
    pixels.show();
  }
}

void startUpAnimation() {
  Serial.println("starting up.");
  for(int j=0; j < 3; j++) {
    for(int i=0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, getColor(255));
    }
    pixels.show();
    delay(200);

    for(int i=0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, getColor(0));
    }
    pixels.show();
    delay(200);
  }
}

uint32_t getColor(int brightness) {
  return pixels.Color(0, 0, 0, brightness);
}
