#ifndef TRONCO_H
#define TRONCO_H


#include "antena.h"
#include "cabeza.h"
#include "pata.h"
#include "conector.h"
#include "cola.h"
#include "boca.h"

class _tronco:public _object3D
{
private:
    _antena Tronco;
    _cabeza Cabeza;
    _conector ConectorCola;
    _ojo ConectorAlas1, ConectorAlas2;
    _cola Cola;
    _aguijon Ala1, Ala2;


    void changeConectorAlas1();
    void changeConectorAlas2();
    void changeAla1();
    void changeAla2();
    void changeCabeza();
    void changeTronco();
    void changeConectorCola();
    void changeCola();
    void changePata1();
    void changePata2();
    void changePata3();
    void changePata4();
    void changePata5();
    void changePata6();
    void changeMandibula1();
    void changeMandibula2();

public:

    _pata Pata1, Pata2, Pata3, Pata4, Pata5, Pata6;

    // Variables para movimientos.
    float rotAla1=0, rotAla2=0, rotCola=0, scaCola=1, rotCabeza=0, rotPata1=0, movPata1=0, rotPata3=0, movPata3=0, rotPata2=0, movPata2=0;

    // Movimiento del ala derecha
    void moverAla1();
    void incrementarAla1();
    void decrementarAla1();

    // Movimiento del ala izquierda
    void moverAla2();
    void incrementarAla2();
    void decrementarAla2();

    // Movimiento de la cola
    void moverCola();
    void incrementarCola();
    void decrementarCola();
    void agrandarCola();
    void menguarCola();

    // Movimiento de la cabeza
    void moverCabeza();
    void incrementarCabeza();
    void decrementarCabeza();

    // Movimiento de la pierna1
    void moverPata1();
    void incrementarPata1();
    void decrementarPata1();

    void moverPata3();
    void incrementarPata3();
    void decrementarPata3();

    void moverPata5();
    void incrementarPata5();
    void decrementarPata5();

    void moverPata2();
    void incrementarPata2(); //Este decrementara
    void decrementarPata2(); //Este incrementara

    void moverPata4();
    void incrementarPata4();
    void decrementarPata4();

    void moverPata6();
    void incrementarPata6();
    void decrementarPata6();


    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

};

#endif // TRONCO_H
