#ifndef PIEZA_BASE_H
#define PIEZA_BASE_H
#include "cilindro.h"
#include "cubo.h"
#include "pieza_cubo.h"

class Pieza_Media : public Objeto3D
{
    Cilindro cilindro;
    Pieza_cubo pieza_cubo;
public:
    Pieza_Media();
    void draw(int modo, float velocidad);
};

#endif // PIEZA_BASE_H
