#ifndef PARTEMEDIA_H
#define PARTEMEDIA_H

#include "o3d.h"
#include "cilindro.h"
#include "partesuperior.h"
#include "cubo.h"
#include "cubowatt.h"
#include "brazopequenio.h"

class ParteMedia
{
    private:
        CuboWatt cuboWatt = CuboWatt();
        Cubo cubo = Cubo();
        Cilindro cilindro1=Cilindro(40);
        Cilindro cilindro2=Cilindro(40);
        ParteSuperior psup = ParteSuperior();
        Cubo cubo2 = Cubo();
        BrazoPequenio bpeq = BrazoPequenio();
    public:
        ParteMedia();
        void draw(int tipo, double angle_z);
};

#endif // PARTEMEDIA_H
