/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"
#include "material.h"
#include "colors.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  glBegin(GL_TRIANGLES);
  glColor3f(0,0,1);
  for (unsigned int i=0;i<Triangles.size();i++){
    glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
    glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
    glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
  }
  glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
    //glMatrixMode(GL_MODELVIEW);
    glPolygonMode(GL_FRONT,GL_FILL);
    glBegin(GL_TRIANGLES);

            // Triangles[i] te devuelve info sobre el triangulo i-esimo.
            // Vertices[Triangles[i]] te devuelve info sobre el vértice i-esimo.
    glColor3f(0,255,255);
    for(unsigned int i=0;i<Triangles.size();i++){
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    glPolygonMode(GL_FRONT,GL_FILL);
    glBegin(GL_TRIANGLES);

    for(unsigned int i=0;i<Triangles.size();i++){
        if(i%2==0){
          glColor3fv((GLfloat *) &MAGENTA);
        }else{
            glColor3fv((GLfloat *) &CYAN);
        }
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
}



/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::calcularNormales(){


    _vertex3f a, b, c;
    float size;
    vector<_vertex3f> auxiliar;

    normalesVertices.resize(Vertices.size(), _vertex3f(0.0, 0.0, 0.0));

    for(unsigned int i=0; i<Triangles.size(); i++){

        a( Vertices[Triangles[i]._1].x - Vertices[Triangles[i]._0].x ,
           Vertices[Triangles[i]._1].y - Vertices[Triangles[i]._0].y ,
           Vertices[Triangles[i]._1].z - Vertices[Triangles[i]._0].z );

        b( Vertices[Triangles[i]._2].x - Vertices[Triangles[i]._0].x ,
           Vertices[Triangles[i]._2].y - Vertices[Triangles[i]._0].y ,
           Vertices[Triangles[i]._2].z - Vertices[Triangles[i]._0].z );

        c( (a.y * b.z ) - (a.z * b.y),
          -((a.x * b.z ) - (a.z * b.x)),
           (a.x * b.y) - (a.y * b.x));

        // Realizamos un producto vectorial de 'a' x 'b' almacenando en 'c'
        // todas las normales calculadas


        size = (float) sqrt(pow(c.x,2.0) + pow(c.y,2.0) + pow(c.z, 2.0));

        // Mediante la operacion modulo calculamos la longitud de c
        // y vamos ajustando el vector de normales.


        c.x /= size; c.y /= size; c.z /= size;

        // Incluyendo en el vector de normales todas aquellas calculadas
        // para los triangulos.

        Normales.push_back(c);
    }

    //En este vector iremos guardando las normales de cada vertice
    //de cada triangulo para el que se ha calculado una normal.
    auxiliar.resize( Vertices.size());


    //Iremos aniadiendo todas las coordenadas de las normales en nuestro
    //vector auxiliar para ordenar las normales en nuestro vector de
    //normales de vertices.
    for(unsigned int i=0 ; i<Triangles.size();i++){
        auxiliar[Triangles[i]._0] += Normales[i];
        auxiliar[Triangles[i]._1] += Normales[i];
        auxiliar[Triangles[i]._2] += Normales[i];
    }


    //Calculamos las normales de los vertices de cada triangulo.
    for(unsigned int i=0; i<auxiliar.size(); i++){
        size = sqrt(pow(auxiliar[i].x,2.0) + pow(auxiliar[i].y,2.0) + pow(auxiliar[i].z, 2.0));

        normalesVertices[i].x = auxiliar[i].x/size;
        normalesVertices[i].y = auxiliar[i].y/size;
        normalesVertices[i].z = auxiliar[i].z/size;

    }

}

void _object3D::draw_flat(){

    glPolygonMode(GL_FRONT, GL_FILL);
    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLES);

    for(unsigned int i=0; i<Triangles.size(); i++){
        glNormal3f((GLfloat) Normales[i]._0, (GLfloat) Normales[i]._1, (GLfloat) Normales[i].z);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
}


void _object3D::draw_gouraud(){

    glPolygonMode(GL_FRONT, GL_FILL);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);

    for(unsigned int i=0; i<Triangles.size(); i++){
        glNormal3f((GLfloat)normalesVertices[Triangles[i]._0]._0, (GLfloat)normalesVertices[Triangles[i]._0]._1, (GLfloat)normalesVertices[Triangles[i]._0]._2);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

        glNormal3f((GLfloat)normalesVertices[Triangles[i]._1]._0, (GLfloat)normalesVertices[Triangles[i]._1]._1, (GLfloat)normalesVertices[Triangles[i]._1]._2);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

        glNormal3f((GLfloat)normalesVertices[Triangles[i]._2]._0, (GLfloat)normalesVertices[Triangles[i]._2]._1, (GLfloat)normalesVertices[Triangles[i]._2]._2);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
}


void _object3D::usarMaterial1(){

    //Dorado

    _vertex4f ambiental = {0.24725, 0.1995, 0.0745, 1.0};
    _vertex4f difusa = {0.75164, 0.60648, 0.22648, 1.0};
    _vertex4f especular = {0.628281, 0.555802, 0.366065, 1.0};
    float brillo = 0.4;

    material mate(ambiental, difusa, especular, brillo);
    mate.usarMaterial();
}

void _object3D::usarMaterial2(){

    //Turquesa

    _vertex4f ambiental = {0.1, 0.18725, 0.1745, 1.0};
    _vertex4f difusa = {0.396, 0.74151, 0.69102, 1.0};
    _vertex4f especular = {0.297254, 0.30829, 0.306678, 1.0};
    float brillo = 0.1;

    material mate(ambiental, difusa, especular, brillo);
    mate.usarMaterial();
}

void _object3D::usarMaterial3(){

    //Green Rubber

    _vertex4f ambiental = {0.0, 0.05, 0.0, 1.0};
    _vertex4f difusa = {0.4, 0.5, 0.4, 1.0};
    _vertex4f especular = {0.04, 0.7, 0.04, 1.0};
    float brillo = 0.078125;

    material mate(ambiental, difusa, especular, brillo);
    mate.usarMaterial();


}


//Constantes





    /*
     * Dimensionar la matriz para introducir vertices
     * (suponemos que afectara a la eficiencia del programa)
     */

    /*
     * Aniadir vector de vertices a la matriz
     * aniadiendo cada coordenada almacenada al comienzo
     * y al final de cada fila. (cerrar revolucion)
     */


   /*
    * Rellenar la matriz atendiendo a las coordenadas de los vertices
    * del perfil para darle revolucion aplicando razones trigonometricas.
    * x=x*cos(2*PI/n_caras*nºiteracion)
    * z=x*sen(2*PI/n_caras*nºiteracion)
    */


   /*
    * Rellenar el vector de vertices con los
    * nuevos vertices guardados en la Matriz.
    */



   /*
    *  Rellenar el final del vector de vertices
    *  con los vertices del perfil.
    *
    */
/*

       cout<<"Numero de vertices: "<<Vertices.size()<<endl;

    Vertices.resize(tamVector);

    for(unsigned int i=0;i<tamVector-numVertices;i++){

        yCord = Vertices[i]._1;
        radio = Vertices[i]._0;

        xCord = radio * cos(rotation*cont1);
        zCord = radio * sin(rotation*cont1);
                                                                   //Cont1 empieza en 2
        Vertices[contador]=_vertex3f(xCord, yCord, zCord);      //Cntador empieza en 3
        contador++;
        if(contador%3==0 && contador!=0){
            cont1++;
            cout<<"NO ENTRA NUNCA"<<endl;
        }
    }


/*
 *
 *  LA REVOLUCION CREA UNA MATRIZ DE PUNTOS CON LOS QUE GENERAN
 *   TODOS LOS VERTICES Y LOS TRIANGULOS A PARTIR DE UN PERFIL.
 * SE DIBUJA CON UNA TECLA PASANDOLE LOS PUNTOS A VERTICES DE OBJECT Y
 * A TRIANGLES DE BASIC OBJECTS.
 *
 *


 *****************************************************************************
 *
 *
 *
 *****************************************************************************/
