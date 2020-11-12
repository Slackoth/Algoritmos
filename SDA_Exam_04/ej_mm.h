#include "ej_g.h"
#include "ej_h.h"
#include "ej_ii.h"
#include <iostream>

using namespace std;

// bool mmFunction(int** arr);

// int main() {
//     int** arr = new int*[ROW_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         arr[i] = new int[COL_SIZE];

//     for(int i = 0; i < ROW_SIZE; i++)
//         for(int j = 0; j < COL_SIZE; j++)
//             arr[i][j] = 0;

//     cout << (mmFunction(arr) ? "Insertado con exito." 
//         : "No se ha podido insertar.") << "\n";

//     for(int i = 0; i < ROW_SIZE; i++) {
//         for(int j = 0; j < COL_SIZE; j++)
//             cout << arr[i][j] << "\t";
//         cout << "\n";
//     }

//     return 0;
// }

bool mmFunction(int** arr, int mSize) {
    int g = randomNumber(1, 4);
    TwoInt h = randomNumbers(1, mSize);
    
    cout << "Opcion -> " << g << " -> (Fila, Columna) -> (" << h.n << ", " << h.m << ")" << endl;
    
    switch (g) {
        case 1:
            return insertFiveLeft(arr, Position(h.n, h.m), mSize);
        break;

        case 2:
            return insertFiveRight(arr, Position(h.n, h.m), mSize);
        break;

        case 3:
            return insertFiveDown(arr, Position(h.n, h.m), mSize);
        break;

        case 4:
            return insertFiveUp(arr, Position(h.n, h.m), mSize);
        break;
    
        default:
            return false;
        break;
    }
}