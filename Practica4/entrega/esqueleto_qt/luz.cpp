#include "luz.h"
#include <string>
#include <iostream>

Luz::Luz()
{

}

Luz::Luz(float x, float y, float z, float w )
{

    posicion[0]=x;
    posicion[1]=y;
    posicion[2]=z;
    posicion[3]=w;

}

void Luz::transformar(float alfa, float beta, float distancia)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(alfa,0,1,0);
    glRotatef(beta,1,0,0);

    if(posicion[3] == 1.0){
        glTranslatef(0,0,distancia);
        glLightfv(GL_LIGHT0, GL_POSITION, posicion);
    }
    else{
        glLightfv(GL_LIGHT1, GL_POSITION, posicion);
    }

    glPopMatrix();
}

void Luz::enable()
{
  if(posicion[3] == 1)
      glEnable(GL_LIGHT0);
  else
      glEnable(GL_LIGHT1);
}

void Luz::disable()
{
    if(posicion[3] == 1)
        glDisable(GL_LIGHT0);
    else
        glDisable(GL_LIGHT1);
}
