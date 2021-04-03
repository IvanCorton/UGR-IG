#ifndef PARTEABAJOPATA_H
#define PARTEABAJOPATA_H

#include "antena.h"
#include "pie.h"

class _parteAbajoPata
{
public:
    _antena Parte3;
    _pie Pie;
    float rotParte2=0, movParte2=0;
    void changeParte3();
    void changePie();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

    void moverParte2();
    void incrementarParte2();
    void decrementarParte2();

};

#endif // PARTEABAJOPATA_H
