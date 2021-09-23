#include <Adafruit_NeoPixel.h> 
#define PIN 2
#define LED_COUNT 256


void setup()
{
  leds.begin(); 
  
  for (int i=0; i<LED_COUNT; i++){
    leds.setPixelColor(i, 0, 20, 250);
    
  }
  leds.show(); //comando para presentar la informacion/colores
}


void loop()
{

}