/*
    LED Strip controlled by potentiometer (WS2812B)
*/

#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 144

#define LED_DATA_PIN 6

Adafruit_NeoPixel pixels(NUMPIXELS, LED_DATA_PIN, NEO_GRB + NEO_KHZ800);

#define POT_READ_PIN A0

#define DELAYVAL 10


void setup() {
  pixels.begin();
}

void loop() {

  int POT_VALUE = analogRead(POT_READ_PIN);
  
  int lauf = map(POT_VALUE, 0, 1023, 0, NUMPIXELS);

  for(int i=0; i < lauf; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
  }

  for(int i=lauf; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }

  pixels.show();
  delay(DELAYVAL);
}
