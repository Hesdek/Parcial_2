#include "menu.h"

QImage menu(){
    QImage im;
    string FilePath = "../Parcial_info_II/Imagenes/";
    string fileName;


cout<<"------------------"<< endl ;
cout <<"|||[Bienvenido]|||"<<endl;
cout<<"------------------"<< endl ;
cout << "Ingrese el nombre de la imagen con su formato incluido"<<endl;
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
