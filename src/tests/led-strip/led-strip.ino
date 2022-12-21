/*
    Hello World test with LED Strip

*/

#include <Adafruit_NeoPixel.h>

#define PIN 6

#define NUMPIXELS 144

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 5

void setup() {
  pixels.begin();
}

void loop() {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<pixels.numPixels(); i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / pixels.numPixels());
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    }
    pixels.show();
    delay(DELAYVAL);
  }
}
