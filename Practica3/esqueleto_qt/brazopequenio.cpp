#include "brazopequenio.h"

BrazoPequenio::BrazoPequenio()
{

}

void BrazoPequenio::draw(int tipo)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.767767/2,0);
   // glRotatef(angle_z,0,0,1);
    glScalef(0.1,1.767767,0.1);
    switch(tipo){
    case 0: cilindro.drawPoints(); break;
    case 1: cilindro.drawLines(); break;
    case 2: cilindro.drawFill();break;
    case 3: cilindro.drawAjedrez();break;
    }
    glPopMatrix();
}
