#ifndef O3DR_H
#define O3DR_H
#include <objeto3d.h>
#include<iostream>

class O3DR : public Objeto3D
{
public:
    _vertex3f TapaSuperior;     // Vertice que forma la tapa superior
    _vertex3f TapaInferior;     // Vertice que forma la tapa inferior
    bool tapa_s;                // Indica si existe la tapa superior
    bool tapa_i;                // Indica si existe la tapa inferior
    int tama_perfil;            // Tamaño del perfil sin tener en cuenta las tapas
    int divisiones;             // Numero de divisiones en un barrido.
    O3DR();
    void PintaObjeto(float angulo_i, float angulo_f);
    void ReconoceObjeto();                              // Reconoce el perfil del objeto y si tiene o no caras superior e inferior.
    void GeneraSuperficie();                            // Genera la superficie del objeto
    void GeneraSuperficieTextura();
    void GeneraTapaSuperior();                          // Genera la tapa superior del objeto
    void GeneraTapaInferior();                          // Genera la tapa inferior del objeto
    void RevolucionPorBarrido_X(float angulo_i, float angulo_f);          // Revolucion por barrido con respecto al eje X con un angulo 'vuelta'.
    void RevolucionPorBarrido_X();
    void RevolucionPorBarrido_Y(float angulo_i, float angulo_f);          // Revolucion por barrido con respecto al eje Y con un angulo 'vuelta'.
    void RevolucionPorBarrido_Y();
    void RevolucionPorBarrido_Z(float angulo_i, float angulo_f);          // Revolucion por barrido con respecto al eje Z con un angulo 'vuelta'.
    void RevolucionPorBarrido_Z();
    void calculaNormales();
    void calculaNormalesVertices();
};

#endif // O3DR_H
