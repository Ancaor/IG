#include "base.h"

Base::Base()
{
   // cilindro = Cilindro(40);
}

void Base::draw(int tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(20,2,20);

    switch(tipo){
    case 0: cilindro.drawPoints(); break;
    case 1: cilindro.drawLines(); break;
    case 2: cilindro.drawFill();break;
    case 3: cilindro.drawAjedrez();break;
    }
    glPopMatrix();
}
