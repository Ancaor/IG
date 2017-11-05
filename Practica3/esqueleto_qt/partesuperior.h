#ifndef PARTESUPERIOR_H
#define PARTESUPERIOR_H

#include "o3d.h"
#include "brazo.h"
#include "cubo.h"

class ParteSuperior
{
    private:

        Brazo brazo1 = Brazo();
        Brazo brazo2 = Brazo();
        Cubo cubo = Cubo();
    public:
        ParteSuperior();
        void draw(int tipo);
};

#endif // PARTESUPERIOR_H
