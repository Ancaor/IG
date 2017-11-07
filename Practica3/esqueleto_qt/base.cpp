#include "base.h"

Base::Base()
{
   // cilindro = Cilindro(40);
}

void Base::draw(int tipo,double angle_y, double velocidad ){

    calcular_angulo_z(velocidad);

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
    glRotatef(angle_y,0,1,0);
    glScalef(0.4,5,0.4);

    switch(tipo){
    case 0: cilindro1.drawPoints(); break;
    case 1: cilindro1.drawLines(); break;
    case 2: cilindro1.drawFill();break;
    case 3: cilindro1.drawAjedrez();break;
    }
    glPopMatrix();
/*
    glPushMatrix();
    glTranslatef(0,5-(((sin((90-angle_z)*(M_PI/180.0)))*3.535534)),0);
    glRotatef(angle_y,0,1,0);
    pmed.draw(tipo,angle_z);
    glPopMatrix();
*/
    glPushMatrix();
    glTranslatef(0,2.75,0);
    glRotatef(angle_y,0,1,0);
    psup.draw(tipo,angle_z);
    glPopMatrix();

}

void Base::calcular_angulo_z(double velocidad)
{
    if(velocidad <= 50.0)
        angle_z=Z_MIN;
    else{
        if(velocidad >= 100)
            angle_z=Z_MAX;
        else
        angle_z = Z_MIN+(((Z_MAX-Z_MIN)/50.0)*(velocidad-50));
    }
}
