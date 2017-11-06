#include "brazo.h"

Brazo::Brazo()
{

}

void Brazo::draw(int tipo){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,-3.535534/2,0);
    glScalef(0.2,3.535534,0.2);

    switch(tipo){
    case 0: cilindro.drawPoints(); break;
    case 1: cilindro.drawLines(); break;
    case 2: cilindro.drawFill();break;
    case 3: cilindro.drawAjedrez();break;
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-3.535534,0);

    switch(tipo){
    case 0: esfera.drawPoints(); break;
    case 1: esfera.drawLines(); break;
    case 2: esfera.drawFill();break;
    case 3: esfera.drawAjedrez();break;
    }
    glPopMatrix();
}
