#ifndef POSITION_H
#define POSITION_H

struct Position {
    int row, col;

    Position() {}
    Position(int _r, int _c): row(_r), col(_c) {}
};

#endif