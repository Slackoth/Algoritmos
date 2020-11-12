#include <iostream>

using namespace std;

void ceroMatrix(int** arr, int size) {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            arr[i][j] = 0;
}