#ifndef MATERIAL_H
#define MATERIAL_H

#include"GL/glew.h"

class Material
{
private:
    float shininess;
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];

public:
    Material();
    Material(GLfloat amb[], GLfloat diff[], GLfloat spec[], float shini);
    void enable();
};

#endif // MATERIAL_H
