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

  interfaz = new Interfaz(this);


  GL_widget = new _gl_widget(this,interfaz);
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

  QAction *RaiseInterfaz = new QAction(QIcon("./icons/exit.png"), tr("&Raise Interfaz..."),this);
  RaiseInterfaz->setShortcut(tr("Ctrl+R"));
  RaiseInterfaz->setToolTip(tr("Raise the interface"));
  connect(RaiseInterfaz, SIGNAL(triggered()), this, SLOT(raiseInterfaz()));

  QAction *ShowInterfaz = new QAction(QIcon("./icons/exit.png"), tr("&Show Interfaz..."),this);
  ShowInterfaz->setShortcut(tr("Ctrl+S"));
  ShowInterfaz->setToolTip(tr("Show the interface if it's closed"));
  connect(ShowInterfaz, SIGNAL(triggered()), this, SLOT(showInterfaz()));

  // menus
  QMenu *File_menu=menuBar()->addMenu(tr("&File"));
  File_menu->addAction(Exit);
  File_menu->addAction(RaiseInterfaz);
  File_menu->addAction(ShowInterfaz);
  File_menu->setAttribute(Qt::WA_AlwaysShowToolTips);

  setWindowTitle(tr("esqueleto_qt (Domingo Martín)"));


  resize(800,800);
}

void _window::raiseInterfaz()
{
    interfaz->raise();
}

void _window::showInterfaz()
{
    interfaz->show();
}


