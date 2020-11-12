#include <iostream>

using namespace std;

const int ROW_SIZE = 5;
const int COL_SIZE = 5;

struct Position {
    int row, col;

    Position() {}
    Position(int _r, int _c): row(_r), col(_c) {}
};

#pragma region prototypes

bool checkTwoUp(int** arr, Position pos);
bool checkTwoDown(int** arr, Position pos);
bool checkTwoLeft(int** arr, Position pos);
bool checkTwoRight(int** arr, Position pos);
bool checkLogicPosition(int trueRow, int trueCol);

#pragma endregion

int main() {
    int** arr = new int*[ROW_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        arr[i] = new int[COL_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        for(int j = 0; j < COL_SIZE; j++)
            arr[i][j] = 1;

    cout << (checkTwoLeft(arr, Position(1,2)) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkTwoRight(arr, Position(1,4)) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkTwoUp(arr, Position(2,1)) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkTwoDown(arr, Position(4,1)) ? "Es accesesible." : "No es accesesible.") << "\n";
    
    return 0;
}

#pragma region directions

bool checkTwoLeft(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueCol - 2 < 0)
        return false;
    else
        return true;
}

bool checkTwoRight(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueCol + 2 >= COL_SIZE)
        return false;
    else
        return true;
}

bool checkTwoUp(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueRow - 2 < 0)
        return false;
    else
        return true;
}

bool checkTwoDown(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueRow + 2 >= ROW_SIZE)
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
