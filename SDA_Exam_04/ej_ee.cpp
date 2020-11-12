#include <iostream>

using namespace std;

const int ROW_SIZE = 5;
const int COL_SIZE = 5;

enum Direction { LEFT, RIGHT, UP, DOWN };

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
bool checkLogicPosition(int trueRow, int trueCol);
bool insertOne(int** arr, Position pos, Direction dir);
bool checkDirection(int nCells, int trueRow, int trueCol, Direction dir);

#pragma endregion

int main() {
    int** arr = new int*[ROW_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        arr[i] = new int[COL_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        for(int j = 0; j < COL_SIZE; j++)
            arr[i][j] = 0;
    
    cout << (insertOne(arr, Position(3,3), UP) ? "Insertado con exito." 
        : "No se ha podido insertar.") << "\n";
    cout << (insertOne(arr, Position(3,3), DOWN) ? "Insertado con exito." 
        : "No se ha podido insertar.") << "\n";
    cout << (insertOne(arr, Position(3,3), LEFT) ? "Insertado con exito." 
        : "No se ha podido insertar.") << "\n";
    cout << (insertOne(arr, Position(3,3), RIGHT) ? "Insertado con exito." 
        : "No se ha podido insertar.") << "\n";
        

    for(int i = 0; i < ROW_SIZE; i++) {
        for(int j = 0; j < COL_SIZE; j++)
            cout << arr[i][j] << "\t";
        cout << "\n";
    }

    return 0;
}

bool insertOne(int** arr, Position pos, Direction dir) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(!checkDirection(1, trueRow, trueCol, dir))
        return false;
    else {
        arr[trueRow][trueCol] = 1;

        switch (dir) {
        case LEFT:
            arr[trueRow][trueCol - 1] = 1;
            break;
        
        case RIGHT:
            arr[trueRow][trueCol + 1] = 1;
            break;

        case UP:
            arr[trueRow - 1][trueCol] = 1;
            break;

        case DOWN:
            arr[trueRow + 1][trueCol] = 1;
            break;    
        
        default:
            break;
        }

        return true;
    }
}

#pragma region directions

bool checkDirection(int nCells, int trueRow, int trueCol, Direction dir) {
    switch (dir) {
        case LEFT:
            return checkLeft(nCells, trueCol);
            break;
        
        case RIGHT:
            return checkRight(nCells, trueCol);
            break;

        case UP:
            return checkUp(nCells, trueRow);
            break;

        case DOWN:
            return checkDown(nCells, trueRow);
            break;    
        
        default:
            return false;
            break;
    }
}

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