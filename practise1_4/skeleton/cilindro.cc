#include "cilindro.h"
#include <vector>

_cilindro::_cilindro(float Size)
{

    Vertices.resize(4);

    unsigned int numCaras = 41;

    //Vector del perfil

    Vertices[0]=_vertex3f(Size/2,-Size/2,0);
    Vertices[1]=_vertex3f(Size/2,Size/2,0);
    Vertices[2]=_vertex3f(0,-Size/2,0);
    Vertices[3]=_vertex3f(0,Size/2,0);

   revolucion::revolucionar(Vertices, Triangles, numCaras);

   this->calcularNormales();
}
