#ifndef ESFERATEXTURIZADA_H
#define ESFERATEXTURIZADA_H

#include "o3dr.h"


class EsferaTexturizada : public O3DR
{
private:
    QImage Imagen;
    int n;
    int index;

public:
    EsferaTexturizada();
    EsferaTexturizada(int secciones, int angulo, float radio);
    void generar_objeto_de_revolucion(int angulo);
    void drawTextura(string path_textura, bool cargar_textura);
    void drawFillIluminado(std::string path_textura,bool cargar_textura,Material material, bool iluminacion);
    void cargarImagen(string path);
    void drawFillIluminadoSuave(std::string path_textura,bool cargar_textura,Material material , bool iluminacion);
   // void generar_caras();
};

#endif // ESFERATEXTURIZADA_H
