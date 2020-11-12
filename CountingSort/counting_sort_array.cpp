#include <iostream>

using namespace std;

#pragma region protoypes

void countingSort(int* A, int* B, int K, int size);

#pragma endregion

int main() {
    int size = 10;
    int A[] = {10,9,7,6,5,3,7,2,0,1};
    int* B = new int[size];

    countingSort(A, B, 10, size);

    for(int i = 0; i < size; i++)
        cout << B[i] << "\t";
}

void countingSort(int* A, int* B, int K, int size) {
    int* C = new int[K + 1];
    
    for(int i = 0; i <= K; i++) 
        C[i] = 0;
    
    for(int i = 0; i < size; i++) 
        C[A[i]] = C[A[i]] + 1;
     
    for(int i = 1; i <= K; i++)
        C[i] = C[i] + C[i - 1];

    for(int i = size - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    } 
}