#include <iostream>

using namespace std;

// void ceroMatrix(int** arr, int size);

// int main() {
//     int size = 5;
//     int** arr = new int*[size];

//     for(int i = 0; i < size; i++)
//         arr[i] = new int[size];

//     ceroMatrix(arr, size);

//     for(int i = 0; i < size; i++) {
//         for(int j = 0; j < size; j++)
//             cout << arr[i][j] << ' ';
//         cout << "\n";
//     }

//     return 0;
// }

void ceroMatrix(int** arr, int size) {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            arr[i][j] = 0;
}