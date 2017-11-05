#ifndef BASE_H
#define BASE_H

#include "o3dr.h"
#include"cilindro.h"
#include "cubo.h"
#include "partemedia.h"
class Base : public O3DR
{
private:
    Cilindro cilindro1 = Cilindro(40);
    Cilindro cilindro2 = Cilindro(40);
    Cilindro cilindro3 = Cilindro(40);
    Cubo cubo1 = Cubo();
    Cubo cubo2 = Cubo();
    Cubo cubo3 = Cubo();
    ParteMedia pmed = ParteMedia();
public:
    Base();
    void draw(int tipo);
};

#endif // BASE_H
