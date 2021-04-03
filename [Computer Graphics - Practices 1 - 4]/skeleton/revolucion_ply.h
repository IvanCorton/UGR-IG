#ifndef REVOLUCION_PLY_H
#define REVOLUCION_PLY_H

#include "revolucion.h"
#include "file_ply_stl.h"

class _revolucion_ply:public revolucion
{
public:
    vector<_vertex3f> Perfil;
    _revolucion_ply();
};

#endif // REVOLUCION_PLY_H
