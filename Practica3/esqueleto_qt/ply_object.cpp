#include "ply_object.h"

PLY_Object::PLY_Object()
{
    pathname_ply = "/home";
}


//*************************************************************************
// Abre el selector de archvivos  y una vez seleccionado un PLY lo carga.
//*************************************************************************


void PLY_Object::read_ply()
{
    _file_ply File_ply;

    if (File_ply.open(buscarPLY())){
      File_ply.read(vertices,triangles);
      std::cout << "PLY leido correctamente." << std::endl;
    }
    else std::cout << "No se pudo leer el archivo PLY, se mostrara el PLY cargado anteriormente, si existe." << std::endl;
}


//*************************************************************************
// Abre un cuadro de dialogo para buscar el PLY que se desea abrir
// La primera vez que se abre se buscara desde /home, pero las siguientes veces
// se habra cambiado el path de inicio al del ultimo PLY abierto.
//*************************************************************************


string PLY_Object::buscarPLY(){

    QString fileName = QFileDialog::getOpenFileName(0,QString::fromStdString("Abrir PLY"), pathname_ply, QString::fromStdString("Archivos PLY (*.ply)"));
    string aux = fileName.toStdString();

    pathname_ply = getPathPLYs(aux);

    return aux;

}


//*************************************************************************
// Obtiene el path de un PLY para que recuerde donde suelen estar los
// archivos PLY
//*************************************************************************

QString PLY_Object::getPathPLYs(string archivo){

    QString path_ply;
    int index = archivo.size()-1;

    while(archivo[index] != '/'){
        index --;
    }

    path_ply = QString::fromStdString(archivo.substr(0,index));

    return path_ply;
}

bool PLY_Object::plyCargado()
{
    if(vertices.size()!=0)
        return true;
    else
        return false;
}
