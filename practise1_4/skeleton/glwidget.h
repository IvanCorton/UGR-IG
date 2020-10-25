/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H



#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QImageReader>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "sphere.h"
#include "tetrahedron.h"
#include "cube.h"
#include "cone.h"
#include "cilindro.h"
#include "tronco.h"
#include "revolucion_ply.h"
#include "semi.h"
#include "revolucion.h"
#include "cabeza.h"
#include "object_ply.h"
#include "antenas.h"
#include "conector.h"
#include "pata.h"
#include "ojo.h"
#include "cola.h"
#include "aguijon.h"
#include <QTimer>
#include "boca.h"
#include "chess_board.h"
#include "material.h"

namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=1;

  // Tope, minimos,v.iniciales

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE, OBJECT_PLY, OBJECT_CONE, OBJECT_CILINDRO, OBJECT_SPHERE, OBJECT_REVOLUCION_PLY, OBJECT_TRONCO, OBJECT_TABLERO} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  int contCola=0, contAla1=0, contCola2=0, contCabeza=0, contPata1=0, contParte2=0, distancia=10, material=0;
  bool activado, iluminado;
  float ratio=0, angW=0, angX=0, angY=0, angZ=0;

  void encenderLuz1();
  void encenderLuz2();
  void apagarLuces();
  void apagarLuz1();
  void apagarLuz2();

  void cargarImagen(QImage &Image);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();

public slots:
  void idle();


protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;


private:
  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;
  _cube Cube;
  _cone Cone;
  _cilindro Cilindro;
  _sphere Sphere;
  //_sphere Sphere(sentido, caras 10, vertices 50);      //Mediante parametros
  _object_ply Ply;
  _revolucion_ply Revolucion_ply;
  _chess_board Tablero;
  _tronco Tronco;

  QTimer *timer;

  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;
  bool Draw_flat;
  bool Draw_gouraud;
  bool Luz1;
  bool Luz2;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;
};

#endif
