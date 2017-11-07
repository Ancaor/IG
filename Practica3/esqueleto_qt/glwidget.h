#ifndef GLWIDGET_H
#define GLWIDGET_H
//**************************************************************************
//
// Domingo Martin Perandres© 2014-2017
// http://calipso.ugr.es/dmartin
// dmartin@ugr.es
//
// GPL
//**************************************************************************

#include <GL/glew.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "vertex.h"
#include "cubo.h"
#include "tetraedro.h"
#include "tubo.h"
#include "ply_object.h"
#include "esfera.h"
#include "cilindro.h"
#include "vaso.h"
#include "vaso_invertido.h"
#include "cono.h"
#include "esfera.h"

#include "base.h"
#include "brazo.h"
#include "partesuperior.h"
#include "partemedia.h"
#include "brazopequenio.h"
#include<QTimer>

namespace _gl_widget_ne {

  const _vertex3f COLORS[]={{0,0,0},{1,0,0},{0,1,0},{0,0,1},{0,1,1},{1,0,1},{1,1,0},{1,1,1}};

  const float X_MIN=-0.5;
  const float X_MAX=0.5;
  const float Y_MIN=-0.5;
  const float Y_MAX=0.5;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=10;
  const float ANGLE_STEP=0.5;

  // axis
  const int AXIS_SIZE=5000;
}


class _window;

class _gl_widget : public QOpenGLWidget
{
    Q_OBJECT
public:
     O3D object;  // objeto
     O3DR object_revolucion;
     PLY_Object ply;

     Base base = Base();
     Brazo brazo = Brazo();
     ParteSuperior psup = ParteSuperior();
     ParteMedia pmed = ParteMedia();
     BrazoPequenio bpeq = BrazoPequenio();
     double angle = 0;
     double angle_z = 0;

     bool ply_bool=0;

     bool revolucion = 0;
     bool objeto_complejo;
     bool vertex = 1; // 1: pinta vertices; 0:No los pinta
     bool lines = 0; // 1: pinta lineas; 0:No los pinta
     bool fill = 0;  // 1: pinta relleno; 0:No los pinta
     bool chest = 0; // 1: pinta ajedrez; 0:No los pinta
     QString pathname_ply = "/home";

     QTimer *timer;
     bool subiendo = 1;
     double velocidad=0;

     float ANGLE_STEPS=2;

  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();
  string buscarPLY();
  QString getPathPLYs(string archivo);
  void timers();

public slots:
  void animar();


protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;


private:
  _window *Window;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;
};

#endif
