#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class Num>
void swap(Num*,Num*);

template <class Num>
void heapSort(vector<Num>*,int);

template <class Num>
void maxHeapify(vector<Num>*,int,int);

int main(void) {
    vector<int> vct = {7, 20, 15, 10, 16, 50, 19, 
    69, 420, 13, 20, 666};

    heapSort(&vct, vct.size());

    for(int i : vct)
        cout << i << "  ";

    return 0;
}

//Float, double or int
template <class Num>
void heapSort(vector<Num>* vct, int size) {
    for(int i = size / 2 - 1; i >= 0; i--)
        maxHeapify(vct, size, i);

    for(int i = size - 1; i > 0; i--) {
        swap(vct->at(0), vct->at(i));
        maxHeapify(vct, i, 0);
    }
}

template <class Num> 
void maxHeapify(vector<Num>* vct, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && vct->at(left) > vct->at(i)) 
        largest = left;
    
    if(right < size && vct->at(right) > vct->at(largest))
        largest = right;
   
    if(largest != i) {
        swap(vct->at(i), vct->at(largest));
        maxHeapify(vct, size, largest);
    }
}

template <class Num>
void swap(Num* a, Num* b) {
    Num aux = *a;
    *a = *b;
    *b = aux;
}

