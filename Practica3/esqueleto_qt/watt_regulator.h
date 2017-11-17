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
    Cilindro cilindro1 = Cilindro(40,360);
    Cubo cubo1 = Cubo();
    ParteSuperior psup = ParteSuperior("");



    constexpr static const double Z_MAX = 81.86989;    // Máximo angulo alcanzable por brazos para que no choque la caja del medio con la superior.
    constexpr static const double Z_MIN = 38.9388;     // Mínimo angulo alcanzable por brazos para que el tope no atraviese la base.


    double angle_z;                   // Angulo que forman los brazos con el mastil
    string path;

public:
    WattRegulator(string path);
    void draw(int tipo, double angle , double velocidad);
    void calcular_angulo_z(double velocidad);
};

#endif // WATT_REGULATOR_H
