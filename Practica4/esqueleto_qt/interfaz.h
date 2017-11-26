#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QDialog>
#include <QFileDialog>

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

    std::string urlPly;
    std::string urlPly_2;
};

#endif // INTERFAZ_H
