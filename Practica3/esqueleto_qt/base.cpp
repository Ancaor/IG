#include "base.h"

Base::Base()
{
   // cilindro = Cilindro(40);
}

void Base::draw(int tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.125,0);
    glScalef(3.5,0.25,3.5);

    switch(tipo){
    case 0: cubo1.drawPoints(); break;
    case 1: cubo1.drawLines(); break;
    case 2: cubo1.drawFill();break;
    case 3: cubo1.drawAjedrez();break;
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.75,0);
    glScalef(0.5,5,0.5);

    switch(tipo){
    case 0: cilindro1.drawPoints(); break;
    case 1: cilindro1.drawLines(); break;
    case 2: cilindro1.drawFill();break;
    case 3: cilindro1.drawAjedrez();break;
    }
    glPopMatrix();

    glPushMatrix();
    pmed.draw(tipo);
    glPopMatrix();
}
