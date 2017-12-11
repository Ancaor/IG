#include "esfera_beethoven.h"


/*
 * En el constructor se carga el PLY, para ello aparecerá por pantalla el selector de PLY grafico.
 */

esfera_beethoven::esfera_beethoven(string path)
{
    if(!path.empty())
    ply_object.read_ply(path);
}

void esfera_beethoven::draw(int tipo)
{


    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.8,0,0);
    glRotatef(-90,0,0,1);
    glScalef(0.05,0.05,0.05);
    switch(tipo){
    case 0: ply_object.drawPoints(); break;
    case 1: ply_object.drawLines(); break;
    case 2: ply_object.drawFill();break;
    case 3: ply_object.drawAjedrez();break;
    }
    glPopMatrix();

    glPushMatrix();
    switch(tipo){
    case 0: esfera.drawPoints(); break;
    case 1: esfera.drawLines(); break;
    case 2: esfera.drawFill();break;
    case 3: esfera.drawAjedrez();break;
    }
    glPopMatrix();
}
