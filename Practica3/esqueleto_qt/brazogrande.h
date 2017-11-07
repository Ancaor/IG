#ifndef BRAZOGRANDE_H
#define BRAZOGRANDE_H

#include"o3d.h"
#include"cilindro.h"
#include"esfera.h"

class BrazoGrande
{
private:
    Cilindro cilindro = Cilindro(40);
    Esfera esfera = Esfera(40);


public:
    BrazoGrande();
    void draw(int tipo);
};

#endif // BRAZOGRANDE_H
