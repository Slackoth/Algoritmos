#include "ej_e.h"
#include "ej_nn.h"
#include <iostream>

using namespace std;

void ooFunction(int* p, int* c, int** arr, int size) {
    TwoInt e = userNumber(1, size);
    bool flag = checkNumberInCell(arr, Position(e.n, e.m));

    if(flag) {
        *p += 100;
        *c += 1;
    }
    else
        *c -= 100;
}