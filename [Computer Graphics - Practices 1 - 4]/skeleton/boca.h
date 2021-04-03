#ifndef BOCA_H
#define BOCA_H

#include "semi.h"
#include "sphere.h"
#include "aguijon.h"

class _boca
{
private:
    _semi ParteSup1, ParteSup2;
    _sphere ParteInf1, ParteInf2;
    _aguijon Pincho;

    // El motivo por el que empieza en el 6 es que en un
    // primer momento pense en introducir 13 pinchos para la boca,
    // pero tras varias pruebas comprobe que unicamente necesitariamos los de un lado
    // para construir los de la otra parte de la boca.

    void changePincho6();
    void changePincho7();
    void changePincho8();
    void changePincho9();
    void changePincho10();
    void changePincho11();
    void changePincho12();
    void changePincho13();
    void changeParteSup2();
    void changeParteInf2();

public:
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
};

#endif // BOCA_H
