#include "o3ds.h"
#include "glwidget.h"

O3DS::O3DS()
{
color_vertices = _vertex4f(0,1,0,1);
}


//*************************************************************************
// Dibuja los puntos del objeto
//*************************************************************************

void O3DS::draw_Points()
{

    glColor3f(color_vertices.x,color_vertices.y,color_vertices.z);
    glPointSize(4);

    glBegin(GL_POINTS);
    for (unsigned int i=0;i<Vertices.size();i++){
      glVertex3fv((GLfloat *) &Vertices[i]);
    }
    glEnd();
}
