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

Pixel_RGB Imagen::Promedio_Color(int fo, int cantidadF, int co, int cantidadC)
{
    int limF = fo+cantidadF;
    int limC = co+cantidadC;
    int pixeles = cantidadF*cantidadC;
    int sumaRed = 0, sumaGreen= 0, sumaBlue = 0;
    for (int f=fo; f<limF; f++ ) {
        for (int c=co; c<limC; c++ ) {
            sumaRed += Pixel_color[f][c].getRed();
            sumaGreen += Pixel_color[f][c].getGreen();
            sumaBlue += Pixel_color[f][c].getBlue();
        }
    }

    return Pixel_RGB(sumaRed/pixeles, sumaGreen/pixeles, sumaBlue/pixeles);
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
            txt<<"{"<<Pixel_color[i][j].getRed()<<","<<Pixel_color[i][j].getGreen()<<","<<Pixel_color[i][j].getBlue()<<"}";
            if(j<columna-1){
                txt<<",";
            }
        }
            txt<<endl;
        }
   txt<<"};";
   txt.close();
   cout<<endl<<"Completado"<<endl;
}
