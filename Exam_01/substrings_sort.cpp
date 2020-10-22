#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

struct Word {
    string w;

    Word() {}
    Word(string _w): w(_w) {}

    bool operator<=(const Word& rhs) {
        if(this->w.length() <= rhs.w.length()) {
            return true;
        }
        else if(this->w.length() == rhs.w.length()) {
            return this->w[0] <= rhs.w[0];
        }
        else
            return false;
    }
};

template<class T>
void swap(T* a, T* b);
int partition(vector<Word>* vct, int low, int high);
void quickSort(vector<Word>* vct, int low, int high);
bool isSubstringOrderPossible(vector<Word>* vct, int size);

int main() {
    vector<Word> vct;
    string w;

    while(getline(cin, w)) 
        vct.push_back(Word(w));

    int size = vct.size();

    quickSort(&vct, 0, size - 1);

    for(auto it : vct) 
        cout << it.w << "\t";
    cout << endl;

    cout << (isSubstringOrderPossible(&vct, size) == true ? "YES" : "NO") << endl;

    return 0;
}

bool isSubstringOrderPossible(vector<Word>* vct, int size) {
    for(int i = 1; i < size; i++) {
        if(vct->at(i).w.find(vct->at(i - 1).w) == string::npos) 
            return false;
    }

    return true;
}

void quickSort(vector<Word>* vct, int low, int high) {
    if(low < high) {
        int pivot = partition(vct, low, high);
        
        quickSort(vct, low, pivot - 1);
        quickSort(vct, pivot + 1, high);
    }
}

int partition(vector<Word>* vct, int low, int high) {
    Word pivot = vct->at(high);
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(vct->at(j) <= vct->at(high)) {
            i++;
            swap(vct->at(i), vct->at(j));
        }
    }

    swap(vct->at(i + 1), vct->at(high));
    return i + 1;
}

template<class T>
void swap(T* a, T* b) {
    T aux = *a;
    *a = *b;
    *b = aux;
}

