#include "ej_e.h"
#include "ej_nn.h"
#include <iostream>

using namespace std;

void ppFunction(int* p, int* c, int** m, char** n, int mSize) {
    TwoInt e = userNumber(1, mSize);
    bool flag = checkNumberInCell(m, Position(e.n, e.m));

    if(flag) {
        n[e.n - 1][e.m - 1] = 'x';
        *p += 100;
        *c += 1;
    }
    else
        *p -= 100;
}