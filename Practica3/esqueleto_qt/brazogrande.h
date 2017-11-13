#ifndef BRAZOGRANDE_H
#define BRAZOGRANDE_H

#include"o3d.h"
#include"cilindro.h"
#include"esfera.h"
#include "esfera_beethoven.h"

class BrazoGrande
{
private:
    Cilindro cilindro = Cilindro(40);
    esfera_beethoven es_beeth;
public:
    BrazoGrande();
    void draw(int tipo);
};

#endif // BRAZOGRANDE_H
