#include "size.h"
#include "ej_g.h"
#include "ej_h.h"
#include "ej_ff.h"
#include <iostream>
#include "two_int.h"
#include "position.h"

using namespace std;

void ptm() {}

bool kkFunction(int** arr, int mSize) {
    int g = randomNumber(1, 4);
    TwoInt h = randomNumbers(1, mSize);
    
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