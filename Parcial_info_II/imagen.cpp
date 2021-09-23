#include "imagen.h"

Imagen::Imagen()
{


}

Imagen::Imagen(int M, int N)
{
    fila=M;
    columna=N;
    Pixel_color.resize(M,vector<Pixel_RGB>(N));
}

void Imagen::set_color(int x, int y, Pixel_RGB color){
        Pixel_color[x][y].setColor(color);
    }
