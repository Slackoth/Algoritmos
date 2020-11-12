#include "ej_g.h"
#include "ej_h.h"
#include "ej_gg.h"
#include <iostream>

using namespace std;

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