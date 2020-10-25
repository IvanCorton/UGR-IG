/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

#include <file_ply_stl.h>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QSurfaceFormat>
#include "window.h"

using namespace std;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

int main( int argc, char ** argv )
{
  QApplication Application( argc, argv );
  _file_ply File_ply;

  QSurfaceFormat Format;
  Format.setDepthBufferSize(24);
  Format.setStencilBufferSize(8);
  QSurfaceFormat::setDefaultFormat(Format);

  _window Window;
  Window.show();

  return Application.exec();


/*
  vector<_vertex3f> Vertices;
  vector<_vertex3ui> Triangles;

  if (File_ply.open("/home/ivancorton/Escritorio/IG/Practicas/Practica1/skeleton/beethoven.ply")){
      File_ply.read(Vertices,Triangles);

        cout<<" Numero de Vertices: "<<Vertices.size()<<endl;

      cout << "File read correctly" << std::endl;
    }
    else cout << "File can't be opened" << std::endl;
*/
}
