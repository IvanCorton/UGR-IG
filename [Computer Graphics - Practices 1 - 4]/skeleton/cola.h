#ifndef COLA_H
#define COLA_H

#include "antena.h"
#include "aguijon.h"
#include "ojo.h"

class _cola
{
private:
    _antena Frag1, Frag2, Frag3, Frag4, Frag5, Frag6;
    _aguijon Aguijon;
    _ojo Soporte;
    void changeSoporte();
    void changeAguijon();
    void changeFrag1();
    void changeFrag2();
    void changeFrag3();
    void changeFrag4();
    void changeFrag5();
    void changeFrag6();

public:

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
};

#endif // COLA_H
