#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QDialog>
#include <QFileDialog>
#include <iostream>

namespace Ui {
class Interfaz;
}

class Interfaz : public QDialog
{
    Q_OBJECT

public:
    explicit Interfaz(QWidget *parent = 0);
    ~Interfaz();

    int getPractica();
    int getFigura();
    bool getPuntos();
    bool getLineas();
    bool getRelleno();
    bool getAjedrez();
    int getSecciones();
    int getAngulo();
    int getAnguloObjetoComplejo();
    int getVelocidad();
    bool Animacion();
    std::string getUrlPly();
    std::string getUrlPly_2();
    bool getRellenoIluminacionPlana();
    bool getRellenoIluminacionSuave();
    int getAnguloLuzInfinito();
    int getAnguloLuzXInfinito();
    double getDistanciaLuzPosicional();

    int getAnguloLuzPosicional();
    int getAnguloLuzXPosicional();

    int getMaterial();
    bool getLightning();
    int getLuz();
    int getDivisiones();
    std::vector<float> getPuntosTextura();
    std::vector<int> getPuntosMarco();

    bool getTexturaConIlu();

    bool getEstadoLuzPosicional();
    bool getEstadoLuzInfinito();

    float getAnchoMarco();
    float getAltoMarco();

    std::string getPathTextura();

    bool getCargarTextura();

    std::string getPathTierra();
    std::string getPathEstrellas();

    bool getCargarTierra();
    bool getCargarEstrellas();

    bool getPintarTierra();

    bool getModoText();

    //Practica 5

    int getCamaraSeleccionada();
    bool getModoProyeccion();

private slots:
    void on_tabWidget_tabBarClicked(int index);

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_8_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_radioButton_9_clicked();

    void on_horizontalSlider_3_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_checkBox_5_clicked();

    void on_pushButton_2_clicked();


    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_checkBox_6_clicked();

    void on_checkBox_7_clicked();

    void on_horizontalSlider_4_valueChanged(int value);

    void on_horizontalSlider_5_valueChanged(int value);

    void on_radioButton_10_clicked();

    void on_radioButton_11_clicked();


    void on_checkBox_8_clicked();

  //  void on_checkBox_7_clicked(bool checked);

    void on_radioButton_12_clicked();

    void on_radioButton_13_clicked();

    void on_radioButton_14_clicked();

    void on_spinBox_2_valueChanged(int arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_doubleSpinBox_5_valueChanged(double arg1);

    void on_horizontalSlider_6_valueChanged(int value);

    void on_checkBox_12_clicked();

    void on_checkBox_13_clicked();

    void on_horizontalSlider_7_valueChanged(int value);

    void on_doubleSpinBox_6_valueChanged(double arg1);

    void on_spinBox_5_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void on_spinBox_6_valueChanged(int arg1);

    void on_checkBox_9_clicked();

    void on_checkBox_10_clicked();

    void on_checkBox_11_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_7_valueChanged(double arg1);

    void on_pushButton_4_clicked();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_checkBox_10_clicked(bool checked);

    void on_radioButton_15_clicked();

    void on_radioButton_16_clicked();

    void on_radioButton_17_clicked();

    void on_radioButton_18_clicked();

    void on_radioButton_19_clicked();

    void on_radioButton_20_clicked();

public slots:
    void raise_dialog();

private:
    Ui::Interfaz *ui;

    int practica=1;

    bool puntos = 1;
    bool lineas = 0;
    bool relleno = 0;
    bool ajedrez = 0;
    bool relleno_iluminacion_plana = 0;
    bool relleno_iluminacion_suave = 0;

    int fig_pract1 = 1;
    int fig_pract2 = 3;
    int fig_pract3 = 9;
    int cargar_ply=0;

    int secciones = 40; // Coincide con el valor predeterminado en el spinBox
    int angulo = 360;
    int velocidad=0;
    int angulo_objeto_complejo=0;
    bool animacion=0;

    int angulo_luz_infinito=0;
    int angulo_luz_x_infinito=0;
    //double distancia_luz_ = 1;

    int angulo_luz_posicional=0;
    int angulo_luz_x_posicional=0;
    double distancia_luz_posicional = 2;

    bool estado_luz_posicional=0;
    bool estado_luz_infinito=0;

    int material=0;
    int luz=-1;

    bool lightning = 0;

    std::string urlPly;
    std::string urlPly_2;


    int obj_textura = 10;
    int divisiones=1;

    bool textura_con_iluminacion=0;

    std::vector<float> puntos_textura = {0,0,0,0};
    std::vector<int> puntos_marco = {0,0,0,0};

    float ancho_marco = 1.0;
    float alto_marco = 1.0;

    std::string path_textura;

    bool cargar_textura=true;

    bool cargar_tierra=true;

    std::string path_tierra;
    std::string path_estrellas;

    int tierra = -11;

    bool pintar_tierra=0;

    bool  cargar_estrellas=false;

    bool modotext = false;

    int escena = 81;



    // PRACTICA 5

    int camara_selec = 1;   // 1 / 2 / 3
    bool modo_proyeccion = 1;  // 1: perspectiva , 0: ortogonal

};

#endif // INTERFAZ_H
