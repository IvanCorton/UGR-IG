#include "sphere.h"

_sphere::_sphere(float Size)
{

    unsigned int numCaras = 50, numVertices = 50;
    const float PI = 3.141592, rotacion = PI/numVertices;
    float angulo, tam = Size/2;

            //Vector del perfil
            Vertices.resize(numVertices+1);

            for(unsigned int i = 1;i<numVertices; i++){
                angulo= i*rotacion - (PI/2);
                Vertices[i-1] = _vertex3f(tam*cos(angulo), tam*sin(angulo), 0);
            }

            Vertices[Vertices.size()-1]= _vertex3f(0, tam, 0);
            Vertices[Vertices.size()-2]= _vertex3f(0, -tam, 0);

    revolucionar(Vertices, Triangles, numCaras);

    this->calcularNormales();
    this->normalesEsfera();

}

void _sphere::normalesEsfera(){     //Intento de metodo que hace mas eficiente el calculo de normales

    //Para ello trataremos de normalizar mediante la funcion 'normalize'
    //evitando todo el lio de calculo de normales que se realiza en 'calcularNormales' de Object3D

    _vertex3f Aux;

    normalesVertices.resize(Vertices.size());

    for(unsigned long i=0; i<Vertices.size(); i++){
        Aux = Vertices[i];
        Aux = Aux.normalize();
        normalesVertices[i] = Aux;
    }
}
