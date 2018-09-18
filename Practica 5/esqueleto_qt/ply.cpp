#include "ply.h"

PLY::PLY(){
    path = "/home";
}

void PLY::ReadPLY()
{
    string fichero;
    QString fileName = QFileDialog::getOpenFileName(0, QTranslator::tr("Abrir PLY"), path, QTranslator::tr("Archivos PLY (*.ply)"));
    fichero = fileName.toStdString();
    path = this->VentanaPLY(fichero);
    _file_ply File_ply;
    if (File_ply.open(fichero)){
        File_ply.read(Vertices,Superficie);
        std::cout << "File read correctly" << std::endl;
    }
    else std::cout << "File can't be opened" << std::endl;

    this->calculaNormales();
}

void PLY::ReadPLY(QString fichero)
{
    string aux = fichero.toStdString();
    _file_ply File_ply;
    if (File_ply.open(aux)){
        File_ply.read(Vertices,Superficie);
        std::cout << "File read correctly" << std::endl;
    }
    else std::cout << "File can't be opened" << std::endl;
    this->calculaNormales();


}

QString PLY::VentanaPLY(string archivo){
    QString directorio;
    int indice = archivo.size() -1;
    while(archivo[indice] != '/')
        indice--;

    directorio = QString::fromStdString(archivo.substr(0, indice));

    return directorio;
}

