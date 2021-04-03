#ifndef TEXTURA_H
#define TEXTURA_H

#include "glwidget.h"
#include "vertex.h"
#include <vector>

class material
{
public:
    _vertex4f ambiental, difusa, especular;
    float brillo;

    material(const _vertex4f &amb, const _vertex4f &diff, const _vertex4f &spec, float brillo);
    void usarMaterial();
};

#endif // TEXTURA_H
