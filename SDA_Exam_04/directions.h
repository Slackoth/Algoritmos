#ifndef DIRECTIONS_H
#define DIRECTIONS_H

#include <iostream>

using namespace std;

#pragma region directions

bool checkUp(int nCells, int trueRow) {
    if(trueRow - nCells < 0)
        return false;
    else
        return true;
}

bool checkDown(int nCells, int trueRow, int mSize) {
    if(trueRow + nCells >= mSize)
        return false;
    else
        return true;
}

bool checkLeft(int nCells, int trueCol) {
    if(trueCol - nCells < 0)
        return false;
    else
        return true;
}

bool checkRight(int nCells, int trueCol, int mSize) {
    if(trueCol + nCells >= mSize)
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

#endif
