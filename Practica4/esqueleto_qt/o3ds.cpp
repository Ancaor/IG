#include "o3ds.h"

O3DS::O3DS()
{

}

void O3DS::drawPoints(){
    unsigned int i;


    glPointSize(4);

    glBegin(GL_POINTS);
    glColor3f(0,1,0);
    for (i=0;i<vertices.size();i++){
      glVertex3fv((GLfloat *) &vertices[i]);
      }
    glEnd();
}
