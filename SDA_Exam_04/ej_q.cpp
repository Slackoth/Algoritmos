#include "size.h"
#include <iostream>
#include "position.h"

using namespace std;

bool checkLeftCell(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(trueRow < 0 || trueCol < 0)
        return false;
    else if(trueRow >= mSize || trueCol >= mSize)
        return false;
    else if(trueCol - 1 < 0)
        return false;
    else
        return true;
}