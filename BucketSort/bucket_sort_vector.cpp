#include <iostream>
#include <vector>

using namespace std;

#pragma region prototypes

void bucketSort(float* arr, int size);

template<class Num>
void insertionSort(vector<Num>* bucket);

#pragma endregion

int main() {
    float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };

    bucketSort(arr, 6);

    for (int i = 0; i < 6; i++) 
        cout << arr[i] << "\t";
    cout << "\n";

    return 0;
}

void bucketSort(float* arr, int size) {
    vector<float> bucket[size];

    for(int i = 0; i < size; i++) {
        int bIndex = size * arr[i];
        
        bucket[bIndex].push_back(arr[i]);
    }

    for(int i = 0; i < size; i++) 
        insertionSort(&bucket[i]);
    
    int index = 0;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < bucket[i].size(); j++) {
            arr[index] = bucket[i][j];
            index++;
        }
    
}

template<class Num>
void insertionSort(vector<Num>* bucket) {
    for(int j = 1; j < bucket->size(); j++) {
        Num key = bucket->at(j);
        int i = j - 1;

        while(i >= 0 && bucket->at(i) > key) {
            bucket->at(i + 1) = bucket->at(i);
            i--;
        }

        bucket->at(i + 1) = key;
    }
}