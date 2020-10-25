#include "conector.h"


void _conector::changeCilindro()
{
    glScalef(1,3,1);

}

void _conector::draw_point()
{
    glPushMatrix();
    changeCilindro();
    Cilindro.draw_point();
    glPopMatrix();
}

void _conector::draw_line()
{

    glPushMatrix();
    changeCilindro();
    Cilindro.draw_line();
    glPopMatrix();

}

void _conector::draw_fill()
{

    glPushMatrix();
    changeCilindro();
    Cilindro.draw_fill();
    glPopMatrix();


}

void _conector::draw_chess()
{
    glPushMatrix();
    changeCilindro();
    Cilindro.draw_chess();
    glPopMatrix();

}

