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
/*
int Interfaz::getPractica()
{
    return practica;
}
*/
int Interfaz::getFigura()
{
    return fig_pract1;
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

