#ifndef PIE_H
#define PIE_H

#include "antena.h"

class _pie
{
public:
    float rotPie=0;
    _antena Pie;

     void changePie();

     void draw_point();
     void draw_line();
     void draw_fill();
     void draw_chess();

     void moverPie();
     void incrementarPie();
     void decrementarPie();

};

#endif // PIE_H
