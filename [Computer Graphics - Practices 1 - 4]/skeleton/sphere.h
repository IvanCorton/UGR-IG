#ifndef SPHERE_H
#define SPHERE_H

#include "revolucion.h"

class _sphere:public revolucion
{
public:
    _sphere(float Size=1.0);
    void normalesEsfera();
};

#endif // SPHERE_H
