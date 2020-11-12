#include "size.h"
#include <iostream>
#include "position.h"
#include "directions.h"

using namespace std;

#pragma region insertion

bool insertFiveLeft(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkLeft(5, trueCol))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow][trueCol - 5] = 1;
        
        return true;
    }
}

bool insertFiveRight(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkRight(5, trueCol, mSize))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow][trueCol + 5] = 1;
        
        return true;
    }
}

bool insertFiveDown(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkDown(5, trueRow, mSize))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow + 5][trueCol] = 1;
        
        return true;
    }
}

bool insertFiveUp(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkUp(5, trueRow))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow - 5][trueCol] = 1;
        
        return true;
    }
}

#pragma endregion