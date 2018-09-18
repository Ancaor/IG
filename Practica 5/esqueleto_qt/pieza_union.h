#ifndef PIEZA_UNION_H
#define PIEZA_UNION_H
#include "cilindro.h"
#include "pieza_ply.h"

class Pieza_union : public Objeto3D
{
    Cilindro cilindro;
    Pieza_PLY piezaPLY;
public:
    Pieza_union();
    void draw(int modo);
};

#endif // PIEZA_UNION_H
