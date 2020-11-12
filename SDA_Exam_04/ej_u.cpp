#include <iostream>
#include "position.h"

using namespace std;

bool checkAllDirectionsCell(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(trueRow + 1 >= mSize || trueRow - 1 < 0)
        return false;
    else if(trueCol + 1 >= mSize || trueCol - 1 < 0)
        return false;
    else
        return true;
}