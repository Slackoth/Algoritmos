#include <iostream>

using namespace std;

const int ROW_SIZE = 5;
const int COL_SIZE = 5;

struct Position {
    int row, col;

    Position() {}
    Position(int _r, int _c): row(_r), col(_c) {}
};

bool checkAllDirectionsCell(int** arr, Position pos);

int main() {
    int** arr = new int*[ROW_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        arr[i] = new int[COL_SIZE];

    for(int i = 0; i < ROW_SIZE; i++)
        for(int j = 0; j < COL_SIZE; j++)
            arr[i][j] = 1;

    cout << (checkAllDirectionsCell(arr, Position(2, 2)) ? "Es accesesible para todas las direcciones." 
        : "No es accesesible en ninguna o al menos una direccion.") << "\n";

    return 0;
}

bool checkAllDirectionsCell(int** arr, Position pos) {
    int trueRow = pos.row - 1;
    int trueCol = pos.col - 1;
    
    if(trueRow + 1 >= ROW_SIZE || trueRow - 1 < 0)
        return false;
    else if(trueCol + 1 >= COL_SIZE || trueCol - 1 < 0)
        return false;
    else
        return true;
}