#include <iostream>

using namespace std;

const int ROW_SIZE = 10;
const int COL_SIZE = 10;

struct Position {
    int row, col;

    Position() {}
    Position(int _r, int _c): row(_r), col(_c) {}
};

#pragma region prototypes

bool checkFiveUp(int** arr, Position pos);
bool checkFiveDown(int** arr, Position pos);
bool checkFiveLeft(int** arr, Position pos);
bool checkFiveRight(int** arr, Position pos);
bool checkLogicPosition(int trueRow, int trueCol);

#pragma endregion

int main() {
    int** arr = new int*[ROW_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        arr[i] = new int[COL_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        for(int j = 0; j < COL_SIZE; j++)
            arr[i][j] = 1;

    cout << (checkFiveLeft(arr, Position(1,5)) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkFiveRight(arr, Position(1,5)) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkFiveUp(arr, Position(5,1)) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkFiveDown(arr, Position(5,1)) ? "Es accesesible." : "No es accesesible.") << "\n";
    
    return 0;
}

#pragma region directions

/*
La verificacion se realiza con los indices reales de de
los arreglos y por eso existen trueRow y trueCol
*/

bool checkFiveLeft(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueCol - 5 < 0)
        return false;
    else
        return true;
}

bool checkFiveRight(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueCol + 5 >= COL_SIZE)
        return false;
    else
        return true;
}

bool checkFiveUp(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueRow - 5 < 0)
        return false;
    else
        return true;
}

bool checkFiveDown(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueRow + 5 >= ROW_SIZE)
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