#include "partemedia.h"

ParteMedia::ParteMedia()
{

}

void ParteMedia::draw(int tipo, double angle_z){

    // brazito derecho

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-0.35,0.25,0);
    glRotatef(angle_z,0,0,1);
    bpeq.draw(tipo);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.35,0.25,0);
    glRotatef(-angle_z,0,0,1);
    bpeq.draw(tipo);
    glPopMatrix();

/*    // brazito izquierdo
    glPushMatrix();
    glTranslatef(-1,3.375,0);
    glRotatef(angle_z,0,0,1);
    glScalef(0.1,1.767767,0.1);
    switch(tipo){
    case 0: cilindro1.drawPoints(); break;
    case 1: cilindro1.drawLines(); break;
    case 2: cilindro1.drawFill();break;
    case 3: cilindro1.drawAjedrez();break;
    }
    glPopMatrix();
  */  //cout << ((sin((90-angle_z)*(M_PI/180.0)))*3.535534)+0.25;
    //parte central
    glPushMatrix();
   // glTranslatef(0,5-(((sin((90-angle_z)*(M_PI/180.0)))*3.535534))+0.25,0);
    glTranslatef(0,0.25,0);
    cuboWatt.draw(tipo);
    glPopMatrix();

    //palitroque raro

    glPushMatrix();
    glTranslatef(-0.35,-0.875,0);
    glScalef(0.125,2.25,0.125);
    switch(tipo){
    case 0: cubo2.drawPoints(); break;
    case 1: cubo2.drawLines(); break;
    case 2: cubo2.drawFill();break;
    case 3: cubo2.drawAjedrez();break;
    }
    glPopMatrix();

    //parte superior
/*
    glPushMatrix();
    glTranslatef(0,2.75,0);
    psup.draw(tipo);
    glPopMatrix();
*/
}
