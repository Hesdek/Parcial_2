#include <iostream>
#include <QImage>
#include<fstream>
#include <vector>
#include "pixel_rgb.h"
#include "imagen.h"
#include "menu.h"

using namespace std;

Imagen reducir(Imagen imagen,int x, int y);//Funcion de submuestreo
Imagen agrandar(Imagen imagen,int x, int y);//Funcion de sobremuestreo


int main()
{
    QImage im=menu();
    Imagen imagen_original(im.width(),im.height());
    Imagen reducida;
    Imagen agrandada;
    int x=ancho();
    int y=alto();

    for(int filas=0;filas<im.width();++filas){
        for(int columnas=0;columnas<im.height();++columnas){
              Pixel_RGB color(im.pixelColor(filas,columnas).red(), im.pixelColor(filas,columnas).green(),im.pixelColor(filas,columnas).blue());
              imagen_original.set_color(filas,columnas,color);
        }
    }
    if(im.width() > x && im.height() > y){
        reducida=reducir(imagen_original,x,y);
        reducida.txt_generado(x,y);
    }
    else if(im.width() < x && im.height() < y){
        agrandada=agrandar(imagen_original,x,y);
        agrandada.txt_generado(x,y);
    }
    else if(im.width() == x && im.height()== y){
        imagen_original.txt_generado(x,y);
    }


}



Imagen reducir(Imagen imagen,int x, int y){
    Imagen reducida(x,y);
    int bloqueF= imagen.getFila()/x;//obtenemos bloque de filas x
    int bloqueC= imagen.getColumna()/y;//obtenemos bloque de columnas y
    int c=0, f=0;

    int filaO=imagen.getFila();
    int ColumnaO=imagen.getColumna();


    if(bloqueF*x<filaO){
        int dif=filaO-bloqueF*x;
        filaO-=dif;
    }
    if(bloqueC*y<ColumnaO){
        int dif=ColumnaO-bloqueC*y;
        ColumnaO-=dif;
    }

    for (int i=0; i<filaO; i+=bloqueF) {
        c=0;
        for (int j=0; j<ColumnaO; j+=bloqueC ) {
            Pixel_RGB nuevoPixel = imagen.Promedio_Color(i,bloqueF,j,bloqueC);
            reducida.set_color(c,f,nuevoPixel);
            c++;
        }
        f++;
    }
    return reducida;
}

Imagen agrandar(Imagen imagen,int x, int y){
    int bloqueF = x/imagen.getFila();
    int bloqueC = y/imagen.getColumna();
    Imagen agrandada(x,y);
    int c=0, f=0;int difF=0, difC=0;


   for(int k=0;k<bloqueF;k++){
    difF=x-bloqueF*imagen.getFila();
    for(int i=0;i<imagen.getFila();i++){
        if(bloqueF==1){
            if(difF>=0){
                difF--;
                 i= 0;
            }
        }
        else if(bloqueF>1){
            if(difF>=0 and k>0){
                difF--;
                i= 0;
            }
        }
        c=0;
        difC=y-bloqueC*imagen.getColumna();
        for(int j=0;j<imagen.getColumna();j++){
            if(difC>0){
                bloqueC = y/imagen.getColumna()+1;
                difC--;
            }
            else{
            bloqueC= y/imagen.getColumna();
            }
            for(int l=0;l<bloqueC;l++){
            Pixel_RGB nuevoPixel= imagen.recorrer(i,j);
            agrandada.set_color(c,f,nuevoPixel);
            c++;
           }
          }
          f++;
        }
    }

    return agrandada;
}


