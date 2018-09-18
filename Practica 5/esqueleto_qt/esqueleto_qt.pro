HEADERS += \
  glwidget.h \
  window.h \
    objeto3d.h \
    cubo.h \
    tetraedro.h \
    o3ds.h \
    o3dr.h \
    tubo.h \
    esfera.h \
    cono.h  \
    file_ply_stl.h \
    ply.h \
    cilindro.h \
    vaso.h \
    vasoinv.h \
    peon.h \
    pieza_brazo.h \
    pieza_union.h \
    pieza_cubo.h \
    watt.h \
    pieza_media.h \
    pieza_ply.h \
    ui.h \
    material.h \
    luz.h \
    marcodetexturas.h \
    esfera_textura.h \
    camara.h \
    escena.h

SOURCES += \
  main.cc \
  glwidget.cc \
  window.cc \
    objeto3d.cpp \
    cubo.cpp \
    tetraedro.cpp \
    o3ds.cpp \
    o3dr.cpp \
    tubo.cpp \
    esfera.cpp \
    cono.cpp    \
    file_ply_stl.cc \
    ply.cpp \
    cilindro.cpp \
    vaso.cpp \
    vasoinv.cpp \
    peon.cpp \
    pieza_brazo.cpp \
    pieza_union.cpp \
    pieza_cubo.cpp \
    watt.cpp \
    pieza_media.cpp \
    pieza_ply.cpp \
    ui.cpp \
    material.cpp \
    luz.cpp \
    marcodetexturas.cpp \
    esfera_textura.cpp \
    camara.cpp \
    escena.cpp


INCLUDEPATH += /casa/dmartin/codigo/funciontecas/glew/include

LIBS += -L/usr/X11R6/lib64 -lGL \
        -L/casa/dmartin/codigo/funciontecas/glew/lib -lGLEW -lGLU

CONFIG += c++11
QT += widgets

FORMS += \
    ui.ui
