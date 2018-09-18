#ifndef O3DS_H
#define O3DS_H
#include "glwidget.h"

class O3DS
{
  public:
    std::vector<_vertex3f> Vertices;
    _vertex4f color_vertices;

    O3DS();
    void draw_Points();
};

#endif // O3DS_H
