#ifndef PARTEARRIBAPATA_H
#define PARTEARRIBAPATA_H

#include "antena.h"

class _parteArribaPata
{
public:
    _antena Parte1, Parte2;
    float rotParte2=0;
    void changeParte1();
    void changeParte2();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

    void moverParte2();
    void incrementarParte2();
    void decrementarParte2();

};

#endif // PARTEARRIBAPATA_H
