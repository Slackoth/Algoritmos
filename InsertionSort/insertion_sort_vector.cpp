#include <iostream>
#include <vector>

using namespace std;

template<class Num>
void insertionSort(vector<Num>* bucket);

int main() {}

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