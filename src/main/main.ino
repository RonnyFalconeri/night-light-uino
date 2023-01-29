#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 144

#define LED_DATA_PIN_LEFT 5
#define POT_DATA_PIN_LEFT A0
#define POT_SWITCH_PIN_LEFT 7

#define LED_DATA_PIN_RIGHT 6
#define POT_DATA_PIN_RIGHT A1
#define POT_SWITCH_PIN_RIGHT 8

#define LOW_BRIGHTNESS 5
#define DELAYVAL 10

Adafruit_NeoPixel STRIP_LEFT(NUMPIXELS, LED_DATA_PIN_LEFT, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel STRIP_RIGHT(NUMPIXELS, LED_DATA_PIN_RIGHT, NEO_RGBW + NEO_KHZ800);

bool isLeftSwitchedOff = true;
bool isRightSwitchedOff = true;

void setup() {
  Serial.begin(9600);

  pinMode(POT_SWITCH_PIN_LEFT, INPUT_PULLUP);
  pinMode(POT_SWITCH_PIN_RIGHT, INPUT_PULLUP);
  
  STRIP_LEFT.begin();
  STRIP_RIGHT.begin();

  startUpAnimation();
}

void loop() {
  
  if(isLeftSwitchedOn()) {
    
    turnOnLeftIfNeeded();

    processCurrentInputLeft();
    
  } else {
    turnOffLeftIfNeeded();
  }

  if(isRightSwitchedOn()) {
    
    turnOnRightIfNeeded();

    processCurrentInputRight();
    
  } else {
    turnOffRightIfNeeded();
  }

  delay(DELAYVAL);
}


bool isLeftSwitchedOn() {
  // because of INPUT_PULLUP, the values LOW and HIGH are switched
  return digitalRead(POT_SWITCH_PIN_LEFT) == LOW;
}

bool isRightSwitchedOn() {
  // because of INPUT_PULLUP, the values LOW and HIGH are switched
  return digitalRead(POT_SWITCH_PIN_RIGHT) == LOW;
}

void turnOnLeftIfNeeded() {
  if(isLeftSwitchedOff) {
      turnLeftOn();
      isLeftSwitchedOff = false;
    }
}

void turnLeftOn() {
  Serial.println("turning on.");
  for(int i=0; i < NUMPIXELS; i++) {
    STRIP_LEFT.setPixelColor(i, getColor(LOW_BRIGHTNESS));
  }
  STRIP_LEFT.show();
}

void turnOnRightIfNeeded() {
  if(isRightSwitchedOff) {
      turnRightOn();
      isRightSwitchedOff = false;
    }
}

void turnRightOn() {
  Serial.println("turning on.");
  for(int i=0; i < NUMPIXELS; i++) {
    STRIP_RIGHT.setPixelColor(i, getColor(LOW_BRIGHTNESS));
  }
  STRIP_RIGHT.show();
}

void processCurrentInputLeft() {
  int pivot = map(analogRead(POT_DATA_PIN_LEFT), 0, 1023, 0, NUMPIXELS);
  int dynamicBrightness = map(analogRead(POT_DATA_PIN_LEFT), 0, 1023, LOW_BRIGHTNESS, 255);

  for(int i=0; i < pivot; i++) {
    STRIP_LEFT.setPixelColor(i, getColor(dynamicBrightness));
  }

  for(int i=pivot; i < NUMPIXELS; i++) {
    STRIP_LEFT.setPixelColor(i, getColor(LOW_BRIGHTNESS));
  }

  STRIP_LEFT.show();
}

void processCurrentInputRight() {
  int pivot = map(analogRead(POT_DATA_PIN_RIGHT), 0, 1023, 0, NUMPIXELS);
  int dynamicBrightness = map(analogRead(POT_DATA_PIN_RIGHT), 0, 1023, LOW_BRIGHTNESS, 255);

  for(int i=0; i < pivot; i++) {
    STRIP_RIGHT.setPixelColor(i, getColor(dynamicBrightness));
  }

  for(int i=pivot; i < NUMPIXELS; i++) {
    STRIP_RIGHT.setPixelColor(i, getColor(LOW_BRIGHTNESS));
  }

  STRIP_RIGHT.show();
}

void turnOffLeftIfNeeded() {
  if(!isLeftSwitchedOff) {
    turnOffLeft();
    isLeftSwitchedOff = true;
  }
}

void turnOffRightIfNeeded() {
  if(!isRightSwitchedOff) {
    turnOffRight();
    isRightSwitchedOff = true;
  }
}

void turnOffLeft() {
  Serial.println("turning off.");
  for(int i=NUMPIXELS-1; i >= 0; i--) {
    STRIP_LEFT.setPixelColor(i, getColor(0));
    STRIP_LEFT.show();
  }
}

void turnOffRight() {
  Serial.println("turning off.");
  for(int i=NUMPIXELS-1; i >= 0; i--) {
    STRIP_RIGHT.setPixelColor(i, getColor(0));
    STRIP_RIGHT.show();
  }
}

void startUpAnimation() {
  Serial.println("starting up.");
  for(int j=0; j < 3; j++) {
    for(int i=0; i < NUMPIXELS; i++) {
      STRIP_LEFT.setPixelColor(i, getColor(255));
      STRIP_RIGHT.setPixelColor(i, getColor(255));
    }
    STRIP_LEFT.show();
    STRIP_RIGHT.show();
    delay(200);

    for(int i=0; i < NUMPIXELS; i++) {
      STRIP_LEFT.setPixelColor(i, getColor(0));
      STRIP_RIGHT.setPixelColor(i, getColor(0));
    }
    STRIP_LEFT.show();
    STRIP_RIGHT.show();
    delay(200);
  }
}

uint32_t getColor(int brightness) {
  return STRIP_LEFT.Color(0, 0, 0, brightness);
}
