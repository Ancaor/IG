#ifndef ESFERA_BEETHOVEN_H
#define ESFERA_BEETHOVEN_H

#include "esfera.h"
#include "ply_object.h"

class esfera_beethoven : public O3D
{

private:
    Esfera esfera = Esfera(40,360);
    PLY_Object ply_object;
public:
    esfera_beethoven(string path);
    void draw(int tipo);
};

#endif // ESFERA_BEETHOVEN_H
