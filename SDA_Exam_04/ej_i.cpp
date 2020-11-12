#include <iostream>

using namespace std;

void spaceArr(char* arr, int size);

int main() {
    int size = 5;
    char* arr = new char[size];

    spaceArr(arr, size);

    //Coloque guiones para que se pudiera
    //visualizar que esta lleno con espacios
    for(int i = 0; i < size; i++)
        cout << arr[i] << '-';
    cout << "\n";

    return 0;
}

void spaceArr(char* arr, int size) {
    for(int i = 0; i < size; i++)
        arr[i] = ' ';
}