#include <iostream>
#include <QImage>
#include<fstream>
#include <vector>
#include "pixel_rgb.h"
#include "imagen.h"

using namespace std;

Imagen reducir(Imagen imagen,int x, int y);//Funcion de submuestreo

int main()
{
    QImage im;
    string FilePath = "../Parcial_info_II/Imagenes/";
    string fileName;
    int x, y;

    cout<<endl<<"------------------"<< endl ;
    cout <<"|||[Bienvenido]|||"<<endl;
    cout<<"------------------"<< endl ;
    cout << "Ingrese el nombre de la imagen con su formato incluido"<<endl;
    cout<< "Ingrese: ";
    cin >> fileName; cout << endl;
    FilePath.append(fileName);
    cout<<"Ingrese el tamaño de la imagen deseado: "<<endl;
    cout<<"Ancho: ";
    cin>>x;
    cout<<endl<<"Alto: ";
    cin>>y;
    cout<<endl;

    if(im.load(FilePath.c_str())){
        cout <<"..."<< endl;
        cout << "Imagen cargada con exito. " << endl;
    }
    else{
        cout << "La imagen no existe" << endl;
        cout << "La imagen debe estar dentro de la carpeta 'Imagenes'" << endl;
        exit(1);
    }

    Imagen imagen_original(im.width(),im.height());

    for(int filas=0;filas<im.width();++filas){
        for(int columnas=0;columnas<im.height();++columnas){
              Pixel_RGB color(im.pixelColor(filas,columnas).red(), im.pixelColor(filas,columnas).green(),im.pixelColor(filas,columnas).blue());
              imagen_original.set_color(filas,columnas,color);
        }
    }

    imagen_original.txt_generado();

}


Imagen reducir(Imagen imagen,int m, int n){
    int bloqueF= imagen.getFila()/m;//obtenemos bloque de filas x
    int bloqueC= imagen.getColumna()/n;//obtenemos bloque de columnas y

    for (int i=0; i<imagen.getFila(); i+=bloqueF) {
        for (int j=0; j<imagen.getColumna(); j+=bloqueC ) {
        }
    }

}
