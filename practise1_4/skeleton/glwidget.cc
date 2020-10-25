/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);

  // Llamada a Read ply
  Ply.read_ply();

  timer = new QTimer(this);
  timer->setInterval(0);
  connect(timer, SIGNAL(timeout()),this,SLOT(idle()));

  //Inicializar variables booleanas y enteras
  activado = false;
  iluminado = false;
  material = 0;

  //Carga de imagen ubicada en la carpeta skeleton.
  cargarImagen(Tablero.Imagen);

}


void _gl_widget::idle(){

    // Movimiento de la cola
    if((contCola < 5) || ((contCola >= 15) && (contCola < 25))){
        Tronco.decrementarCola(); contCola++;
    }else if(contCola >= 5 && contCola < 15){
        Tronco.incrementarCola(); contCola++;
    }else{
         contCola = 5;
    }

    if(contCola2 < 2 ){
        Tronco.agrandarCola(); contCola2++;
    }else if(contCola2 >= 2 && contCola2 < 3){
        Tronco.menguarCola(); contCola2++;
    }else{
         Tronco.menguarCola();
         contCola2 = 0;

    }


    // Movimiento de las alas
    if((contAla1 < 5 )|| ((contAla1 >= 15) && (contAla1 < 25))){
        Tronco.decrementarAla1(); Tronco.decrementarAla2(); contAla1++;
    }else if(contAla1 >= 5 && contAla1 < 15){
        Tronco.incrementarAla1(); Tronco.incrementarAla2(); contAla1++;
    }else{
         contAla1 = 5;
    }

    // Movimiento de las alas
    if((contCabeza < 5 )|| ((contCabeza >= 15) && (contCabeza < 25))){
        Tronco.decrementarCabeza(); Tronco.decrementarCabeza(); contCabeza++;
    }else if(contCabeza >= 5 && contCabeza < 15){
        Tronco.incrementarCabeza(); Tronco.incrementarCabeza(); contCabeza++;
    }else{
         contCabeza = 5;
    }

    // Movimiento de las patas
    if((contPata1 < 4 )|| ((contPata1 >= 12) && (contPata1 < 20))){
        Tronco.decrementarPata1();
        Tronco.decrementarPata3();
        Tronco.decrementarPata2();
        Tronco.Pata1.ParteArriba.decrementarParte2();
        Tronco.Pata1.ParteAbajo.incrementarParte2();
        Tronco.Pata1.ParteAbajo.Pie.incrementarPie();

        Tronco.Pata3.ParteArriba.decrementarParte2();
        Tronco.Pata3.ParteAbajo.incrementarParte2();
        Tronco.Pata3.ParteAbajo.Pie.incrementarPie();

        Tronco.Pata2.ParteArriba.decrementarParte2();
        Tronco.Pata2.ParteAbajo.incrementarParte2();
        Tronco.Pata2.ParteAbajo.Pie.incrementarPie();

        contPata1++;
    }else if(contPata1 >= 4 && contPata1 < 12){
        Tronco.incrementarPata1();
        Tronco.incrementarPata3();
        Tronco.incrementarPata2();
        Tronco.Pata1.ParteArriba.incrementarParte2();
        Tronco.Pata1.ParteAbajo.decrementarParte2();
        Tronco.Pata1.ParteAbajo.Pie.decrementarPie();

        Tronco.Pata3.ParteArriba.incrementarParte2();
        Tronco.Pata3.ParteAbajo.decrementarParte2();
        Tronco.Pata3.ParteAbajo.Pie.decrementarPie();

        Tronco.Pata2.ParteArriba.incrementarParte2();
        Tronco.Pata2.ParteAbajo.decrementarParte2();
        Tronco.Pata2.ParteAbajo.Pie.decrementarPie();


        contPata1++;
    }else{
         contPata1 = 4;
    }

    update();


}

/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
  case Qt::Key_2:Object=OBJECT_CUBE;break;
  case Qt::Key_3:Object=OBJECT_CONE;break;
  case Qt::Key_4:Object=OBJECT_CILINDRO;break;
  case Qt::Key_5:Object=OBJECT_SPHERE;break;
  case Qt::Key_6:Object=OBJECT_PLY;break;
  case Qt::Key_7:Object=OBJECT_TRONCO;break;
  case Qt::Key_8:Object=OBJECT_TABLERO;break;   //Tablero
  case Qt::Key_9:Object=OBJECT_REVOLUCION_PLY;break;    //Imagen de revolucion mediante fichero .ply

  //Accion de puesta en marcha y detenimiento de las animaciones de nuestra 'avispa'.
  case Qt::Key_A:
      if(!activado){
          timer->start(1);
          activado=true;
      }else{
          timer->stop();
          activado=false;
      }
      break;

  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F1:Draw_fill=!Draw_fill;break;
  case Qt::Key_F2:Draw_chess=!Draw_chess;break;
  case Qt::Key_F3:if(iluminado)Draw_flat=!Draw_flat;break;
  case Qt::Key_F4:if(iluminado)Draw_gouraud=!Draw_gouraud;break;
  case Qt::Key_M:material=(material+1)%3;break;     //Textura 0 desde inicio.
  case Qt::Key_I:
      if(!iluminado){
          iluminado = true;
      }else{
          iluminado = false;
          apagarLuces();
      }
    break;
  case Qt::Key_J:if(iluminado)Luz1=!Luz1;break;
  case Qt::Key_K:if(iluminado)Luz2=!Luz2;break;
  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_PageUp:Observer_distance*=1.2;break;
  case Qt::Key_PageDown:Observer_distance/=1.2;break;
  }

  update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(X_MIN*ratio,X_MAX*ratio,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);        //Mantenimiento de relacion de aspecto

  //x_maxx-x_min / u_max-y_max = relacion de aspecto del nuevo x e y. width  y heyight
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{

  glMatrixMode(GL_MODELVIEW);
  Axis.draw_line();

  //En funcion del numero de material usaremos un material u otro de los 3 implementados.
  switch(material){
        case 0: Cube.usarMaterial1();break;
        case 1: Cube.usarMaterial2();break;
        case 2: Cube.usarMaterial3();break;
        default:break;
  }

  if(iluminado){
      if(Luz1)
          encenderLuz1();
      else
          apagarLuz1();

      if(Luz2)
          encenderLuz2();
      else
          apagarLuz2();
  }else{
     apagarLuces();
  }

  if(Draw_gouraud){
      switch (Object){
      case OBJECT_TETRAHEDRON:Tetrahedron.draw_gouraud();break;
      case OBJECT_CUBE:Cube.draw_gouraud();break;
      case OBJECT_CONE:Cone.draw_gouraud();break;
      case OBJECT_CILINDRO:Cilindro.draw_gouraud();break;
      case OBJECT_SPHERE:Sphere.draw_gouraud();break;
      case OBJECT_PLY:Ply.draw_gouraud();break;
      case OBJECT_REVOLUCION_PLY:Revolucion_ply.draw_gouraud();break;
      case OBJECT_TRONCO:Tronco.draw_gouraud();break;
      default:break;
      }
  }

  if(Draw_flat){
      switch (Object){
      case OBJECT_TETRAHEDRON:Tetrahedron.draw_flat();break;
      case OBJECT_CUBE:Cube.draw_flat();break;
      case OBJECT_CONE:Cone.draw_flat();break;
      case OBJECT_CILINDRO:Cilindro.draw_flat();break;
      case OBJECT_SPHERE:Sphere.draw_flat();break;
      case OBJECT_PLY:Ply.draw_flat();break;
      case OBJECT_REVOLUCION_PLY:Revolucion_ply.draw_flat();break;
      case OBJECT_TRONCO:Tronco.draw_flat();break;
      default:break;
  }
}

  if (Draw_point){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_CONE:Cone.draw_point();break;
    case OBJECT_CILINDRO:Cilindro.draw_point();break;
    case OBJECT_SPHERE:Sphere.draw_point();break;
    case OBJECT_PLY:Ply.draw_point();break;
    case OBJECT_REVOLUCION_PLY:Revolucion_ply.draw_point();break;
    case OBJECT_TRONCO:Tronco.draw_point();break;
    default:break;
    }
  }

  if (Draw_line){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_CONE:Cone.draw_line();break;
    case OBJECT_CILINDRO:Cilindro.draw_line();break;
    case OBJECT_SPHERE:Sphere.draw_line();break;
    case OBJECT_PLY:Ply.draw_line();break;
    case OBJECT_REVOLUCION_PLY:Revolucion_ply.draw_line();break;
    case OBJECT_TRONCO:Tronco.draw_line();break;
    default:break;
    }
  }

  if (Draw_fill){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
    case OBJECT_CUBE:Cube.draw_fill();break;
    case OBJECT_CONE:Cone.draw_fill();break;
    case OBJECT_CILINDRO:Cilindro.draw_fill();break;
    case OBJECT_SPHERE:Sphere.draw_fill();break;
    case OBJECT_PLY:Ply.draw_fill();break;
    case OBJECT_REVOLUCION_PLY:Revolucion_ply.draw_fill();break;
    case OBJECT_TRONCO:Tronco.draw_fill();break;
    case OBJECT_TABLERO:Tablero.TableroA();break;   //Únicamente en el caso del relleno.
    default:break;
    }
  }



  if (Draw_chess){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_CONE:Cone.draw_chess();break;
    case OBJECT_CILINDRO:Cilindro.draw_chess();break;
    case OBJECT_SPHERE:Sphere.draw_chess();break;
    case OBJECT_PLY:Ply.draw_chess();break;
    case OBJECT_REVOLUCION_PLY:Revolucion_ply.draw_chess();break;
    case OBJECT_TRONCO:Tronco.draw_chess();break;
    default:break;
    }
  }

}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
  ratio = Width1 / (float) Height1;     //Para conseguir mantener la relacion de aspecto
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";


  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  //Variables booleanas de los modos de dibujado e iluminacion
  Draw_point=false;
  Draw_line=false;
  Draw_fill=false;
  Draw_chess=false;
  Draw_flat=false;
  Draw_gouraud=false;
  Luz1=false;
  Luz2=false;

}

void _gl_widget::encenderLuz1(){    //Luz ambiente en infinito (blanco)

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat pos[] = {1.0, 1.0, 1.0, 0.0};

    glPushMatrix();
        glRotatef(angW,0,1,0);
        glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glPopMatrix();
}


void _gl_widget::encenderLuz2(){

    GLfloat luzDifusa[] = {1.0,0.0,1.0,1.0};  //Luz difusa (magenta)

    glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);

    GLfloat posInicial[] = {(GLfloat)distancia, (GLfloat)distancia, (GLfloat)distancia, 1.0};
    glPushMatrix();
        glRotatef(angZ,0,0,1);
        glRotatef(angX,1,0,0);
        glRotatef(angY,0,1,0);
        glLightfv(GL_LIGHT1, GL_POSITION, posInicial);
    glPopMatrix();

}


void _gl_widget::apagarLuces(){

    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHTING);
}


void _gl_widget::apagarLuz1(){
    glDisable(GL_LIGHT0);
}

void _gl_widget::apagarLuz2(){
    glDisable(GL_LIGHT1);
}

void _gl_widget::cargarImagen(QImage &Image){

    //Codigo aportado en la plataforma de 'Prado' por el profesor.

    // Code for reading an image
    QString File_name("/home/ivancorton/Escritorio/IG/Practicas/Practica1/skeleton/imagen.jpg");
    QImageReader Reader(File_name);
    Reader.setAutoTransform(true);
    Image = Reader.read();
    if (Image.isNull()) {
      QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                               tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
      exit(-1);
    }
    Image=Image.mirrored();
    Image=Image.convertToFormat(QImage::Format_RGB888);

}

