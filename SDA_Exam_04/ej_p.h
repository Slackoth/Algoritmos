#include <iostream>

using namespace std;

void printCharArr(char* arr, int size) {
    cout << "|    ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << "    |    ";
    cout << "\n";
}