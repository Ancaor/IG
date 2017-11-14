#ifndef BRAZO_H
#define BRAZO_H

#include"o3d.h"
#include"brazopequenio.h"
#include "brazogrande.h"


class Brazo : public O3D
{
private:
    BrazoPequenio bpeq = BrazoPequenio();
    BrazoGrande brazog = BrazoGrande();

public:
    Brazo();
    void draw(int tipo,double angle_z);

};

#endif // BRAZO_H

