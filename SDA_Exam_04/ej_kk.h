#include "size.h"
#include "ej_g.h"
#include "ej_h.h"
#include "ej_ff.h"
#include <iostream>
#include "two_int.h"
#include "position.h"

using namespace std;

// bool kkFunction(int** arr, int mSize);

// int main() {
//     int mSize = MATRIX_SIZE_H;
//     int** arr = new int*[mSize];

//     for(int i = 0; i < mSize; i++)
//         arr[i] = new int[mSize];

//     for(int i = 0; i < mSize; i++)
//         for(int j = 0; j < mSize; j++)
//             arr[i][j] = 0;

//     cout << (kkFunction(arr, mSize) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";

//     for(int i = 0; i < mSize; i++) {
//         for(int j = 0; j < mSize; j++)
//             cout << arr[i][j] << "\t";
//         cout << "\n";
//     }

//     return 0;
// }

void ptm() {}

bool kkFunction(int** arr, int mSize) {
    int g = randomNumber(1, 4);
    TwoInt h = randomNumbers(1, mSize);
    
    //Extra para que se facilite saber si se ha ejecutadao de forma exitosa
    cout << "Opcion -> " << g << " -> (Fila, Columna) -> (" << h.n << ", " << h.m << ")" << endl;
    
    switch (g) {
        case 1:
            return insertTwoLeft(arr, Position(h.n, h.m), mSize);
        break;

        case 2:
            return insertTwoRight(arr, Position(h.n, h.m), mSize);
        break;

        case 3:
            return insertTwoDown(arr, Position(h.n, h.m), mSize);
        break;

        case 4:
            return insertTwoUp(arr, Position(h.n, h.m), mSize);
        break;
    
        default:
            return false;
        break;
    }
}