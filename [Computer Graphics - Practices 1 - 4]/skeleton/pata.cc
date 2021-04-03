#include "pata.h"

void _pata::changeParteArriba(){


}

void _pata::changeParteAbajo(){


}

void _pata::draw_point(){

    glPushMatrix();
    changeParteArriba();
    ParteArriba.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeParteAbajo();
    ParteAbajo.draw_point();
    glPopMatrix();

}

void _pata::draw_line(){

    glPushMatrix();
    changeParteArriba();
    ParteArriba.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeParteAbajo();
    ParteAbajo.draw_line();
    glPopMatrix();


}


void _pata::draw_fill(){


    glPushMatrix();
    changeParteArriba();
    ParteArriba.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeParteAbajo();
    ParteAbajo.draw_fill();
    glPopMatrix();


}


void _pata::draw_chess(){

    glPushMatrix();
    changeParteArriba();
    ParteArriba.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeParteAbajo();
    ParteAbajo.draw_chess();
    glPopMatrix();


}

/*********************************************/
// Movimientos de las partes de las piernas.
