#include <iostream>
#include <cmath>
using namespace std;

void fillArray(int*,int);
void printArray(int*,int);
void orderArray(int*,int,int);
void mergeSort(int*,int,int,int);

int main(void) {
    int size = 8;
    int* array = new  int[size+1];
    fillArray(array,size);
    printArray(array,size);
    cout << "**************" << endl;
    orderArray(array,1,size);
    printArray(array,size);
    
}

void fillArray(int* array, int size) {
    for (int i = 1; i <= size; i++)
        array[i] = rand() % 1501;
}

void printArray(int* array, int size) {
    for (int i = 1; i <= size; i++)
        cout << "array #" << i << ": " << array[i] << endl;
}

void orderArray(int* array, int start, int end) {
    if(start < end) {
        int half  = floor((start+end)/2);

        // cout << "start: " << start << endl;
        // cout << "end: " << end << endl;
        // cout << "half: " << half << endl;
        // cout << "**************" << endl;

        orderArray(array,start,half);
        orderArray(array,half+1,end);
        mergeSort(array,start,half,end);
    }
}

void mergeSort(int* array, int start, int half, int end) {
    int size1 = half - start + 1;
    int size2 = end - half;

    // cout << "size1: " << size1 << endl;
    // cout << "size2: " << size2 << endl;
    // cout << "start: " << start << endl;
    // cout << "end: " << end << endl;
    // cout << "half: " << half << endl;

    int* left = new int[size1+1];
    int* right = new int[size2+1];
    for (int i = 1; i <= size1; i++)
        left[i] = array[i + start - 1];
    for (int j = 1; j <= size2; j++) 
        right[j] = array[half + j];
        
    left[size1+1] = 1502;
    right[size2+1] = 1502;
    // for (int i = 1; i <= size1 + 1; i++)
    //     cout << "left #" << i << ": " << left[i] << endl;
    // for (int j = 1; j <= size2 + 1; j++) 
    //     cout << "right #" << j << ": " << right[j] << endl;

    int i = 1;
    int j = 1;
    for (int k = start; k <= end; k++) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            //cout << "array #" << k << ": " << array[k] << endl;
            i++;
        }
        else {
            array[k] = right[j];
            //cout << "array #" << k << ": " << array[k] << endl;
            j++;
        }   
    }
    //cout << "**************" << endl;
    
}