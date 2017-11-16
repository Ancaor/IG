#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QDialog>

namespace Ui {
class Interfaz;
}

class Interfaz : public QDialog
{
    Q_OBJECT

public:
    explicit Interfaz(QWidget *parent = 0);
    ~Interfaz();

   // int getPractica();
    int getFigura();
    bool getPuntos();
    bool getLineas();
    bool getRelleno();
    bool getAjedrez();

private slots:
  //  void on_tabWidget_tabBarClicked(int index);

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::Interfaz *ui;

  //  int practica;

    bool puntos = 0;
    bool lineas = 0;
    bool relleno = 0;
    bool ajedrez = 0;

    int fig_pract1 = 0;
};

#endif // INTERFAZ_H
