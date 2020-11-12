#include <iostream>

using namespace std;

const int ROW_SIZE = 10;
const int COL_SIZE = 10;

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
bool checkDirection(int** arr, Position pos, Direction dir, int nCells);

#pragma endregion

int main() {
    int** arr = new int*[ROW_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        arr[i] = new int[COL_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        for(int j = 0; j < COL_SIZE; j++)
            arr[i][j] = 1;

    cout << (checkDirection(arr, Position(2,10), LEFT, 3) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkDirection(arr, Position(3,10), RIGHT, 2) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkDirection(arr, Position(1,3), UP, 4) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkDirection(arr, Position(1,7), DOWN, 9) ? "Es accesesible." : "No es accesesible.") << "\n";
    
    return 0;
}

#pragma region directions

/*
La verificacion se realiza con los indices reales de de
los arreglos y por eso existen trueRow y trueCol
*/

bool checkDirection(int** arr, Position pos, Direction dir, int nCells) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else {
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

#pragma endregion

bool checkLogicPosition(int trueRow, int trueCol) {
    if(trueRow < 0 || trueCol < 0)
        return false;
    else if(trueRow >= ROW_SIZE || trueCol >= COL_SIZE)
        return false;
    else
        return true;
}