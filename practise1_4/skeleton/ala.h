#ifndef ALA_H
#define ALA_H

#include "cone.h"
#include "ojo.h"

class _ala
{
private:
    _ojo Curvatura;
    _cone Cuerpo;
    void changeCurvatura();
    void changeCuerpo();

public:
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

};

#endif // ALA_H
