#ifndef O3DS_H
#define O3DS_H

#include<vector>
#include <QPainter>
#include <QPaintEngine>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QCoreApplication>
#include"vertex.h"

class O3DS
{
public:
    std::vector<_vertex3f> vertices;

    O3DS();
    void drawPoints();
};

#endif // O3DS_H
