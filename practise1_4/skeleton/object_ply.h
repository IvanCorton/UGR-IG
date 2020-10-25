#include "object3d.h"
#include "file_ply_stl.h"

#ifndef OBJECT_PLY_H
#define OBJECT_PLY_H


class _object_ply:public _object3D
{
public:
    _object_ply();
    bool read_ply();
};

#endif // OBJECT_PLY_H
