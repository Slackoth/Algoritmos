#include <iostream>

using namespace std;

// void spaceMatrix(char** arr, int size);

// int main() {
//     int size = 5;
//     char** arr = new char*[size];

//     for(int i = 0; i < size; i++)
//         arr[i] = new char[size];

//     spaceMatrix(arr, size);

//     //Coloque guiones para que se pudiera
//     //visualizar que esta lleno con espacios
//     for(int i = 0; i < size; i++) {
//         for(int j = 0; j < size; j++)
//             cout << arr[i][j] << '-';
//         cout << "\n";
//     }

//     return 0;
// }

void spaceMatrix(char** arr, int size) {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            arr[i][j] = ' ';
}