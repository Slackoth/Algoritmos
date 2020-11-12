#include <iostream>

using namespace std;

const int ROW_SIZE = 9;
const int COL_SIZE = 9;

struct Position {
    int row, col;

    Position() {}
    Position(int _r, int _c): row(_r), col(_c) {}
};

#pragma region prototypes

bool checkUp(int nCells, int trueRow);
bool checkDown(int nCells, int trueRow);
bool checkLeft(int nCells, int trueCol);
bool checkRight(int nCells, int trueCol);
bool insertFourUp(int** arr, Position pos);
bool insertFourDown(int** arr, Position pos);
bool insertFourLeft(int** arr, Position pos);
bool insertFourRight(int** arr, Position pos);
bool checkLogicPosition(int trueRow, int trueCol);

#pragma endregion

int main() {
    int** arr = new int*[ROW_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        arr[i] = new int[COL_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        for(int j = 0; j < COL_SIZE; j++)
            arr[i][j] = 0;
    
    cout << (insertFourLeft(arr, Position(5, 5)) ? "Insertado con exito." 
        : "No se ha podido insertar.") << "\n";
    cout << (insertFourRight(arr, Position(5, 5)) ? "Insertado con exito." 
        : "No se ha podido insertar.") << "\n";
    cout << (insertFourUp(arr, Position(5, 5)) ? "Insertado con exito." 
        : "No se ha podido insertar.") << "\n";
    cout << (insertFourDown(arr, Position(5, 5)) ? "Insertado con exito." 
        : "No se ha podido insertar.") << "\n";

    for(int i = 0; i < ROW_SIZE; i++) {
        for(int j = 0; j < COL_SIZE; j++)
            cout << arr[i][j] << "\t";
        cout << "\n";
    }

    return 0;
}

#pragma region insertion

bool insertFourLeft(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(!checkLeft(4, trueCol))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow][trueCol - 4] = 1;
        
        return true;
    }
}

bool insertFourRight(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(!checkRight(4, trueCol))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow][trueCol + 4] = 1;
        
        return true;
    }
}

bool insertFourDown(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(!checkDown(4, trueRow))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow + 4][trueCol] = 1;
        
        return true;
    }
}

bool insertFourUp(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
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

#pragma region directions

bool checkUp(int nCells, int trueRow) {
    if(trueRow - nCells < 0)
        return false;
    else
        return true;
}

bool checkDown(int nCells, int trueRow) {
    if(trueRow + nCells >= ROW_SIZE)
        return false;
    else
        return true;
}

bool checkLeft(int nCells, int trueCol) {
    if(trueCol - nCells < 0)
        return false;
    else
        return true;
}

bool checkRight(int nCells, int trueCol) {
    if(trueCol + nCells >= COL_SIZE)
        return false;
    else
        return true;
}

#pragma endregion

bool checkLogicPosition(int trueRow, int trueCol) {
    if(trueRow < 0 || trueCol < 0)
        return false;
    else if(trueRow >= ROW_SIZE || trueCol >= COL_SIZE)
        return false;
    else
        return true;
}