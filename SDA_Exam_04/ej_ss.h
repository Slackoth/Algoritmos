#include "ej_p.h"
#include <iostream>

using namespace std;

void printMatrix(char** arr, int mSize) {
    for(int i = 0; i < mSize; i++) {
        printCharArr(arr[i], mSize);
    }
}