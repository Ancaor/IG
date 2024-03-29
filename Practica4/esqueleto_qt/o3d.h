#ifndef O3D_H
#define O3D_H

#include "material.h"
#include "luz.h"
#include "o3ds.h"

class O3D : public O3DS
{
public:
    std::vector<_vertex3i> triangles;
    std::vector<_vertex3f> normalCaras;
    std::vector<_vertex3f> normalVertices;

    O3D();
    void drawLines();
    void drawFill();
    void drawAjedrez();
    void calcularNormalesCaras();
    void drawNormalesCaras();
    void calcularNormalesVertices();
    void drawFillIluminado(Material material , bool iluminacion);
    void drawFillIluminadoSuave(Material material , bool iluminacion);
    void drawNormalesVertices();
};

#endif // O3D_H
