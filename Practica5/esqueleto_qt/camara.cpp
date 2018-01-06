#include "camara.h"

Camara::Camara()
{

}

Camara::Camara(float x_min, float x_max, float y_min, float y_max, float back_plane_perspective, float default_distance, float angle_step, bool tipo)
{
    X_MIN=x_min;
    X_MAX=x_max;
    Y_MIN=y_min;
    Y_MAX=y_max;
    FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
    BACK_PLANE_PERSPECTIVE=back_plane_perspective;
    DEFAULT_DISTANCE=default_distance;
    ANGLE_STEP=angle_step;
    this->tipo = tipo;
    observer_angle_x=0;
    observer_angle_y=0;
    observer_distance=DEFAULT_DISTANCE;
}

void Camara::setX_MIN(float x_min)
{
    X_MIN = x_min;
}

void Camara::setX_MAX(float x_max)
{
    X_MAX=x_max;
}

void Camara::setY_MIN(float y_min)
{
    Y_MIN=y_min;
}

void Camara::setY_MAX(float y_max)
{
    Y_MAX=y_max;
}

void Camara::setTipo(bool tipo)
{
    this->tipo = tipo;
}

void Camara::setANGLE_STEP(float angle_step)
{
    ANGLE_STEP = angle_step;
}

void Camara::setRelacion_de_aspecto(float relacion_de_aspecto)
{
    this->relacion_de_aspecto = relacion_de_aspecto;
}

void Camara::setObserver_angle_x(float x)
{
    observer_angle_x=x;
}

void Camara::setObserver_angle_y(float y)
{
    observer_angle_y=y;
}

void Camara::setObserver_distance(float d)
{
    observer_distance = d;
}

void Camara::change_projection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(tipo==1)
        glFrustum(X_MIN*relacion_de_aspecto,X_MAX*relacion_de_aspecto,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
    else
        glOrtho((X_MIN-(observer_distance/2))*relacion_de_aspecto,(X_MAX+(observer_distance/2))*relacion_de_aspecto,Y_MIN-(observer_distance/2),Y_MAX+(observer_distance/2),FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}

void Camara::change_observer()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-observer_distance); //
    glRotatef(observer_angle_x,1,0,0);    //
    glRotatef(observer_angle_y,0,1,0);    //
}

void Camara::setModoProyeccion(bool modo)
{
    tipo = modo;
}

void Camara::changeVPN(float vpn1, float vpn2, float vpn3)
{
    VPN[0] = vpn1;
    VPN[1] = vpn2;
    VPN[2] = vpn3;
}

float *Camara::getVPN(){
    return VPN;
}

bool Camara::getTipo()
{
    return tipo;
}


void Camara::changeLookAt()
{
    gluLookAt(VPN[0],VPN[1],VPN[2],VPN[0],VPN[1],VPN[2]-1,0,1,0);
}
