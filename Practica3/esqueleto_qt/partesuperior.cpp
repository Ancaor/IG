#include "partesuperior.h"

ParteSuperior::ParteSuperior()
{

}

void ParteSuperior::draw(int tipo,double angle_z){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.375,0,0);
    //glRotatef(-angle_z,0,0,1);
    brazo.draw(tipo,angle_z);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.375,0,0);
    glRotatef(180,0,1,0);
    brazo.draw(tipo,angle_z);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.5,0);
    cuboWatt.draw(tipo);
    glPopMatrix();

    glTranslatef(0,2.5-(((sin((90-angle_z)*(M_PI/180.0)))*3.535534)),0);
    glPushMatrix();
    cuboWatt.draw(tipo);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.35,-1.125,0);
    glScalef(0.08,2.25,0.1);
    switch(tipo){
    case 0: cubo.drawPoints(); break;
    case 1: cubo.drawLines(); break;
    case 2: cubo.drawFill();break;
    case 3: cubo.drawAjedrez();break;
    }
    glPopMatrix();

}
