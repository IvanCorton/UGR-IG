#ifndef ANTENAS_H
#define ANTENAS_H

#include "antena.h"
#include "conector.h"

class _antenas
{
private:
    _antena Antena1, Antena2;
    _conector Conector1;
    _conector Conector2;
    void changeAntena1();
    void changeAntena2();
    void changeConector1();
    void changeConector2();
public:
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
};

#endif // ANTENAS_H
