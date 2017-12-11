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

public:
    int PUNTOS_PERFIL;             // Almacena el numero de puntos que tiene el perfil, sin contar las tapas.
    int SECCIONES;      // Numero de secciones en las que se divide el objeto de revolucion, a más secciones mas puntos tiene el objeto.
    O3DR();
    void setPuntosPerfil(int size);
    void revolucion_por_barrido_y(float angulo);
    void revolucion_por_barrido_z(float angulo);
    void generar_caras();
    void generar_tapa_superior(int indice_centro);
    void generar_tapa_inferior(int indice_centro);
    void generar_objeto_de_revolucion(int angulo);
    void encontrar_tapas();
};

#endif // O3DR_H
