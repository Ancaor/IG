#include "partesuperior.h"

ParteSuperior::ParteSuperior()
{

}

void ParteSuperior::draw(int tipo,double angle_z){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-0.375,0.25,0);
    glRotatef(-angle_z,0,0,1);
    brazo.draw(tipo);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.375,0.25,0);
    glRotatef(angle_z,0,0,1);
    brazo.draw(tipo);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.25,0);
    cuboWatt.draw(tipo);
    glPopMatrix();

}
