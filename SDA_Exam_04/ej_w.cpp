#include <iostream>
#include "position.h"

using namespace std;

#pragma region directions

bool checkThreeLeft(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueCol - 3 < 0)
        return false;
    else
        return true;
}

bool checkThreeRight(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueCol + 3 >= mSize)
        return false;
    else
        return true;
}

bool checkThreeUp(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueRow - 3 < 0)
        return false;
    else
        return true;
}

bool checkThreeDown(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueRow + 3 >= mSize)
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