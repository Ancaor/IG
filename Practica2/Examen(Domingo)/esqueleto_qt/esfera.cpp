#include "esfera.h"

Esfera::Esfera(int secciones,float angulo_inicial, float angulo_final)
{
    SECCIONES = secciones;

    vertices.push_back(_vertex3f(0.0,-0.5,0.0));
    revolucion_por_barrido_z(M_PI);
    setPuntosPerfil(vertices.size());
    vertices[vertices.size()-1] = _vertex3f(0.0,0.5,0.0);
    generar_objeto_de_revolucion(angulo_inicial,angulo_final);

}
