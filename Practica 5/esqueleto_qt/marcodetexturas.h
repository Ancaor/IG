#ifndef MARCODETEXTURAS_H
#define MARCODETEXTURAS_H
#include <QImage>
//#include<GL/glut.h>
#include "objeto3d.h"
#include "QString"
#include <iostream>

class MarcoDeTexturas : public Objeto3D
{
    QImage textura;
    float ancho = 1;
    float alto = 1;
    int divisiones_ancho = 1;
    int divisiones_alto = 1;

    bool iluminado = false;
    bool textura_habilitada = false;
public:
    MarcoDeTexturas();
    void cargarTextura(QString path);
    void drawTextura(float *pos_img, int *pos_marco);
    void draw_Triangles_Iluminacion_Flat(float *pos_img, int *pos_marco, Material material);
    void draw_Triangles_Iluminacion_Smooth(float *pos_img, int *pos_marco, Material material);
    void setTablero(float width, float height, int dw, int dh);
    void generaTablero();
    void setTextura(bool check);
};

#endif // MARCODETEXTURAS_H
