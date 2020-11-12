#include <iostream>

using namespace std;

void printCharArr(char* arr, int size);

int main() {
    int size = 5;
    char* arr = new char[size];

    for(int i = 0; i < size; i++)
        arr[i] = 'g';

    printCharArr(arr, size);

    return 0;
}

void printCharArr(char* arr, int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << "    |    ";
    cout << "\n";
}