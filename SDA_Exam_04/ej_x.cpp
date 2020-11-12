#include <iostream>
#include "position.h"

using namespace std;

#pragma region directions

bool checkFourLeft(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueCol - 4 < 0)
        return false;
    else
        return true;
}

bool checkFourRight(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueCol + 4 >= mSize)
        return false;
    else
        return true;
}

bool checkFourUp(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueRow - 4 < 0)
        return false;
    else
        return true;
}

bool checkFourDown(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueRow + 4 >= mSize)
        return false;
    else
        return true;
}

#pragma endregion

bool checkLogicPosition(int trueRow, int trueCol, int mSize) {
    if(trueRow < 0 || trueCol < 0)
        return false;
    else if(trueRow >= mSize || trueCol >= mSize)
        return false;
    else
        return true;
}