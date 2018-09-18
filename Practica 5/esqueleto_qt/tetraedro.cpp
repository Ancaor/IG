#include "tetraedro.h"

Tetraedro::Tetraedro()
{
    //Puntos

    Vertices.resize(4);
    Vertices[0]=_vertex3f(-0.5,-0.5,0.5);
    Vertices[1]=_vertex3f(0.5,-0.5,0.5);
    Vertices[2]=_vertex3f(0,-0.5,-0.5);
    Vertices[3]=_vertex3f(0,0.5,0);

    //Caras

    Superficie.resize(4);
    Superficie[0] = _vertex3i(1,0,2);
    Superficie[1] = _vertex3i(3,0,1);
    Superficie[2] = _vertex3i(3,1,2);
    Superficie[3] = _vertex3i(3,2,0);

    //Normales

    this->calculaNormales();

}
