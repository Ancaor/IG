#ifndef LUZ_H
#define LUZ_H

#include"GL/glew.h"

class Luz
{
private:
    GLfloat posicion[4];
    float alfa;
    float beta;
    float distancia;
    int tipo;
public:
    Luz();
    Luz(float x, float y, float z, float w);
    void transformar(float alfa, float beta, float distancia);
    void enable();
    void disable();
    bool estado;
};

#endif // LUZ_H
