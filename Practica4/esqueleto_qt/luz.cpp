#include "luz.h"

Luz::Luz()
{

}

Luz::Luz(int w)
{
    posicion[0]=0.0;
    posicion[1]=0.0;

    if(w == 0)
        posicion[2]=1.0;
    else
        posicion[2]=0.0;

    posicion[3]=w;
}

void Luz::transformar(float alfa, float beta, float distancia)
{
    this->alfa=alfa;
    this->beta=beta;
    this->distancia=distancia;
}

void Luz::enable()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(alfa,0,1,0);
    glRotatef(beta,1,0,0);
    if(posicion[3] == 1)
    glTranslatef(0,0,distancia);
    glLightfv(GL_LIGHT0, GL_POSITION, posicion);
    glPopMatrix();
    glEnable(GL_LIGHT0);
}

void Luz::disable()
{
    glDisable(GL_LIGHT0);
}
