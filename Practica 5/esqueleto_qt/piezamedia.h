#ifndef PIEZAMEDIA_H
#define PIEZAMEDIA_H
#include "cilindro.h"
#include "cubo.h"
#include "pieza1.h"

class PiezaMedia : public Objeto3D
{
    Pieza1 pieza1;
    Cilindro cilindro;
    Cubo cubo;
public:
    PiezaMedia();
    void draw(int modo);
};

#endif // PIEZAMEDIA_H
