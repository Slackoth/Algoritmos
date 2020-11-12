#include "size.h"
#include <iostream>
#include "position.h"

using namespace std;

// const int ROW_SIZE = 5;
// const int COL_SIZE = 5;

// bool checkNumberInCell(int** arr, Position pos);

// int main() {
//     int** arr = new int*[ROW_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         arr[i] = new int[COL_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         for(int j = 0; j < COL_SIZE; j++)
//             arr[i][j] = 0;

//     arr[2][2] = 1;

//     cout << (checkNumberInCell(arr, Position(3, 3)) ? "Si." : "No.") << "\n";

//     for(int i = 0; i < ROW_SIZE; i++) {
//         for(int j = 0; j < COL_SIZE; j++)
//             cout << arr[i][j] << "\t";
//         cout << "\n";
//     }

//     return 0;
// }

bool checkNumberInCell(int** arr, Position pos) {
    return arr[pos.row - 1][pos.col - 1] == 1 ? true : false;
}