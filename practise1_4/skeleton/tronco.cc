#include "tronco.h"

//  Traslate siempre primero


void _tronco::changeConectorAlas1(){

    glTranslatef(4,1.2,9.7);
    glRotatef(-90,1,0,0);
    glScalef(2,2,2);
}

void _tronco::changeConectorAlas2(){

    glTranslatef(4,1.2,-9.7);
    glRotatef(90,1,0,0);
    glScalef(2,2,2);

}

void _tronco::changeAla1(){

    glTranslatef(4.2,1.1,10.5);
    glRotatef(-25,1,0,0);
    glRotatef(20,0,1,0);
    glRotatef(-90,0,0,1);
    glScalef(35,55,1);

}

void _tronco::changeAla2(){

    glTranslatef(4.2,1.1,-10.5);
    glRotatef(25,1,0,0);
    glRotatef(-20,0,1,0);
    glRotatef(-90,0,0,1);
    glScalef(35,55,1);
}

void _tronco::changeTronco(){

    glTranslatef(-27,0,0);
    glScalef(0.3, 0.2,0.2);
    glRotatef(90,0,0,1);

}

void _tronco::changeCabeza(){

    glScalef(0.2,0.4,0.4);
    glTranslatef(87,25,0);
    glRotatef(90,0,1,0);

}


void _tronco::changeCola(){

    glTranslatef(-20,0,0);
    glScalef(0.3,0.3,0.3);

}

void _tronco::changePata1(){

    glTranslatef(11,-5,4);
    glRotatef(180,0,1,0);
    glRotatef(30,1,0,0);
    glScalef(0.3,0.3,0.3);

}

void _tronco::changePata2(){

    glTranslatef(0,-5,4);
    glRotatef(180,0,1,0);
    glRotatef(30,1,0,0);
    glScalef(0.3,0.3,0.3);

}

void _tronco::changePata3(){

    glTranslatef(-11,-5,4);
    glRotatef(180,0,1,0);
    glRotatef(30,1,0,0);
    glScalef(0.3,0.3,0.3);

}

void _tronco::changePata4(){

    glTranslatef(11,-5,-4);
    glRotatef(30,1,0,0);
    glScalef(0.3,0.3,0.3);

}

void _tronco::changePata5(){

    glTranslatef(0,-5,-4);
    glRotatef(30,1,0,0);
    glScalef(0.3,0.3,0.3);

}

void _tronco::changePata6(){

    glTranslatef(-11,-5,-4);
    glRotatef(30,1,0,0);
    glScalef(0.3,0.3,0.3);

}


/*
 *
 * void _tronco::changeMandibula1(){

    glTranslatef(28,-6,0);
    glScalef(11,8,10);

}


void _tronco::changeMandibula2(){

    glTranslatef(28,-6,0);
    glScalef(11,8,10);
    glRotatef(180,0,1,0);

}

***************************************/

void _tronco::draw_point()
{
    glPushMatrix();
    changeTronco();
    Tronco.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeCabeza();
    moverCabeza();
    Cabeza.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePata1();
    moverPata1();
    Pata1.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePata2();
    moverPata2();
    Pata2.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePata3();
    moverPata3();
    Pata3.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePata4();
    moverPata4();
    Pata4.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePata5();
    moverPata5();
    Pata5.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePata6();
    moverPata6();
    Pata6.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeCola();
    moverCola();
    Cola.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeAla1();
    moverAla1();
    Ala1.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeAla2();
    moverAla2();
    Ala2.draw_point();
    glPopMatrix();


    glPushMatrix();
    changeConectorAlas1();
    ConectorAlas1.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeConectorAlas2();
    ConectorAlas2.draw_point();
    glPopMatrix();

    /*glPushMatrix();
    changeMandibula1();
    Mandibula1.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeMandibula2();
    Mandibula2.draw_point();
    glPopMatrix();
*/

}

void _tronco::draw_line()
{
    glPushMatrix();
    changeTronco();
    Tronco.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeCabeza();
    moverCabeza();
    Cabeza.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePata1();
    moverPata1();
    Pata1.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePata2();
    moverPata2();
    Pata2.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePata3();
    moverPata3();
    Pata3.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePata4();
    moverPata4();
    Pata4.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePata5();
    moverPata5();
    Pata5.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePata6();
    moverPata6();
    Pata6.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeCola();
    moverCola();
    Cola.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeAla1();
    moverAla1();
    Ala1.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeAla2();
    moverAla2();
    Ala2.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeConectorAlas1();
    ConectorAlas1.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeConectorAlas2();
    ConectorAlas2.draw_line();
    glPopMatrix();

    /*
    glPushMatrix();
    changeMandibula1();
    Mandibula1.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeMandibula2();
    Mandibula2.draw_line();
    glPopMatrix();
*/
}

void _tronco::draw_fill()
{


    glPushMatrix();
    changeTronco();
    Tronco.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeCabeza();
    moverCabeza();
    Cabeza.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePata1();
    moverPata1();
    Pata1.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePata2();
    moverPata2();
    Pata2.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePata3();
    moverPata3();
    Pata3.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePata4();
    moverPata4();
    Pata4.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePata5();
    moverPata5();
    Pata5.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePata6();
    moverPata6();
    Pata6.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeCola();
    moverCola();
    Cola.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeAla1();
    moverAla1();
    Ala1.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeAla2();
    moverAla2();
    Ala2.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeConectorAlas1();
    ConectorAlas1.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeConectorAlas2();
    ConectorAlas2.draw_fill();
    glPopMatrix();
/*
    glPushMatrix();
    changeMandibula1();
    Mandibula1.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeMandibula2();
    Mandibula2.draw_fill();
    glPopMatrix();
*/
}

void _tronco::draw_chess()
{

    glPushMatrix();
    changeTronco();
    Tronco.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeCabeza();
    moverCabeza();
    Cabeza.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePata1();
    moverPata1();
    Pata1.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePata2();
    moverPata2();
    Pata2.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePata3();
    moverPata3();
    Pata3.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePata4();
    moverPata4();
    Pata4.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePata5();
    moverPata5();
    Pata5.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePata6();
    moverPata6();
    Pata6.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeCola();
    moverCola();
    Cola.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeAla1();
    moverAla1();
    Ala1.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeAla2();
    moverAla2();
    Ala2.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeConectorAlas1();
    ConectorAlas1.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeConectorAlas2();
    ConectorAlas2.draw_chess();
    glPopMatrix();
/*
    glPushMatrix();
    changeMandibula1();
    Mandibula1.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeMandibula2();
    Mandibula2.draw_chess();
    glPopMatrix();
*/

}

void _tronco::moverAla1(){

    glRotatef(rotAla1,0,1,0);
    glRotatef(rotAla1,0,0,1);

}

void _tronco::incrementarAla1(){
    rotAla1 += 3;
}

void _tronco::decrementarAla1(){
    rotAla1 -= 3;
}

/************************************/

void _tronco::moverAla2(){

    glRotatef(rotAla2,0,1,0);
    glRotatef(rotAla2,0,0,1);

}

void _tronco::incrementarAla2(){
    rotAla2 += 3;
}

void _tronco::decrementarAla2(){
    rotAla2 -= 3;
}

/************************************/

void _tronco::moverCola(){

    glRotatef(rotCola,0,0,1);
    glScalef(scaCola,1,1);

}

void _tronco::incrementarCola(){
    rotCola += 1.5;
}

void _tronco::decrementarCola(){
    rotCola -= 1.5;
}

void _tronco::agrandarCola(){
    scaCola += .05;
}

void _tronco::menguarCola(){
    scaCola -= .05;
}




/************************************/


void _tronco::moverCabeza(){

    glRotatef(rotCabeza,0,1,0);
}

void _tronco::incrementarCabeza(){
    rotCabeza += 2;
}

void _tronco::decrementarCabeza(){
    rotCabeza -= 2;
}

/****************************************/

void _tronco::moverPata1(){

   // glRotatef(rotPata1, 1,0,0);
    glTranslatef(1,movPata1,1);
    glRotatef(rotPata1, 0,1,0);

}

void _tronco::incrementarPata1(){

    rotPata1+=3;
    movPata1+=0.6;

}

void _tronco::decrementarPata1(){

    rotPata1-=3;
    movPata1-=0.6;

}

void _tronco::moverPata3(){

    glTranslatef(1,movPata3,1);
    glRotatef(rotPata3, 0,1,0);

}

void _tronco::incrementarPata3(){

    rotPata3+=3;
    movPata3+=0.6;

}

void _tronco::decrementarPata3(){

    rotPata3-=3;
    movPata3-=0.6;

}

void _tronco::moverPata2(){

    glTranslatef(1,movPata2,1);
    glRotatef(rotPata2, 0,1,0);

}

void _tronco::incrementarPata2(){

    rotPata2-=3;
    movPata2-=0.6;

}

void _tronco::decrementarPata2(){

    rotPata2+=3;
    movPata2+=0.6;

}


void _tronco::moverPata4(){

    glTranslatef(1,movPata1,1);
    glRotatef(rotPata1, 0,1,0);

}

void _tronco::moverPata5(){

    glTranslatef(1,movPata2,1);
    glRotatef(rotPata2, 0,1,0);

}

void _tronco::moverPata6(){

    glTranslatef(1,movPata1,1);
    glRotatef(rotPata1, 0,1,0);

}
