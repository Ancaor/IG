#include "peon.h"

Peon::Peon(int secciones,float angulo)
{
    SECCIONES = secciones;

    vertices.resize(13);
    setPuntosPerfil(vertices.size());
    vertices[0] = _vertex3f(0,-1.4,0);
    vertices[1] = _vertex3f(1.0,-1.4,0);
    vertices[2] = _vertex3f(1.0,-1.1,0);
    vertices[3] = _vertex3f(0.5,-0.7,0);
    vertices[4] = _vertex3f(0.4,-0.4,0);
    vertices[5] = _vertex3f(0.4 ,0.5, 0.0);
    vertices[6] = _vertex3f(0.5,0.6, 0.0);
    vertices[7] = _vertex3f(0.3, 0.6, 0.0);
    vertices[8] = _vertex3f(0.5 ,0.8 ,0.0);
    vertices[9] = _vertex3f(0.55, 1.0, 0.0);
    vertices[10] = _vertex3f(0.5, 1.2, 0.0);
    vertices[11] = _vertex3f(0.3, 1.4, 0.0);
    vertices[12] = _vertex3f(0, 1.4, 0.0);

    generar_objeto_de_revolucion(angulo);
}
