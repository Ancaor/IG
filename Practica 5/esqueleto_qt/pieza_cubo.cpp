#include "pieza_cubo.h"

Pieza_cubo::Pieza_cubo()
{

}

void Pieza_cubo::draw(int modo, float angulo){
    glPushMatrix();
        glRotatef(angulo, 0, 0, 1);
        glPushMatrix();
            glTranslatef(0,0.25,0);
            glScalef(1, 0.5, 1);
            switch(modo){
                case 0: cubo.draw_Points(); break;
                case 1: cubo.draw_Lines(); break;
                case 2: cubo.draw_Triangles(); break;
                case 3: cubo.draw_Chess(); break;
            }
        glPopMatrix();
    glPopMatrix();
}
