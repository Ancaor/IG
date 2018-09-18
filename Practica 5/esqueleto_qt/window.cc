//**************************************************************************
//
// Domingo Martin Perandres© 2014-2017
// http://calipso.ugr.es/dmartin
// dmartin@ugr.es
//
// GPL
//**************************************************************************

#include <QApplication>
#include <QMenuBar>
#include <QGroupBox>
#include <QSlider>
#include <QLabel>
#include <QCheckBox>
#include <QSpinBox>
#include <QScrollArea>

#include "window.h"
#include "glwidget.h"

_window::_window()
{

  QSizePolicy Q(QSizePolicy::Expanding,QSizePolicy::Expanding);

  QWidget *Central_widget = new QWidget(this);

  QFrame *Framed_widget= new QFrame(Central_widget);
  Framed_widget->setSizePolicy(Q);
  Framed_widget->setFrameStyle(QFrame::Panel);
  Framed_widget->setLineWidth(3);

  ui = new UI(this);

  GL_widget = new _gl_widget(this, ui);
  GL_widget->setSizePolicy(Q);

  QHBoxLayout *Horizontal_frame = new QHBoxLayout();
  Horizontal_frame->setContentsMargins(1,1,1,1);

  Horizontal_frame->addWidget(GL_widget);
  Framed_widget->setLayout(Horizontal_frame);

  QHBoxLayout *Horizontal_main = new QHBoxLayout(Central_widget);

  Horizontal_main->addWidget(Framed_widget);

  Central_widget->setLayout(Horizontal_main);
  setCentralWidget(Central_widget);

  // actions for file menu
  QAction *Exit = new QAction(QIcon("./icons/exit.png"), tr("&Exit..."), this);
  Exit->setShortcut(tr("Ctrl+Q"));
  Exit->setToolTip(tr("Exit the application"));
  connect(Exit, SIGNAL(triggered()), this, SLOT(close()));

  QAction *OpenUI = new QAction( tr("&Abrir ventana de herramientas"), this);
  OpenUI->setShortcut(tr("Ctrl+M"));
  connect(OpenUI, SIGNAL(triggered()), this, SLOT(OpenUI()));

  QAction *RaiseUI = new QAction( tr("&Mostrar barra de herramientas"), this);
  RaiseUI->setShortcut(tr("Ctrl+S"));
  connect(RaiseUI, SIGNAL(triggered()), this, SLOT(RaiseUI()));

  // menus
  QMenu *File_menu=menuBar()->addMenu(tr("&File"));
  File_menu->addAction(Exit);
  QMenu *File_menu_ui=menuBar()->addMenu(tr("&Interfaz"));
  File_menu_ui->addAction(OpenUI);
  File_menu_ui->addAction(RaiseUI);
  File_menu->setAttribute(Qt::WA_AlwaysShowToolTips);

  setWindowTitle(tr("esqueleto_qt (Domingo Martín)"));

  resize(800,800);
}

void _window::OpenUI(){
    ui->show();
}

void _window::RaiseUI(){
    ui->raise();
}

