#include "aguijon.h"

void _aguijon::changeCapula(){

    glTranslatef(0,-0.92,0);
    glScalef(0.53,0.5,0.53);

}
void _aguijon::changePincho(){

    glTranslatef(0,-0.5,0);
    glScalef(0.5,1,0.5);

}

void _aguijon::draw_point(){

    glPushMatrix();
    changeCapula();
    Capula.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePincho();
    Pincho.draw_point();
    glPopMatrix();
}

void _aguijon::draw_line(){

    glPushMatrix();
    changeCapula();
    Capula.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePincho();
    Pincho.draw_line();
    glPopMatrix();

}

void _aguijon::draw_fill(){


    glPushMatrix();
    changeCapula();
    Capula.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePincho();
    Pincho.draw_fill();
    glPopMatrix();
}

void _aguijon::draw_chess(){


    glPushMatrix();
    changeCapula();
    Capula.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePincho();
    Pincho.draw_chess();
    glPopMatrix();
}
