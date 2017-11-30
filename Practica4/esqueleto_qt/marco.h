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
    marco(int n);
    void cargarImagen(string path);
    void drawTextura(vector<float> porcion_textura , vector<int> porcion_marco);
};

#endif // MARCO_H
