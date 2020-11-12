#include "ej_p.h"
#include <iostream>

using namespace std;

// void printMatrix(char** arr, int size);

// int main() {
//     char** charr = new char*[5];

//     for(int i = 0; i < 5; i++)
//         charr[i] = new char[5];
    
//     for(int i = 0; i < 5; i++)
//         for(int j = 0; j < 5; j++)
//             charr[i][j] = 'A';
 
//     // for(int i = 0; i < 5; i++) {
//     //     for(int j = 0; j < 5; j++)
//     //         cout << charr[i][j] << "\t";
//     //     cout << "\n";
//     // }

//     printMatrix(charr, 5);

//     return 0;
// }

void printMatrix(char** arr, int mSize) {
    for(int i = 0; i < mSize; i++) {
        printCharArr(arr[i], mSize);
    }
}