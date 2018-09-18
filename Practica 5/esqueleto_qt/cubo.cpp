#include "cubo.h"

Cubo::Cubo()
{
    //Puntos

    Vertices.resize(8);
    Vertices[0]=_vertex3f(-0.5,0.5,0.5);
    Vertices[1]=_vertex3f(0.5,0.5,0.5);
    Vertices[2]=_vertex3f(0.5,-0.5,0.5);
    Vertices[3]=_vertex3f(-0.5,-0.5,0.5);
    Vertices[4]=_vertex3f(0.5,0.5,-0.5);
    Vertices[5]=_vertex3f(0.5,-0.5,-0.5);
    Vertices[6]=_vertex3f(-0.5,0.5,-0.5);
    Vertices[7]=_vertex3f(-0.5,-0.5,-0.5);

    //Caras

    Superficie.resize(12);
    Superficie[0] = _vertex3i(1,0,2);
    Superficie[1] = _vertex3i(2,0,3);
    Superficie[2] = _vertex3i(4,1,5);
    Superficie[3] = _vertex3i(5,1,2);
    Superficie[4] = _vertex3i(6,4,7);
    Superficie[5] = _vertex3i(7,4,5);
    Superficie[6] = _vertex3i(0,6,7);
    Superficie[7] = _vertex3i(3,0,7);
    Superficie[8] = _vertex3i(4,0,1);
    Superficie[9] = _vertex3i(6,0,4);
    Superficie[10] = _vertex3i(5,3,7);
    Superficie[11] = _vertex3i(2,3,5);

    //Normales

    this->calculaNormales();


}
