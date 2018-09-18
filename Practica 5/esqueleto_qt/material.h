#ifndef MATERIAL_H
#define MATERIAL_H
#include <QOpenGLShaderProgram>
#include <iostream>

class Material
{
    GLfloat material_ambiente[4];
    GLfloat material_difuso[4];
    GLfloat material_especular[4];
    GLfloat brillo;
    bool habilitado = false;
public:
    Material();
    Material(GLfloat *mat);

    GLfloat* getAmb();
    GLfloat* getDif();
    GLfloat* getEsp();
    GLfloat getShine();

    void enable_material();

};

#endif // MATERIAL_H
