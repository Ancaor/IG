#ifndef BASE_H
#define BASE_H

#include "o3dr.h"
#include"cilindro.h"

class Base : public O3DR
{
private:
    Cilindro cilindro = Cilindro(40);

public:
    Base();
    void draw(int tipo);
};

#endif // BASE_H
