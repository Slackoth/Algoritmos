#include <iostream>
#include "position.h"

using namespace std;

#pragma region directions

/*
La verificacion se realiza con los indices reales de de
los arreglos y por eso existen trueRow y trueCol
*/

bool checkFiveLeft(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueCol - 5 < 0)
        return false;
    else
        return true;
}

bool checkFiveRight(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueCol + 5 >= mSize)
        return false;
    else
        return true;
}

bool checkFiveUp(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueRow - 5 < 0)
        return false;
    else
        return true;
}

bool checkFiveDown(int** arr, Position pos, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(trueRow + 5 >= mSize)
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