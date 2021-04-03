#ifndef REVOLUCION_H
#define REVOLUCION_H

#include "object3d.h"

class revolucion:public _object3D
{
public:
    void rotacionVertices(vector<_vertex3f> &Vertices, unsigned long tamPerfil, unsigned long numCaras);
    void triangulosCentrales(vector<_vertex3ui> &Triangles, unsigned long tamPerfil, unsigned long numCaras, unsigned long totalVertices, unsigned long &start);
    void triangulosSuperiores(vector<_vertex3ui> &Triangles, unsigned long tamPerfil, unsigned long numCaras, unsigned long totalVertices, unsigned long &start, unsigned long n_tapas);
    void triangulosInferiores(vector<_vertex3ui> &Triangles, unsigned long tamPerfil, unsigned long numCaras, unsigned long totalVertices, unsigned long &start, unsigned long n_tapas);
    void revolucionar(vector<_vertex3f> &Vertices, vector<_vertex3ui> &Triangles, unsigned long numCaras);
};

#endif // REVOLUCION_H
