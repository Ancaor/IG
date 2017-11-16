#ifndef BRAZOPEQUENIO_H
#define BRAZOPEQUENIO_H

#include "cilindro.h"
#include "o3d.h"

class BrazoPequenio
{
private:
    Cilindro cilindro = Cilindro(40,360);
public:
    BrazoPequenio();
    void draw(int tipo);
};

#endif // BRAZOPEQUENIO_H
