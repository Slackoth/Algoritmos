#include "size.h"
#include <iostream>
#include "position.h"
#include "directions.h"

using namespace std;

// const int ROW_SIZE = 11;
// const int COL_SIZE = 11;

// #pragma region prototypes

// bool checkUp(int nCells, int trueRow);
// bool checkDown(int nCells, int trueRow);
// bool checkLeft(int nCells, int trueCol);
// bool checkRight(int nCells, int trueCol);
// bool insertFiveUp(int** arr, Position pos);
// bool insertFiveDown(int** arr, Position pos);
// bool insertFiveLeft(int** arr, Position pos);
// bool insertFiveRight(int** arr, Position pos);
// bool checkLogicPosition(int trueRow, int trueCol);

// #pragma endregion

// int main() {
//     int** arr = new int*[ROW_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         arr[i] = new int[COL_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         for(int j = 0; j < COL_SIZE; j++)
//             arr[i][j] = 0;
    
//     cout << (insertFiveLeft(arr, Position(6, 6)) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";
//     cout << (insertFiveRight(arr, Position(6, 6)) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";
//     cout << (insertFiveUp(arr, Position(6, 6)) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";
//     cout << (insertFiveDown(arr, Position(6, 6)) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";

//     for(int i = 0; i < ROW_SIZE; i++) {
//         for(int j = 0; j < COL_SIZE; j++)
//             cout << arr[i][j] << "\t";
//         cout << "\n";
//     }

//     return 0;
// }

// #pragma region directions

// bool checkUp(int nCells, int trueRow) {
//     if(trueRow - nCells < 0)
//         return false;
//     else
//         return true;
// }

// bool checkDown(int nCells, int trueRow) {
//     if(trueRow + nCells >= ROW_SIZE)
//         return false;
//     else
//         return true;
// }

// bool checkLeft(int nCells, int trueCol) {
//     if(trueCol - nCells < 0)
//         return false;
//     else
//         return true;
// }

// bool checkRight(int nCells, int trueCol) {
//     if(trueCol + nCells >= COL_SIZE)
//         return false;
//     else
//         return true;
// }

// #pragma endregion

// bool checkLogicPosition(int trueRow, int trueCol) {
//     if(trueRow < 0 || trueCol < 0)
//         return false;
//     else if(trueRow >= ROW_SIZE || trueCol >= COL_SIZE)
//         return false;
//     else
//         return true;
// }

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