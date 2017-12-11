#ifndef BRAZOGRANDE_H
#define BRAZOGRANDE_H

#include"o3d.h"
#include"cilindro.h"
#include"esfera.h"
#include "esfera_beethoven.h"

class BrazoGrande
{
private:
    Cilindro cilindro = Cilindro(40,360);
    esfera_beethoven es_beeth = esfera_beethoven("");
public:
    BrazoGrande(string path);
    void draw(int tipo);
};

#endif // BRAZOGRANDE_H
