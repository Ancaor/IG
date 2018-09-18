#ifndef CAMARA_H
#define CAMARA_H
#include <GL/glut.h>

class Camara
{
    float Observer_distance;
    float Observer_angle_x;
    float Observer_angle_y;
    int tipo_proyeccion;        // perspectiva = 0. Ortogonal = 1.

    bool cambio_objetivo;
    float VPN[3];

    float X_MIN=-0.3;
    float X_MAX=0.3;
    float Y_MIN=-0.3;
    float Y_MAX=0.3;
    float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
    float BACK_PLANE_PERSPECTIVE=1000;

public:
    Camara();
    Camara(float x, float y, float d, int p);
    void moverCamara();
    void setPosicion(float x, float y, float d);
    void CambiarProyeccion(float relacion_aspecto);
    float getObserverAngle_X();
    float getObserverAngle_Y();
    float getObserverDistance();
    void cambiarObjetivo(float x, float y, float z);
    void setValoresProyeccion(float VPN_x, float VPN_y);
    float getXMIN();
    float getXMAX();
    float getYMIN();
    float getYMAX();
    void cambiarLookAt();


};

#endif // CAMARA_H
