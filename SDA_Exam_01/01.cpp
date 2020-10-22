#include <cstdlib>
#include <iostream>

using namespace std;

int sumMatrix(int**,int,int,int,int);

int main(void) {
    //Creating the matrix
    int rows = 5;
    int cols = 5;
    int** doublePointer;
    doublePointer = new int* [rows];

    for(int i = 0; i < rows; i++)
        doublePointer[i] = new int [cols];

    //Filling the matrix
    int count = 0;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            doublePointer[i][j] = count++;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cout << doublePointer[i][j] << "\t";
        cout << endl;
    }

    cout << sumMatrix(&(*doublePointer),5,5,0,0) << endl;
}

int sumMatrix(int **matrix,int rows,int cols,int total, int count) {
    //Traversing the matrix
    if(count < rows) {
        for(int j = 0; j < cols; j++) 
            total+=matrix[count][j];
        return sumMatrix(matrix,5,5,total,count + 1);
    }

    return total;
}