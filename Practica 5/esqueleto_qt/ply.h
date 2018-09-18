#ifndef PLY_H
#define PLY_H
#include <o3dr.h>
#include <file_ply_stl.h>
#include <QFileDialog>
#include <QObject>
#include <QTranslator>

class PLY : public Objeto3D
{
    QString path;
public:
    PLY();
    void ReadPLY();
    void ReadPLY(QString fichero);
    QString VentanaPLY(string archivo);
};

#endif // PLY_H
