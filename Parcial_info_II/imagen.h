#ifndef IMAGEN_H
#define IMAGEN_H
#include <vector>
#include "pixel_rgb.h"
#include <iostream>
#include <fstream>

using namespace std;

class Imagen
{
private:
    int fila, columna;
    vector<vector<Pixel_RGB>> Pixel_color;

public:
    Imagen();
    Imagen(int M, int N);
    void set_color(int x, int y, Pixel_RGB color);   
    int getFila() const;
    void setFila(int value);
    int getColumna() const;
    void setColumna(int value);
    void imprimir_pruebas();
    void txt_generado();
};



#endif // IMAGEN_H
