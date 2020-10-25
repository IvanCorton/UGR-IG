#include "cone.h"
#include <vector>


_cone::_cone(float Size)
{

    Vertices.resize(3);

    unsigned int numCaras = 20;

    //Vector del perfil
    Vertices[2]=_vertex3f(0,Size/2,0);
    Vertices[0]=_vertex3f(Size/2,-Size/2,0);
    Vertices[1]=_vertex3f(0,-Size/2,0);

    revolucion::revolucionar(Vertices, Triangles, numCaras);

    this->calcularNormales();

}

//QTabs
//QGridLayout       Punteros = new ....
//QCheckBox
//QLabel
//addwidget
//Comentar connect para poder modificar
//Signal -> Señal a recibir de un widget    Slot -> Señal a enviar de un widget     widget- widget->funcion - funcion.
