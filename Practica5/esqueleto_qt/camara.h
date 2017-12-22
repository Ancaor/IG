#ifndef CAMARA_H
#define CAMARA_H

#include <GL/glew.h>

class Camara
{
private:
     float X_MIN=-0.5;
     float X_MAX=0.5;
     float Y_MIN=-0.5;
     float Y_MAX=0.5;
     float observer_angle_x;
     float observer_angle_y;
     float observer_distance;
     float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
     float BACK_PLANE_PERSPECTIVE=1000;
     float DEFAULT_DISTANCE=10;
     float ANGLE_STEP=1.5;
     float relacion_de_aspecto;
     float VPN[3] = {0,0,0};




     bool tipo =0;  // 0 == Perspectiva , 1 == Ortogonal
public:
    Camara();
    Camara(float x_min, float x_max, float y_min, float y_max, float back_plane_perspective, float default_distance, float angle_step, bool tipo);
    void setX_MIN(float x_min);
    void setX_MAX(float x_max);
    void setY_MIN(float y_min);
    void setY_MAX(float y_max);
    void setTipo(bool tipo);
    void setANGLE_STEP(float angle_step);
    void setRelacion_de_aspecto(float relacion_de_aspecto);
    void setObserver_angle_x(float x);
    void setObserver_angle_y(float y);
    void setObserver_distance(float d);
    void change_projection();
    void change_observer();
    void setModoProyeccion(bool modo);
    void changeVPN(float vpn1, float vpn2, float vpn3);
    void changeLookAt();
    float zoom_orto=0;
    float* getVPN();
};

#endif // CAMARA_H
