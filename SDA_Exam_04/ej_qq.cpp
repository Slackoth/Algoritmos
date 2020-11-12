#include "ej_pp.h"
#include <iostream>

using namespace std;

void qqFunction(int* p, int* c, int** m, char** n, int size) {
    while(*c < 13) {
        ppFunction(p, c, m, n, size);
    }
}