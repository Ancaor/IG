#include "watt.h"

Watt::Watt()
{

}

void Watt::draw(int modo, float angulo, float velocidad){

    double angulo_piezas = 0;

    angulo_piezas = 45.51160159*velocidad;

    // Base del Watt
    glPushMatrix();
        glTranslatef(0,0.125,0);
        glScalef(3.5,0.25,3.5);
        switch(modo){
            case 0: cubo.draw_Points(); break;
            case 1: cubo.draw_Lines(); break;
            case 2: cubo.draw_Triangles(); break;
            case 3: cubo.draw_Chess(); break;
        }
    glPopMatrix();

    //Parte que rota
    glPushMatrix();
        glRotatef(angulo, 0, 1, 0);

        // Cuerpo del Watt

        glPushMatrix();
            glTranslatef(0, 0.25, 0);
            pieza_media.draw(modo, velocidad);
        glPopMatrix();


        //Brazo derecho
        glPushMatrix();
            glTranslatef(0.3, 5.5, 0);
            glRotatef(angulo_piezas, 0, 0, 1);
            pieza_brazo.draw(modo, angulo_piezas);
        glPopMatrix();

        //Brazo izquierdo
        glPushMatrix();
            glTranslatef(-0.3, 5.5, 0);
            glRotatef(180, 0, 1, 0);
            glRotatef(angulo_piezas, 0, 0, 1);
            pieza_brazo.draw(modo, angulo_piezas);
        glPopMatrix();

    glPopMatrix();
    this->calculaNormales();
}
