#ifndef PARTEMEDIA_H
#define PARTEMEDIA_H

#include "o3d.h"
#include "cilindro.h"
#include "partesuperior.h"
#include "cubo.h"

class ParteMedia
{
    private:
        Cubo cubo = Cubo();
        Cilindro cilindro1=Cilindro(40);
        Cilindro cilindro2=Cilindro(40);
        ParteSuperior psup = ParteSuperior();
        Cubo cubo2 = Cubo();
    public:
        ParteMedia();
        void draw(int tipo);
};

#endif // PARTEMEDIA_H
