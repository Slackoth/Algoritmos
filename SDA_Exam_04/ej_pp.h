#include "ej_e.h"
#include "ej_nn.h"
#include <iostream>

using namespace std;

// void ppFunction(int* p, int* c, int** m, char** n, int size);

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

//     ppFunction(&p, &c, arr, charr, ROW_SIZE);

//     for(int i = 0; i < ROW_SIZE; i++) {
//         for(int j = 0; j < COL_SIZE; j++)
//             cout << charr[i][j] << "\t";
//         cout << "\n";
//     }

//     return 0;
// }

void ppFunction(int* p, int* c, int** m, char** n, int mSize) {
    TwoInt e = userNumber(1, mSize);
    bool flag = checkNumberInCell(m, Position(e.n, e.m));

    if(flag) {
        n[e.n - 1][e.m - 1] = 'x';
        *p += 100;
        *c += 1;
    }
    else
        *c -= 100;
}