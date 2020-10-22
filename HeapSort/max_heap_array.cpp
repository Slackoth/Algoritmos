#include <cstdlib>
#include <iostream>

using namespace std;

int left(int);
int right(int);
void heapSort(int*,int);
void buildMaxHeap(int*,int);
void maxHeapify(int*,int,int);

int main(void) {
    srand(time(NULL));

    int size = 10;
    int* a = new int[size];

    for(int i = 0; i < size; i++) {
        a[i] = rand() % 100 + 1;
    }

    cout << "Unordered numbers: ";

    for(int i = 0; i < size; i++) {
        cout << a[i] << "    ";
    }

    cout << endl;

    heapSort(a,size);

    return 0;
}

void heapSort(int* arr,int size) {
    buildMaxHeap(arr,size);    
    
    cout << "Ordered numbers: " ;

    while(size >= 1) {
            int aux = arr[0];

            arr[0] = arr[size-1];
            arr[size-1] = aux;
            size--;

            cout << aux << "    ";

            maxHeapify(arr,1,size);
    }

   cout << endl;
}

void buildMaxHeap(int* arr, int size) {
    for(int i = size/2 - 1; i >= 0; i--) {
        maxHeapify(arr,i + 1,size);
    }
}

void maxHeapify(int* arr,int i, int size) {
    int ls = left(i) - 1;
    int rs = right(i) - 1;
    int largest = 0;

    if(ls < size && arr[ls] > arr[i-1]) 
        largest = ls;
    else
        largest = i-1;

    if(rs < size && arr[rs] > arr[largest])
        largest = rs;
        
    if(largest != i-1) {
        int aux = arr[i-1];

        arr[i-1] = arr[largest];
        arr[largest] = aux;

        maxHeapify(arr,largest + 1,size);
    }   
}

int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i + 1;
}