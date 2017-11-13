#ifndef WATT_REGULATOR_H
#define WATT_REGULATOR_H

#include "o3dr.h"
#include"cilindro.h"
#include "cubo.h"
#include "partesuperior.h"
//#include "partemedia.h"

class WattRegulator : public O3DR
{
private:
    Cilindro cilindro1 = Cilindro(40);
    Cubo cubo1 = Cubo();
    ParteSuperior psup = ParteSuperior();

    const double Z_MAX = 81.86989;
    const double Z_MIN = 38.9388;
    double angle_z;
public:
    WattRegulator();
    void draw(int tipo,double angle ,double velocidad );
    void calcular_angulo_z(double velocidad);
};

#endif // WATT_REGULATOR_H
