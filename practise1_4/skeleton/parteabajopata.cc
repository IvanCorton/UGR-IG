#include "parteabajopata.h"


void _parteAbajoPata::changeParte3(){

    glTranslatef(0,-50,-47);
    glRotatef(270,1,0,0);
    glRotatef(90,0,1,0);
    glScalef(0.3,0.12,0.12);
    glRotatef(90,0,0,1);

}

void _parteAbajoPata::changePie(){

    glTranslatef(0,-91,-45);
    glRotatef(90,0,0,1);
    glRotatef(110,0,1,0);
    glScalef(0.2,0.1,0.05);
    glRotatef(90,0,0,1);

}

void _parteAbajoPata::draw_point(){

    glPushMatrix();
    changeParte3();
    moverParte2();
    Parte3.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePie();
    Pie.draw_point();
    glPopMatrix();

}

void _parteAbajoPata::draw_line(){

    glPushMatrix();
    changeParte3();
    moverParte2();
    Parte3.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePie();
    Pie.draw_line();
    glPopMatrix();

}

void _parteAbajoPata::draw_fill(){

    glPushMatrix();
    changeParte3();
    moverParte2();
    Parte3.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePie();
    Pie.draw_fill();
    glPopMatrix();

}

void _parteAbajoPata::draw_chess(){

    glPushMatrix();
    changeParte3();
    moverParte2();
    Parte3.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePie();
    Pie.draw_chess();
    glPopMatrix();

}


void _parteAbajoPata::moverParte2(){

    glTranslatef(1,movParte2,1);
    glRotatef(rotParte2, 0, 0, 1);

}

void _parteAbajoPata::incrementarParte2(){

    rotParte2+=2;
    movParte2+=0.3;
}

void _parteAbajoPata::decrementarParte2(){

    rotParte2-=2;
    movParte2-=0.3;
}




