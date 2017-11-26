#include "cubowatt.h"

CuboWatt::CuboWatt()
{

}

void CuboWatt::draw(int tipo)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,0.5,0.5);
    switch(tipo){
    case 0: cubo.drawPoints(); break;
    case 1: cubo.drawLines(); break;
    case 2: cubo.drawFill();break;
    case 3: cubo.drawAjedrez();break;
    }
    glPopMatrix();
}
