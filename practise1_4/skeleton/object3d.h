/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"
#include <cmath>
#include <QImage>


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
  public:
      vector<_vertex3ui> Triangles;
      vector<_vertex3f> Normales;
      vector<_vertex3f> normalesVertices;
      vector<_vertex2f> Materiales;
      QImage Imagen;

      void draw_line();
      void draw_fill();
      void draw_chess();
      void draw_flat();
      void draw_gouraud();
      void calcularNormales();

      void usarMaterial1();
      void usarMaterial2();
      void usarMaterial3();

};

#endif // OBJECT3D_H
