#ifndef CUBOWATT_H
#define CUBOWATT_H

#include "a.out.h"
#include "cubo.h"
class CuboWatt
{
private:
    Cubo cubo = Cubo();

public:
    CuboWatt();
    void draw(int tipo);
};

#endif // CUBOWATT_H
