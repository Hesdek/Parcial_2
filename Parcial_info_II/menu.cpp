#include "menu.h"

QImage menu(){
    QImage im;
    string FilePath = "../Parcial_info_II/Imagenes/";
    string fileName;


cout<<"-------------------------------------------------------"<< endl ;
cout <<"|||||||||||||||||||||[BIENVENIDO]||||||||||||||||||||||"<<endl;
cout<<"-------------------------------------------------------"<< endl ;
cout << "Ingrese el nombre de la imagen con su formato incluido"<<endl;
cout<<"Ejemplo: Colombia.png"<<endl;
cout<< "Ingrese: ";
cin >> fileName; cout << endl;
FilePath.append(fileName);
if(im.load(FilePath.c_str())){
    cout <<"..."<< endl;
    cout << "Imagen cargada con exito. " << endl;
}
else{
    cout << "La imagen no existe" << endl;
    cout << "La imagen debe estar dentro de la carpeta 'Imagenes'" << endl;
    exit(1);
}
return im;
}

int ancho()
{
    int x;
    cout<<"Ingrese el tamano de la imagen deseado: "<<endl;
    cout<<"Ancho: ";
    cin>>x;

    return x;
}

int alto()
{
    int y;
    cout<<"Alto: ";
    cin>>y;

    return y;
}
