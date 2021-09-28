#include "imagen.h"

Imagen::Imagen()
{


}

Imagen::Imagen(int x, int y)
{
    fila=x;
    columna=y;
    Pixel_color.resize(x,vector<Pixel_RGB>(y));
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

Pixel_RGB Imagen::recorrer (int fo, int co)
{
    int limF = fo;
    int limC = co;
    int Red = 0, Green= 0, Blue = 0;
    for (int f=fo; f<=limF; f++ ) {
        for (int c=co; c<=limC; c++ ) {
            Red = Pixel_color[f][c].getRed();
            Green = Pixel_color[f][c].getGreen();
            Blue = Pixel_color[f][c].getBlue();
        }
    }

    return Pixel_RGB(Red, Green, Blue);
}

void Imagen::txt_generado(int x,int y)
{
    ofstream txt;
    txt.open ("../Parcial_info_II/tinker.txt");
    txt << "byte arrays["<<x*y<<"][3]={";
    for (int i=0;i<fila ;i++ ) {
        for (int j=0;j<columna ;j++ ) {
            txt<<"{"<<Pixel_color[i][j].getRed()<<","<<Pixel_color[i][j].getGreen()<<","<<Pixel_color[i][j].getBlue()<<"}";
            if(i==fila-1){
                if(j<columna-1){
                    txt<<",";
                }
            }
            else if(j<columna){
                txt<<",";
            }
        }
        txt<<endl;
    }
   txt<<"};";
   txt.close();
   cout<<endl<<"Completado"<<endl;
}
