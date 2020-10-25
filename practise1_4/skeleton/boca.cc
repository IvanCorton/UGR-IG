#include "boca.h"


//-------------------------------
// Lado Derecho (de frente)

void _boca::changePincho6(){

    glTranslatef(0,0.15,-0.05);
    glRotatef(90,1,0,0);
    glScalef(0.2,0.2,0.2);

}

void _boca::changePincho7(){

    glTranslatef(0,0.35,-0.05);
    glRotatef(90,1,0,0);
    glScalef(0.2,0.2,0.2);

}

void _boca::changePincho8(){

    glTranslatef(0,0.45,-0.02);
    glRotatef(90,1,0,0);
    glScalef(0.2,0.2,0.2);
}

void _boca::changePincho9(){

    glTranslatef(0,0.55,-0.02);
    glRotatef(90,1,0,0);
    glScalef(0.2,0.2,0.2);
}

void _boca::changePincho10(){

    glTranslatef(0,0.65,-0.02);
    glRotatef(90,1,0,0);
    glScalef(0.2,0.2,0.2);
}

void _boca::changePincho11(){

    glTranslatef(0,0.75,-0.02);
    glRotatef(90,1,0,0);
    glScalef(0.2,0.2,0.2);
}

void _boca::changePincho12(){

    glTranslatef(0,0.85,-0.02);
    glRotatef(90,1,0,0);
    glScalef(0.2,0.2,0.2);
}

void _boca::changePincho13(){

    glTranslatef(0,0.25,-0.02);
    glRotatef(90,1,0,0);
    glScalef(0.2,0.2,0.2);
}

/*void _boca::changeParteSup1(){

    glTranslatef(0,0.5,-0.05);
    glScalef(0.1,1,1);
    glRotatef(-90,1,0,0);

void _boca::changeParteInf1(){

     glTranslatef(0,0.1,0.3);
    glRotatef(90,0,1,0);
    glScalef(0.4,0.4,0.1);

}


}*/

void _boca::changeParteSup2(){

    glTranslatef(0,0.5,0.05);
    glScalef(0.2,1,1);
    glRotatef(90,1,0,0);


}



void _boca::changeParteInf2(){

     glTranslatef(0,0.1,-0.3);
    glRotatef(90,0,1,0);
    glScalef(0.4,0.4,0.1);

}

void _boca::draw_point(){

    glPushMatrix();
    changeParteInf2();
    ParteInf2.draw_point();
    glPopMatrix();

    glPushMatrix();
    changeParteSup2();
    ParteSup2.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePincho6();
    Pincho.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePincho7();
    Pincho.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePincho8();
    Pincho.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePincho9();
    Pincho.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePincho10();
    Pincho.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePincho11();
    Pincho.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePincho12();
    Pincho.draw_point();
    glPopMatrix();

    glPushMatrix();
    changePincho13();
    Pincho.draw_point();
    glPopMatrix();

}

void _boca::draw_line(){


    glPushMatrix();
    changeParteInf2();
    ParteInf2.draw_line();
    glPopMatrix();


    glPushMatrix();
    changeParteSup2();
    ParteSup2.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePincho6();
    Pincho.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePincho7();
    Pincho.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePincho8();
    Pincho.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePincho9();
    Pincho.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePincho10();
    Pincho.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePincho11();
    Pincho.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePincho12();
    Pincho.draw_line();
    glPopMatrix();

    glPushMatrix();
    changePincho13();
    Pincho.draw_line();
    glPopMatrix();

}

void _boca::draw_fill(){


    glPushMatrix();
    changeParteInf2();
    ParteInf2.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changeParteSup2();
    ParteSup2.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePincho6();
    Pincho.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePincho7();
    Pincho.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePincho8();
    Pincho.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePincho9();
    Pincho.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePincho10();
    Pincho.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePincho11();
    Pincho.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePincho12();
    Pincho.draw_fill();
    glPopMatrix();

    glPushMatrix();
    changePincho13();
    Pincho.draw_fill();
    glPopMatrix();
}

void _boca::draw_chess(){

    glPushMatrix();
    changeParteInf2();
    ParteInf2.draw_chess();
    glPopMatrix();


    glPushMatrix();
    changeParteSup2();
    ParteSup2.draw_chess();
    glPopMatrix();

   /*
    *
    * Decidi que seria mas conveniente usar
    * por un lado una mandibula, anadiendo al tronco
    * dos objetos de esta clase para poder darle
    * movimientos a la boca por separado, aunque por falta
    * de organizacion no pude animar tanto como deseaba
    * la 'avispa'.
    *
    * glPushMatrix();
    changePincho1();
    Pincho.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePincho2();
    Pincho.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePincho3();
    Pincho.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePincho4();
    Pincho.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePincho5();
    Pincho.draw_chess();
    glPopMatrix();*/

    glPushMatrix();
    changePincho6();
    Pincho.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePincho7();
    Pincho.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePincho8();
    Pincho.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePincho9();
    Pincho.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePincho10();
    Pincho.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePincho11();
    Pincho.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePincho12();
    Pincho.draw_chess();
    glPopMatrix();

    glPushMatrix();
    changePincho13();
    Pincho.draw_chess();
    glPopMatrix();


}
