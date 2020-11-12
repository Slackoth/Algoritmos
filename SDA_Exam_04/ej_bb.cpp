#include "size.h"
#include <iostream>
#include "position.h"
#include "directions.h"

using namespace std;

bool insertOneRight(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkRight(1, trueCol, mSize))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow][trueCol + 1] = 1;
        
        return true;
    }
}