#ifndef CONECTOR_H
#define CONECTOR_H

#include "cilindro.h"

class _conector
{
private:
    _cilindro Cilindro;
   void changeCilindro();
public:
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
};

#endif // CONECTOR_H
