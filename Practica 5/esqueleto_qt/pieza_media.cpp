#include "pieza_media.h"

Pieza_Media::Pieza_Media()
{

}

void Pieza_Media::draw(int modo, float velocidad){


    double angulo_piezas = 45.51160159*velocidad;                                   // Angulo de rotacion de los brazos
    double mov = 2.75-sin((180-angulo_piezas - 36.03187907 - 90)*M_PI/180.0)*1.7*2; // movimiento de la pieza_cubo inferior y el cilindro pequeño



    //Cuerpo de la pieza
    glPushMatrix();
        glTranslatef(0,2.625,0);
        glScalef(0.3,5.25,0.3);
        switch(modo){
            case 0: cilindro.draw_Points(); break;
            case 1: cilindro.draw_Lines(); break;
            case 2: cilindro.draw_Triangles(); break;
            case 3: cilindro.draw_Chess(); break;
        }
    glPopMatrix();

    //Pieza cubo inferior
    glPushMatrix();
        glTranslatef(0,2.25+mov,0);
        pieza_cubo.draw(modo, 0);
    glPopMatrix();

    //Cilindro de la pieza inferior
    glPushMatrix();
        glTranslatef(-0.3,1.25+mov,0);
        glScalef(0.1,2.5,0.1);
        switch(modo){
            case 0: cilindro.draw_Points(); break;
            case 1: cilindro.draw_Lines(); break;
            case 2: cilindro.draw_Triangles(); break;
            case 3: cilindro.draw_Chess(); break;
        }
    glPopMatrix();

    //Pieza cubo superior
    glPushMatrix();
        glTranslatef(0,5,0);
        pieza_cubo.draw(modo, 0);
    glPopMatrix();

}
