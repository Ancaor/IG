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


#include "window.h"

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
 // this->interfaz->




  mat_ambient[0] = 1.0;
          mat_ambient[1] = 1.0;
          mat_ambient[2] = 1.0;
          mat_ambient[3] = 1.0;
          //mat_ambient  (0.24725,0.1995,0.0745,1.0;
        //  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat);
          mat_diffuse[0] = 1.0;
          mat_diffuse[1] = 1.0;
          mat_diffuse[2] = 1.0;
          mat_diffuse[3] = 1.0;
          //glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat);
          mat_especular[0] = 1.0;
          mat_especular[1] = 1.0;
          mat_especular[2] = 1.0;
          mat_especular[3] = 1.0;
        //  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
       //  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.4 * 128.0);
          shininess = 0.6 * 128.0;

          vacio = Material(mat_ambient,mat_diffuse,mat_especular,shininess);






  timer_interfaz->start(0);
}

//*************************************************************************
//
//*************************************************************************

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  if(Keyevent->modifiers() == Qt::ShiftModifier){ // Composiciones de teclas SHIFT+TECLA
      switch(Keyevent->key()){
     // case Qt::Key_N:if((velocidad-1) >=0) velocidad-=1; if(timer->isActive())angle+=velocidad/10;break;  // Disminuye la velocidad de giro ( TIENE UN TOPE DE VELOCIDAD )
     // case Qt::Key_B:angle+=(-1); // Gira el regulador de watt en sentido horario
      }

  }else
      switch(Keyevent->key()){
      case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
      case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
      case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
      case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
      case Qt::Key_PageUp:Observer_distance*=1.2;break;
      case Qt::Key_PageDown:Observer_distance/=1.2;break;
      case Qt::Key_0: interfaz->raise();break;
     // case Qt::Key_F:
//      case Qt::Key_P: if(!vertex)vertex = 1; else vertex=0;break; // pinta puntos
  //    case Qt::Key_L: if(!lines)lines = 1; else lines=0;break; // pinta aristass
    //  case Qt::Key_F: if(!fill)fill = 1;else fill=0;break; // pinta caras
    //  case Qt::Key_C: if(!chest)chest = 1;else chest=0;break; // pinta ajedrez

      //case Qt::Key_1: object = Tetraedro();revolucion=false;ply_bool=false;objeto_complejo= false;break;
      //case Qt::Key_2: object = Cubo();revolucion=false;ply_bool=false;objeto_complejo= false;break;

      //case Qt::Key_3: ply.read_ply(); revolucion=true; ply_bool=true;break;
/*
      case Qt::Key_4: object_revolucion = Tubo(40); revolucion=true; ply_bool=false;objeto_complejo= false; break;
      case Qt::Key_5: object_revolucion = Cilindro(40); revolucion=true; ply_bool=false;objeto_complejo= false; break;
      case Qt::Key_6: object_revolucion = Vaso(40); revolucion=true; ply_bool=false;objeto_complejo= false; break;
      case Qt::Key_7: object_revolucion = Vaso_Invertido(40); revolucion=true; ply_bool=false;objeto_complejo= false; break;
      case Qt::Key_8: object_revolucion = Cono(40); revolucion=true; ply_bool=false;objeto_complejo= false; break;
      case Qt::Key_9: object_revolucion = Esfera(40); revolucion=true; ply_bool=false;objeto_complejo= false; break;

*/
          /*Teclas PRACTICA 3*/

      //case Qt::Key_N:if(velocidad+1 <=100) velocidad+=1; if(timer->isActive()) angle+=velocidad/10;break;  // Aumenta velocidad de giro ( TIENE UN TOPE DE VELOCIDAD )
      //case Qt::Key_B: angle+=1; break;     // Gira el regulador de watt en sentido anti-horario.
      //case Qt::Key_A: timers(); break;     // Activa / Desactiva la animacion
      //case Qt::Key_W: watt_regulator=new WattRegulator(); objeto_complejo=true;  // Activa e inicializa el Watt Regulattor

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

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  //  Front_plane>0  Back_plane>PlanoDelantero)
  //cout << this->size().width()<<" "<<this->size().height()<<endl;
  //cout << this->parentWidget()->size().width()<<" "<<this->parentWidget()->parentWidget()->parentWidget()->size().height()<<endl;
  float relacion_aspecto = (this->size().width()*1.0)/(this->size().height()*1.0);
  //float r = (this->size().height()*(X_MAX-X_MIN)*1.0)/(this->size().width()*1.0);

  glFrustum(X_MIN*relacion_aspecto,X_MAX*relacion_aspecto,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
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
     luz_posicional.transformar(angulo_luz_y_posicional,angulo_luz_x_posicional,distancia_luz_posicional);
     luz_infinito.transformar(angulo_luz_y_infinito,angulo_luz_x_infinito,distancia_luz_posicional);
  //  const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
  //  glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse);
     //INICIALIZACION DE LUCES

      GLfloat light_ambient[]  = { 0.1f, 0.1f, 0.1f, 1.0f };  // 10%
      GLfloat light_diffuse[]  = { 0.7f, 0.7f, 0.7f, 1.0f };  // 70%
      GLfloat light_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };  // 20%

     glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
     glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
     glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

     glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient);
     glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse);
     glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
   // if(interfaz->getLightning())
    //    glEnable(GL_LIGHTING);

    if(interfaz->getEstadoLuzInfinito())
        luz_infinito.enable();
    else luz_infinito.disable();

    if(interfaz->getEstadoLuzPosicional())
        luz_posicional.enable();
    else luz_posicional.disable();

    if(planeta_tierra){
        if(tierra_cargada){
            if(vertex){
                tierra.drawPoints();
                //estrellas.drawPoints();
            }
            if(lines){
                //estrellas.drawLines();
                tierra.drawLines();
            }
            if(fill){
                //estrellas.drawFill();
                tierra.drawFill();
            }
            if(chest){
                //estrellas.drawAjedrez();
                tierra.drawAjedrez();
            }

            if(fill_flat_ilu)
                tierra.drawFillIluminado(path_tierra,cargar_tierra,vacio,interfaz->getLightning());
            if(fill_smooth_ilu)
                tierra.drawFillIluminadoSuave(path_tierra,cargar_tierra,vacio,interfaz->getLightning());
               // tierra.drawNormalesCaras();
                // if(fill_smooth_ilu)
             //   tierra.drawFillIluminadoSuave(porcion_textura,porcion_marco,mater,interfaz->getLightning());
            if(!textura_con_iluminacion){

               // glMatrixMode(GL_MODELVIEW);
                tierra.drawTextura(path_tierra,cargar_tierra);
            }
        }

    }
    else{
        if(textura){
            if(vertex)
                marcoTextura.drawPoints();
            if(lines)
                marcoTextura.drawLines();
            if(fill)
                marcoTextura.drawFill();
            if(chest)
                marcoTextura.drawAjedrez();
            if(fill_flat_ilu)
                marcoTextura.drawFillIluminado(porcion_textura,porcion_marco,mater,interfaz->getLightning());
            if(fill_smooth_ilu)
                marcoTextura.drawFillIluminadoSuave(porcion_textura,porcion_marco,mater,interfaz->getLightning());
            if(!textura_con_iluminacion)
                marcoTextura.drawTextura(porcion_textura,porcion_marco);   // nunca se activa   revisar variables
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
                        object.drawFillIluminadoSuave(mater,interfaz->getLightning());//mat_ambient,mat_diffuse,mat_especular,shininess);

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
                            ply.drawFillIluminadoSuave(mater,interfaz->getLightning());//,luz_infinito,luz_posicional);
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
                            object_revolucion.drawFillIluminadoSuave(mater,interfaz->getLightning());//,luz_infinito,luz_posicional);//mat_ambient,mat_diffuse,mat_especular,shininess);
                    }
                }
            }
        }
    }
    //glDisable(GL_LIGHTING);
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

void _gl_widget::updateInterfaz()
{
    int figura = interfaz->getFigura();
    vertex = interfaz->getPuntos();
    lines = interfaz->getLineas();
    fill = interfaz->getRelleno();
    chest = interfaz->getAjedrez();
    fill_flat_ilu = interfaz->getRellenoIluminacionPlana();
    fill_smooth_ilu = interfaz->getRellenoIluminacionSuave();

    angulo_luz_y_infinito=interfaz->getAnguloLuzInfinito();
    angulo_luz_x_infinito = interfaz->getAnguloLuzXInfinito();

    lighting = interfaz->getLightning();

   // luz_infinito = Luz(interfaz->getLuz(),interfaz->getEstadoLuzInfinito());
  //  luz_infinito.transformar(angulo_luz,angulo_luz_x,distancia_luz);

    angulo_luz_y_posicional=interfaz->getAnguloLuzPosicional();
    angulo_luz_x_posicional = interfaz->getAnguloLuzXPosicional();
    distancia_luz_posicional = interfaz->getDistanciaLuzPosicional();

    //luz_posicional = Luz(interfaz->getLuz(),interfaz->getEstadoLuzPosicional());
   // luz_posicional.transformar(angulo_luz,angulo_luz_x,distancia_luz);

    cargar_estrellas = interfaz->getCargarEstrellas();

    path_tierra = interfaz->getPathTierra();
    path_estrellas = interfaz->getPathEstrellas();

    cargar_tierra = interfaz->getCargarTierra();
    pintar_tierra = interfaz->getPintarTierra();

    divisiones=interfaz->getDivisiones();
    porcion_textura = interfaz->getPuntosTextura();
    porcion_marco=interfaz->getPuntosMarco();

    textura_con_iluminacion = interfaz->getTexturaConIlu();

    ancho_marco = interfaz->getAnchoMarco();
    alto_marco = interfaz->getAltoMarco();

    path_textura = interfaz->getPathTextura();

    cargar_textura = interfaz->getCargarTextura();
    cout << cargar_textura << endl;
  //  cout << divisiones<< endl;

    //if(lighting)
      //  glEnable(GL_LIGHTING);
   // else
     //   glDisable(GL_LIGHTING);

    material=interfaz->getMaterial();

   // cout << lighting << endl;

    switch(material)
    {
    case 0: mat_ambient[0] = 0.24725;
        mat_ambient[1] = 0.1995;
        mat_ambient[2] = 0.0745;
        mat_ambient[3] = 1.0;
        //mat_ambient  (0.24725,0.1995,0.0745,1.0;
      //  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat);
        mat_diffuse[0] = 0.75164;
        mat_diffuse[1] = 0.60648;
        mat_diffuse[2] = 0.22648;
        mat_diffuse[3] = 1.0;
        //glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat);
        mat_especular[0] = 0.628281;
        mat_especular[1] = 0.555802;
        mat_especular[2] = 0.366065;
        mat_especular[3] = 1.0;
      //  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
     //  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.4 * 128.0);
        shininess = 0.4 * 128.0;
        break;
    case 1:
      // glEnable(GL_COLOR_MATERIAL);
        mat_ambient[0] = 0.0215;
        mat_ambient[1] = 0.1745	;
        mat_ambient[2] = 0.0215;
        mat_ambient[3] = 1.0;
        //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat);
        mat_diffuse[0] = 0.07568;
        mat_diffuse[1] = 0.61424;
        mat_diffuse[2] = 0.07568;
        mat_diffuse[3] = 1.0;
        //glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat);
        mat_especular[0] = 0.633;
        mat_especular[1] = 0.727811;
        mat_especular[2] = 0.633;
        mat_especular[3] = 1.0;
        //glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
        shininess = 0.9 * 128.0;
        // glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.6 * 128.0);
        break;
    case 2:mat_ambient[0] = 1.0;
        mat_ambient[1] = 1.0;
        mat_ambient[2] = 1.0;
        mat_ambient[3] = 1.0;
        //mat_ambient  (0.24725,0.1995,0.0745,1.0;
      //  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat);
        mat_diffuse[0] = 1.0;
        mat_diffuse[1] = 1.0;
        mat_diffuse[2] = 1.0;
        mat_diffuse[3] = 1.0;
        //glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat);
        mat_especular[0] = 1.0;
        mat_especular[1] = 1.0;
        mat_especular[2] = 1.0;
        mat_especular[3] = 1.0;
      //  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
     //  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.4 * 128.0);
        shininess = 0.4 * 128.0;
        break;

    case 3:mat_ambient[0] = 0.05	;
        mat_ambient[1] = 0.0;
        mat_ambient[2] = 0.0;
        mat_ambient[3] = 1.0;
        //mat_ambient  (0.24725,0.1995,0.0745,1.0;
      //  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat);
        mat_diffuse[0] = 0.5;
        mat_diffuse[1] = 0.4;
        mat_diffuse[2] = 0.4;
        mat_diffuse[3] = 1.0;
        //glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat);
        mat_especular[0] = 0.7;
        mat_especular[1] = 0.04;
        mat_especular[2] = 0.04;
        mat_especular[3] = 1.0;
      //  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
     //  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.4 * 128.0);
        shininess = 0.078125 * 128.0;
    }
  //  vacio = Material()
    mater = Material(mat_ambient,mat_diffuse,mat_especular,shininess);


  /*  if(fill_flat_ilu == false){
        //cout << "entra";
        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
    }
*/
    int secciones = interfaz->getSecciones();
    int angulo = interfaz->getAngulo();

    string urlPlyWatt = interfaz->getUrlPly();//"/home/ancaor/IG/PLY/modelos_ply/beethoven.ply";

    if(urlPlyWatt != url_ply_watt_anterior)
        figura_anterior=0;
    url_ply_watt_anterior = urlPlyWatt;

    string urlPly = interfaz->getUrlPly_2();//"/home/ancaor/IG/PLY/modelos_ply/beethoven.ply";

    if(urlPly != url_ply_anterior)
        figura_anterior=0;
    url_ply_anterior = urlPly;
  //  cout << figura;
    if((figura != figura_anterior)|| (figura!=9 && figura !=55 ))
    switch(figura)
    {
    case 1: object = Cubo();revolucion=false;ply_bool=false;objeto_complejo= false;textura=false;planeta_tierra=false;break;
    case 2: object = Tetraedro();revolucion=false;ply_bool=false;objeto_complejo= false;textura=false;planeta_tierra=false;break;
    case 3: object_revolucion = Esfera(secciones,angulo); revolucion=true; ply_bool=false;objeto_complejo= false;textura=false; planeta_tierra=false;break;
    case 4: object_revolucion = Cilindro(secciones,angulo); revolucion=true; ply_bool=false;objeto_complejo= false;textura=false;planeta_tierra=false; break;
    case 5: object_revolucion = Tubo(secciones,angulo); revolucion=true; ply_bool=false;objeto_complejo= false;textura=false;planeta_tierra=false; break;
    case 6: object_revolucion = Vaso(secciones,angulo); revolucion=true; ply_bool=false;objeto_complejo= false; textura=false;planeta_tierra=false;break;
    case 7: object_revolucion = Vaso_Invertido(secciones,angulo); revolucion=true; ply_bool=false;objeto_complejo= false; textura=false;planeta_tierra=false;break;
    case 8: object_revolucion = Cono(secciones,angulo); revolucion=true; ply_bool=false;objeto_complejo= false; textura=false;planeta_tierra=false;break;
    case 9: watt_regulator= WattRegulator(urlPlyWatt); revolucion=false; ply_bool=false;objeto_complejo=true;textura=false; planeta_tierra=false;break;
    case 10: if(cargar_textura){marcoTextura = marco(divisiones,ancho_marco,alto_marco);marcoTextura.cargarImagen(path_textura);}textura=true;planeta_tierra=false;break;
    case 11: if(cargar_tierra){tierra = EsferaTexturizada(secciones,360,1.0);tierra_cargada=true;tierra.cargarImagen(path_tierra);}/*if(pintar_tierra)*/planeta_tierra=true;/*else planeta_tierra=false;*/break;
    case 55:ply.read_ply(urlPly); revolucion=true; ply_bool=true;objeto_complejo= false;textura=false;planeta_tierra=false;break;
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

