HEADERS += \
  colors.h \
  basic_object3d.h \
  object3d.h \
  axis.h \
  tetrahedron.h \
  glwidget.h \
  window.h \
    cube.h \
    file_ply_stl.h \
    cone.h \
    object_ply.h \
    revolucion.h \
    tronco.h \
    cilindro.h \
    sphere.h \
    revolucion_ply.h \
    semi.h \
    cabeza.h \
    antenas.h \
    conector.h \
    ojo.h \
    antena.h \
    pata.h \
    cola.h \
    aguijon.h \
    boca.h \
    partearribapata.h \
    parteabajopata.h \
    pie.h \
    chess_board.h \
    material.h

SOURCES += \
  basic_object3d.cc \
  object3d.cc \
  axis.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc \
    cube.cc \
    file_ply_stl.cc \
    cone.cc \
    object_ply.cc \
    revolucion.cc \
    cilindro.cc \
    tronco.cc \
    sphere.cc \
    revolucion_ply.cc \
    semi.cc \
    cabeza.cc \
    antenas.cc \
    conector.cc \
    ojo.cc \
    antena.cc \
    pata.cc \
    cola.cc \
    aguijon.cc \
    boca.cc \
    partearribapata.cc \
    parteabajopata.cc \
    pie.cc \
    chess_board.cc \
    material.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
