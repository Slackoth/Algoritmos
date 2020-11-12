#include <iostream>

using namespace std;

void cerpArr(int* arr, int size);

int main() {
    int size = 5;
    int* arr = new int[size];

    cerpArr(arr, size);

    for(int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << "\n";

    return 0;
}

void cerpArr(int* arr, int size) {
    for(int i = 0; i < size; i++)
        arr[i] = 0;
}