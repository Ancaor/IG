#include "tubo.h"

Tubo::Tubo(int secciones,int angulo)
{
    SECCIONES = secciones;

    vertices.resize(2);
    setPuntosPerfil(vertices.size());
    vertices[0] = _vertex3f(0.5,-0.5,0);
    vertices[1] = _vertex3f(0.5,0.5,0);
    generar_objeto_de_revolucion(angulo);
}
