#include "ui.h"
#include "ui.h"
#include "ui.h"
#include "ui_ui.h"

UI::UI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UI)
{
    ui->setupUi(this);
}

UI::~UI()
{
    delete ui;
}

bool UI::getPuntos(){
    return Puntos;
}

bool UI::getLineas(){
    return Lineas;
}

bool UI::getRelleno(){
    return Relleno;
}

bool UI::getAjedrez(){
    return Ajedrez;
}
bool UI::getRellenoIluminadoFlat(){
    return Relleno_iluminado_flat;
}
bool UI::getRellenoIluminadoSmooth(){
    return Relleno_iluminado_smooth;
}

int UI::getFigura(){
    switch(Practica){
        case 1: return Figura_P1; break;
        case 2: return Figura_P2; break;
        case 3: return Figura_P3; break;
        case 4: return Figura_P4; break;
        case 5: return Figura_P5; break;
    }
    return 0;
}

float UI::getAnguloFinal(){
    return angulo_final;
}

int UI::getDivisiones(){
    return divisiones;
}

float UI::getVelocidad(){
    return velocidad;
}

bool UI::getAnimar(){
    return animar;
}

int UI::getAnguloRotacion(){
    return angulo_rotacion;
}

void UI::setAnguloRotacion(int angulo){
    angulo_rotacion = angulo;
}

bool UI::getLuzPunto()
{
    return luz_punto;
}

bool UI::getLuzInf()
{
    return luz_inf;
}

int UI::getMaterial(){
    return material;
}

float UI::getMovLuz_Punto_X(){
    return movimiento_luz_punto_x;
}

float UI::getMovLuz_Punto_Y(){
    return movimiento_luz_punto_y;
}

float UI::getMovLuz_Punto_Z(){
    return movimiento_luz_punto_z;
}

float UI::getMovLuz_Inf_X()
{
    return movimiento_luz_inf_x;
}

float UI::getMovLuz_Inf_Y()
{
    return movimiento_luz_inf_y;
}

bool UI::getFondo()
{
    return fondo_textura;
}

float UI::getAnchoMarco()
{
    return ancho_marco;
}

float UI::getAltoMarco()
{
    return alto_marco;
}

int UI::getDivisionesMarco()
{
    return divisiones_marco;
}

QString UI::getPathTextura()
{
    return path_textura;
}

QString UI::getPathPly()
{
    return path_ply;
}

void UI::setPathTextura(QString p)
{
    path_textura = p;
    this->ui->lineEdit->setText(path_textura);
}

void UI::setPathPly(QString p)
{
    path_ply = p;
    this->ui->lineEdit_2->setText(path_ply);
}

void UI::clearText()
{
    this->ui->lineEdit->clear();
    this->ui->lineEdit_2->clear();
}

int UI::getMargenMarcoXMin()
{
    return margen_marco_x_min;
}

int UI::getMargenMarcoXMax()
{
    return margen_marco_x_max;
}

int UI::getMargenMarcoYMin()
{
    return margen_marco_y_min;
}

int UI::getMargenMarcoYMax()
{
    return margen_marco_y_max;
}

float UI::getMargenImagenXMin()
{
    return margen_img_x_min;
}

float UI::getMargenImagenXMax()
{
    return margen_img_x_max;
}

float UI::getMargenImagenYMin()
{
    return margen_img_y_min;
}

float UI::getMargenImagenYMax()
{
    return margen_img_y_max;
}

bool UI::getAbrirTextura()
{
    bool aux = abrir_textura;
    abrir_textura = false;
    return aux;
}

bool UI::getCargarTextura()
{
    bool res;
    if(cargar_textura)
        res = true;
    else
        res = false;

    cargar_textura= false;
    return res;
}

bool UI::getTexturaHabilitada()
{
    return textura_habilitada;
}

bool UI::getAbrirPly()
{
    bool aux = abrir_ply;
    abrir_ply = false;
    return aux;

}

bool UI::getCargarPly()
{
    bool res;
    if(cargar_ply)
        res = true;
    else
        res = false;

    cargar_ply= false;
    return res;
}

int UI::getCamaraActual()
{
    return camara_actual;
}

int UI::getNumeroCamaraPerspectiva()
{
    return n_camara_perspectiva;
}

int UI::getNumeroCamaraOrtogonal()
{
    return n_camara_ortogonal;
}

int UI::getSensibilidadZoom()
{
    return sensibilidad_zoom;
}

int UI::getSensibilidadRotacion()
{
    return sensibilidad_rotacion;
}

bool UI::getReiniciarCamara()
{
    bool aux = reiniciar_camara;
    reiniciar_camara = false;
    return aux;
}

bool UI::getColorearSeleccion()
{
    return colorear_seleccion;
}


void UI::on_checkBox_clicked()
{
    if(Puntos)
        Puntos = false;
    else
        Puntos = true;
}

void UI::on_checkBox_2_clicked()
{
    if(Lineas)
        Lineas = false;
    else
        Lineas = true;
}

void UI::on_checkBox_3_clicked()
{
    if(Relleno)
        Relleno = false;
    else
        Relleno = true;

    this->ui->checkBox_4->setChecked(false);
    this->ui->radioButton_12->setChecked(true);
    this->ui->radioButton_13->setChecked(false);
    this->ui->radioButton_14->setChecked(false);
    this->ui->radioButton_15->setChecked(false);
    this->ui->radioButton_16->setChecked(false);
    this->ui->radioButton_17->setChecked(false);
    this->ui->radioButton_18->setChecked(true);
    Relleno_iluminado_flat = false;
    Relleno_iluminado_smooth = false;
    material=0;
    Ajedrez = false;


}

void UI::on_checkBox_4_clicked()
{
    if(Ajedrez)
        Ajedrez = false;
    else
        Ajedrez = true;

    this->ui->checkBox_3->setChecked(false);
    this->ui->radioButton_12->setChecked(true);
    this->ui->radioButton_13->setChecked(false);
    this->ui->radioButton_14->setChecked(false);
    this->ui->radioButton_15->setChecked(false);
    this->ui->radioButton_16->setChecked(false);
    this->ui->radioButton_17->setChecked(false);
    this->ui->radioButton_18->setChecked(true);
    Relleno_iluminado_flat = false;
    Relleno_iluminado_smooth = false;
    material=0;
    Relleno = false;
}

void UI::on_checkBox_8_clicked()
{
    if(!luz_punto)
        luz_punto = true;
    else
        luz_punto = false;
}

void UI::on_checkBox_6_clicked()
{
    if(!luz_inf)
        luz_inf = true;
    else
        luz_inf = false;
}

void UI::on_radioButton_clicked()
{
    Figura_P1 = 0;
}

void UI::on_radioButton_2_clicked()
{
    Figura_P1 = 1;
}

void UI::on_radioButton_3_clicked()
{
    Figura_P2 = 2;
}

void UI::on_radioButton_4_clicked()
{
    Figura_P2 = 3;
}

void UI::on_radioButton_5_clicked()
{
    Figura_P2 = 4;
}

void UI::on_radioButton_6_clicked()
{
    Figura_P2 = 5;
}

void UI::on_radioButton_7_clicked()
{
    Figura_P2 = 6;
}

void UI::on_radioButton_8_clicked()
{
    Figura_P2 = 7;
}

void UI::on_radioButton_9_clicked()
{
    Figura_P2 = 8;
}

void UI::on_spinBox_valueChanged(int arg1)
{
    divisiones = arg1;
}

void UI::on_radioButton_10_clicked()
{
    Figura_P3 = 9;
}

void UI::on_checkBox_5_clicked()
{
    if(!animar)
        animar = true;
    else
        animar = false;
}

void UI::on_pushButton_clicked()
{
    angulo_rotacion-=5;
}

void UI::on_pushButton_2_clicked()
{
    angulo_rotacion+=5;
}

void UI::on_radioButton_11_clicked()
{
    Figura_P2 = 10;
}

void UI::on_horizontalSlider_2_valueChanged(int value)
{
    velocidad = value*1.0/100;
}

void UI::on_horizontalSlider_valueChanged(int value)
{
    angulo_final = value;
}

void UI::on_tabWidget_tabBarClicked(int index)
{
    switch(index){
        case 0: Practica = 1;break;
        case 1: Practica = 2;break;
        case 2: Practica = 3;break;
        case 3: break;
        case 4: Practica = 4; material = 0; break;
        case 5: break;
        case 6: Practica = 5; break;
        case 7: break;
    }
}

void UI::on_radioButton_13_clicked()
{
    material = 1;
    this->ui->checkBox_3->setChecked(false);
    this->ui->checkBox_4->setChecked(false);
    Relleno = false;
}

void UI::on_radioButton_14_clicked()
{
    material = 2;
    this->ui->checkBox_3->setChecked(false);
    this->ui->checkBox_4->setChecked(false);
    Relleno = false;
}

void UI::on_radioButton_15_clicked()
{
    material = 3;
    this->ui->checkBox_3->setChecked(false);
    this->ui->checkBox_4->setChecked(false);
    Relleno = false;
}

void UI::on_radioButton_16_clicked()
{
    Relleno_iluminado_smooth = false;
    Relleno_iluminado_flat = true;
    this->ui->checkBox_3->setChecked(false);
    this->ui->checkBox_4->setChecked(false);
    Relleno = false;
    Ajedrez = false;
}

void UI::on_radioButton_17_clicked()
{
    Relleno_iluminado_smooth = true;
    Relleno_iluminado_flat = false;
    this->ui->checkBox_3->setChecked(false);
    this->ui->checkBox_4->setChecked(false);
    Relleno = false;
    Ajedrez = false;
}

void UI::on_radioButton_18_clicked()
{
    Relleno_iluminado_flat = false;
    Relleno_iluminado_smooth = false;
}

void UI::on_horizontalSlider_3_valueChanged(int value)
{
    movimiento_luz_punto_x = value;
}

void UI::on_horizontalSlider_4_valueChanged(int value)
{
    movimiento_luz_punto_y = value;
}

void UI::on_doubleSpinBox_valueChanged(double arg1)
{
    movimiento_luz_punto_z = arg1;
}

void UI::on_radioButton_12_clicked()
{
    material = 0;
}

void UI::on_radioButton_19_clicked()
{
    Figura_P4 = 11;
}

void UI::on_doubleSpinBox_2_valueChanged(double arg1)
{
    ancho_marco = arg1;
}

void UI::on_doubleSpinBox_3_valueChanged(double arg1)
{
    alto_marco = arg1;
}

void UI::on_spinBox_2_valueChanged(int arg1)
{
    divisiones_marco = arg1;
    this->actualiza_spinbox();
}

void UI::on_spinBox_3_valueChanged(int arg1)
{
    margen_marco_y_min = arg1;
    this->actualiza_spinbox();
}

void UI::on_spinBox_4_valueChanged(int arg1)
{
    margen_marco_y_max = arg1;
    this->actualiza_spinbox();
}

void UI::on_spinBox_5_valueChanged(int arg1)
{
    margen_marco_x_min = arg1;
    this->actualiza_spinbox();
}

void UI::on_spinBox_6_valueChanged(int arg1)
{
    margen_marco_x_max = arg1;
    this->actualiza_spinbox();
}

void UI::actualiza_spinbox(){
    //marco
    this->ui->spinBox_3->setMaximum(margen_marco_y_max - 1);
    this->ui->spinBox_4->setMaximum(divisiones_marco);
    this->ui->spinBox_5->setMaximum(margen_marco_x_max - 1);
    this->ui->spinBox_6->setMaximum(divisiones_marco);

    //imagen
    this->ui->doubleSpinBox_4->setMaximum(margen_img_y_max - 0.05);
    this->ui->doubleSpinBox_5->setMinimum(margen_img_y_min + 0.05);
    this->ui->doubleSpinBox_6->setMaximum(margen_img_x_max - 0.05);
    this->ui->doubleSpinBox_7->setMinimum(margen_img_x_min + 0.05);
}

void UI::on_doubleSpinBox_4_valueChanged(double arg1)
{
    margen_img_y_min = arg1;
    this->actualiza_spinbox();
}

void UI::on_doubleSpinBox_5_valueChanged(double arg1)
{
     margen_img_y_max = arg1;
     this->actualiza_spinbox();
}

void UI::on_doubleSpinBox_6_valueChanged(double arg1)
{
    margen_img_x_min = arg1;
    this->actualiza_spinbox();
}

void UI::on_doubleSpinBox_7_valueChanged(double arg1)
{
    margen_img_x_max = arg1;
    this->actualiza_spinbox();
}

void UI::on_pushButton_3_clicked()
{

    if(!path_textura.isEmpty()){
        cargar_textura = true;
        abrir_textura = false;
    }
    else{
        abrir_textura = true;
        cargar_textura = false;
    }

}

void UI::on_horizontalSlider_5_valueChanged(int value)
{
    movimiento_luz_inf_x = value;
}

void UI::on_horizontalSlider_6_valueChanged(int value)
{
    movimiento_luz_inf_y = value;
}

void UI::on_lineEdit_textChanged(const QString &arg1)
{
    path_textura = arg1;
}

void UI::on_pushButton_4_clicked()
{
    if(!path_ply.isEmpty()){
        cargar_ply = true;
        this->ui->radioButton_11->setChecked(true);
        Figura_P2 = 10;
        abrir_ply = false;
    }
    else{
        abrir_ply = true;
        cargar_ply = false;
    }
}

void UI::on_lineEdit_2_textChanged(const QString &arg1)
{
    path_ply = arg1;
}

void UI::on_radioButton_20_clicked()
{
    Figura_P4 = 12;
}

void UI::on_checkBox_7_clicked(bool checked)
{
    fondo_textura = checked;
}

void UI::on_checkBox_9_clicked(bool checked)
{
    textura_habilitada = checked;
}

void UI::on_radioButton_21_clicked()
{
    camara_actual = 0;
}

void UI::on_radioButton_22_clicked()
{
    camara_actual = 1;
}

void UI::on_horizontalSlider_7_valueChanged(int value)
{
    sensibilidad_rotacion = value;
}

void UI::on_horizontalSlider_8_valueChanged(int value)
{
    sensibilidad_zoom = value;
}

void UI::on_radioButton_23_clicked()
{
    Figura_P5 = 13;
}

void UI::on_pushButton_5_clicked()
{
    reiniciar_camara = true;
}

void UI::on_checkBox_10_clicked(bool checked)
{
    colorear_seleccion = checked;
}

void UI::on_spinBox_7_valueChanged(int arg1)
{
    n_camara_perspectiva = arg1;
}

void UI::on_spinBox_8_valueChanged(int arg1)
{
    n_camara_ortogonal = arg1;
}
