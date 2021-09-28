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
    Imagen(int x, int y);
    void set_color(int x, int y, Pixel_RGB color);   
    int getFila() const;
    void setFila(int value);
    int getColumna() const;
    void setColumna(int value);
    void imprimir_pruebas();
    void txt_generado(int x, int y);
    Pixel_RGB Promedio_Color(int fo, int cantidadF, int co, int cantidadC);
    Pixel_RGB recorrer(int fo, int co);
};



#endif // IMAGEN_H
