#include "brazo.h"

Brazo::Brazo()
{

}

void Brazo::draw(int tipo,double angle_z){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,2.5,0);
    glRotatef(angle_z,0,0,1);
    brazog.draw(tipo);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.5-(((sin((90-angle_z)*(M_PI/180.0)))*3.535534)),0);
    glRotatef(-angle_z,0,0,1);
    bpeq.draw(tipo);
    glPopMatrix();
}
