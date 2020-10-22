#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
void swap(T* a, T* b);
void heapSort(vector<int>* vct, int size);
void maxHeapify(vector<int>* vct, int size, int i);
int countSupportedStwards(vector<int>* sts, int jon);

int main() {
    vector<int> vct;
    int nStewards;
    int steward;
    
    cin >> nStewards;

    while(nStewards != 0) {
        cin >> steward;
        vct.push_back(steward);
        
        nStewards--;
    }

    heapSort(&vct, vct.size());

    for(auto it : vct) 
        cout <<  it << "\t";
    cout << endl;

    cout  << countSupportedStwards(&vct, 15);
    
    return 0;
}

int countSupportedStwards(vector<int>* sts, int jon) {
    int weak = 0;
    int strong = 0;

    for(auto it : *sts) {
        if(jon < it)
            strong++;
        else if(jon > it)
            weak++;
    }

    if(strong > weak)
        return (strong * weak) / strong;
    else
        return (strong * weak) / weak;

}

void heapSort(vector<int>* vct, int size) {
    for(int i = size / 2 - 1; i >= 0; i--) 
        maxHeapify(vct, size, i);
    
    for(int i = size - 1; i > 0; i--) {
        swap(vct->at(0), vct->at(i));
        maxHeapify(vct, i, 0);
    }
}

void maxHeapify(vector<int>* vct, int size, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if(left < size && vct->at(left) > vct->at(largest))
        largest =  left;
    
    if(right < size && vct->at(right) > vct->at(largest))
        largest = right;

    if(largest != i) {
        swap(vct->at(i), vct->at(largest));
        maxHeapify(vct, size, largest);
    }
}

template <class T>
void swap(T* a, T* b) {
    T aux = *a;
    *a = *b;
    *b = aux;
}