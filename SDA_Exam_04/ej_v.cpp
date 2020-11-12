#include <iostream>
#include "position.h"

using namespace std;

#pragma region directions

bool checkTwoLeft(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueCol - 2 < 0)
        return false;
    else
        return true;
}

bool checkTwoRight(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueCol + 2 >= mSize)
        return false;
    else
        return true;
}

bool checkTwoUp(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueRow - 2 < 0)
        return false;
    else
        return true;
}

bool checkTwoDown(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueRow + 2 >= mSize)
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
