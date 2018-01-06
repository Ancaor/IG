#include "interfaz.h"
#include "ui_interfaz.h"
#include <string>
#include <iostream>

Interfaz::Interfaz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Interfaz)
{
    ui->setupUi(this);
    modoProyeccion.resize(3);
    modoProyeccion[0]=1;
}

Interfaz::~Interfaz()
{
    delete ui;
}

int Interfaz::getPractica()
{
    return practica;
}

int Interfaz::getFigura()
{
    int aux;
    switch(practica)
    {
    case 1: return fig_pract1; break;
    case 2: return fig_pract2;break;
    case 3: return fig_pract3;break;
    case 4: return obj_textura; break;
    case 10: aux = cargar_ply; cargar_ply=0;return aux;break;
    case 11 : return tierra; break;
    case 80 : return escena; break;
    }
    return 0;
}

bool Interfaz::getPuntos()
{
    return puntos;
}

bool Interfaz::getLineas()
{
    return lineas;
}

bool Interfaz::getRelleno()
{
    return relleno;
}

bool Interfaz::getAjedrez()
{
    return ajedrez;
}

int Interfaz::getSecciones()
{
    return secciones;
}

int Interfaz::getAngulo()
{
    return angulo;
}

int Interfaz::getAnguloObjetoComplejo()
{
    return angulo_objeto_complejo;
}

int Interfaz::getVelocidad()
{
    return velocidad;
}

bool Interfaz::Animacion()
{
    return animacion;
}

std::__cxx11::string Interfaz::getUrlPly()
{
    return urlPly;
}

std::__cxx11::string Interfaz::getUrlPly_2()
{
    return urlPly_2;
}

bool Interfaz::getRellenoIluminacionPlana()
{
    return relleno_iluminacion_plana;
}

bool Interfaz::getRellenoIluminacionSuave()
{
    return relleno_iluminacion_suave;
}

int Interfaz::getAnguloLuzXInfinito()
{
    return angulo_luz_x_infinito;
}

double Interfaz::getDistanciaLuzPosicional()
{
    return distancia_luz_posicional;
}

int Interfaz::getAnguloLuzPosicional()
{
    return angulo_luz_posicional;
}

int Interfaz::getAnguloLuzXPosicional()
{
    return angulo_luz_x_posicional;
}

int Interfaz::getMaterial()
{
    return material;
}

bool Interfaz::getLightning()
{
    return lightning;
}

int Interfaz::getLuz()
{
    return luz;
}

int Interfaz::getDivisiones()
{
    return divisiones;
}

std::vector<float> Interfaz::getPuntosTextura()
{
    return puntos_textura;
}

std::vector<int> Interfaz::getPuntosMarco()
{
    return puntos_marco;
}

bool Interfaz::getTexturaConIlu()
{
    return textura_con_iluminacion;
}

bool Interfaz::getEstadoLuzPosicional()
{
    return estado_luz_posicional;
}

bool Interfaz::getEstadoLuzInfinito()
{
    return estado_luz_infinito;
}

float Interfaz::getAnchoMarco()
{
    return ancho_marco;
}

float Interfaz::getAltoMarco()
{
    return alto_marco;
}

std::__cxx11::string Interfaz::getPathTextura()
{
    return path_textura;
}

bool Interfaz::getCargarTextura()
{
    bool ctex = cargar_textura;
    cargar_textura=false;

    return ctex;
}

std::__cxx11::string Interfaz::getPathTierra()
{
    return path_tierra;
}

std::__cxx11::string Interfaz::getPathEstrellas()
{
    return path_estrellas;
}

bool Interfaz::getCargarTierra()
{
    bool aux = cargar_tierra;
    cargar_tierra=false;

    return aux;
}

bool Interfaz::getCargarEstrellas()
{
    bool aux = cargar_estrellas;
    cargar_estrellas=false;
    return aux;
}

bool Interfaz::getPintarTierra()
{
    return pintar_tierra;
}

bool Interfaz::getModoText()
{
    return modotext;
}

int Interfaz::getCamaraSeleccionada()
{
    return camara_selec;
}

bool Interfaz::getModoProyeccion()
{
    return modoProyeccion[camara_selec];
}

int Interfaz::getAnguloLuzInfinito()
{
    return angulo_luz_infinito;
}

void Interfaz::on_tabWidget_tabBarClicked(int index)
{
    switch(index)
    {
    case 0: practica=1; break;
    case 1: practica=2; break;
    case 2: practica=10; break;
    case 3: practica=3; break;
    case 5: practica=4; break;
    case 6: practica=11; break;
    case 7: practica =80; break;
    }
}

void Interfaz::on_checkBox_clicked()
{
    if(!puntos){
        puntos=true;
      //  ui->checkBox_7->setChecked(false);
      //  relleno_iluminacion_plana=false;
      //  ui->checkBox_6->setChecked(false);
      //  relleno_iluminacion_suave=false;
    }
    else
        puntos=false;
}

void Interfaz::on_checkBox_2_clicked()
{
    if(!lineas){
        lineas=true;
    //    ui->checkBox_7->setChecked(false);
    //    relleno_iluminacion_plana=false;
    //    ui->checkBox_6->setChecked(false);
    //    relleno_iluminacion_suave=false;
    }
    else
        lineas=false;
}

void Interfaz::on_checkBox_3_clicked()
{
    if(!relleno){
        relleno=true;
    /*    ui->checkBox_7->setChecked(false);
        relleno_iluminacion_plana=false;
        ui->checkBox_6->setChecked(false);
        relleno_iluminacion_suave=false;
    */
    }
    else
        relleno=false;
}

void Interfaz::on_checkBox_4_clicked()
{
    if(!ajedrez){
        ajedrez=true;
      //  ui->checkBox_7->setChecked(false);
      //  relleno_iluminacion_plana=false;
      //  ui->checkBox_6->setChecked(false);
      //  relleno_iluminacion_suave=false;
          ui->checkBox_3->setChecked(false);
          relleno=false;

    }
    else
        ajedrez=false;
}

void Interfaz::on_radioButton_clicked()
{
   fig_pract1=1;
}

void Interfaz::on_radioButton_2_clicked()
{
    fig_pract1=2;
}


void Interfaz::on_radioButton_3_clicked()
{
    fig_pract2=3;
}

void Interfaz::on_radioButton_4_clicked()
{
    fig_pract2=4;
}

void Interfaz::on_radioButton_5_clicked()
{
    fig_pract2=5;
}

void Interfaz::on_radioButton_6_clicked()
{
    fig_pract2=6;
}

void Interfaz::on_radioButton_7_clicked()
{
    fig_pract2=7;
}

void Interfaz::on_radioButton_8_clicked()
{
    fig_pract2=8;
}

void Interfaz::on_spinBox_valueChanged(int arg1)
{
    secciones = arg1;
}

void Interfaz::on_horizontalSlider_valueChanged(int value)
{
    angulo = value;
}

void Interfaz::on_pushButton_clicked()
{
    cargar_ply = 55;
}

void Interfaz::on_radioButton_9_clicked()
{
    fig_pract3=9;
}

void Interfaz::on_horizontalSlider_3_valueChanged(int value)
{
    velocidad=value;
}

void Interfaz::on_horizontalSlider_2_valueChanged(int value)
{
    angulo_objeto_complejo=value;
}

void Interfaz::on_checkBox_5_clicked()
{
    if(!animacion)
        animacion=true;
    else animacion=false;
}

void Interfaz::raise_dialog()
{
    this->raise();
}

void Interfaz::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(0,QString::fromStdString("Abrir PLY"), "/home", QString::fromStdString("Archivos PLY (*.ply)"));

    ui->lineEdit->setText(fileName);



}

void Interfaz::on_lineEdit_textChanged(const QString &arg1)
{
    urlPly = arg1.toStdString();
}

void Interfaz::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(0,QString::fromStdString("Abrir PLY"), "/home", QString::fromStdString("Archivos PLY (*.ply)"));

    ui->lineEdit_2->setText(fileName);
}

void Interfaz::on_lineEdit_2_textChanged(const QString &arg1)
{
    urlPly_2 = arg1.toStdString();
}

void Interfaz::on_checkBox_6_clicked()
{
    if(!relleno_iluminacion_plana){
       relleno_iluminacion_plana=true;
       ui->checkBox_11->setChecked(true);
       ui->checkBox_9->setChecked(true);
     //  ui->checkBox_3->setChecked(false);
       ui->checkBox_7->setChecked(false);
       relleno_iluminacion_suave=false;

       lightning=true;
       ui->checkBox_8->setChecked(true);

    }
    else relleno_iluminacion_plana=false;
}


void Interfaz::on_checkBox_7_clicked()
{
    if(!relleno_iluminacion_suave){
       relleno_iluminacion_suave=true;
       //ui->checkBox->setChecked(false);
       ui->checkBox_11->setChecked(true);
      ui->checkBox_9->setChecked(true);
       //ui->checkBox_4->setChecked(false);
       //ui->checkBox_6->setChecked(false);
       //relleno=0;
       //lineas=0;
       //puntos=0;
       //ajedrez=0;
       //relleno_iluminacion_plana=0;
       relleno_iluminacion_plana=false;
       ui->checkBox_6->setChecked(false);

       // activar iluminacion y luz infinito por defecto

       lightning=true;
       ui->checkBox_8->setChecked(true);

   //    if(luz==-1){
     //      luz=0;
     //      ui->radioButton_13->setChecked(true);
     //  }


    }
    else relleno_iluminacion_suave=false;
}

void Interfaz::on_horizontalSlider_4_valueChanged(int value)
{
    angulo_luz_infinito=value;
}

void Interfaz::on_horizontalSlider_5_valueChanged(int value)
{
    angulo_luz_x_infinito = value;
}

void Interfaz::on_radioButton_10_clicked()
{
    material=0;
}

void Interfaz::on_radioButton_11_clicked()
{
    material=1;
}

void Interfaz::on_checkBox_8_clicked()
{
    if(!lightning){
        lightning=true;
        textura_con_iluminacion=true;
        ui->checkBox_11->setChecked(true);
        ui->checkBox_9->setChecked(true);
    }
    else{
        lightning=false;
        textura_con_iluminacion=false;
        ui->checkBox_6->setChecked(false);
        ui->checkBox_7->setChecked(false);
        ui->checkBox_11->setChecked(false);
        ui->checkBox_9->setChecked(false);
        relleno_iluminacion_suave = false;
        relleno_iluminacion_plana = false;
    }

}
void Interfaz::on_radioButton_12_clicked()
{
    material=2;

}

void Interfaz::on_radioButton_13_clicked()
{
    material = 3;
}

void Interfaz::on_radioButton_14_clicked()
{
    if(obj_textura != 10)
        obj_textura=10;
    else
        obj_textura=-1;
}

void Interfaz::on_spinBox_2_valueChanged(int arg1)
{
    divisiones=arg1;
    ui->spinBox_3->setMaximum(arg1);
    ui->spinBox_4->setMaximum(arg1);
    ui->spinBox_5->setMaximum(arg1);
    ui->spinBox_6->setMaximum(arg1);
    cargar_textura = true;


    // std::cout << divisiones;
}

void Interfaz::on_doubleSpinBox_2_valueChanged(double arg1)
{
    puntos_textura[1]=arg1;
    cargar_textura = true;
}

void Interfaz::on_doubleSpinBox_4_valueChanged(double arg1)
{
    puntos_textura[0]=arg1;
    cargar_textura = true;
}

void Interfaz::on_doubleSpinBox_3_valueChanged(double arg1)
{
    puntos_textura[3]=arg1;
    cargar_textura = true;
}

void Interfaz::on_doubleSpinBox_5_valueChanged(double arg1)
{
    puntos_textura[2]=arg1;
    cargar_textura = true;
}

void Interfaz::on_checkBox_12_clicked()
{
    if(!estado_luz_posicional)
        estado_luz_posicional=true;
    else
        estado_luz_posicional=false;

    luz=1;
}

void Interfaz::on_checkBox_13_clicked()
{
    if(!estado_luz_infinito)
        estado_luz_infinito=true;
    else
        estado_luz_infinito=false;

    luz=0;
}

void Interfaz::on_horizontalSlider_6_valueChanged(int value)
{
    angulo_luz_posicional=value;
}

void Interfaz::on_horizontalSlider_7_valueChanged(int value)
{
    angulo_luz_x_posicional=value;
}

void Interfaz::on_doubleSpinBox_6_valueChanged(double arg1)
{
    distancia_luz_posicional = arg1;
}

void Interfaz::on_spinBox_5_valueChanged(int arg1)
{
    puntos_marco[0]=arg1;
    cargar_textura = true;
}

void Interfaz::on_spinBox_3_valueChanged(int arg1)
{
    puntos_marco[1]=arg1;
    cargar_textura = true;
}

void Interfaz::on_spinBox_4_valueChanged(int arg1)
{
    puntos_marco[2]=arg1;
    cargar_textura = true;
}

void Interfaz::on_spinBox_6_valueChanged(int arg1)
{
    puntos_marco[3]=arg1;
    cargar_textura = true;
}

void Interfaz::on_checkBox_9_clicked()
{
    if(!lightning){
        lightning=true;
         textura_con_iluminacion=true;
        ui->checkBox_8->setChecked(true);
        ui->checkBox_11->setChecked(true);
       // cargar_tierra=true;
    }
    else{
         textura_con_iluminacion=false;
        lightning=false;
        ui->checkBox_8->setChecked(false);
        ui->checkBox_11->setChecked(false);
    }
}

void Interfaz::on_checkBox_10_clicked()
{
    if(!pintar_tierra)
        pintar_tierra=true;
    else
        pintar_tierra=false;
}

void Interfaz::on_checkBox_11_clicked()
{
    if(!textura_con_iluminacion){
        textura_con_iluminacion=true;
        lightning=true;
        ui->checkBox_9->setChecked(true);
        ui->checkBox_8->setChecked(true);
    }else{
        ui->checkBox_9->setChecked(false);
        textura_con_iluminacion=false;
        ui->checkBox_6->setChecked(false);
        ui->checkBox_7->setChecked(false);
        relleno_iluminacion_plana = false;
        relleno_iluminacion_suave = false;
        lightning=false;
        ui->checkBox_8->setChecked(false);
    }

}

void Interfaz::on_doubleSpinBox_valueChanged(double arg1)
{
    ancho_marco = arg1;
    cargar_textura=true;
}

void Interfaz::on_doubleSpinBox_7_valueChanged(double arg1)
{
    alto_marco = arg1;
    cargar_textura=true;
}

void Interfaz::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(0,QString::fromStdString("Cargar TExtura"), "/home", QString::fromStdString("Imagenes (*)"));

    ui->lineEdit_3->setText(fileName);
}

void Interfaz::on_lineEdit_3_textChanged(const QString &arg1)
{
    path_textura = arg1.toStdString();
}



void Interfaz::on_pushButton_5_clicked()
{
    cargar_textura = true;
}

void Interfaz::on_pushButton_7_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(0,QString::fromStdString("Cargar TExtura"), "/home", QString::fromStdString("Imagenes (*)"));

    ui->lineEdit_4->setText(fileName);
}


void Interfaz::on_lineEdit_4_textChanged(const QString &arg1)
{
    path_tierra=arg1.toStdString();
}

void Interfaz::on_lineEdit_5_textChanged(const QString &arg1)
{
    path_estrellas=arg1.toStdString();
}

void Interfaz::on_pushButton_6_clicked()
{
    cargar_tierra=true;
    this->tierra = 11;
}

void Interfaz::on_pushButton_9_clicked()
{
    cargar_estrellas=true;
}

void Interfaz::on_checkBox_10_clicked(bool checked)
{
    modotext = checked;
}

void Interfaz::on_radioButton_15_clicked()
{
    camara_selec = 0;
}

void Interfaz::on_radioButton_16_clicked()
{
    camara_selec = 1;
}

void Interfaz::on_radioButton_17_clicked()
{
    camara_selec = 2;
}

void Interfaz::on_radioButton_18_clicked()
{
    modo_proyeccion = 0;
}

void Interfaz::on_radioButton_19_clicked()
{
    modo_proyeccion = 1;
}

void Interfaz::on_radioButton_20_clicked()
{

}

void Interfaz::on_tipoCamara1_currentIndexChanged(int index)
{
    modoProyeccion[0] = index;
}

void Interfaz::on_tipoCamara2_currentIndexChanged(int index)
{
    modoProyeccion[1] = index;
}

void Interfaz::on_tipoCamara3_currentIndexChanged(int index)
{
    modoProyeccion[2] = index;}
