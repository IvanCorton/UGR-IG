#ifndef CABEZA_H
#define CABEZA_H

#include "sphere.h"
#include "antenas.h"
#include "ojo.h"
#include "conector.h"
#include "boca.h"

class _cabeza
{
private:
    _sphere Esfera;
    _ojo ojoD, ojoI;
    _antenas Antena;
    _conector Cuello;
    _boca Boca1, Boca2;
    void changeCuello();
    void changeEsfera();
    void changeAntenas();
    void changeOjoD();
    void changeOjoI();
    void changeBoca1();
    void changeBoca2();
public:
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

};

#endif // CABEZA_H
