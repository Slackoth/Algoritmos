#include <iostream>
#include "position.h"

/*
De este ejercicio se creo la base para el archivo directions.h
para utilizarlo en ejercicios posteriores
*/

using namespace std;

enum Direction { LEFT, RIGHT, UP, DOWN };

#pragma region directions

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

bool checkDirection(int** arr, Position pos, Direction dir, int nCells, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else {
        switch (dir) {
        case LEFT:
            return checkLeft(nCells, trueCol);
            break;
        
        case RIGHT:
            return checkRight(nCells, trueCol, mSize);
            break;

        case UP:
            return checkUp(nCells, trueRow);
            break;

        case DOWN:
            return checkDown(nCells, trueRow, mSize);
            break;    
        
        default:
            return false;
            break;
        }
    }
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