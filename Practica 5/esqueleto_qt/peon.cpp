#include "peon.h"

Peon::Peon()
{
    divisiones--;
    tama_perfil = 12;
    Vertices.resize(tama_perfil);
    Vertices[0] = _vertex3f(0,-1.4,0);
    Vertices[1] = _vertex3f(1.0,-1.4,0);
    Vertices[2] = _vertex3f(1.0,-1.1,0);
    Vertices[3] = _vertex3f(0.5,-0.7,0);
    Vertices[4] = _vertex3f(0.4,-0.4,0);
    Vertices[5] = _vertex3f(0.4 ,0.5, 0.0);
    Vertices[6] = _vertex3f(0.5,0.6, 0.0);
    Vertices[7] = _vertex3f(0.3, 0.6, 0.0);
    Vertices[8] = _vertex3f(0.5 ,0.8 ,0.0);
    Vertices[9] = _vertex3f(0.55, 1.0, 0.0);
    Vertices[10] = _vertex3f(0.5, 1.2, 0.0);
    Vertices[11] = _vertex3f(0.3, 1.4, 0.0);
    Vertices[12] = _vertex3f(0, 1.4, 0);

    this->PintaObjeto(0,360);
    this->calculaNormales();
}

Peon::Peon(int d, float a_i, float a_f)
{
    divisiones = d-1;
    tama_perfil = 13;
    Vertices.resize(tama_perfil);
    Vertices[0] = _vertex3f(0,-1.4,0);
    Vertices[1] = _vertex3f(1.0,-1.4,0);
    Vertices[2] = _vertex3f(1.0,-1.1,0);
    Vertices[3] = _vertex3f(0.5,-0.7,0);
    Vertices[4] = _vertex3f(0.4,-0.4,0);
    Vertices[5] = _vertex3f(0.4 ,0.5, 0.0);
    Vertices[6] = _vertex3f(0.5,0.6, 0.0);
    Vertices[7] = _vertex3f(0.3, 0.6, 0.0);
    Vertices[8] = _vertex3f(0.5 ,0.8 ,0.0);
    Vertices[9] = _vertex3f(0.55, 1.0, 0.0);
    Vertices[10] = _vertex3f(0.5, 1.2, 0.0);
    Vertices[11] = _vertex3f(0.3, 1.4, 0.0);
    Vertices[12] = _vertex3f(0, 1.4, 0);

    this->PintaObjeto(a_i,a_f);
    this->calculaNormales();
}
