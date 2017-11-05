#include "partemedia.h"

ParteMedia::ParteMedia()
{

}

void ParteMedia::draw(int tipo){

    // brazito derecho

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,3.375,0);
    glRotatef(-45,0,0,1);
    glScalef(0.1,1.767767,0.1);
    switch(tipo){
    case 0: cilindro1.drawPoints(); break;
    case 1: cilindro1.drawLines(); break;
    case 2: cilindro1.drawFill();break;
    case 3: cilindro1.drawAjedrez();break;
    }

    glPopMatrix();

    // brazito izquierdo
    glPushMatrix();
    glTranslatef(-1,3.375,0);
    glRotatef(45,0,0,1);
    glScalef(0.1,1.767767,0.1);
    switch(tipo){
    case 0: cilindro1.drawPoints(); break;
    case 1: cilindro1.drawLines(); break;
    case 2: cilindro1.drawFill();break;
    case 3: cilindro1.drawAjedrez();break;
    }
    glPopMatrix();

    //parte central

    glPushMatrix();
    glTranslatef(0,2.75,0);
    glScalef(1,0.5,0.5);
    switch(tipo){
    case 0: cubo.drawPoints(); break;
    case 1: cubo.drawLines(); break;
    case 2: cubo.drawFill();break;
    case 3: cubo.drawAjedrez();break;
    }
    glPopMatrix();

    //palitroque raro

    glPushMatrix();
    glTranslatef(-0.35,1.625,0);
    glScalef(0.125,2.25,0.125);
    switch(tipo){
    case 0: cubo2.drawPoints(); break;
    case 1: cubo2.drawLines(); break;
    case 2: cubo2.drawFill();break;
    case 3: cubo2.drawAjedrez();break;
    }
    glPopMatrix();

    //parte superior

    glPushMatrix();
    glTranslatef(0,2.75,0);
    psup.draw(tipo);
    glPopMatrix();
}
