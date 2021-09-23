#include <Adafruit_NeoPixel.h>
#define PIN 2
#define LED_COUNT 256
Adafruit_NeoPixel strip(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);


void setup()
{
  strip.begin(); 
  strip.show(); //comando para presentar la informacion/colores
}


void loop()
{
  for(int i = 0; i < LED_COUNT; i++){
  		//leds.setPixelColor(i, arrays[i][0],arrays[i][1],arrays[i][2]);
      	strip.setPixelColor(i, 11,173,56);
  }
  strip.show();
}