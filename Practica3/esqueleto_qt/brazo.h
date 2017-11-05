#ifndef BRAZO_H
#define BRAZO_H

#include"o3d.h"
#include"cilindro.h"
#include"esfera.h"


class Brazo : public O3D
{
private:
    Esfera esfera = Esfera(40);
    Cilindro cilindro = Cilindro(40);
public:
    Brazo();
    void draw(int tipo);

};

#endif // BRAZO_H
