#ifndef ANTENA_H
#define ANTENA_H

#include "ojo.h"
#include "cilindro.h"

class _antena
{
private:
    _ojo SemiCirc;
    _cilindro Cilindro;
    void changeSemiCircIzq();
    void changeSemiCircDer();
    void changeCilindro();
public:
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

};

#endif // ANTENA_H
