#include "size.h"
#include <iostream>
#include "position.h"
#include "directions.h"

using namespace std;

#pragma region insertion

bool insertTwoLeft(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkLeft(2, trueCol))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow][trueCol - 2] = 1;
        
        return true;
    }
}

bool insertTwoRight(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkRight(2, trueCol, mSize))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow][trueCol + 2] = 1;
        
        return true;
    }
}

bool insertTwoDown(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkDown(2, trueRow, mSize))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow + 2][trueCol] = 1;
        
        return true;
    }
}

bool insertTwoUp(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkUp(2, trueRow))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow - 2][trueCol] = 1;
        
        return true;
    }
}

#pragma endregion