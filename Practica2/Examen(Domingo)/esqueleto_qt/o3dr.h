#ifndef O3DR_H
#define O3DR_H

#include "o3d.h"

class O3DR : public O3D
{

private:
    bool tapa_superior;
    bool tapa_inferior;
    _vertex3f posicion_tapa_superior;
    _vertex3f posicion_tapa_inferior;
    int PUNTOS_PERFIL;             // Almacena el numero de puntos que tiene el perfil, sin contar las tapas.


public:

    int SECCIONES;      // Numero de secciones en las que se divide el objeto de revolucion, a más secciones mas puntos tiene el objeto.
    O3DR();
    void setPuntosPerfil(int size);
    void revolucion_por_barrido_y(float angulo);
    void revolucion_por_barrido_z(float angulo);
    void generar_caras();
    void generar_tapa_superior(int indice_centro);
    void generar_tapa_inferior(int indice_centro);
    void generar_objeto_de_revolucion();
    void generar_objeto_de_revolucion(float angulo_inicial,float angulo_final);
    void encontrar_tapas();
    void revolucion_por_barrido_y(float angulo_inicial,float angulo_final);
};

#endif // O3DR_H
