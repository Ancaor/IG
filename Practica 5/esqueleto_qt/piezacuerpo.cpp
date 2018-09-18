#include "piezacuerpo.h"

PiezaCuerpo::PiezaCuerpo()
{

}

void PiezaCuerpo::draw(int modo){
    glPushMatrix();
    glTranslatef(0,5,0);
    pieza1.draw(modo);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.5,0);
    glScalef(0.3,5,0.3);
    switch(modo){
        case 0: cilindro.draw_Points(); break;
        case 1: cilindro.draw_Lines(); break;
        case 2: cilindro.draw_Triangles(); break;
        case 3: cilindro.draw_Chess(); break;
    }
    glPopMatrix();
}
