#include "chess_board.h"

void _chess_board::changeTablero(){

    glPushMatrix();
    glTranslatef(0,0,-0.0001);
    glScalef(1,1,0);
    Tablero.draw_fill();
    glPopMatrix();

}

void _chess_board::TableroA(){

    this->changeTablero();

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, 3,Imagen.width() ,Imagen.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, Imagen.bits());

    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.5, 0.5, 0.0);

    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5, 0.5, 0.0);

    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.5, -0.5, 0.0);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);

    glEnd();
    glDisable(GL_TEXTURE_2D);


}

