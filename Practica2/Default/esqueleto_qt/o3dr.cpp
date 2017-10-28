#include "o3dr.h"

O3DR::O3DR()
{
    tapa_inferior = 0;
    tapa_superior = 0;
}

/*********************************************************************************
Funcion que ajusta a size la variable PUNTOS_PERFIL
*********************************************************************************/

void O3DR::setPuntosPerfil(int size){
    PUNTOS_PERFIL=size;
}

/*********************************************************************************
Funcion que realiza la revolucion por barrido respecto al eje y.
*********************************************************************************/

void O3DR::revolucion_por_barrido_y(float angulo)
{
    int i,j;
    float alpha;
    int tamanio = vertices.size();

    for(i=1;i <= SECCIONES ; i++){
        alpha = (i*angulo)/SECCIONES; // 2.0*M_PI
        for(j=0;j<tamanio;j++){
            float x_rotado= ((vertices[j].x) * cos(alpha) + (vertices[j].z) * sin(alpha));
            float z_rotado= (-(vertices[j].x)*sin(alpha) + (vertices[j].z)*cos(alpha) );
            _vertex3f rotado = _vertex3f(x_rotado,vertices[j].y,z_rotado);
            vertices.push_back(rotado);
        }
    }

}

/*********************************************************************************
Funcion que realiza la revolucion por barrido respecto aal eje z. Util para generar
la esfera .
*********************************************************************************/

void O3DR::revolucion_por_barrido_z(float angulo)
{
    int i,j;
    float x_rotado;
    float y_rotado;
    float alpha;
    int tamanio = vertices.size();

    for(i = 1;i <= SECCIONES; i++){
        alpha = (i*angulo)/SECCIONES;
        for(j=0;j<tamanio;j++){
            x_rotado= ((vertices[j].x) * cos(alpha) - (vertices[j].y) * sin(alpha));
            y_rotado= ((vertices[j].x)*sin(alpha) + (vertices[j].y)*cos(alpha) );
            _vertex3f rotado = _vertex3f(x_rotado,y_rotado,vertices[j].z);
            vertices.push_back(rotado);
        }
    }
}

/*********************************************************************************
Funcion que genera las caras del cuerpo del objeto, es decir, sin las tapas
*********************************************************************************/
void O3DR::generar_caras()
{
    int i,j;
    int PUNTOS = vertices.size();
    for(i = 0; i < PUNTOS_PERFIL-1 ; i++){
        for(j=0; j < SECCIONES ; j++){
            //Triangulo Par
            triangles.push_back(_vertex3i( ((j*PUNTOS_PERFIL)+(i+1))%PUNTOS ,((j*PUNTOS_PERFIL)+i)%PUNTOS , (((j+1)*PUNTOS_PERFIL)+i )%PUNTOS) );
            //Triangulo Impar
            triangles.push_back(_vertex3i( (((j+1)*PUNTOS_PERFIL)+i)%PUNTOS ,(((j+1)*PUNTOS_PERFIL)+(i+1))%PUNTOS , ((j*PUNTOS_PERFIL)+(i+1))%PUNTOS ) );
        }
    }
}

/*********************************************************************************
Funcion que genera las caras de la tapa superior
*********************************************************************************/

void O3DR::generar_tapa_superior(int indice_centro)
{
    int j;
    int PUNTOS = vertices.size()-1;
    for(j = 0; j<SECCIONES;j++){
        triangles.push_back(_vertex3i( indice_centro,((j*PUNTOS_PERFIL)+(PUNTOS_PERFIL-1))%PUNTOS , (((j+1)*PUNTOS_PERFIL)+(PUNTOS_PERFIL-1) )%PUNTOS) );
    }

}

/*********************************************************************************
Funcion que genera las caras de la tapa inferior
*********************************************************************************/

void O3DR::generar_tapa_inferior(int indice_centro)
{
    int j;
    int PUNTOS = vertices.size()-1;
    for(j = 0; j<SECCIONES;j++){
        triangles.push_back(_vertex3i( indice_centro,((j*PUNTOS_PERFIL))%PUNTOS , (((j+1)*PUNTOS_PERFIL) )%PUNTOS) );
    }

}

/*********************************************************************************
Funcion que busca en el perfil dado si tiene tapas.
*********************************************************************************/

void O3DR::encontrar_tapas()
{
    for(auto it = vertices.begin();it < vertices.end();it++){
        if((it->x == 0.0) && (it->z == 0.0) ){
            if(!tapa_inferior && (it->y)<0.0){
                posicion_tapa_inferior = *it;
                tapa_inferior=true;
                it = vertices.erase(it);
                PUNTOS_PERFIL--;
            }
            if(!tapa_superior && (it->y)>0.0){
                posicion_tapa_superior = *it;
                tapa_superior = true;
                it = vertices.erase(it);
                PUNTOS_PERFIL--;
            }
        }
    }
}

/*********************************************************************************
Funcion que genera el objeto por revolucion:
    1- primero encuentra las tapas
    2- despues quita las tapas si tiene y realiza la revolucion por barrido al
       cuerpo del objeto
    3- si el cuerpo tiene mas de 2 puntos puede generar sus caras
    4- en funcion del numero de tapas qe tuviera las genera.
*********************************************************************************/

void O3DR::generar_objeto_de_revolucion()
{
    encontrar_tapas();
    revolucion_por_barrido_y(2.0*M_PI);

    if(PUNTOS_PERFIL>1)
        generar_caras();

    if(tapa_inferior){
        vertices.push_back(posicion_tapa_inferior);
        generar_tapa_inferior(vertices.size()-1);
    }
    if(tapa_superior){
        vertices.push_back(posicion_tapa_superior);
        generar_tapa_superior(vertices.size()-1);
    }

}
