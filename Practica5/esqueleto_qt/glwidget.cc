//**************************************************************************
//
// Domingo Martin Perandres© 2014-2017
// http://calipso.ugr.es/dmartin
// dmartin@ugr.es
//
// GPL
//**************************************************************************

#include "glwidget.h"
#include <QPainter>
#include <QPaintEngine>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QCoreApplication>
#include <math.h>
#include "GL/glu.h"

//#include"GL/glu_mangle.h"


#include "window.h"


float aux= 0;

// COMPONENTES DE LUCES BLANCAS
GLfloat light_ambient[]  = { 0.1f, 0.1f, 0.1f, 1.0f };  // 10%
GLfloat light_diffuse[]  = { 0.7f, 0.7f, 0.7f, 1.0f };  // 70%
GLfloat light_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };  // 20%

using namespace std;
using namespace _gl_widget_ne;

_gl_widget::_gl_widget(_window *Window1, Interfaz *interfaz):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
  object=Cubo();                           // Cubo por defecto

  timer = new QTimer(this);                               // inicializacion del QTimer
  connect(timer,SIGNAL(timeout()),this,SLOT(animar()));

  timer_interfaz = new QTimer(this);
  connect(timer_interfaz,SIGNAL(timeout()),this,SLOT(updateInterfaz()));

  this->interfaz = interfaz;
  this->interfaz->show();
  this->interfaz->move(870,120);

// Inicializacion de Material Vacio

  mat_ambient[0] = 1.0;
  mat_ambient[1] = 1.0;
  mat_ambient[2] = 1.0;
  mat_ambient[3] = 1.0;

  mat_diffuse[0] = 1.0;
  mat_diffuse[1] = 1.0;
  mat_diffuse[2] = 1.0;
  mat_diffuse[3] = 1.0;

  mat_especular[0] = 1.0;
  mat_especular[1] = 1.0;
  mat_especular[2] = 1.0;
  mat_especular[3] = 1.0;

  shininess = 0.6 * 128.0;

  vacio = Material(mat_ambient,mat_diffuse,mat_especular,shininess);

  timer_interfaz->start(0);
}

//*************************************************************************
//
//*************************************************************************

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{

    switch(Keyevent->key()){
      case Qt::Key_Left:coordx-=0.5;break;
      case Qt::Key_Right:coordx+=0.5;break;
      case Qt::Key_Up:coordz-=0.5;break;
      case Qt::Key_Down:coordz+=0.5;break;
      case Qt::Key_PageUp:Observer_distance*=1.2;break;
      case Qt::Key_PageDown:Observer_distance/=1.2;break;
      case Qt::Key_0: interfaz->raise();break;
      case Qt::Key_7 : camara1.zoom_orto = camara1.zoom_orto-0.5;break;
      case Qt::Key_8 : camara1.zoom_orto = camara1.zoom_orto+0.5;break;
    }
    camara1.setObserver_angle_x(Observer_angle_x);
    camara1.setObserver_angle_y(Observer_angle_y);
    camara1.setObserver_distance(Observer_distance);
    update();
}

void _gl_widget::mouseMoveEvent(QMouseEvent *Mouseevent)
{
    if(Mouseevent->buttons() == Qt::LeftButton){
        //cout << Mouseevent->localPos().x() << " " << Mouseevent->localPos().y() << endl;
       // if(Mouseevent->localPos().x() > origen_raton_x){
        //    cout << "positivo";
       // Observer_angle_y+=ANGLE_STEP;
       // }
       // else Observer_angle_y-=ANGLE_STEP;

        /*
        if(Mouseevent->localPos().y()>origen_raton_y)
            Observer_angle_x+=ANGLE_STEP;
        else Observer_angle_x-=ANGLE_STEP;
        */

        Observer_angle_y += (Mouseevent->localPos().x()-x_ant);
        Observer_angle_x += (Mouseevent->localPos().y()-y_ant);
        x_ant=Mouseevent->localPos().x();
        y_ant=Mouseevent->localPos().y();

        camara1.setObserver_angle_x(Observer_angle_x);
        camara1.setObserver_angle_y(Observer_angle_y);
    }
    camara1.setObserver_angle_x(Observer_angle_x);
    camara1.setObserver_angle_y(Observer_angle_y);
//cout << x_ant << " , " << y_ant << endl;
    Mouseevent->accept();
    update();
}

void _gl_widget::mousePressEvent(QMouseEvent *Mouseevent)
{

    x_ant = Mouseevent->localPos().x();
    y_ant = Mouseevent->localPos().y();


    if(Mouseevent->buttons() == Qt::RightButton){
        pick(x_ant,y_ant,3,3);
    }


     Mouseevent->accept();
}

void _gl_widget::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0)
    Observer_distance += 1;
    else Observer_distance -= 1;


    camara1.setObserver_distance(Observer_distance);
    update();
}


void _gl_widget::pick(unsigned int x, unsigned int y, unsigned int Width, unsigned int Height)
{
  GLuint Selection_buffer[100] = {0};
  GLint Hits, Viewport[4];

  glViewport(0,0,this->width(),this->height());
  glGetIntegerv (GL_VIEWPORT, Viewport);

  glSelectBuffer (100, Selection_buffer);
  glRenderMode (GL_SELECT);
  glInitNames();
  glPushName(0);

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPickMatrix(x,Viewport[3]-y,Width,Height,Viewport);
  cout << "pickeando" <<endl;

    float relacion_aspecto = (this->size().width()*1.0)/(this->size().height()*1.0);
    glFrustum(X_MIN*relacion_aspecto,X_MAX*relacion_aspecto,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);

    float* a = camara1.getVPN();
    camara1.change_observer();
    gluLookAt(a[0],a[1],a[2],a[0],a[1],a[2]-1,0,1,0);
   // camara1.change_projection();
//    change_projection();
    //glMatrixMode(GL_MODELVIEW);
  //glLoadIdentity();
  //glTranslatef(0,0,-Observer_distance);
  //cout << Observer_angle_x;
  //cout << Observer_angle_y;

  //  clear_window();
   // change_projection();
   // change_observer();
   // glPushName(1);
    draw_axis();
    draw_objects();


  /*
  Draw(){
    Limpiar_ventana();
    Cambiar_proyeccion(); // PROJECTION
    Cambiar_observador(); // MODELVIEW
    Dibujar_escena();
  }
  */
  Hits = glRenderMode (GL_RENDER);
  cout << "Hits: " << Hits << endl;
if (Hits>0){
  // Obtener información de la selección y marcar el objeto seleccionado
    for(int i=0; i < Hits; i++){

    cout << "Numero en pila: " << Selection_buffer[(i*4)+0] <<endl;
    cout << "Minima z: " << Selection_buffer[(i*4)+1] <<endl;
    cout << "Maxima z: " << Selection_buffer[(i*4)+2] <<endl;
    cout << "Nombre: "<< Selection_buffer[(i*4)+3] <<endl;

    }
    cout << endl;

    float z_min = INFINITY;
    int seleccionado=0;
    float z_actual=z_min;

    for(int i=0; i < Hits ; i++){
        z_actual = Selection_buffer[i*4 +1];
        if(z_actual < z_min){
            z_min=z_actual;
            seleccionado = Selection_buffer[i*4 +3];
        }
    }

    cout << "Seleccionado: " << seleccionado << endl;
    //float vpn[3] = {0,0,0};
    if(seleccionado == 1){
        if(!cubo_seleccionado){
        camara1.changeVPN(2,0,0);
        cubo_seleccionado=true;
        aux = -2;
        esfera_seleccionado=false;
        }
      //  else{
     //   camara1.changeVPN(0,0,0);
     //   cubo_seleccionado=false;
     //   aux = 0;


    }else if(seleccionado == 2){
        if(!esfera_seleccionado){
        camara1.changeVPN(0,0,0);
        cubo_seleccionado=false;
        esfera_seleccionado=true;
        aux = -2;
        }
        else{
        camara1.changeVPN(0,0,0);
        cubo_seleccionado=false;
        aux = 0;
        }

    }


  }
else {
    cout << "No choca" << endl
          ;
}
  // volver a dibujar la escena pero teniendo en cuenta si hay algún objeto seleccionado
clear_window();
 change_projection();
//change_observer();
// glPushName(1);
draw_axis();
draw_objects();
//update();
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
  //glMatrixMode(GL_PROJECTION);
  //glLoadIdentity();


  float relacion_aspecto = (this->size().width()*1.0)/(this->size().height()*1.0);
  camara1.setRelacion_de_aspecto(relacion_aspecto);
  camara1.change_projection();

  //glFrustum(X_MIN*relacion_aspecto,X_MAX*relacion_aspecto,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void _gl_widget::change_observer()
{
  // posicion del observador
  camara1.change_observer();
    /*
    glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
*/
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

    if(escena){
        object = Cubo();
        glLoadName(1);
        glPushMatrix();
        glTranslatef(2,0,0);
        if(vertex)
            object.drawPoints();
        if(lines)
            object.drawLines();
        if(fill)
            object.drawFill();
        if(chest)
            object.drawAjedrez();
        glPopMatrix();

        object_revolucion = Esfera(40,360);
        glLoadName(2);
        if(vertex)
            object_revolucion.drawPoints();
        if(lines)
            object_revolucion.drawLines();
        if(fill)
            object_revolucion.drawFill();
        if(chest)
            object_revolucion.drawAjedrez();

        //ply_escena = PLY_Object(urlPly);
        glLoadName(3);
        glPushMatrix();
        glTranslatef(-2,0,0);
        glScalef(0.2,0.2,0.2);
        if(vertex)
            ply_escena.drawPoints();
        if(lines)
            ply_escena.drawLines();
        if(fill)
            ply_escena.drawFill();
        if(chest)
            ply_escena.drawAjedrez();
        glPopMatrix();



    }else{


             luz_posicional.transformar(angulo_luz_y_posicional,angulo_luz_x_posicional,distancia_luz_posicional);
             luz_infinito.transformar(angulo_luz_y_infinito,angulo_luz_x_infinito,distancia_luz_posicional);



             //INICIALIZACION DE LUCES

             glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
             glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
             glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

             glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient);
             glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse);
             glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);

            // Activador de luz en infinito

            if(interfaz->getEstadoLuzInfinito())
                luz_infinito.enable();
            else luz_infinito.disable();

            // Activador de luz en punto

            if(interfaz->getEstadoLuzPosicional())
                luz_posicional.enable();
            else luz_posicional.disable();


            if(planeta_tierra){

                if(tierra_cargada){
                    if(vertex){
                        tierra.drawPoints();
                    }
                    if(lines){
                        tierra.drawLines();
                    }
                    if(fill){
                        tierra.drawFill();
                    }
                    if(chest){
                        tierra.drawAjedrez();
                    }

                    if(fill_flat_ilu)
                        tierra.drawFillIluminado(vacio,interfaz->getLightning());
                    if(fill_smooth_ilu)
                        tierra.drawFillIluminadoSuave(vacio,interfaz->getLightning());
                    if(!textura_con_iluminacion){
                        tierra.drawTextura();
                    }
                }
            }
            else{
                if(textura){
                    if(vertex)
                        marcoTextura.drawPoints();
                    if(lines)
                        marcoTextura.drawNormalesCaras();
                    if(fill)
                        marcoTextura.drawFill();
                    if(chest)
                        marcoTextura.drawAjedrez();
                    if(modotextura){
                        if(fill_flat_ilu)
                            marcoTextura.drawFillIluminado(porcion_textura,porcion_marco,mater,interfaz->getLightning());
                        if(fill_smooth_ilu)
                            marcoTextura.drawFillIluminadoSuave(porcion_textura,porcion_marco,mater,interfaz->getLightning());
                        if(!textura_con_iluminacion)
                            marcoTextura.drawTextura(porcion_textura,porcion_marco);
                    }
                    else{
                        if(fill_flat_ilu)
                            marcoTextura.drawFillIluminado(mater,interfaz->getLightning());
                        if(fill_smooth_ilu)
                            marcoTextura.drawFillIluminadoSuave(mater,interfaz->getLightning());
                        //if(!textura_con_iluminacion)
                        //    marcoTextura.drawTextura(porcion_textura,porcion_marco);
                    }
                }

                else{
                    if(objeto_complejo){
                        if(vertex)
                            watt_regulator.draw(0,angle,velocidad);
                        if(lines)
                           watt_regulator.draw(1,angle,velocidad);
                        if(fill)
                            watt_regulator.draw(2,angle,velocidad);
                        if(chest)
                            watt_regulator.draw(3,angle,velocidad);
                    }
                    else{

                        if(!revolucion){
                            //glLoadName(1);
                            if(vertex)
                                object.drawPoints();
                            if(lines)
                                object.drawLines();
                            if(fill)
                                object.drawFill();
                            if(chest)
                                object.drawAjedrez();
                            if(fill_flat_ilu)
                                object.drawFillIluminado(mater,interfaz->getLightning());
                            if(fill_smooth_ilu)
                                object.drawFillIluminadoSuave(mater,interfaz->getLightning());
                        }
                        else {
                            if(ply_bool){
                                if(vertex)
                                    ply.drawPoints();
                                if(lines)
                                    ply.drawLines();
                                if(fill)
                                    ply.drawFill();
                                if(chest)
                                    ply.drawAjedrez();
                                if(fill_smooth_ilu)
                                    ply.drawFillIluminadoSuave(mater,interfaz->getLightning());
                                if(fill_flat_ilu)
                                    ply.drawFillIluminado(mater,interfaz->getLightning());
                            }
                            else{
                                if(vertex)
                                    object_revolucion.drawPoints();
                                if(lines)
                                    object_revolucion.drawLines();
                                if(fill)
                                    object_revolucion.drawFill();
                                if(chest)
                                    object_revolucion.drawAjedrez();
                                if(fill_flat_ilu)
                                    object_revolucion.drawFillIluminado(mater,interfaz->getLightning());
                                if(fill_smooth_ilu)
                                    object_revolucion.drawFillIluminadoSuave(mater,interfaz->getLightning());
                            }
                        }
                    }
                }
            }
          /*  glPointSize(6);

            glBegin(GL_LINES);
            glColor3f(1,0,0);

                glVertex3f(coordx-0.15,0,coordz);
                glVertex3f(coordx+0.15,0,coordz);

                glVertex3f(coordx,0,coordz-0.15);
                glVertex3f(coordx,0,coordz+0.15);

                glVertex3f(coordx,-0.15,coordz);
                glVertex3f(coordx,+0.15,coordz);
            glEnd();
        */
    }
}


// Funcion que activa y desactiva el timer, es decir, activa y desactiva la animacion

void _gl_widget::timers()
{
    if(!timer->isActive()){

        timer->start(10);
    }
    else timer->stop();
}


// Funcion que activa la animacion, haciendo que el watt regulator vaya girando acorde a la velocidad seleccionada con las teclas

void _gl_widget::animar()
{
    cout << "activa";
    angle+=velocidad/10;
    update();
}

/*********************************
 * Funcion que actualiza interfaz
 * *******************************/


void _gl_widget::updateInterfaz()
{

    // PRACTICA 5
    modo_proyeccion = interfaz->getModoProyeccion();
    //camara_seleccionada = interfaz->getCamaraSeleccionada();

    camara1.setModoProyeccion(modo_proyeccion);

    //


    // Figura que va a pintarse
    int figura = interfaz->getFigura();

    // Variables de modo de dibujado

    vertex = interfaz->getPuntos();
    lines = interfaz->getLineas();
    fill = interfaz->getRelleno();
    chest = interfaz->getAjedrez();
    fill_flat_ilu = interfaz->getRellenoIluminacionPlana();
    fill_smooth_ilu = interfaz->getRellenoIluminacionSuave();

    // Variable de estado de iluminacion
    lighting = interfaz->getLightning();

    // Posicion luz infinito
    angulo_luz_y_infinito=interfaz->getAnguloLuzInfinito();
    angulo_luz_x_infinito = interfaz->getAnguloLuzXInfinito();

    // Posicion luz en un punto
    angulo_luz_y_posicional=interfaz->getAnguloLuzPosicional();
    angulo_luz_x_posicional = interfaz->getAnguloLuzXPosicional();
    distancia_luz_posicional = interfaz->getDistanciaLuzPosicional();

    // Path de la textura para la tierra.
    path_tierra = interfaz->getPathTierra();


    // Indica si hay que construir el objeto tierra
    cargar_tierra = interfaz->getCargarTierra();

    // Divisiones del marco
    divisiones=interfaz->getDivisiones();

    // Modo textura ?
    modotextura = interfaz->getModoText();

    // Porcion de textura y marco.
    porcion_textura = interfaz->getPuntosTextura();
    porcion_marco=interfaz->getPuntosMarco();

    // Indica si se va a pintar la textura junto a iluminación
    textura_con_iluminacion = interfaz->getTexturaConIlu();

    // tamaño de marco
    ancho_marco = interfaz->getAnchoMarco();
    alto_marco = interfaz->getAltoMarco();

    // path textura de marco
    path_textura = interfaz->getPathTextura();

    // indica si hay que cargar la textura de nuevo
    cargar_textura = interfaz->getCargarTextura();

    // indica el material a usar.
    material=interfaz->getMaterial();

    // Eleccion del material

    switch(material)
    {
        case 0: mat_ambient[0] = 0.24725;
            mat_ambient[1] = 0.1995;
            mat_ambient[2] = 0.0745;
            mat_ambient[3] = 1.0;

            mat_diffuse[0] = 0.75164;
            mat_diffuse[1] = 0.60648;
            mat_diffuse[2] = 0.22648;
            mat_diffuse[3] = 1.0;

            mat_especular[0] = 0.628281;
            mat_especular[1] = 0.555802;
            mat_especular[2] = 0.366065;
            mat_especular[3] = 1.0;

            shininess = 0.4 * 128.0;
            break;
        case 1:
            mat_ambient[0] = 0.0215;
            mat_ambient[1] = 0.1745	;
            mat_ambient[2] = 0.0215;
            mat_ambient[3] = 1.0;

            mat_diffuse[0] = 0.07568;
            mat_diffuse[1] = 0.61424;
            mat_diffuse[2] = 0.07568;
            mat_diffuse[3] = 1.0;

            mat_especular[0] = 0.633;
            mat_especular[1] = 0.727811;
            mat_especular[2] = 0.633;
            mat_especular[3] = 1.0;

            shininess = 0.9 * 128.0;
            break;
        case 2:mat_ambient[0] = 1.0;
            mat_ambient[1] = 1.0;
            mat_ambient[2] = 1.0;
            mat_ambient[3] = 1.0;

            mat_diffuse[0] = 1.0;
            mat_diffuse[1] = 1.0;
            mat_diffuse[2] = 1.0;
            mat_diffuse[3] = 1.0;

            mat_especular[0] = 1.0;
            mat_especular[1] = 1.0;
            mat_especular[2] = 1.0;
            mat_especular[3] = 1.0;

            shininess = 0.4 * 128.0;
            break;

        case 3:mat_ambient[0] = 0.05;
            mat_ambient[1] = 0.0;
            mat_ambient[2] = 0.0;
            mat_ambient[3] = 1.0;

            mat_diffuse[0] = 0.5;
            mat_diffuse[1] = 0.4;
            mat_diffuse[2] = 0.4;
            mat_diffuse[3] = 1.0;

            mat_especular[0] = 0.7;
            mat_especular[1] = 0.04;
            mat_especular[2] = 0.04;
            mat_especular[3] = 1.0;

            shininess = 0.078125 * 128.0;
            break;
    }

    mater = Material(mat_ambient,mat_diffuse,mat_especular,shininess);

    // Secciones y angulo de objetos de revolución
    int secciones = interfaz->getSecciones();
    int angulo = interfaz->getAngulo();

    // Path de ply
    string urlPlyWatt = interfaz->getUrlPly();

    if(urlPlyWatt != url_ply_watt_anterior)
        figura_anterior=0;
    url_ply_watt_anterior = urlPlyWatt;

    urlPly = interfaz->getUrlPly_2();

    if(urlPly != url_ply_anterior)
        figura_anterior=0;
    url_ply_anterior = urlPly;


    if((figura != figura_anterior)|| (figura!=9 && figura !=55 && figura !=81 ))
    switch(figura)
    {
    case 1: object = Cubo();revolucion=false;ply_bool=false;objeto_complejo= false;textura=false;planeta_tierra=false;escena = false;break;
    case 2: object = Tetraedro();revolucion=false;ply_bool=false;objeto_complejo= false;textura=false;planeta_tierra=false;escena = false;break;
    case 3: object_revolucion = Esfera(secciones,angulo); revolucion=true; ply_bool=false;objeto_complejo= false;textura=false; planeta_tierra=false;escena = false;break;
    case 4: object_revolucion = Cilindro(secciones,angulo); revolucion=true; ply_bool=false;objeto_complejo= false;textura=false;planeta_tierra=false;escena = false; break;
    case 5: object_revolucion = Tubo(secciones,angulo); revolucion=true; ply_bool=false;objeto_complejo= false;textura=false;planeta_tierra=false; escena = false;break;
    case 6: object_revolucion = Vaso(secciones,angulo); revolucion=true; ply_bool=false;objeto_complejo= false; textura=false;planeta_tierra=false;escena = false;break;
    case 7: object_revolucion = Vaso_Invertido(secciones,angulo); revolucion=true; ply_bool=false;objeto_complejo= false; textura=false;planeta_tierra=false;escena = false;break;
    case 8: object_revolucion = Cono(secciones,angulo); revolucion=true; ply_bool=false;objeto_complejo= false; textura=false;planeta_tierra=false;escena = false;break;
    case 9: watt_regulator= WattRegulator(urlPlyWatt); revolucion=false; ply_bool=false;objeto_complejo=true;textura=false; planeta_tierra=false;escena = false;break;
    case 10: if(cargar_textura){marcoTextura = marco(divisiones,ancho_marco,alto_marco);marcoTextura.cargarImagen(path_textura);}textura=true;planeta_tierra=false;escena = false;break;
    case 11: if(cargar_tierra){tierra = EsferaTexturizada(secciones,360,1.0);tierra_cargada=true;tierra.cargarImagen(path_tierra);}planeta_tierra=true;escena = false;break;
    case 55:ply.read_ply(urlPly); revolucion=true; ply_bool=true;objeto_complejo= false;textura=false;planeta_tierra=false;escena = false;break;
    case 81: if(ply_escena.vertices.size() == 0)ply_escena = PLY_Object(urlPly);  escena = true; break;
    }

    figura_anterior=figura;

    velocidad=interfaz->getVelocidad();

    if(interfaz->Animacion()){
         angle+=velocidad/10;
    }
    else{
        angle=interfaz->getAnguloObjetoComplejo();
    }

    update();
}


//*************************************************************************
//
//*************************************************************************

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
 // float a[3] = {2,0,0};
 // camara1.changeVPN(a);
  camara1.changeLookAt();
  // lookat
  //cout << coordx << " " << coordz << " " << vpn_x << " " << vpn_y << endl;


  //gluLookAt(coordx,0,coordz,coordx + vpn_x,vpn_y,coordz-1,0,1,0);


  // gluLookAt(coordx + vpn_x,vpn_y,coordz-1,coordx,0,coordz,0,1,0);
 //cout << coordx << " " << coordz << endl;
 // resizeGL(this->width(),this->height());
  draw_axis();
  draw_objects();
}

//*************************************************************************
//
//*************************************************************************

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
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
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

}

