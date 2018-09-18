#ifndef PIEZACUERPO_H
#define PIEZACUERPO_H
#include "pieza1.h"

class PiezaCuerpo : public Objeto3D
{
    Cilindro cilindro;
    Pieza1 pieza1;
public:
    PiezaCuerpo();
    void draw(int modo);
};

#endif // PIEZACUERPO_H
