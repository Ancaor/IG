#include "interfaz.h"
#include "ui_interfaz.h"

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

void Interfaz::on_tabWidget_tabBarClicked(int index)
{
    switch(index)
    {
    case 0: practica=1; break;
    case 1: practica=2; break;
    case 2: practica=10; break;
    case 3: practica=3; break;
    }
}

void Interfaz::on_checkBox_clicked()
{
    if(!puntos)
        puntos=true;
    else
        puntos=false;
}

void Interfaz::on_checkBox_2_clicked()
{
    if(!lineas)
        lineas=true;
    else
        lineas=false;
}

void Interfaz::on_checkBox_3_clicked()
{
    if(!relleno)
        relleno=true;
    else
        relleno=false;
}

void Interfaz::on_checkBox_4_clicked()
{
    if(!ajedrez)
        ajedrez=true;
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
