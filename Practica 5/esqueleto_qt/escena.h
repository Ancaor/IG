#ifndef ESCENA_H
#define ESCENA_H
#include "cubo.h"
#include "vaso.h"
#include "esfera.h"
#include "ply.h"

class Escena
{
    PLY ply1;
    PLY ply2;
    PLY ply3;
    PLY ply4;
    PLY ply5;
    PLY ply6;
    PLY ply7;
    PLY ply8;
    PLY ply9;
    PLY ply10;
    PLY ply11;
    PLY ply12;
    PLY ply13;
    PLY ply14;
    PLY ply15;
    PLY ply16;

public:
    Escena();
    void draw(int modo);
    void setColor(_vertex4f color, int figura);
    void setColor(_vertex4f color);
};

#endif // ESCENA_H
