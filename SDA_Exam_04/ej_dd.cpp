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

bool checkUp(int nCells, int trueRow);
bool insertOneUp(int** arr, Position pos);
bool checkLogicPosition(int trueRow, int trueCol);

#pragma endregion

int main() {
    int** arr = new int*[ROW_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        arr[i] = new int[COL_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        for(int j = 0; j < COL_SIZE; j++)
            arr[i][j] = 0;
    
    cout << (insertOneUp(arr, Position(3,2)) ? "Insertado con exito." 
        : "No se ha podido insertar.") << "\n";

    for(int i = 0; i < ROW_SIZE; i++) {
        for(int j = 0; j < COL_SIZE; j++)
            cout << arr[i][j] << "\t";
        cout << "\n";
    }

    
    return 0;
}

bool insertOneUp(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;

    if(!checkLogicPosition(trueRow, trueCol))
        return false;
    else if(!checkUp(1, trueRow))
        return false;
    else {
        arr[trueRow][trueCol] = 1;
        arr[trueRow - 1][trueCol] = 1;
        
        return true;
    }
}

bool checkUp(int nCells, int trueRow) {
    if(trueRow - nCells < 0)
        return false;
    else
        return true;
}

bool checkLogicPosition(int trueRow, int trueCol) {
    if(trueRow < 0 || trueCol < 0)
        return false;
    else if(trueRow >= ROW_SIZE || trueCol >= COL_SIZE)
        return false;
    else
        return true;
}