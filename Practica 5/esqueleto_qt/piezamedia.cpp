#include "piezamedia.h"

PiezaMedia::PiezaMedia()
{

}

void PiezaMedia::draw(int modo){
    glPushMatrix();
    glTranslatef(0,2.75,0);
    pieza1.draw(modo);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.25,0);
    glScalef(1,0.5,1);
    switch(modo){
        case 0: cubo.draw_Points(); break;
        case 1: cubo.draw_Lines(); break;
        case 2: cubo.draw_Triangles(); break;
        case 3: cubo.draw_Chess(); break;
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.85,0.85,0);
    glRotatef(-36.03187907, 0, 0, 1);
    glScalef(0.15,1.7,0.15);
    switch(modo){
        case 0: cilindro.draw_Points(); break;
        case 1: cilindro.draw_Lines(); break;
        case 2: cilindro.draw_Triangles(); break;
        case 3: cilindro.draw_Chess(); break;
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.85,0.85,0);
    glRotatef(36.03187907, 0, 0, 1);
    glScalef(0.15,1.7,0.15);
    switch(modo){
        case 0: cilindro.draw_Points(); break;
        case 1: cilindro.draw_Lines(); break;
        case 2: cilindro.draw_Triangles(); break;
        case 3: cilindro.draw_Chess(); break;
    }
    glPopMatrix();
}
