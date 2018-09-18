#include "esfera.h"

Esfera::Esfera()
{
   divisiones--;
   tama_perfil = divisiones;

   Vertices.resize(1);
   Vertices[0]=_vertex3f(0,-0.5,0);
   this->RevolucionPorBarrido_Z(0,180);
   Vertices.push_back(_vertex3f(0,0.5,0));

   this->PintaObjeto(0, 360);
   this->calculaNormales();

}

Esfera::Esfera(int d, float a_i, float a_f)
{
   divisiones = d-1;
   tama_perfil = divisiones;
   Vertices.resize(1);
   Vertices[0]=_vertex3f(0,-0.5,0);
   this->RevolucionPorBarrido_Z(0,180);
   Vertices.push_back(_vertex3f(0,0.5,0));

   this->PintaObjeto(a_i, a_f);
   this->calculaNormales();

}

