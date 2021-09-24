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

int Imagen::getFila() const
{
    return fila;
}

void Imagen::setFila(int value)
{
    fila = value;
}

int Imagen::getColumna() const
{
    return columna;
}

void Imagen::setColumna(int value)
{
    columna = value;
}

void Imagen::imprimir_pruebas()
{
    for (int i=0;i<fila ;i++ ) {
        for (int j=0;j<columna ;j++ ) {
            cout<<"{"<<Pixel_color[i][j].getRed()<<","<<Pixel_color[i][j].getGreen()<<","<<Pixel_color[i][j].getBlue()<<"}";
            }
            cout<<endl;
        }
}
void Imagen::txt_generado()
{
    ofstream txt;
    txt.open ("../Parcial_info_II/tinker.txt");
    txt << "byte arrays[256][3]={";
    for (int i=0;i<fila ;i++ ) {
        for (int j=0;j<columna ;j++ ) {
            txt<<"{"<<Pixel_color[i][j].getRed()<<","<<Pixel_color[i][j].getGreen()<<","<<Pixel_color[i][j].getBlue()<<"}"<<"}";
            }
            txt<<endl;
        }
   txt.close();
   cout<<"Completado";
}
