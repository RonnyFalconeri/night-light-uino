/*
    Hello World test with LED Strip

*/

#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 144

Adafruit_NeoPixel pixels_left(NUMPIXELS, 5, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel pixels_right(NUMPIXELS, 6, NEO_RGBW + NEO_KHZ800);

#define DELAYVAL 5

void setup() {
  pixels_left.begin();
  pixels_right.begin();
}

void loop() {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<NUMPIXELS; i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / NUMPIXELS);
      pixels_left.setPixelColor(i, pixels_left.gamma32(pixels_left.ColorHSV(pixelHue)));
      pixels_right.setPixelColor(i, pixels_right.gamma32(pixels_right.ColorHSV(pixelHue)));
    }
    pixels_left.show();
    pixels_right.show();
    delay(DELAYVAL);
  }
}
