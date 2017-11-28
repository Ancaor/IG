HEADERS += \
  glwidget.h \
  window.h \
    cubo.h \
    tetraedro.h \
    o3ds.h \
    o3d.h \
    o3dr.h \
    file_ply_stl.h \
    ply_object.h \
    cilindro.h \
    vaso.h \
    vaso_invertido.h \
    cono.h \
    tubo.h\
    esfera.h\
    brazo.h \
    partesuperior.h \
    cubowatt.h \
    brazopequenio.h \
    brazogrande.h \
    watt_regulator.h \
    esfera_beethoven.h \
    interfaz.h \
    material.h \
    luz.h

SOURCES += \
  main.cc \
  glwidget.cc \
  window.cc \
    cubo.cpp \
    tetraedro.cpp \
    o3ds.cpp \
    o3d.cpp \
    o3dr.cpp \
    file_ply_stl.cc \
    ply_object.cpp \
    cilindro.cpp \
    vaso.cpp \
    vaso_invertido.cpp \
    cono.cpp \
    tubo.cpp\
    esfera.cpp \
    brazo.cpp \
    partesuperior.cpp \
    cubowatt.cpp \
    brazopequenio.cpp \
    brazogrande.cpp \
    watt_regulator.cpp \
    esfera_beethoven.cpp \
    interfaz.cpp \
    material.cpp \
    luz.cpp

INCLUDEPATH += /casa/dmartin/codigo/funciontecas/glew/include

LIBS += -L/usr/X11R6/lib64 -lGL \
        -L/casa/dmartin/codigo/funciontecas/glew/lib -lGLEW

CONFIG += c++11
QT += widgets

DISTFILES +=

FORMS += \
    interfaz.ui
