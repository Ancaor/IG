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
    void drawTextura();
    void drawFillIluminado(Material material, bool iluminacion);
    void cargarImagen(string path);
    void drawFillIluminadoSuave(Material material , bool iluminacion);
};

#endif // ESFERATEXTURIZADA_H
