#include "ej_e.h"
#include "ej_nn.h"
#include <iostream>

using namespace std;

//void ooFunction(int* p, int* c, int** arr, int size);

// int main() {
//     int p = 0, c = 0;
//     int** arr = new int*[ROW_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         arr[i] = new int[COL_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         for(int j = 0; j < COL_SIZE; j++)
//             arr[i][j] = 0;

//     arr[2][2] = 1;

//     ooFunction(&p, &c, arr, ROW_SIZE);

//     cout << p << " " << c << "\n";

//     return 0;
// }

void ooFunction(int* p, int* c, int** arr, int size) {
    TwoInt e = userNumber(1, size);
    bool flag = checkNumberInCell(arr, Position(e.n, e.m));

    if(flag) {
        *p += 100;
        *c += 1;
    }
    else
        *c -= 100;
}