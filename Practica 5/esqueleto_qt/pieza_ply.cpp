#include "pieza_ply.h"

Pieza_PLY::Pieza_PLY()
{
    piezaPLY.ReadPLY("beethoven.ply");
}

void Pieza_PLY::draw(int modo){

    glPushMatrix();
        glTranslatef(0, 6.03088, 0);
        glScalef(1,1,1);
        switch(modo){
            case 0: piezaPLY.draw_Points(); break;
            case 1: piezaPLY.draw_Lines(); break;
            case 2: piezaPLY.draw_Triangles(); break;
            case 3: piezaPLY.draw_Chess(); break;
        }

    glPopMatrix();
}
