#include "ej_g.h"
#include "ej_h.h"
#include "ej_gg.h"
#include <iostream>

using namespace std;

// bool llFunction(int** arr, int mSize);

// int main() {
//     int mSize = MATRIX_SIZE_H;
//     int** arr = new int*[mSize];

//     for(int i = 0; i < mSize; i++)
//         arr[i] = new int[mSize];

//     for(int i = 0; i < mSize; i++)
//         for(int j = 0; j < mSize; j++)
//             arr[i][j] = 0;

//     cout << (llFunction(arr, mSize) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";

//     for(int i = 0; i < mSize; i++) {
//         for(int j = 0; j < mSize; j++)
//             cout << arr[i][j] << "\t";
//         cout << "\n";
//     }

//     return 0;
// }

bool llFunction(int** arr, int mSize) {
    int g = randomNumber(1, 4);
    TwoInt h = randomNumbers(1, mSize);
    
    cout << "Opcion -> " << g << " -> (Fila, Columna) -> (" << h.n << ", " << h.m << ")" << endl;
    
    switch (g) {
        case 1:
            return insertThreeLeft(arr, Position(h.n, h.m), mSize);
        break;

        case 2:
            return insertThreeRight(arr, Position(h.n, h.m), mSize);
        break;

        case 3:
            return insertThreeDown(arr, Position(h.n, h.m), mSize);
        break;

        case 4:
            return insertThreeUp(arr, Position(h.n, h.m), mSize);
        break;
    
        default:
            return false;
        break;
    }
}