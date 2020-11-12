#include "size.h"
#include <iostream>
#include "position.h"
#include "directions.h"

using namespace std;

// const int ROW_SIZE = 5;
// const int MATRIX_SIZE = 5;

/*
// struct Position {
//     int row, col;

//     Position() {}
//     Position(int _r, int _c): row(_r), col(_c) {}
// };

// #pragma region prototypes

// bool checkUp(int nCells, int trueRow);
// bool checkDown(int nCells, int trueRow);
// bool checkLeft(int nCells, int trueCol);
// bool checkRight(int nCells, int trueCol);
// bool insertTwoUp(int** arr, Position pos);
// bool insertTwoDown(int** arr, Position pos);
// bool insertTwoLeft(int** arr, Position pos);
// bool insertTwoRight(int** arr, Position pos);
// bool checkLogicPosition(int trueRow, int trueCol);

// #pragma endregion

// int main() {
//     int** arr = new int*[ROW_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         arr[i] = new int[MATRIX_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         for(int j = 0; j < MATRIX_SIZE; j++)
//             arr[i][j] = 0;
    
//     cout << (insertTwoLeft(arr, Position(3, 3)) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";
//     cout << (insertTwoRight(arr, Position(3, 3)) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";
//     cout << (insertTwoUp(arr, Position(3, 3)) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";
//     cout << (insertTwoDown(arr, Position(3, 3)) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";

//     for(int i = 0; i < ROW_SIZE; i++) {
//         for(int j = 0; j < MATRIX_SIZE; j++)
//             cout << arr[i][j] << "\t";
//         cout << "\n";
//     }

//     return 0;
// }
*/
// #pragma region directions

// bool checkUp(int nCells, int trueRow) {
//     if(trueRow - nCells < 0)
//         return false;
//     else
//         return true;
// }

// bool checkDown(int nCells, int trueRow, int mSize) {
//     if(trueRow + nCells >= mSize)
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

// bool checkRight(int nCells, int trueCol, int mSize) {
//     if(trueCol + nCells >= mSize)
//         return false;
//     else
//         return true;
// }

// #pragma endregion

// bool checkLogicPosition(int trueRow, int trueCol, int mSize) {
//     if(trueRow < 0 || trueCol < 0)
//         return false;
//     else if(trueRow >= mSize || trueCol >= mSize)
//         return false;
//     else
//         return true;
// }

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