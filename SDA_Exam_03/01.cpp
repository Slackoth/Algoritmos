#include <vector>
#include <iostream>

using namespace std;

float* generateZeroToOne(int size);
void bucketSort(float* arr, int size);
void bucketSort(float* arr, int size);

template<class Num>
void insertionSort(vector<Num>* bucket);


int main(void) {
    int size = 10;
    
    cout << "Numbers from [0,1[:\n";
    float* arr = generateZeroToOne(size);
    cout << "\n";

    bucketSort(arr, size);

    cout << "Ordered array using bucket sort:\n";
    for(int i = 0; i < size; i++) 
        cout << arr[i] << "\t";
    cout << "\n";
    
    return 0;
}

float* generateZeroToOne(int size) {
    float* arr = new float[size];
    //Generating random values
    srand(time(NULL));

    for(int i = 0; i < size; i++) {
        //Divinding by 100 to obtain decimals.
        arr[i] = float(rand() % 90 + 0) / 100;
        cout << arr[i] << "\t";
    }

    return arr;
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
  