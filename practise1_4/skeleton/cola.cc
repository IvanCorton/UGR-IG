#include "cola.h"

void _cola::changeSoporte(){

    glTranslatef(-240,0,0);
    glRotatef(-90,0,0,1);
    glScalef(8,8,8);

}

void _cola::changeAguijon(){

    glTranslatef(-253,0,0);
    glRotatef(90,0,0,1);
    glScalef(1,10,1);

}



void _cola::changeFrag1(){

    glTranslatef(-77,0,0);
    glScalef(0.5,1,1);
    glRotatef(90,0,0,1);

}

void _cola::changeFrag2(){

    glTranslatef(-130,0,0);
    glScalef(0.5,1.1,1);
    glRotatef(90,0,0,1);

}

void _cola::changeFrag3(){

    glTranslatef(-172,0,0);
    glScalef(0.4,1,0.9);
    glRotatef(90,0,0,1);

}


void _cola::changeFrag4(){

    glTranslatef(-206,0,0);
    glScalef(0.3,0.7,0.8);
    glRotatef(90,0,0,1);


}

void _cola::changeFrag5(){

    glTranslatef(-229,0,0);
    glScalef(0.2,0.5,0.6);
    glRotatef(90,0,0,1);


}

void _cola::changeFrag6(){

    glTranslatef(-242,0,0);
    glScalef(0.1,0.2,0.2);
    glRotatef(90,0,0,1);


}

void _cola::draw_point(){

    glPushMatrix();
    changeFrag1();
    Frag1.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeFrag2();
    Frag2.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeFrag3();
    Frag3.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeFrag4();
    Frag4.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeFrag5();
    Frag5.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeFrag6();
    Frag6.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeSoporte();
    Soporte.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeAguijon();
    Aguijon.draw_point();
    glPopMatrix();

}

void _cola::draw_line(){

    glPushMatrix();
    changeFrag1();
    Frag1.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeFrag2();
    Frag2.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeFrag3();
    Frag3.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeFrag4();
    Frag4.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeFrag5();
    Frag5.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeFrag6();
    Frag6.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeSoporte();
    Soporte.draw_line();
    glPopMatrix();

    glPushMatrix();
    changeAguijon();
    Aguijon.draw_line();
    glPopMatrix();
}

void _cola::draw_fill(){

    glPushMatrix();
    changeFrag1();
    Frag1.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeFrag2();
    Frag2.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeFrag3();
    Frag3.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeFrag4();
    Frag4.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeFrag5();
    Frag5.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeFrag6();
    Frag6.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeSoporte();
    Soporte.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeAguijon();
    Aguijon.draw_fill();
    glPopMatrix();

}

void _cola::draw_chess(){


    glPushMatrix();
    changeFrag1();
    Frag1.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeFrag2();
    Frag2.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeFrag3();
    Frag3.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeFrag4();
    Frag4.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeFrag5();
    Frag5.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeFrag6();
    Frag6.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeSoporte();
    Soporte.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changeAguijon();
    Aguijon.draw_chess();
    glPopMatrix();
}
