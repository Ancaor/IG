#ifndef ESFERA_TEXTURA_H
#define ESFERA_TEXTURA_H
#include "o3dr.h"

class Esfera_Textura : public O3DR
{
    QImage textura;
    bool textura_habilitada = false;
public:
    Esfera_Textura();
    Esfera_Textura(int d, float r);
    void cargarTextura(QString path);
    void drawTextura();
    void draw_Triangles_Iluminacion_Flat(Material material);
    void draw_Triangles_Iluminacion_Smooth(Material material);
    void setTextura(bool check);
};

#endif // ESFERA_TEXTURA_H
