#include "ej_pp.h"
#include "ej_ss.h"
#include <iostream>

using namespace std;

void rrFunction(int* p, int* c, int** m, char** n, int mSize) {
    while(*c < 13) {
        ppFunction(p, c, m, n, mSize);
        printMatrix(n, mSize);
    }

    cout << "p: " << *p << "\n";
}