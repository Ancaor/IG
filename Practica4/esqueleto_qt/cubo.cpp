#include "cubo.h"

Cubo::Cubo()
{
    vertices.resize(8);
    vertices[0] = _vertex3f(-0.5,-0.5,0.5);
    vertices[1] = _vertex3f(0.5,-0.5,0.5);
    vertices[2] = _vertex3f(-0.5,0.5,0.5);
    vertices[3] = _vertex3f(0.5,0.5,0.5);
    vertices[4] = _vertex3f(-0.5,-0.5,-0.5);
    vertices[5] = _vertex3f(0.5,-0.5,-0.5);
    vertices[6] = _vertex3f(-0.5,0.5,-0.5);
    vertices[7] = _vertex3f(0.5,0.5,-0.5);

    triangles.resize(12);
    triangles[0] = _vertex3i(0,1,3);
    triangles[1] = _vertex3i(0,3,2);
    triangles[2] = _vertex3i(4,2,6);
    triangles[3] = _vertex3i(4,0,2);
    triangles[4] = _vertex3i(2,7,6);
    triangles[5] = _vertex3i(2,3,7);
    triangles[6] = _vertex3i(1,7,3);
    triangles[7] = _vertex3i(1,5,7);
    triangles[8] = _vertex3i(4,1,0);
    triangles[9] = _vertex3i(4,5,1);
    triangles[10] = _vertex3i(5,6,7);
    triangles[11] = _vertex3i(5,4,6);

    calcularNormalesCaras();
    calcularNormalesVertices();
}
