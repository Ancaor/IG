#include "brazogrande.h"

BrazoGrande::BrazoGrande()
{

}

void BrazoGrande::draw(int tipo)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,-3.535534/2,0);
    glScalef(0.2,3.535534,0.2);

    switch(tipo){
    case 0: cilindro.drawPoints(); break;
    case 1: cilindro.drawLines(); break;
    case 2: cilindro.drawFill();break;
    case 3: cilindro.drawAjedrez();break;
    }
    glPopMatrix();

    /*
     * Originalmente se instanciaba una esfera y se trasladaba, pero para
     * añadir el Beethoven más facilmente creé una clase que pintara una esfera con el
     * Beethoven bien colocado en ella
     */


    glPushMatrix();
    glTranslatef(0,-3.535534,0);
    es_beeth.draw(tipo);
    glPopMatrix();

}
