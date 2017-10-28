#include "cilindro.h"

Cilindro::Cilindro(int secciones)
{
    SECCIONES = secciones;
    vertices.resize(4);
    setPuntosPerfil(vertices.size());
    vertices[0] = _vertex3f(0,-0.5,0);
    vertices[1] = _vertex3f(0.5,-0.5,0);
    vertices[2] = _vertex3f(0.5,0.5,0);
    vertices[3] = _vertex3f(0,0.5,0);
    generar_objeto_de_revolucion();
}
