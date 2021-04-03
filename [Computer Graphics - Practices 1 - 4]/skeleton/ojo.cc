#include "ojo.h"

_ojo::_ojo(float Size)
{

    unsigned int numCaras = 40, numVertices = 20;
    const float PI = 3.141592, rotacion = PI/numVertices;
    float angulo, tam = Size/2;

            //Vector del perfil
            Vertices.resize((numVertices+1)/2);

            for(unsigned int i = 1;i<numVertices/2; i++){
                angulo= i*rotacion - (PI/2);
                Vertices[i-1] = _vertex3f(tam*cos(angulo), tam*sin(angulo), 0);
            }

            Vertices[Vertices.size()-1] = _vertex3f(Vertices[Vertices.size()-3]._0, Vertices[Vertices.size()-3]._1, 0);

            Vertices[Vertices.size()-2]= _vertex3f(0, -tam, 0);

    revolucionar(Vertices, Triangles, numCaras);

    this->calcularNormales();


}
