#include "cilindro.h"

Cilindro::Cilindro()
{
    divisiones--;
    tama_perfil = 4;
    Vertices.resize(tama_perfil);

    Vertices[0]=_vertex3f(0,-0.5,0);
    Vertices[1]=_vertex3f(0.5,-0.5,0);
    Vertices[2]=_vertex3f(0.5,0.5,0);
    Vertices[3]=_vertex3f(0,0.5,0);

    this->PintaObjeto(0,360);
    this->calculaNormales();

}

Cilindro::Cilindro(int d, float a_i, float a_f)
{
    divisiones = d -1;
    tama_perfil = 4;
    Vertices.resize(tama_perfil);

    Vertices[0]=_vertex3f(0,-0.5,0);
    Vertices[1]=_vertex3f(0.5,-0.5,0);
    Vertices[2]=_vertex3f(0.5,0.5,0);
    Vertices[3]=_vertex3f(0,0.5,0);

    this->PintaObjeto(a_i, a_f);
    this->calculaNormales();

}

