#include "partearribapata.h"

void _parteArribaPata::changeParte1(){

    glTranslatef(0,0,0);
    glRotatef(45,1,0,0);
    glRotatef(-45,1,0,0);
    glRotatef(-90,0,0,1);
    glScalef(0.4,0.17,0.17);
    glRotatef(90,0,0,1);

}

void _parteArribaPata::changeParte2(){

    glTranslatef(0,-35,31);
    glRotatef(45,1,0,0);
    glTranslatef(1,-30,-4);
    glRotatef(45,1,0,0);
    glRotatef(-90,0,0,1);
    glScalef(0.4,0.15,0.15);
    glRotatef(90,0,0,1);

}


void _parteArribaPata::draw_point(){

    glPushMatrix();
    changeParte1();
    Parte1.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeParte2();
    moverParte2();
    Parte2.draw_point();
    glPopMatrix();

}

void _parteArribaPata::draw_line(){


    glPushMatrix();
    changeParte1();
    Parte1.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeParte2();
    moverParte2();
    Parte2.draw_line();
    glPopMatrix();


}

void _parteArribaPata::draw_fill(){

    glPushMatrix();
    changeParte1();
    Parte1.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeParte2();
    moverParte2();
    Parte2.draw_fill();
    glPopMatrix();

}

void _parteArribaPata::draw_chess(){

    glPushMatrix();
    changeParte1();
    Parte1.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeParte2();
    moverParte2();
    Parte2.draw_chess();
    glPopMatrix();

}

void _parteArribaPata::moverParte2(){

    glRotatef(rotParte2, 1, 0, 0);
}

void _parteArribaPata::incrementarParte2(){

    rotParte2+=2;
}

void _parteArribaPata::decrementarParte2(){

    rotParte2-=2;
}
