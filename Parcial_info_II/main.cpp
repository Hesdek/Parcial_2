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
    Imagen reducida;


    for(int filas=0;filas<im.width();++filas){
        for(int columnas=0;columnas<im.height();++columnas){
              Pixel_RGB color(im.pixelColor(filas,columnas).red(), im.pixelColor(filas,columnas).green(),im.pixelColor(filas,columnas).blue());
              imagen_original.set_color(filas,columnas,color);
        }
    }
    reducida=reducir(imagen_original,x,y);
    reducida.txt_generado();

}



Imagen reducir(Imagen imagen,int m, int n){
    Imagen reducida(m,n);
    int bloqueF= imagen.getFila()/m;//obtenemos bloque de filas x
    int bloqueC= imagen.getColumna()/n;//obtenemos bloque de columnas y
    int c=0, f=0;

    int filaO=imagen.getFila();
    int ColumnaO=imagen.getColumna();
    if(bloqueF*m<filaO){
        int dif=filaO-bloqueF*m;
        filaO-=dif;
    }
    if(bloqueC*n<ColumnaO){
        int dif=ColumnaO-bloqueC*n;
        ColumnaO-=dif;
    }

    for (int i=0; i<filaO; i+=bloqueF) {
        c=0;
        for (int j=0; j<ColumnaO; j+=bloqueC ) {
            Pixel_RGB nuevoPixel = imagen.Promedio_Color(i,bloqueF,j,bloqueC);
                        reducida.set_color(f,c,nuevoPixel);
                        c++;
        }
        f++;
    }
    return reducida;
}

