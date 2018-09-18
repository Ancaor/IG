#include "tubo.h"

Tubo::Tubo()
{
    //Puntos
    divisiones--;
    tama_perfil = 2;
    Vertices.resize(tama_perfil);

    Vertices[0]=_vertex3f(0.5,-0.5,0);
    Vertices[1]=_vertex3f(0.5,0.5,0);

    this->PintaObjeto(0, 360);
    this->calculaNormales();
}

Tubo::Tubo(int d, float a_i, float a_f)
{
    //Puntos
    divisiones = d-1;
    tama_perfil = 2;
    Vertices.resize(tama_perfil);

    Vertices[0]=_vertex3f(0.5,-0.5,0);
    Vertices[1]=_vertex3f(0.5,0.5,0);

    this->PintaObjeto(a_i, a_f);
    this->calculaNormales();
}

