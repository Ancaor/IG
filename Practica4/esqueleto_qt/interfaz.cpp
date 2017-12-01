#include "interfaz.h"
#include "ui_interfaz.h"
#include <string>

Interfaz::Interfaz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Interfaz)
{
    ui->setupUi(this);
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
    switch(practica)
    {
    case 1: return fig_pract1; break;
    case 2: return fig_pract2;break;
    case 3: return fig_pract3;break;
    case 4: return marco; break;
    case 10: int aux = cargar_ply; cargar_ply=0;return aux;break;

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

bool Interfaz::getEstadoLuzPosicional()
{
    return estado_luz_posicional;
}

bool Interfaz::getEstadoLuzInfinito()
{
    return estado_luz_infinito;
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
     //  ui->checkBox->setChecked(false);
     //  ui->checkBox_2->setChecked(false);
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
       //ui->checkBox_2->setChecked(false);
       //ui->checkBox_3->setChecked(false);
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
    if(!lightning)
        lightning=true;
    else lightning=false;
}

void Interfaz::on_radioButton_12_clicked()
{
    material=2;

}

void Interfaz::on_radioButton_13_clicked()
{
    luz=0;
}

void Interfaz::on_radioButton_14_clicked()
{
    if(marco != 10)
        marco=10;
    else
        marco=-1;
}

void Interfaz::on_spinBox_2_valueChanged(int arg1)
{
    divisiones=arg1;
   // std::cout << divisiones;
}

void Interfaz::on_doubleSpinBox_2_valueChanged(double arg1)
{
    puntos_textura[1]=arg1;
}

void Interfaz::on_doubleSpinBox_4_valueChanged(double arg1)
{
    puntos_textura[0]=arg1;
}

void Interfaz::on_doubleSpinBox_3_valueChanged(double arg1)
{
    puntos_textura[3]=arg1;
}

void Interfaz::on_doubleSpinBox_5_valueChanged(double arg1)
{
    puntos_textura[2]=arg1;
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
}

void Interfaz::on_spinBox_3_valueChanged(int arg1)
{
    puntos_marco[1]=arg1;
}

void Interfaz::on_spinBox_4_valueChanged(int arg1)
{
    puntos_marco[2]=arg1;
}

void Interfaz::on_spinBox_6_valueChanged(int arg1)
{
    puntos_marco[3]=arg1;
}
