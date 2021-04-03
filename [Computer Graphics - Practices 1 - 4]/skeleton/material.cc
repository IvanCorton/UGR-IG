#include "material.h"

material::material(const _vertex4f &amb, const _vertex4f &diff, const _vertex4f &spec, float brillo):ambiental(amb),difusa(diff),especular(spec),brillo(brillo){}

void material::usarMaterial(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *)&ambiental);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *)&difusa);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, (GLfloat *)&especular);
        glMaterialf(GL_FRONT, GL_SHININESS, brillo*128.0);
    glPopMatrix();
}
