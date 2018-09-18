#include "luz.h"

Luz::Luz()
{

}

Luz::Luz(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    posicion[0] = x;
    posicion[1] = y;
    posicion[2] = z;
    posicion[3] = w;

}

void Luz::setTransformaciones(float x, float y, float z)
{
    angulo_rotacion_x = x;
    angulo_rotacion_y = y;
    if(posicion[3]==1)
        radio_z = z;
}

void Luz::mover_luz()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(angulo_rotacion_x, 1, 0, 0);
        glRotatef(angulo_rotacion_y, 0, 1, 0);
        glTranslatef(0,0,radio_z);
        if(posicion[3] == 1)
            glLightfv(GL_LIGHT0, GL_POSITION, posicion);
        else
            glLightfv(GL_LIGHT1, GL_POSITION, posicion);
    glPopMatrix();
}

void Luz::enable_luz()
{
    if(posicion[3] == 1)
        glEnable(GL_LIGHT0);
    else
        glEnable(GL_LIGHT1);
}

void Luz::disable_luz()
{
    if(posicion[3] == 1)
        glDisable(GL_LIGHT0);
    else
        glDisable(GL_LIGHT1);

}
