#ifndef BRAZO_H
#define BRAZO_H
#include "esfera.h"
#include "cilindro.h"
#include "pieza_union.h"

class Pieza_Brazo : public Objeto3D
{
    Esfera esfera;
    Cilindro cilindro;
    Pieza_union pieza_union;
public:
    Pieza_Brazo();
    void draw(int modo, float angulo);
};

#endif // BRAZO_H
