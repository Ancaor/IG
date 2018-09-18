#include "pieza_brazo.h"

Pieza_Brazo::Pieza_Brazo()
{

}

void Pieza_Brazo::draw(int modo, float angulo){
    glPushMatrix();
    glRotatef(36.03187907,0,0,1);
        //Bola
        glPushMatrix();
            glTranslatef(0, -3.40, 0);
            switch(modo){
                case 0: esfera.draw_Points(); break;
                case 1: esfera.draw_Lines(); break;
                case 2: esfera.draw_Triangles(); break;
                case 3: esfera.draw_Chess(); break;
            }
        glPopMatrix();

        //Brazo
        glPushMatrix();
            glTranslatef(0,-1.7,0);
            glScalef(0.2,3.4,0.2);
            switch(modo){
                case 0: cilindro.draw_Points(); break;
                case 1: cilindro.draw_Lines(); break;
                case 2: cilindro.draw_Triangles(); break;
                case 3: cilindro.draw_Chess(); break;
            }
        glPopMatrix();

        //Union
        glPushMatrix();
            glTranslatef(0,-1.7,0);
            glRotatef(107.9362419, 0, 0, 1);
            glRotatef(-2*angulo, 0, 0, 1);
            pieza_union.draw(modo);
        glPopMatrix();
    glPopMatrix();

}
