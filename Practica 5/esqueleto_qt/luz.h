#ifndef LUZ_H
#define LUZ_H
#include <QOpenGLShaderProgram>

class Luz
{
    GLfloat posicion[4];
    float angulo_rotacion_x = 0;
    float angulo_rotacion_y = 0;
    float radio_z = 0;
public:
    Luz();
    Luz(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void setTransformaciones(float x, float y, float z);
    void mover_luz();
    void enable_luz();
    void disable_luz();
};

#endif // LUZ_H
