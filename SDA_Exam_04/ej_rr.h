#include "ej_pp.h"
#include <iostream>

using namespace std;

void rrFunction(int* p, int* c, int** m, char** n, int mSize) {
    while(*c < 13) {
        ppFunction(p, c, m, n, mSize);
    }

    cout << "c: " << *c << "\n";
}