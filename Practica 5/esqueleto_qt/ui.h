#ifndef UI_H
#define UI_H

#include <QDialog>

#include <QFileDialog>
#include <QObject>
#include <QTranslator>

namespace Ui {
class UI;
}

class UI : public QDialog
{
    Q_OBJECT

public:
    explicit UI(QWidget *parent = 0);
    bool getPuntos();
    bool getLineas();
    bool getRelleno();
    bool getAjedrez();
    bool getRellenoIluminadoFlat();
    bool getRellenoIluminadoSmooth();
    int getFigura();
    float getAnguloFinal();
    int getDivisiones();
    float getVelocidad();
    bool getAnimar();
    int getAnguloRotacion();
    void setAnguloRotacion(int angulo);


    bool getLuzPunto();
    bool getLuzInf();
    int getMaterial();
    float getMovLuz_Punto_X();
    float getMovLuz_Punto_Y();
    float getMovLuz_Punto_Z();
    float getMovLuz_Inf_X();
    float getMovLuz_Inf_Y();

    bool getMarco();
    bool getFondo();
    float getAnchoMarco();
    float getAltoMarco();
    int getDivisionesMarco();
    QString getPathTextura();
    QString getPathPly();
    void setPathTextura(QString p);
    void setPathPly(QString p);
    void clearText();

    int getMargenMarcoXMin();
    int getMargenMarcoXMax();
    int getMargenMarcoYMin();
    int getMargenMarcoYMax();

    float getMargenImagenXMin();
    float getMargenImagenXMax();
    float getMargenImagenYMin();
    float getMargenImagenYMax();

    bool getAbrirTextura();
    bool getCargarTextura();
    bool getTexturaHabilitada();
    bool getAbrirPly();
    bool getCargarPly();

    int getCamaraActual();
    int getNumeroCamaraPerspectiva();
    int getNumeroCamaraOrtogonal();
    int getSensibilidadZoom();
    int getSensibilidadRotacion();
    bool getReiniciarCamara();
    bool getColorearSeleccion();

    ~UI();

private slots:
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

    void on_radioButton_9_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_radioButton_10_clicked();

    void on_checkBox_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_11_clicked();

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_tabWidget_tabBarClicked(int index);

    void on_checkBox_8_clicked();

    void on_radioButton_13_clicked();

    void on_radioButton_14_clicked();

    void on_radioButton_15_clicked();

    void on_radioButton_16_clicked();

    void on_radioButton_17_clicked();

    void on_radioButton_18_clicked();

    void on_horizontalSlider_3_valueChanged(int value);

    void on_horizontalSlider_4_valueChanged(int value);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_radioButton_12_clicked();

    void on_checkBox_6_clicked();

    void on_radioButton_19_clicked();

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void on_spinBox_5_valueChanged(int arg1);

    void on_spinBox_6_valueChanged(int arg1);

    void actualiza_spinbox();

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_doubleSpinBox_5_valueChanged(double arg1);

    void on_doubleSpinBox_6_valueChanged(double arg1);

    void on_doubleSpinBox_7_valueChanged(double arg1);

    void on_pushButton_3_clicked();

    void on_horizontalSlider_5_valueChanged(int value);

    void on_horizontalSlider_6_valueChanged(int value);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_radioButton_20_clicked();

    void on_checkBox_7_clicked(bool checked);

    void on_checkBox_9_clicked(bool checked);

    void on_radioButton_21_clicked();

    void on_radioButton_22_clicked();

    void on_horizontalSlider_7_valueChanged(int value);

    void on_horizontalSlider_8_valueChanged(int value);

    void on_radioButton_23_clicked();

    void on_pushButton_5_clicked();

    void on_checkBox_10_clicked(bool checked);

    void on_spinBox_7_valueChanged(int arg1);

    void on_spinBox_8_valueChanged(int arg1);

private:
    Ui::UI *ui;
    bool Puntos = true;
    bool Lineas = false;
    bool Relleno = false;
    bool Ajedrez = false;
    bool Relleno_iluminado_flat = false;
    bool Relleno_iluminado_smooth = false;
    int material = 0;
    int Figura = 0;
    int Practica = 1;
    int Figura_P1 = 0;
    int Figura_P2 = 2;
    int Figura_P3 = 9;
    int Figura_P4 = 11;

    float ancho_marco = 1;
    float alto_marco = 1;
    int divisiones_marco = 1;

    int margen_marco_x_min = 0;
    int margen_marco_x_max = divisiones_marco;
    int margen_marco_y_min = 0;
    int margen_marco_y_max = divisiones_marco;

    float margen_img_x_min = 0;
    float margen_img_x_max = 1;
    float margen_img_y_min = 0;
    float margen_img_y_max = 1;

    bool cargar_textura = false;

    bool abrir_textura = false;
    bool textura_habilitada = false;

    bool abrir_ply = false;
    bool cargar_ply = false;

    QString path_textura;
    bool fondo_textura = false;

    QString path_ply;
    QString path_guardado = "/home";



    float angulo_final = 360;
    int divisiones = 41;
    float velocidad = 0;
    bool animar = false;
    int angulo_rotacion = 0;

    bool luz_punto = false;
    bool luz_inf = false;

    float movimiento_luz_punto_x = 0;
    float movimiento_luz_punto_y = 0;
    float movimiento_luz_punto_z = 0;

    float movimiento_luz_inf_x = 0;
    float movimiento_luz_inf_y = 0;

    int camara_actual = 0;
    int sensibilidad_zoom = 25;
    int sensibilidad_rotacion = 25;
    int Figura_P5 = 13;
    bool reiniciar_camara = false;
    bool colorear_seleccion = true;

    int n_camara_perspectiva = 0;
    int n_camara_ortogonal = 0;
};

#endif // UI_H
