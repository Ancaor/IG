#ifndef WATT_H
#define WATT_H
#include "pieza_media.h"
#include "pieza_brazo.h"

class Watt : public Objeto3D
{
    Pieza_Media pieza_media;
    Pieza_Brazo pieza_brazo;
    Cubo cubo;
public:
    Watt();
    void draw(int modo, float angulo, float velocidad);
};

#endif // WATT_H
