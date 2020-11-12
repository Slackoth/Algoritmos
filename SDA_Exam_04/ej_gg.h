#include "size.h"
#include <iostream>
#include "position.h"
#include "directions.h"

using namespace std;

#pragma region insertion

bool insertThreeLeft(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkLeft(3, trueCol))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow][trueCol - 3] = 1;
        
        return true;
    }
}

bool insertThreeRight(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkRight(3, trueCol, mSize))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow][trueCol + 3] = 1;
        
        return true;
    }
}

bool insertThreeDown(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkDown(3, trueRow, mSize))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow + 3][trueCol] = 1;
        
        return true;
    }
}

bool insertThreeUp(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkUp(3, trueRow))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow - 3][trueCol] = 1;
        
        return true;
    }
}

#pragma endregion