HEADERS += \
  glwidget.h \
  window.h \
    cubo.h \
    tetraedro.h \
    o3ds.h \
    o3d.h

SOURCES += \
  main.cc \
  glwidget.cc \
  window.cc \
    cubo.cpp \
    tetraedro.cpp \
    o3ds.cpp \
    o3d.cpp

INCLUDEPATH += /casa/dmartin/codigo/funciontecas/glew/include

LIBS += -L/usr/X11R6/lib64 -lGL \
        -L/casa/dmartin/codigo/funciontecas/glew/lib -lGLEW

CONFIG += c++11
QT += widgets
