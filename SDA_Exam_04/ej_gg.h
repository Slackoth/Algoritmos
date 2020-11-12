#include "size.h"
#include <iostream>
#include "position.h"
#include "directions.h"

using namespace std;

// const int ROW_SIZE = 7;
// const int COL_SIZE = 7;

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
// bool insertThreeUp(int** arr, Position pos);
// bool insertThreeDown(int** arr, Position pos);
// bool insertThreeLeft(int** arr, Position pos);
// bool insertThreeRight(int** arr, Position pos);
// bool checkLogicPosition(int trueRow, int trueCol);

// #pragma endregion

// int main() {
//     int** arr = new int*[ROW_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         arr[i] = new int[COL_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         for(int j = 0; j < COL_SIZE; j++)
//             arr[i][j] = 0;
    
//     cout << (insertThreeLeft(arr, Position(4, 4)) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";
//     cout << (insertThreeRight(arr, Position(4, 4)) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";
//     cout << (insertThreeUp(arr, Position(4, 4)) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";
//     cout << (insertThreeDown(arr, Position(4, 4)) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";

//     for(int i = 0; i < ROW_SIZE; i++) {
//         for(int j = 0; j < COL_SIZE; j++)
//             cout << arr[i][j] << "\t";
//         cout << "\n";
//     }

//     return 0;
// }


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