#include "size.h"
#include <iostream>
#include "position.h"
#include "directions.h"

using namespace std;

bool insert(int** arr, Position pos, Direction dir, int nCells, int mSize) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol, mSize))
        return false;
    else if(!checkDirection(nCells, trueRow, trueCol, dir, mSize))
        return false;
    else {
        arr[trueRow][trueCol] = 1;

        switch (dir) {
        case LEFT:
            arr[trueRow][trueCol - nCells] = 1;
            break;
        
        case RIGHT:
            arr[trueRow][trueCol + nCells] = 1;
            break;

        case UP:
            arr[trueRow - nCells][trueCol] = 1;
            break;

        case DOWN:
            arr[trueRow + nCells][trueCol] = 1;
            break;    
        
        default:
            break;
        }

        return true;
    }
}