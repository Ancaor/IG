#ifndef O3D_H
#define O3D_H

#include "o3ds.h"

class O3D : public O3DS
{
public:
    std::vector<_vertex3i> triangles;

    O3D();
    void drawLines();
    void drawFill();
    void drawAjedrez();
};

#endif // O3D_H
