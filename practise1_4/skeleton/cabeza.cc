#include "cabeza.h"

void _cabeza::changeEsfera()
{
    glTranslatef(0,0,31);
    glRotatef(-45,1,0,0);
    glScalef(50,70,35);

}

void _cabeza::changeCuello(){

    glTranslatef(0, -15, 11);
    glRotatef(50,1,0,0);
    glScalef(11,6,11);

}


void _cabeza::changeOjoD(){

    glTranslatef(-14,9,30);
    glScalef(10,10,10);
    glRotatef(-35,0,1,0);
    glRotatef(20,0,0,1);
    glRotatef(227,1,0,0);
    glScalef(2,2,4);
}

void _cabeza::changeOjoI(){

    glTranslatef(14,9,30);
    glScalef(10,10,10);
    glRotatef(-20,0,0,1);
    glRotatef(35,0,1,0);
    glRotatef(215.5,1,0,0);
    glScalef(2,2,4);
}


//Solo le queda ajustar tamaño y posicion.

void _cabeza::changeAntenas(){
    glTranslatef(0,30,50);
    glRotatef(90,1,0,0);
    glRotatef(242,1,0,0);
    glScalef(0.47, 0.47, 0.47);
}


void _cabeza::changeBoca1(){

    glTranslatef(0,-39,52);
    glScalef(21,18,22);
    glRotatef(90,0,1,0);

}


void _cabeza::changeBoca2(){

    glTranslatef(0,-39,52);
    glScalef(21,18,22);
    glRotatef(270,0,1,0);


}

void _cabeza::draw_point()
{
    glPushMatrix();
    changeEsfera();
    Esfera.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeAntenas();
    Antena.draw_point();
    glPopMatrix();


    glPushMatrix();
    changeOjoD();
    ojoD.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeOjoI();
    ojoI.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeCuello();
    Cuello.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeBoca1();
    Boca1.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeBoca2();
    Boca2.draw_point();
    glPopMatrix();
}

void _cabeza::draw_line()
{

    glPushMatrix();
    changeEsfera();
    Esfera.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeAntenas();
    Antena.draw_line();
    glPopMatrix();


    glPushMatrix();
    changeOjoD();
    ojoD.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeOjoI();
    ojoI.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeCuello();
    Cuello.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeBoca1();
    Boca1.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeBoca2();
    Boca2.draw_line();
    glPopMatrix();

}

void _cabeza::draw_fill()
{

    glPushMatrix();
    changeEsfera();
    Esfera.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeAntenas();
    Antena.draw_fill();
    glPopMatrix();


    glPushMatrix();
    changeOjoD();
    ojoD.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeOjoI();
    ojoI.draw_fill();
    glPopMatrix();


    glPushMatrix();
    changeCuello();
    Cuello.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeBoca1();
    Boca1.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeBoca2();
    Boca2.draw_fill();
    glPopMatrix();


}

void _cabeza::draw_chess()
{
    glPushMatrix();
    changeEsfera();
    Esfera.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeAntenas();
    Antena.draw_chess();
    glPopMatrix();


    glPushMatrix();
    changeOjoD();
    ojoD.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeOjoI();
    ojoI.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeCuello();
    Cuello.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeBoca1();
    Boca1.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeBoca2();
    Boca2.draw_chess();
    glPopMatrix();
}
