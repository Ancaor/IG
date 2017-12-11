#ifndef MARCO_H
#define MARCO_H

#include "o3d.h"

class marco : public O3D
{
private:
    QImage Imagen;
    int n;
public:
    marco();
    marco(int n, float ancho , float alto);
    void cargarImagen(string path);
    void drawTextura(vector<float> porcion_textura , vector<int> porcion_marco);
    void drawFillIluminado(vector<float> porcion_textura, vector<int> porcion_marco, Material material , bool iluminacion);
    void drawFillIluminadoSuave(vector<float> porcion_textura, vector<int> porcion_marco,Material material , bool iluminacion);
    void drawFillIluminadoSuave(Material material, bool iluminacion);
    void drawFillIluminado(Material material, bool iluminacion);
};

#endif // MARCO_H
