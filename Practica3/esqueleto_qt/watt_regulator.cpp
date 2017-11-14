#include "watt_regulator.h"

WattRegulator::WattRegulator()
{

}

void WattRegulator::draw(int tipo,double angle_y, double velocidad ){

    calcular_angulo_z(velocidad);

    /*Base*/

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

    /*Mastil*/

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

    /*Parte Superior*/

    glPushMatrix();
    glTranslatef(0,2.75,0);
    glRotatef(angle_y,0,1,0);
    psup.draw(tipo,angle_z);
    glPopMatrix();

}


/*
 * Calcula el angulo que formaran los brazos con el mastil en funcion de la velocidad.
 * Hasta que la velocidad no sea >= 50, los brazos no comenzaran a subir.
 *
 *
 * Para quitar topes de angulos, comentar todas las lineas menos la ultima asignacion de angle_z = Z_MIN+(((Z_MAX- ...
 * Tambien sera necesario comentar los if(velociad-1 <= 0) e if(velocidad+1 >=100) que se encuentran en las lineas
 * 42 y 75 de glwidget.cc para eliminar el tope de velocidad de la variable velocidad.
*/

void WattRegulator::calcular_angulo_z(double velocidad)
{
    if(velocidad <= 50.0)
        angle_z=Z_MIN;
    else{
        if(velocidad >= 100)
            angle_z=Z_MAX;
        else
        angle_z = Z_MIN+(((Z_MAX-Z_MIN)/50.0)*(velocidad-50));   // linea que NO se debe comentar para quitar topes.
    }
}
