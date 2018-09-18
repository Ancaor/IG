//**************************************************************************
//
// Domingo Martin Perandres© 2014-2017
// http://calipso.ugr.es/dmartin
// dmartin@ugr.es
//
// GPL
//**************************************************************************

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QFileDialog>
#include <QDialog>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QGuiApplication>
#include "ui.h"

QT_FORWARD_DECLARE_CLASS(QOpenGLWidget)

class _gl_widget;

class _window : public QMainWindow
{
    Q_OBJECT

public:
    _window();

public slots:
    void OpenUI();
    void RaiseUI();

private:
  _gl_widget *GL_widget;
  UI *ui;
};

#endif
