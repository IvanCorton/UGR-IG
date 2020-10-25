#include "antenas.h"

void _antenas::changeAntena1()
{
    glTranslatef(25,16,3);
    glRotatef(-15,1,0,0);
    glRotatef(-90,0,0,1);
    glScalef(1,0.16,0.16);
    glRotatef(90,0,0,1);

}

void _antenas::changeAntena2()
{


    glTranslatef(-25,16,3);
    glRotatef(-15,1,0,0);
    glRotatef(-90,0,0,1);
    glScalef(1,0.16,0.16);
    glRotatef(90,0,0,1);

}

void _antenas::changeConector1(){


    glTranslatef(25,-37,-11);
    glRotatef(65,1,0,0);
    glScalef(16,16,16);

}

void _antenas::changeConector2(){

    glTranslatef(-25,-37,-11);
    glRotatef(65,1,0,0);
    glScalef(16,16,16);

}

void _antenas::draw_point()
{
    glPushMatrix();
    changeAntena1();
    Antena1.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeConector1();
    Conector1.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeAntena2();
    Antena2.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeConector2();
    Conector2.draw_point();
    glPopMatrix();
}

void _antenas::draw_line()
{

    glPushMatrix();
    changeAntena1();
    Antena1.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeConector1();
    Conector1.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeAntena2();
    Antena2.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeConector2();
    Conector2.draw_line();
    glPopMatrix();

}

void _antenas::draw_fill()
{

    glPushMatrix();
    changeAntena1();
    Antena1.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeConector1();
    Conector1.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeAntena2();
    Antena2.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeConector2();
    Conector2.draw_fill();
    glPopMatrix();


}

void _antenas::draw_chess()
{
    glPushMatrix();
    changeAntena1();
    Antena1.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeConector1();
    Conector1.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeAntena2();
    Antena2.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeConector2();
    Conector2.draw_chess();
    glPopMatrix();

}
