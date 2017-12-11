#include "material.h"

Material::Material(){

}


Material::Material(GLfloat amb[], GLfloat diff[], GLfloat spec[], float shini)
{
    shininess = shini;

    for(int i=0; i<4; i++){
        ambient[i]=amb[i];
        diffuse[i]=diff[i];
        specular[i]=spec[i];
    }

}

void Material::enable()
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}
