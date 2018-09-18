//**************************************************************************
//
// Domingo Martin Perandres© 2014-2017
// http://calipso.ugr.es/dmartin
// dmartin@ugr.es
//
// GPL
//**************************************************************************

#include "glwidget.h"
#include <GL/glut.h>
#include <QPainter>
#include <QPaintEngine>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QCoreApplication>
#include <QTimer>
#include <math.h>
#include "objeto3d.h"
#include "cubo.h"
#include "tetraedro.h"
#include "tubo.h"
#include "esfera.h"
#include "cono.h"
#include "cilindro.h"
#include "vaso.h"
#include "vasoinv.h"
#include "peon.h"
#include "o3dr.h"
#include "ply.h"
#include "watt.h"
#include "material.h"
#include "luz.h"
#include "marcodetexturas.h"
#include "esfera_textura.h"
#include "camara.h"
#include "escena.h"

#include "window.h"

#include <QDebug>
using namespace std;
using namespace _gl_widget_ne;

//*************************************************************************
// Variables necesarias para la practica 5
//*************************************************************************

// Camara

Camara camaras_perspectiva[3];
int n_camara_perspectiva = 0;

Camara camaras_ortogonales[3];
int n_camara_ortogonal = 0;

int camara_actual = 0;

// Movimiento con el ratón

QPointF punto_ini;                           // punto donde se hace click
QPointF punto_fin;                           // punto hasta donde se arrastra el raton con un boton presionado.

int sensibilidad_zoom = 25;
int sensibilidad_rotacion = 25;

float factor_zoom = 0.012/100;               // Ajusta la sensibilidad del zoom.
float factor_angulo_rotaciones = 0.4/100;    // Ajusta la sensibilidad de la rotacion.

//Movimiento primera persona

float VRP[3];
float VPN[3] = {0,0,0};

float Paso_movimiento = 0.25;        // Tamaño del salto con los movimientos en 1ª persona



//Seleccion de objeto

GLint rendermode;
_vertex4f color_seleccion = _vertex4f(1,0,0,1);
_vertex4f color_deseleccion = _vertex4f(0,0.5,1,1);

bool colorear_seleccion = false;


int objeto_seleccionado = 0;

// Escena
Escena escena;
bool escenario = false;


//*************************************************************************
// Variables necesarias para la practica 4
//*************************************************************************

//Iluminación

bool luz_punto = false;
bool luz_inf = false;
bool Caras_iluminadas_flat = false;
bool Caras_iluminadas_smooth = false;

float movimiento_luz_punto_x = 0;
float movimiento_luz_punto_y = 0;
float movimiento_luz_punto_z = 0;

float movimiento_luz_inf_x = 0;
float movimiento_luz_inf_y = 0;

Luz foco_punto(0,0,0,1);
Luz foco_infinito(0,0,1,0);

GLfloat ambiente[] = {0.1, 0.1, 0.1, 1.0};
GLfloat difuso[]= {0.7, 0.7, 0.7, 1.0};
GLfloat especular[]= {0.2, 0.2, 0.2, 1.0};


//Materiales

int n_material = 0;

Material material;

GLfloat mat0[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
Material vacio(mat0);       //Para las texturas

GLfloat mat1[] = {0.0, 0.05, 0.05, 1.0, 0.4, 0.5, 0.5, 1.0, 0.04, 0.7, 0.7, 1.0, 0.78125 };
Material goma_azul(mat1);

GLfloat mat2[] = {0.0215, 0.1745, 0.0215, 1.0, 0.07568, 0.61424, 0.07568, 1.0, 0.633, 0.727811, 0.633, 1.0, 0.6 };
Material esmeralda(mat2);

GLfloat mat3[] = {0.19225, 0.19225, 0.19225, 1.0, 0.50754, 0.50754, 0.50754, 1.0, 0.508273, 0.508273, 0.508273, 1.0, 0.4};
Material plata(mat3);

GLfloat mat4[] = {0.0, 0.1, 0.06, 1.0, 0.0, 0.50980392, 0.50980392, 1.0, 0.50196078, 0.50196078, 0.50196078, 1.0, 0.25};
Material plastico_azul(mat4);


//Texturas


MarcoDeTexturas marco;
Esfera_Textura esfera_textura;
Esfera_Textura esfera_fondo;

QString pathText;                                   // Path de la textura.
QString path_guardado = "/home";                    // Path guardado para la ventana.
QString path_fondo = "/home/ruben/Github/UGR/3GII/IG/Texturas/fondo.png";

bool texturas = false;
bool fondo_textura = false;
bool textura_nubes = false;

float ancho_marco = 1.0;                            // Datos iniciales del marco.
float alto_marco = 1.0;
int divisiones_marco = 1;


float pos_img[4] = {0,1,0,1};                       // Parte de la textura que se va a dibujar. Por defecto se dibujará toda la textura.
int pos_marco[4] = {0,1,0,1};                       // Columnas inicial/final y filas inicial/final que delimita donde se dibujará la textura.

bool cargar_textura = false;                        // Indica si cargamos una textura en el programa.
bool abrir_textura = false;                         // Indica si vamos a elegir una textura con la interfaz de la ventana


//*************************************************************************
// Parámetros necesarios para crear objetos O3DR
//*************************************************************************

int divisiones = 41;
float angulo_inicial =0;
float angulo_final = 360;

//*************************************************************************
// Parámetros necesarios para la animacion del Watt
//*************************************************************************


float angle = 0;
float velocidad = 0.1;
float salto_velocidad = 0.01;

bool usar_topes = true;             //Si no se quiere tener tope inferior cambiar a false

float tope_superior = 1 - salto_velocidad;
float tope_inferior = 0 + salto_velocidad;

bool animando = false;
bool anima = false;


bool aumenta_v = true;              // Se usa para la animación automática
bool animacion_auto = false;        // Se usa para la animación automática
int contador_iteraciones = 0;       // Se usa para la animación automática
Watt watt;

//*************************************************************************
// Variables globales
//*************************************************************************

bool Ajedrez = false;
bool Lineas = false;
bool Caras = false;
bool Puntos = true;
int Figura = 0;
bool Objeto_revolucion = false;
bool Objeto_PLY = false;
bool cargar_ply = false;
bool ObjetoCompuesto = false;
int nPly = 0;
Objeto3D objeto = Cubo();
O3DR objetoR;
PLY objetoPLY;

QString pathPly;
bool abrir_ply = false;


_gl_widget::_gl_widget(_window *Window1, UI *ui):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(animar()));

  timer_ui = new QTimer(this);
  connect(timer_ui, SIGNAL(timeout()), this, SLOT(updateUI()));
  connect(timer_ui, SIGNAL(timeout()), this, SLOT(updateRES()));
  Window_ui = ui;
  Window_ui->move(850,0);


  camaras_perspectiva[0] = Camara(0, 0, 10, 0);
  camaras_perspectiva[1] = Camara(0, 0, 10, 0);
  camaras_perspectiva[2] = Camara(0, 0, 10, 0);

  camaras_ortogonales[0] = Camara(0, 0, 10, 1);
  camaras_ortogonales[1] = Camara(0, 0, 10, 1);
  camaras_ortogonales[2] = Camara(0, 0, 10, 1);

  Window_ui->setWindowFlags( Qt::Window);
  Window_ui->show();
  timer_ui->start(0);

}

//*************************************************************************
// Eventos que se producen al pulsar teclas
//*************************************************************************

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
    switch (camara_actual){
        case 0: Observer_angle_x = camaras_perspectiva[n_camara_perspectiva].getObserverAngle_X(); Observer_angle_y = camaras_perspectiva[n_camara_perspectiva].getObserverAngle_Y(); Observer_distance = camaras_perspectiva[n_camara_perspectiva].getObserverDistance(); break;
        case 1: Observer_angle_x = camaras_ortogonales[n_camara_ortogonal].getObserverAngle_X(); Observer_angle_y = camaras_ortogonales[n_camara_ortogonal].getObserverAngle_Y(); Observer_distance = camaras_ortogonales[n_camara_ortogonal].getObserverDistance(); break;
    }

    switch(Keyevent->key()){
      case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
      case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
      case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
      case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
      case Qt::Key_PageUp:Observer_distance*=1.2;break;
      case Qt::Key_PageDown:Observer_distance/=1.2;break;
      case Qt::Key_R: VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;break;
    }

    switch (camara_actual){
        case 0: camaras_perspectiva[n_camara_perspectiva].setPosicion(Observer_angle_x, Observer_angle_y, Observer_distance); break;
        case 1: camaras_ortogonales[n_camara_ortogonal].setPosicion(Observer_angle_x, Observer_angle_y, Observer_distance); break;
    }

  update();
}


//**************************************************************************
//
//***************************************************************************

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  float relacion_aspecto_X = this->size().width()*1.0 / this->size().height();

  glFrustum(X_MIN*relacion_aspecto_X,X_MAX*relacion_aspecto_X,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void _gl_widget::draw_axis()
{
  glBegin(GL_LINES);
  // eje X, color rojo
  glColor3f(1,0,0);
  glVertex3f(-AXIS_SIZE,0,0);
  glVertex3f(AXIS_SIZE,0,0);
  // eje Y, color verde
  glColor3f(0,1,0);
  glVertex3f(0,-AXIS_SIZE,0);
  glVertex3f(0,AXIS_SIZE,0);
  // eje Z, color azul
  glColor3f(0,0,1);
  glVertex3f(0,0,-AXIS_SIZE);
  glVertex3f(0,0,AXIS_SIZE);
  glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void _gl_widget::draw_objects()
{
    // Activo o desactivo la luz en un punto.
    if(luz_punto){
        foco_punto.enable_luz();

        glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, difuso);
        glLightfv(GL_LIGHT0, GL_SPECULAR, especular);
        foco_punto.mover_luz();
    }else
        foco_punto.disable_luz();

    // Activo o desactivo la luz en el infinito.
    if(luz_inf){
        foco_infinito.enable_luz();

        glLightfv(GL_LIGHT1, GL_AMBIENT, ambiente);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, difuso);
        glLightfv(GL_LIGHT1, GL_SPECULAR, especular);
        foco_infinito.mover_luz();
    }else
        foco_infinito.disable_luz();


    if(texturas){                                                     // Si dibujamos texturas tenemos 2 opciones.
        if(Objeto_revolucion){                                                  // La esfera con texturas.

            if(fondo_textura){

                esfera_fondo = Esfera_Textura(40, 20.0);
                esfera_fondo.cargarTextura(path_fondo);
                esfera_fondo.drawTextura();
                esfera_textura.cargarTextura(pathText);
            }


            if(Puntos)
                esfera_textura.draw_Points();
            if(Lineas)
                esfera_textura.draw_Lines();
            if(Caras)
                esfera_textura.draw_Triangles();
            if(Ajedrez)
                esfera_textura.draw_Chess();

            if(n_material == 3){
                if(Caras_iluminadas_flat)
                    esfera_textura.draw_Triangles_Iluminacion_Flat(vacio);
                else if(Caras_iluminadas_smooth)
                    esfera_textura.draw_Triangles_Iluminacion_Smooth(vacio);
                else
                    esfera_textura.drawTextura();
            }else{
                if(Caras_iluminadas_flat)
                    esfera_textura.draw_Triangles_Iluminacion_Flat(material);
                else if(Caras_iluminadas_smooth)
                    esfera_textura.draw_Triangles_Iluminacion_Smooth(material);
                else
                    esfera_textura.drawTextura();
            }
        }
        else{                                                                   // El marco con texturas.
            if(Puntos)
                marco.draw_Points();
            if(Lineas)
                marco.draw_Lines();
            if(Caras)
                marco.draw_Triangles();
            if(Ajedrez)
                marco.draw_Chess();

            if(Caras_iluminadas_flat)
                marco.draw_Triangles_Iluminacion_Flat(pos_img, pos_marco, material);
            else if(Caras_iluminadas_smooth)
                marco.draw_Triangles_Iluminacion_Smooth(pos_img, pos_marco, material);
            else
                marco.drawTextura(pos_img, pos_marco);
        }
    }
    else if(Objeto_revolucion){                                                 // Dibujamos un objeto de revolución.
        if(Puntos)
            objetoR.draw_Points();
        if(Lineas)
            objetoR.draw_Lines();
        if(Caras)
            objetoR.draw_Triangles();
        if(Caras_iluminadas_flat)
            objetoR.draw_Triangles_Iluminacion_Flat(material);
        if(Caras_iluminadas_smooth)
            objetoR.draw_Triangles_Iluminacion_Smooth(material);
        if(Ajedrez)
            objetoR.draw_Chess();
    }
    else if(Objeto_PLY){                                                        // Dibujamos un objeto PLY.
        if(Puntos)
            objetoPLY.draw_Points();
        if(Lineas)
            objetoPLY.draw_Lines();
        if(Caras)
            objetoPLY.draw_Triangles();
        if(Caras_iluminadas_flat)
            objetoPLY.draw_Triangles_Iluminacion_Flat(material);
        if(Caras_iluminadas_smooth)
            objetoPLY.draw_Triangles_Iluminacion_Smooth(material);
        if(Ajedrez)
            objetoPLY.draw_Chess();
    }
    else if(ObjetoCompuesto){                                                     // Dibujamos un objeto jerarquico (El regulador Watt).
        if(Puntos)
            watt.draw(0, angle, velocidad);
        if(Lineas)
            watt.draw(1, angle, velocidad);
        if(Caras)
            watt.draw(2, angle, velocidad);
        if(Ajedrez)
            watt.draw(3, angle, velocidad);
    }
    else if(escenario){
        if(Puntos)
            escena.draw(0);
        if(Lineas)
            escena.draw(1);
        if(Caras)
            escena.draw(2);
        if(Ajedrez)
            escena.draw(3);
    }
    else{                                                                        // Dibujamos un objeto simple (cubo o tetraedro).
        if(Puntos)
            objeto.draw_Points();
        if(Lineas)
            objeto.draw_Lines();
        if(Caras)
            objeto.draw_Triangles();
        if(Caras_iluminadas_flat)
            objeto.draw_Triangles_Iluminacion_Flat(material);
        if(Caras_iluminadas_smooth)
            objeto.draw_Triangles_Iluminacion_Smooth(material);
        if(Ajedrez)
            objeto.draw_Chess();
 }

}

//*************************************************************************
//
//*************************************************************************

void _gl_widget::paintGL()
{
  clear_window();
  float relacion_aspecto_X = this->size().width()*1.0 / this->size().height();
  //change_projection();
  //change_observer();
  switch(camara_actual){
    case 0: camaras_perspectiva[n_camara_perspectiva].CambiarProyeccion(relacion_aspecto_X);camaras_perspectiva[n_camara_perspectiva].moverCamara();camaras_perspectiva[n_camara_perspectiva].cambiarLookAt(); break;
    case 1: camaras_ortogonales[n_camara_ortogonal].CambiarProyeccion(relacion_aspecto_X);camaras_ortogonales[n_camara_ortogonal].moverCamara();camaras_ortogonales[n_camara_ortogonal].cambiarLookAt(); break;
  }

  draw_axis();
  draw_objects();
}

void _gl_widget::draw_scene()
{
    clear_window();
    switch(camara_actual){
      case 0:camaras_perspectiva[n_camara_perspectiva].moverCamara(); break;
      case 1:camaras_ortogonales[n_camara_ortogonal].moverCamara(); break;
    }
    draw_axis();
    draw_objects();
}

//*************************************************************************
//
//*************************************************************************

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
  /*
  cout << "this->Width = " << this->width() << endl;
  cout << "this->Height = " << this->height() << endl;
  cout << "Width1 = " << Width1 << endl;
  cout << "Height1 = " << Height1 << endl;
  */
}


//*************************************************************************
//
//*************************************************************************

void _gl_widget::initializeGL()
{
  const GLubyte* strm;
  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
    }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  glewExperimental = GL_TRUE;
  int err = glewInit();
  if (GLEW_OK != err){
    std::cerr << "Error: " << glewGetErrorString(err) << "\n";
    exit (-1);
    }

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;
}

//*************************************************************************
// Funcion que se encarga de realizar la animación
//*************************************************************************

void _gl_widget::animar(){


    if(animacion_auto){
        if(aumenta_v){
            if(velocidad < tope_superior)
                velocidad += salto_velocidad;
            else{
                if(contador_iteraciones < 200)
                    contador_iteraciones++;
                else{
                    aumenta_v = false;
                    contador_iteraciones = 0;
                }
            }
        }else{
            if(velocidad > tope_inferior)
                velocidad -= salto_velocidad;
            else{
                if(contador_iteraciones < 100)
                    contador_iteraciones++;
                else{
                    aumenta_v = true;
                    contador_iteraciones = 0;
                }
            }
        }
    }


    angle += velocidad*10;

    update();
}

//*************************************************************************
// Controla la animación. el parámetro 'automatico' determina si la animación
// cambia de velocidad de forma automatica o no.
//*************************************************************************

void _gl_widget::control_animacion(bool automatico){
    animacion_auto = automatico;

    if(!animando){
      animando = true;
      timer->start(0);
    }
    else{
      timer->stop();
      animando = false;
    }

}

//*************************************************************************
// Conecta la interfaz con gl_widget.
//*************************************************************************

void _gl_widget::updateUI(){

    // Modos de dibujo.
    Puntos = Window_ui->getPuntos();
    Lineas = Window_ui->getLineas();
    Caras = Window_ui->getRelleno();
    Ajedrez = Window_ui->getAjedrez();
    Caras_iluminadas_flat = Window_ui->getRellenoIluminadoFlat();
    Caras_iluminadas_smooth = Window_ui->getRellenoIluminadoSmooth();

    // Parámetros para los objetos de revolución.
    angulo_final = Window_ui->getAnguloFinal();
    divisiones = Window_ui->getDivisiones();

    // Parámetros para controlar el regulador Watt, su movimiento y animación.
    velocidad = Window_ui->getVelocidad();
    anima = Window_ui->getAnimar();

    // Indice de la figura que queremos dibujar
    Figura = Window_ui->getFigura();

    // Activación o no de la luz en un punto y sus parámetros de movimiento.
    luz_punto = Window_ui->getLuzPunto();
    movimiento_luz_punto_x = Window_ui->getMovLuz_Punto_X();
    movimiento_luz_punto_y = Window_ui->getMovLuz_Punto_Y();
    movimiento_luz_punto_z = Window_ui->getMovLuz_Punto_Z();
    foco_punto.setTransformaciones(movimiento_luz_punto_x, movimiento_luz_punto_y, movimiento_luz_punto_z);

    // Activación o no de la luz en el infinito y sus parámetros de movimiento.
    luz_inf = Window_ui->getLuzInf();
    movimiento_luz_inf_x = Window_ui->getMovLuz_Inf_X();
    movimiento_luz_inf_y = Window_ui->getMovLuz_Inf_Y();
    foco_infinito.setTransformaciones(movimiento_luz_inf_x, movimiento_luz_inf_y, 0);

    // Indice del material elegido
    n_material = Window_ui->getMaterial();

    // Asignamos el material elegido.
    switch(n_material){
        case 0: material = plastico_azul;break;
        case 1: material = goma_azul;break;
        case 2: material = plata; break;
        case 3: material = vacio;break;
    }

    // Propiedades del marco de textura
    ancho_marco = Window_ui->getAnchoMarco();
    alto_marco = Window_ui->getAltoMarco();
    divisiones_marco = Window_ui->getDivisionesMarco();

    // Zona del marco donde se va a pegar la textura (columnas y filas inicial y final).
    pos_marco[0] = Window_ui->getMargenMarcoXMin();
    pos_marco[1]= Window_ui->getMargenMarcoXMax();
    pos_marco[2] = Window_ui->getMargenMarcoYMin();
    pos_marco[3] = Window_ui->getMargenMarcoYMax();

    // Zona de la textura que queremos dibujar.
    pos_img[0] = Window_ui->getMargenImagenXMin();
    pos_img[1] = Window_ui->getMargenImagenXMax();
    pos_img[2] = Window_ui->getMargenImagenYMin();
    pos_img[3] = Window_ui->getMargenImagenYMax();


    // Abrir una textura. Se selecciona la textura en una ventana QFileDialog.
    abrir_textura = Window_ui->getAbrirTextura();
    if(abrir_textura){
       QString aux = QFileDialog::getOpenFileName(0, QTranslator::tr("Abrir Textura"), path_guardado, QTranslator::tr("Imagenes (*.png *.jpg)"));
       path_guardado = getDirectorio(aux);
       Window_ui->setPathTextura(aux);
    }

    // Cargar una textura. Se carga la misma textura tanto en el marco como en la esfera.
    cargar_textura =  Window_ui->getCargarTextura();
    if(cargar_textura){
        pathText = Window_ui->getPathTextura();
        marco.cargarTextura(pathText);
        esfera_textura.cargarTextura(pathText);
        Window_ui->clearText();                     // limpia el texto del line edit de la interfaz.
    }

    fondo_textura = Window_ui->getFondo();
    // Abrir un PLY. Se selecciona un fichero PLY en una ventana QFileDialog.
    abrir_ply = Window_ui->getAbrirPly();
    if(abrir_ply){
       QString aux = QFileDialog::getOpenFileName(0, QTranslator::tr("Abrir PLY"), path_guardado, QTranslator::tr("Archivos PLY (*.ply)"));
       path_guardado = getDirectorio(aux);
       Window_ui->setPathPly(aux);
    }

    // Cargar un PLY.
    cargar_ply =  Window_ui->getCargarPly();
    if(cargar_ply){
        pathPly = Window_ui->getPathPly();
        objetoPLY.ReadPLY(pathPly);
        Figura = 10;
        Window_ui->clearText();                      // limpia el texto del line edit de la interfaz.
    }


    colorear_seleccion = Window_ui->getColorearSeleccion();

    // Ajustamos los parámetros para dibujar la figura elegida.
    switch(Figura){
        case 0: objeto = Cubo();Objeto_revolucion = false;Objeto_PLY = false;ObjetoCompuesto = false;texturas = false;break;
        case 1: objeto = Tetraedro(); Objeto_revolucion = false;Objeto_PLY = false;ObjetoCompuesto = false;texturas = false; break;
        case 2: objetoR = Cilindro(divisiones, angulo_inicial, angulo_final);Objeto_revolucion = true;Objeto_PLY = false;ObjetoCompuesto = false;texturas = false;  break;
        case 3: objetoR = Vaso(divisiones, angulo_inicial, angulo_final);Objeto_revolucion = true;Objeto_PLY = false;ObjetoCompuesto = false;texturas = false;   break;
        case 4: objetoR = VasoInv(divisiones, angulo_inicial, angulo_final);Objeto_revolucion = true;Objeto_PLY = false;ObjetoCompuesto = false; texturas = false;  break;
        case 5: objetoR = Cono(divisiones, angulo_inicial, angulo_final);Objeto_revolucion = true;Objeto_PLY = false;ObjetoCompuesto = false;texturas = false;   break;
        case 6: objetoR = Tubo(divisiones, angulo_inicial, angulo_final);Objeto_revolucion = true;Objeto_PLY = false;ObjetoCompuesto = false;texturas = false;break;
        case 7: objetoR = Esfera(divisiones, angulo_inicial, angulo_final);Objeto_revolucion = true;Objeto_PLY = false; ObjetoCompuesto = false;texturas = false;break;
        case 8: objetoR = Peon(divisiones, angulo_inicial, angulo_final);Objeto_revolucion = true;Objeto_PLY = false;ObjetoCompuesto = false;texturas = false;break;
        case 9: Objeto_revolucion = false;Objeto_PLY = false;ObjetoCompuesto = true;texturas = false;break;
        case 10: Objeto_revolucion = false;Objeto_PLY = true;ObjetoCompuesto = false;texturas = false;break;
        case 11: marco.setTextura(Window_ui->getTexturaHabilitada()); texturas = true;Objeto_revolucion = false; marco.setTablero(ancho_marco, alto_marco, divisiones_marco, divisiones_marco);break;
        case 12: esfera_textura.setTextura(Window_ui->getTexturaHabilitada()); Objeto_revolucion = true;Objeto_PLY = false; ObjetoCompuesto = false;texturas = true;break;
        case 13: Objeto_revolucion = false;Objeto_PLY = false;ObjetoCompuesto = false;texturas = false;escenario = true;
            if(colorear_seleccion){
                escena.setColor(color_deseleccion);
                escena.setColor(colorear_seleccion, objeto_seleccionado);
            }

        break;
    }

    // Controla la animación del Watt
    if(anima && !animando){         // Comienza la animación.
        animando = true;
        timer->start(0);
    }
    else if(!anima && animando){    // Finaliza la animación
        animando = false;
        timer->stop();
        Window_ui->setAnguloRotacion(angle);
    }

    // Permite la rotación del Watt manualmente si no se esta animando.
     if(!anima)
        angle = Window_ui->getAnguloRotacion();

     camara_actual = Window_ui->getCamaraActual();
     n_camara_perspectiva = Window_ui->getNumeroCamaraPerspectiva();
     n_camara_ortogonal = Window_ui->getNumeroCamaraOrtogonal();

     sensibilidad_zoom = Window_ui->getSensibilidadZoom();
     sensibilidad_rotacion = Window_ui->getSensibilidadRotacion();
     if(Window_ui->getReiniciarCamara()){
         switch(camara_actual){
            case 0: camaras_perspectiva[n_camara_perspectiva].cambiarObjetivo(0,0,0);break;
            case 1: camaras_ortogonales[n_camara_ortogonal].cambiarObjetivo(0,0,0);break;
         }
         objeto_seleccionado = 0;
    }


 update();

}

//*************************************************************************
// Nos permite obtener el path de la carpeta de un archivo.
//*************************************************************************

QString _gl_widget::getDirectorio(QString archivo){
    string aux = archivo.toStdString();
    QString directorio;
    int indice = aux.size() -1;
    while(aux[indice] != '/')
        indice--;

    directorio = QString::fromStdString(aux.substr(0, indice));

    return directorio;
}

//*************************************************************************
// Actualiza el Fustrum constantemente por si se produce
// un cambio de la resolución de la ventana.
//*************************************************************************

void _gl_widget::updateRES(){
    this->change_projection();
}


//*************************************************************************
// Control del movimiento de camara con el ratón
//*************************************************************************
void _gl_widget::mouseMoveEvent(QMouseEvent *event)
{
    float angulo_y, angulo_x;
    if(event->buttons() == Qt::LeftButton){
        punto_fin = event->localPos();

        angulo_y = sensibilidad_rotacion*factor_angulo_rotaciones*(punto_fin.x() - punto_ini.x());
        angulo_x = sensibilidad_rotacion*factor_angulo_rotaciones*(punto_fin.y() - punto_ini.y());

        switch (camara_actual){
            case 0: Observer_angle_x = camaras_perspectiva[n_camara_perspectiva].getObserverAngle_X(); Observer_angle_y = camaras_perspectiva[n_camara_perspectiva].getObserverAngle_Y(); Observer_distance = camaras_perspectiva[n_camara_perspectiva].getObserverDistance(); break;
            case 1: Observer_angle_x = camaras_ortogonales[n_camara_ortogonal].getObserverAngle_X(); Observer_angle_y = camaras_ortogonales[n_camara_ortogonal].getObserverAngle_Y(); Observer_distance = camaras_ortogonales[n_camara_ortogonal].getObserverDistance(); break;
        }
        switch (camara_actual){
            case 0: camaras_perspectiva[n_camara_perspectiva].setPosicion(Observer_angle_x + angulo_x,Observer_angle_y + angulo_y, Observer_distance); break;
            case 1: camaras_ortogonales[n_camara_ortogonal].setPosicion(Observer_angle_x + angulo_x,Observer_angle_y + angulo_y, Observer_distance); break;
        }

        punto_ini = punto_fin;
    }
}


//*************************************************************************
// Guarda el punto donde se hace click con el ratón
//*************************************************************************
void _gl_widget::mousePressEvent(QMouseEvent *event)
{
    punto_ini = event->localPos();
    if(event->buttons() == Qt::RightButton){
        if(event->modifiers().testFlag(Qt::ControlModifier))
            pick(punto_ini.x(), punto_ini.y(), true);
        else
            pick(punto_ini.x(), punto_ini.y(), false);
    }
}


//*************************************************************************
// Control del zoom de la cámara mediante la rueda del ratón
//*************************************************************************
void _gl_widget::wheelEvent(QWheelEvent *event)
{
    switch (camara_actual){
        case 0:Observer_distance = camaras_perspectiva[n_camara_perspectiva].getObserverDistance();Observer_distance += -event->delta()*factor_zoom*sensibilidad_zoom; camaras_perspectiva[n_camara_perspectiva].setPosicion(camaras_perspectiva[n_camara_perspectiva].getObserverAngle_X(),camaras_perspectiva[n_camara_perspectiva].getObserverAngle_Y(), Observer_distance); break;
        case 1:Observer_distance = camaras_ortogonales[n_camara_ortogonal].getObserverDistance();Observer_distance += -event->delta()*factor_zoom*sensibilidad_zoom; camaras_ortogonales[n_camara_ortogonal].setPosicion(camaras_ortogonales[n_camara_ortogonal].getObserverAngle_X(),camaras_ortogonales[n_camara_ortogonal].getObserverAngle_Y(), Observer_distance); break;
    }
}

void _gl_widget::pick (int x, int y, bool mover_camara)
{
    glViewport(0,0,this->width(), this->height());     // Qt modifica el viewport. Hacemos un resize para actualizar y asegurar que los valores son correctos.

    cout << "pick x=" << x << ",y=" << y << endl;

    float relacion_aspecto_X = this->size().width()*1.0 / this->size().height();

    GLuint Selection_buffer[100] = {0};
    GLint Hits, Viewport[4];

    glGetIntegerv (GL_VIEWPORT, Viewport);
    glSelectBuffer (100, Selection_buffer);

    //cout << "Viewport = ( " << Viewport[0] << ", " << Viewport[1] << ", " << Viewport[2] << ", " << Viewport[3] << " )" << endl;

    glRenderMode (GL_SELECT);
    glInitNames();
    glPushName(0);

    // Fijar la transformación de proyección para la selección

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPickMatrix (x,(Viewport[3] - y),1.0, 1.0, Viewport);

    if(camara_actual == 0)
        glFrustum(X_MIN*relacion_aspecto_X,X_MAX*relacion_aspecto_X,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
    else if(camara_actual == 1)
        glOrtho(X_MIN*camaras_ortogonales[n_camara_ortogonal].getObserverDistance()*relacion_aspecto_X, X_MAX*camaras_ortogonales[n_camara_ortogonal].getObserverDistance()*relacion_aspecto_X, Y_MIN*camaras_ortogonales[n_camara_ortogonal].getObserverDistance(), Y_MAX*camaras_ortogonales[n_camara_ortogonal].getObserverDistance(), FRONT_PLANE_PERSPECTIVE, BACK_PLANE_PERSPECTIVE);


    // Dibujar la escena

    clear_window();

    switch(camara_actual){
      case 0:camaras_perspectiva[n_camara_perspectiva].moverCamara();camaras_perspectiva[n_camara_perspectiva].cambiarLookAt(); break;
      case 1:camaras_ortogonales[n_camara_ortogonal].moverCamara();camaras_ortogonales[n_camara_ortogonal].cambiarLookAt(); break;
    }

    draw_axis();
    draw_objects();

    // Pasar OpenGL a modo render
    Hits = glRenderMode (GL_RENDER);

    // mostrar contenido de la pila
    cout << "Hits: " << Hits << endl;


    for(int i = 0; i < Hits; i++){
        cout << "Numero: " << Selection_buffer[i*4] << endl;
        cout << "Min Z: " << Selection_buffer[i*4+1] << endl;
        cout << "Max Z: " << Selection_buffer[i*4+2] << endl;
        cout << "Nombre en la pila: " << Selection_buffer[i*4+3] << endl;
    }


    // De todos los hits queremos seleccionar el que tenga Z menor (mas cercano).

    float z, z_min = INFINITY;
    int seleccionado = -1;

    for(int i = 0; i < Hits; i++){
        if(Selection_buffer[i*4] != 0){
            z = Selection_buffer[i*4 + 1];   //Z minima del objeto.
            if(z < z_min){
                seleccionado = Selection_buffer[i*4+3];  //nombre del elemento en la pila.
                z_min = z;
            }
        }

    }


    if(Hits > 0){

        switch(seleccionado){
            case 1: if(objeto_seleccionado != 1){if(mover_camara){VPN[0] = -4.5;VPN[1] = 6; VPN[2] = 0;} objeto_seleccionado = 1;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 2: if(objeto_seleccionado != 2){if(mover_camara){VPN[0] = -1.5;VPN[1] = 6; VPN[2] = 0;} objeto_seleccionado = 2;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 3: if(objeto_seleccionado != 3){if(mover_camara){VPN[0] = 1.5;VPN[1] = 6; VPN[2] = 0;} objeto_seleccionado = 3;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 4: if(objeto_seleccionado != 4){if(mover_camara){VPN[0] = 4.5;VPN[1] = 6; VPN[2] = 0;} objeto_seleccionado = 4;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 5: if(objeto_seleccionado != 5){if(mover_camara){VPN[0] = -4.5;VPN[1] = 2; VPN[2] = 0;} objeto_seleccionado = 5;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 6: if(objeto_seleccionado != 6){if(mover_camara){VPN[0] = -1.5;VPN[1] = 2; VPN[2] = 0;} objeto_seleccionado = 6;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 7: if(objeto_seleccionado != 7){if(mover_camara){VPN[0] = 1.5;VPN[1] = 2; VPN[2] = 0;} objeto_seleccionado = 7;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 8: if(objeto_seleccionado != 8){if(mover_camara){VPN[0] = 4.5;VPN[1] = 2; VPN[2] = 0;} objeto_seleccionado = 8;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 9: if(objeto_seleccionado != 9){if(mover_camara){VPN[0] = -4.5;VPN[1] = -2; VPN[2] = 0;} objeto_seleccionado = 9;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 10: if(objeto_seleccionado != 10){if(mover_camara){VPN[0] = -1.5;VPN[1] = -2; VPN[2] = 0;} objeto_seleccionado = 10;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 11: if(objeto_seleccionado != 11){if(mover_camara){VPN[0] = 1.5;VPN[1] = -2; VPN[2] = 0;} objeto_seleccionado = 11;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 12: if(objeto_seleccionado != 12){if(mover_camara){VPN[0] = 4.5;VPN[1] = -2; VPN[2] = 0;} objeto_seleccionado = 12;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 13: if(objeto_seleccionado != 13){if(mover_camara){VPN[0] = -4.5;VPN[1] = -6; VPN[2] = 0;} objeto_seleccionado = 13;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 14: if(objeto_seleccionado != 14){if(mover_camara){VPN[0] = -1.5;VPN[1] = -6; VPN[2] = 0;} objeto_seleccionado = 14;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 15: if(objeto_seleccionado != 15){if(mover_camara){VPN[0] = 1.5;VPN[1] = -6; VPN[2] = 0;} objeto_seleccionado = 15;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        case 16: if(objeto_seleccionado != 16){if(mover_camara){VPN[0] = 4.5;VPN[1] = -6; VPN[2] = 0;} objeto_seleccionado = 16;}else{VPN[0] = 0;VPN[1] = 0; VPN[2] = 0; objeto_seleccionado = 0;} break;
        }
    }
    else{
        objeto_seleccionado = 0;
        VPN[0] = 0;
        VPN[1] = 0;
        VPN[2] = 0;
    }

    switch(camara_actual){
        case 0: camaras_perspectiva[n_camara_perspectiva].cambiarObjetivo(VPN[0],VPN[1],VPN[2]);break;
        case 1: camaras_ortogonales[n_camara_ortogonal].cambiarObjetivo(VPN[0],VPN[1],VPN[2]);break;
    }

    // Dibujar la escena
    draw_scene();
}
