#ifndef PLY_OBJECT_H
#define PLY_OBJECT_H

#include "o3d.h"
#include "file_ply_stl.h"
#include <QFileDialog>


class PLY_Object : public O3D
{
private:
    QString pathname_ply; //Path de los PLY (por defecto /home)
public:
    PLY_Object();
    PLY_Object(string url);
    void read_ply(string path);
    string buscarPLY();
    QString getPathPLYs(string archivo);
    bool plyCargado();
};

#endif // PLY_OBJECT_H
