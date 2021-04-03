#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "cube.h"
#include <QImage>

class _chess_board
{
public:
    void changeTablero();
    _cube Tablero;
    QImage Imagen;
    void TableroA();

};

#endif // CHESS_BOARD_H
