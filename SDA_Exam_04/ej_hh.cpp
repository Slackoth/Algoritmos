#include "size.h"
#include <iostream>
#include "position.h"
#include "directions.h"

using namespace std;

#pragma region insertion

bool insertFourLeft(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkLeft(4, trueCol))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow][trueCol - 4] = 1;
        
        return true;
    }
}

bool insertFourRight(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkRight(4, trueCol, mSize))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow][trueCol + 4] = 1;
        
        return true;
    }
}

bool insertFourDown(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkDown(4, trueRow, mSize))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow + 4][trueCol] = 1;
        
        return true;
    }
}

bool insertFourUp(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkUp(4, trueRow))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow - 4][trueCol] = 1;
        
        return true;
    }
}

#pragma endregion
