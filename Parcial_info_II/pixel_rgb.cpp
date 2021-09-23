#include "pixel_rgb.h"


int Pixel_RGB::getRed() const
{
    return red;
}

void Pixel_RGB::setRed(int value)
{
    red = value;
}

int Pixel_RGB::getGreen() const
{
    return green;
}

void Pixel_RGB::setGreen(int value)
{
    green = value;
}

int Pixel_RGB::getBlue() const
{
    return blue;
}

void Pixel_RGB::setBlue(int value)
{
    blue = value;
}

Pixel_RGB::Pixel_RGB()
{

}

Pixel_RGB::Pixel_RGB(int r, int g, int b):red(r),green(g),blue(b)
{

}
//tipoRetorno Clase::nombre(param)
void Pixel_RGB::setColor(int r, int g, int b){
    red = r;
    green = g;
    blue = b;
}

void Pixel_RGB::setColor(Pixel_RGB color){
    red = color.red;
    green = color.green;
    blue = color.blue;
}
