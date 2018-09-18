#include "o3dr.h"



//*************************************************************************
// Constructor primitivo
//*************************************************************************

O3DR::O3DR()
{
    tapa_i = false;
    tapa_s = false;
    tama_perfil = 0;
    divisiones = 50;
}


//*************************************************************************
// Pinta el objeto
//*************************************************************************

void O3DR::PintaObjeto(float a_i, float a_f){
    this->ReconoceObjeto();
    this->RevolucionPorBarrido_Y(a_i,a_f);
    this->GeneraSuperficie();
}



//*************************************************************************
// Reconoce los puntos correspondientes de las tapas superior e inferior si existen
//*************************************************************************

void O3DR::ReconoceObjeto(){

for(auto it = Vertices.begin(); it < Vertices.end(); it++)
    if(it->x == 0 && it->z == 0){
        if(it == Vertices.begin()){
            tapa_i = true;
            TapaInferior = (*it);
            it = Vertices.erase(it);
            it--;
        }else{
            tapa_s = true;
            TapaSuperior = (*it);
            it = Vertices.erase(it);
        }
    }

tama_perfil = Vertices.size();

}



//*************************************************************************
// Genera la superficie del objeto, incluidas tapas superior e inferior si las tiene.
//*************************************************************************

void O3DR::GeneraSuperficie(){

    for(int i = 0; i < tama_perfil-1; i++){
         for(int j = 0; j < divisiones; j++){
            Superficie.push_back(_vertex3i((j*tama_perfil+i+1)%Vertices.size(), (j*tama_perfil + i)%Vertices.size(), ((j+1)*tama_perfil + i)%Vertices.size() ) );
            Superficie.push_back(_vertex3i(((j+1)*tama_perfil + i)%Vertices.size(), ((j+1)*tama_perfil + i+1)%Vertices.size(),(j*tama_perfil+i+1)%Vertices.size()));
        }
    }

    if(tapa_i){
        Vertices.push_back(TapaInferior);
        GeneraTapaInferior();

    }
    if(tapa_s){
        Vertices.push_back(TapaSuperior);
        GeneraTapaSuperior();

    }
}





//*************************************************************************
// Función que genera la tapa inferior
//*************************************************************************

void O3DR::GeneraTapaInferior(){
    for(int i = 0; i <= divisiones-1; i++)
       Superficie.push_back(_vertex3i(i*tama_perfil,Vertices.size() - 1, i*tama_perfil + tama_perfil ) );

//    Superficie.push_back(_vertex3i(Vertices.size() - 1,0, Vertices.size() - tama_perfil - 1));
}



//*************************************************************************
// Función que genera la tapa superior
//*************************************************************************

void O3DR::GeneraTapaSuperior(){
    for(int i = 1; i <= divisiones; i++)
       Superficie.push_back(_vertex3i(Vertices.size() - 1, (i*tama_perfil - 1), (i*tama_perfil + tama_perfil - 1) ) );

}



//*************************************************************************
// Realiza la revolución por barrido respecto al eje X
//*************************************************************************

void O3DR::RevolucionPorBarrido_X(float angulo_i, float angulo_f){
    float x_rotado, y_rotado, z_rotado, angulo;
    int tama = Vertices.size();
    float inicio = (2.0*M_PI/360) * angulo_i;
    float fin = (2.0*M_PI/360) * angulo_f;

    for(int j = 0; j < tama; j++){
        x_rotado = Vertices[j].x;
        y_rotado = Vertices[j].y * cos(inicio) - Vertices[j].z * sin(inicio);
        z_rotado = Vertices[j].y * sin(inicio) + Vertices[j].z * cos(inicio);
        Vertices[j] = _vertex3f(x_rotado,y_rotado, z_rotado);
    }

    for(int i = 1; i <= divisiones; i++){
        for(int j = 0; j < tama; j++){
            angulo = (i*(fin-inicio))/divisiones;
            x_rotado = Vertices[j].x;
            y_rotado = Vertices[j].y * cos(angulo) - Vertices[j].z * sin(angulo);
            z_rotado = Vertices[j].y * sin(angulo) + Vertices[j].z * cos(angulo);
            Vertices.push_back(_vertex3f(x_rotado,y_rotado, z_rotado));
        }
    }
}



//*************************************************************************
// Realiza la revolución por barrido respecto al eje Y
//*************************************************************************



void O3DR::RevolucionPorBarrido_Y(float angulo_i, float angulo_f){
    float x_rotado, y_rotado, z_rotado, angulo;
    int tama = Vertices.size();
    float inicio = (2.0*M_PI/360) * angulo_i;
    float fin = (2.0*M_PI/360) * angulo_f;

    for(int j = 0; j < tama; j++){
        x_rotado = Vertices[j].x * cos(inicio) + Vertices[j].z * sin(inicio);
        y_rotado = Vertices[j].y;
        z_rotado = -Vertices[j].x * sin(inicio) + Vertices[j].z * cos(inicio);
        Vertices[j] = _vertex3f(x_rotado,y_rotado, z_rotado);
    }

    for(int i = 1; i <= divisiones; i++){
        for(int j = 0; j < tama; j++){
            angulo = (i*(fin-inicio))/divisiones;
            x_rotado = Vertices[j].x * cos(angulo) + Vertices[j].z * sin(angulo);
            y_rotado = Vertices[j].y;
            z_rotado = -Vertices[j].x * sin(angulo) + Vertices[j].z * cos(angulo);
            Vertices.push_back(_vertex3f(x_rotado,y_rotado, z_rotado));
        }
    }
}



//*************************************************************************
// Realiza la revolución por barrido respecto al eje Z
//*************************************************************************

void O3DR::RevolucionPorBarrido_Z(float angulo_i, float angulo_f)
{
    float x_rotado, y_rotado, z_rotado, angulo;
    int tama = Vertices.size();
    float inicio = (2.0*M_PI/360) * angulo_i;
    float fin = (2.0*M_PI/360) * angulo_f;

    for(int j = 0; j < tama; j++){
        x_rotado = Vertices[j].x * cos(inicio) - Vertices[j].y * sin(inicio);
        y_rotado = Vertices[j].x * sin(inicio) + Vertices[j].y * cos(inicio);
        z_rotado = Vertices[j].z;
        Vertices[j] = _vertex3f(x_rotado,y_rotado, z_rotado);
    }

    for(int i = 1; i <= divisiones; i++){
        for(int j = 0; j < tama; j++){
            angulo = (i*(fin-inicio))/divisiones;
            x_rotado = Vertices[j].x * cos(angulo) - Vertices[j].y * sin(angulo);
            y_rotado = Vertices[j].x * sin(angulo) + Vertices[j].y * cos(angulo);
            z_rotado = Vertices[j].z;
            Vertices.push_back(_vertex3f(x_rotado,y_rotado, z_rotado));
        }
    }
}

void O3DR::calculaNormales()
{
    calculaNormalesSuperficie();
    calculaNormalesVertices();
}


void O3DR::calculaNormalesVertices(){
    Normales_V.resize(Vertices.size());

    for(unsigned int i = 0; i < Normales_V.size(); i++){

        Normales_V[i] = _vertex3f(Vertices[i]);
    }

    for(unsigned int i = 0; i < Normales_V.size(); i++){
        Normales_V[i] = _vertex3f(Normales_V[i].normalize());
    }
}

void O3DR::GeneraSuperficieTextura(){


    for(int i = 0; i < divisiones; i++)
        for(int j = 0; j < divisiones; j++){
            Superficie.push_back(_vertex3i(j*(divisiones+1) + i, (j+1)*(divisiones+1) + i, j*(divisiones+1) + 1 + i)  );
            Superficie.push_back(_vertex3i( (j+1)*(divisiones+1) + i, (j+1)*(divisiones+1) + i + 1, j*(divisiones+1) + 1 + i  )  );
        }

}

