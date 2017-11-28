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
public:
    Luz();
    Luz(int w);
    void transformar(float alfa, float beta, float distancia);
    void enable();
    void disable();
};

#endif // LUZ_H
