#ifndef PARTESUPERIOR_H
#define PARTESUPERIOR_H

#include "o3d.h"
#include "brazo.h"
#include "cubowatt.h"
#include "cubo.h"

class ParteSuperior
{
    private:

        Brazo brazo = Brazo();
        CuboWatt cuboWatt = CuboWatt();
        Cubo cubo = Cubo();
    public:
        ParteSuperior();
        void draw(int tipo, double angle_z);
};

#endif // PARTESUPERIOR_H
