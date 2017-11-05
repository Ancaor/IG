#include "partesuperior.h"

ParteSuperior::ParteSuperior()
{

}

void ParteSuperior::draw(int tipo){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1.625,0,0);
    glRotatef(180,0,1,0);
    brazo1.draw(tipo);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.625,0,0);
    brazo2.draw(tipo);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.5,0);
    glScalef(1,0.5,0.5);
    switch(tipo){
    case 0: cubo.drawPoints(); break;
    case 1: cubo.drawLines(); break;
    case 2: cubo.drawFill();break;
    case 3: cubo.drawAjedrez();break;
    }
    glPopMatrix();

}
