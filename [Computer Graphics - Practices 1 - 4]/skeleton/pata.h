#ifndef PATA_H
#define PATA_H

#include "partearribapata.h"
#include "parteabajopata.h"

class _pata
{
public:

    _parteArribaPata ParteArriba;
    _parteAbajoPata ParteAbajo;
    void changeParteArriba();
    void changeParteAbajo();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

};

#endif // PATA_H
