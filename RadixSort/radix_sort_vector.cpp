#include <iostream>
#include <vector>

using namespace std;

#pragma region prototypes

template<class T>
void swap(T* a, T* b);

void radixSort(vector<string>* vct, int digit);
void insertionSort(vector<string>* vct, int digit);

#pragma endregion

int main() {
    vector<string> vct = {"cow", "dog", "sea", "rug", "row", "mob",
        "box", "tab", "bar", "ear", "tar", "dig", "big",
        "tea", "now", "fox"};
    
    radixSort(&vct, vct.at(0).length());

    for(string i : vct) 
        cout << i << endl;
    cout <<  endl;
    
    return 0;
}

void radixSort(vector<string>* vct, int digit) {
    for(int i = digit - 1; i >= 0; i--) 
        insertionSort(vct, i);
}

void insertionSort(vector<string>* vct, int digit) {
    for(int j = 1; j < vct->size(); j++) {
        string key = vct->at(j);
        int i = j - 1;

        while(i >= 0 && vct->at(i)[digit] > key[digit]) {
            vct->at(i + 1) = vct->at(i);
            i--;
        }

        vct->at(i + 1) = key;
    }
}