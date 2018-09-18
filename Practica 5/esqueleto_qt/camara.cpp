#include "camara.h"

Camara::Camara()
{
    Observer_angle_x = 0;
    Observer_angle_y = 0;
    Observer_distance = 10;
    tipo_proyeccion = 0;

    cambio_objetivo = false;
    VPN[0] = 0;
    VPN[1] = 0;
    VPN[2] = 0;
}

Camara::Camara(float x, float y, float d, int p)
{
    Observer_angle_x = x;
    Observer_angle_y = y;
    Observer_distance = d;
    tipo_proyeccion = p;
}


//**************************************************************************
// Funcion para mover la cámara de posición
//***************************************************************************

void Camara::moverCamara()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-Observer_distance);
    glRotatef(Observer_angle_x,1,0,0);
    glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion para ajustar los parámetros de la posicion de la cámara
//***************************************************************************

void Camara::setPosicion(float x, float y, float d)
{
    Observer_angle_x = x;
    Observer_angle_y = y;
    Observer_distance = d;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Camara::CambiarProyeccion(float relacion_aspecto)
{

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if(tipo_proyeccion == 0)
            glFrustum(X_MIN*relacion_aspecto,X_MAX*relacion_aspecto,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
        else
            glOrtho(X_MIN*Observer_distance*relacion_aspecto, X_MAX*Observer_distance*relacion_aspecto, Y_MIN*Observer_distance, Y_MAX*Observer_distance, FRONT_PLANE_PERSPECTIVE, BACK_PLANE_PERSPECTIVE);

}

//**************************************************************************
// Funcion para obtener el angulo X de la cámara
//***************************************************************************

float Camara::getObserverAngle_X()
{
    return Observer_angle_x;
}


//**************************************************************************
// Funcion para obtener el angulo Y de la cámara
//***************************************************************************
float Camara::getObserverAngle_Y()
{
    return Observer_angle_y;
}

//**************************************************************************
// Funcion para obtener la distancia respecto al origen
//***************************************************************************

float Camara::getObserverDistance()
{
    return Observer_distance;
}

void Camara::cambiarObjetivo(float x, float y, float z)
{
    VPN[0] = x;
    VPN[1] = y;
    VPN[2] = z;
}

void Camara::setValoresProyeccion(float VPN_x, float VPN_y)
{
    X_MIN += VPN_x;
    X_MAX += VPN_x;
    Y_MIN += VPN_y;
    Y_MAX += VPN_y;
}

float Camara::getXMIN()
{
    return X_MIN;
}

float Camara::getXMAX()
{
    return X_MAX;
}

float Camara::getYMIN()
{
    return Y_MIN;
}

float Camara::getYMAX()
{
    return Y_MAX;
}

void Camara::cambiarLookAt()
{
    gluLookAt(VPN[0],VPN[1],VPN[2],VPN[0],VPN[1],VPN[2]-1,0,1,0);
}
