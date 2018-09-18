#include "vasoinv.h"

VasoInv::VasoInv()
{
    divisiones--;
    tama_perfil = 3;
    Vertices.resize(tama_perfil);

    Vertices[2] = _vertex3f(0, 0.5, 0);
    Vertices[1] = _vertex3f(0.4, 0.5, 0);
    Vertices[0] = _vertex3f(0.7, -0.5, 0);

    this->PintaObjeto(0, 360);
    this->calculaNormales();
}

VasoInv::VasoInv(int d, float a_i, float a_f)
{
    divisiones = d-1;
    tama_perfil = 3;
    Vertices.resize(tama_perfil);

    Vertices[2] = _vertex3f(0, 0.5, 0);
    Vertices[1] = _vertex3f(0.4, 0.5, 0);
    Vertices[0] = _vertex3f(0.7, -0.5, 0);

    this->PintaObjeto(a_i, a_f);
    this->calculaNormales();
}
