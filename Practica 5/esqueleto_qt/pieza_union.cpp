#include "pieza_union.h"

Pieza_union::Pieza_union()
{
}

void Pieza_union::draw(int modo){

    glPushMatrix();
        glTranslatef(0, 0.85, 0);
        glScalef(0.1,1.7,0.1);
        switch(modo){
            case 0: cilindro.draw_Points(); break;
            case 1: cilindro.draw_Lines(); break;
            case 2: cilindro.draw_Triangles(); break;
            case 3: cilindro.draw_Chess(); break;
        }

    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.05, 0.85, 0);
        glRotatef(-90,0,0,1);
        glScalef(0.05,0.05,0.05);
        piezaPLY.draw(modo);
    glPopMatrix();
}
