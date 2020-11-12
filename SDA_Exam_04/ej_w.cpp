#include <iostream>

using namespace std;

const int ROW_SIZE = 6;
const int COL_SIZE = 6;

struct Position {
    int row, col;

    Position() {}
    Position(int _r, int _c): row(_r), col(_c) {}
};

#pragma region prototypes

bool checkThreeUp(int** arr, Position pos);
bool checkThreeDown(int** arr, Position pos);
bool checkThreeLeft(int** arr, Position pos);
bool checkThreeRight(int** arr, Position pos);
bool checkLogicPosition(int trueRow, int trueCol);

#pragma endregion

int main() {
    int** arr = new int*[ROW_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        arr[i] = new int[COL_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        for(int j = 0; j < COL_SIZE; j++)
            arr[i][j] = 1;

    cout << (checkThreeLeft(arr, Position(1,3)) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkThreeRight(arr, Position(1,3)) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkThreeUp(arr, Position(3,1)) ? "Es accesesible." : "No es accesesible.") << "\n";
    cout << (checkThreeDown(arr, Position(3,1)) ? "Es accesesible." : "No es accesesible.") << "\n";
    
    return 0;
}

#pragma region directions

bool checkThreeLeft(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueCol - 3 < 0)
        return false;
    else
        return true;
}

bool checkThreeRight(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueCol + 3 >= COL_SIZE)
        return false;
    else
        return true;
}

bool checkThreeUp(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueRow - 3 < 0)
        return false;
    else
        return true;
}

bool checkThreeDown(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(trueRow + 3 >= ROW_SIZE)
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