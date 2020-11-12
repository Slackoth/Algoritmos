#include <iostream>

using namespace std;

const int ROW_SIZE = 8;
const int COL_SIZE = 8;

struct Position {
    int row, col;

    Position() {}
    Position(int _r, int _c): row(_r), col(_c) {}
};

#pragma region prototypes

bool checkFourUp(int** arr, Position pos);
bool checkFourDown(int** arr, Position pos);
bool checkFourLeft(int** arr, Position pos);
bool checkFourRight(int** arr, Position pos);
bool checkLogicPosition(int trueRow, int trueCol);

#pragma endregion

int main() {
    int** arr = new int*[ROW_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        arr[i] = new int[COL_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        for(int j = 0; j < COL_SIZE; j++)
            arr[i][j] = 1;

    cout << (checkFourLeft(arr, Position(1,4)) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkFourRight(arr, Position(1,4)) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkFourUp(arr, Position(4,1)) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkFourDown(arr, Position(4,1)) ? "Es accesesible." : "No es accesesible.") << "\n";
    
    return 0;
}

#pragma region directions

bool checkFourLeft(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueCol - 4 < 0)
        return false;
    else
        return true;
}

bool checkFourRight(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueCol + 4 >= COL_SIZE)
        return false;
    else
        return true;
}

bool checkFourUp(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueRow - 4 < 0)
        return false;
    else
        return true;
}

bool checkFourDown(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueRow + 4 >= ROW_SIZE)
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