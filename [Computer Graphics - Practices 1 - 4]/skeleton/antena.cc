#include "antena.h"

void _antena::changeSemiCircIzq(){
   glTranslatef(0,-52.5,0);
   glScalef(105,105,105);
   glRotatef(90,0,1,0);
   glRotatef(180,1,0,0);
}

void _antena::changeSemiCircDer(){
   glTranslatef(0,-129,0);
   glScalef(106,50,106);
   glRotatef(270,0,1,0);
}

void _antena::changeCilindro(){
    glTranslatef(0,-86.5,0);
    glScalef(100,101,101);
    glRotatef(180,0,0,1);

}


void _antena::draw_point(){

    glPushMatrix();
    changeSemiCircIzq();
    SemiCirc.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeSemiCircDer();
    SemiCirc.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeCilindro();
    Cilindro.draw_point();
    glPopMatrix();


}
void _antena::draw_line(){

    glPushMatrix();
    changeSemiCircIzq();
    SemiCirc.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeSemiCircDer();
    SemiCirc.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeCilindro();
    Cilindro.draw_line();
    glPopMatrix();


}


void _antena::draw_fill(){

    glPushMatrix();
    changeSemiCircIzq();
    SemiCirc.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeSemiCircDer();
    SemiCirc.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeCilindro();
    Cilindro.draw_fill();
    glPopMatrix();

}



void _antena::draw_chess(){

    glPushMatrix();
    changeSemiCircIzq();
    SemiCirc.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeSemiCircDer();
    SemiCirc.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeCilindro();
    Cilindro.draw_chess();
    glPopMatrix();

}
