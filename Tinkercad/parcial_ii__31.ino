#include <Adafruit_NeoPixel.h>
#define PIN 2
#define LED_COUNT 256
Adafruit_NeoPixel leds(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

//Bienvenido! 
//Por favor copie y pegue el txt generado "Tinker" en la siguiente línea de abajo
//Luego de insertarlo, dele click en el botón "Inciar simulación" en la parte superior derecha
//Recuerde que las obras maestras requieren tiempo
//los LEDs tardarán de 20 a 30 segundos en encenderce por completo


void setup()
{
  leds.begin(); 
  leds.show(); //comando para presentar la informacion/colores
}


void loop()
{
  for(int i = 0; i < LED_COUNT; i++){
  		leds.setPixelColor(i, arrays[i][0],arrays[i][1],arrays[i][2]);
  }
  leds.show();
}