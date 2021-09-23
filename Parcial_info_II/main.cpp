#include <iostream>
#include <QImage>
#include<fstream>
#include <vector>
#include "pixel_rgb.h"
#include "imagen.h"

using namespace std;

int main()
{
    string filename="../Parcial_info_II/imagenes/Brasil.jpeg";
    QImage im(filename.c_str());

    Imagen imagen_original(im.width(),im.height());

    for(int filas=0;filas<im.width();++filas){
        for(int columnas=0;columnas<im.height();++columnas){
              Pixel_RGB color(im.pixelColor(filas,columnas).red(), im.pixelColor(filas,columnas).green(),im.pixelColor(filas,columnas).blue());
              imagen_original.set_color(filas,columnas,color);
        }
    }
}
