#include "ej_pp.h"
#include <iostream>

using namespace std;

// void qqFunction(int* p, int* c, int** m, char** n, int size);

// int main() {
//     int p = 0, c = 0;
//     int** arr = new int*[ROW_SIZE];
//     char** charr = new char*[ROW_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         arr[i] = new int[COL_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         charr[i] = new char[COL_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         for(int j = 0; j < COL_SIZE; j++)
//             arr[i][j] = 0;
    
//     for(int i = 0; i < ROW_SIZE; i++)
//         for(int j = 0; j < COL_SIZE; j++)
//             charr[i][j] = '!';

//     arr[2][2] = 1;

//     qqFunction(&p, &c, arr, charr, ROW_SIZE);
 
//     for(int i = 0; i < ROW_SIZE; i++) {
//         for(int j = 0; j < COL_SIZE; j++)
//             cout << charr[i][j] << "\t";
//         cout << "\n";
//     }

//     return 0;
// }

void qqFunction(int* p, int* c, int** m, char** n, int size) {
    while(*c < 13) {
        ppFunction(p, c, m, n, size);
    }
}