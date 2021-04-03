#include "pie.h"

void _pie::changePie(){



}

void _pie::draw_point(){

    glPushMatrix();
    moverPie();
    Pie.draw_point();
    glPopMatrix();

}

void _pie::draw_line(){

    glPushMatrix();
    moverPie();
    Pie.draw_line();
    glPopMatrix();

}

void _pie::draw_fill(){


    glPushMatrix();
    moverPie();
    Pie.draw_fill();
    glPopMatrix();
}

void _pie::draw_chess(){

    glPushMatrix();
    moverPie();
    Pie.draw_chess();
    glPopMatrix();

}

void _pie::moverPie(){

    glRotatef(rotPie,0,1,0);

}

void _pie::incrementarPie(){

    rotPie+=10;
}

void _pie::decrementarPie(){

    rotPie-=10;
}




