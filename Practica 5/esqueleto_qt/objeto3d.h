#ifndef OBJETO3D_H
#define OBJETO3D_H
#include "glwidget.h"
#include "material.h"
#include "luz.h"
#include <o3ds.h>

class Objeto3D : public O3DS
{
    public:

    //Atributos

    std::vector<_vertex3i> Superficie;
    std::vector<_vertex3f> Normales;
    std::vector<_vertex3f> Normales_V;
    _vertex4f color;
    _vertex4f color_lineas;

    //Métodos

    Objeto3D();

    void draw_Lines();
    void draw_Normales_Caras();
    void draw_Normales_Vertices();
    void draw_Triangles();
    void draw_Chess();
    void draw_Triangles_Iluminacion_Flat(Material mat);
    void draw_Triangles_Iluminacion_Smooth(Material mat);
    void calculaNormales();
    void calculaNormalesSuperficie();
    void calculaNormalesVertices();
    void setColor(float r, float g, float b, float alpha);
};

#endif // OBJETO3D_H
