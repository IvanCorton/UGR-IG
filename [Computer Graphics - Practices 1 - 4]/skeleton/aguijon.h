#ifndef AGUIJON_H
#define AGUIJON_H


#include "cone.h"
#include "ojo.h"

class _aguijon
{
private:
    _ojo Capula;
    _cone Pincho;
    void changeCapula();
    void changePincho();

public:
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

};

#endif // AGUIJON_H
