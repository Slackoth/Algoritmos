#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

struct Person {
    string name;
    string lastN;

    Person() {}
    Person(string _name, string _lastN): name(_name), lastN(_lastN) {}

    /*
        str1.compare(str2) returns an integer.

        0 -> strings are equal.
        1 -> str1 goes after str2 in alphabetical order.
        -1 -> str1 goes before str2 in alphabetical order. 
    */

    bool operator<(const Person& rhs) {
        //return this->lastN.compare(rhs.lastN) == -1 ? true : false;
        return this->lastN[0] < rhs.lastN[0];
    }

    bool operator>(const Person& rhs) {
        //return this->lastN.compare(rhs.lastN) == 1 ? true : false;
        return this->lastN[0] > rhs.lastN[0];
    }

    /*
        A friend function of a class is defined outside that class' scope 
        but it has the right to access all private and protected members
        of the class.
    */

    friend ostream& operator<<(ostream& os, const Person& p) {
        os << (p.name + " " + p.lastN);
        return os;
    }
};

typedef Person P;

template <class T>
void swap(T*,T*);

template <class T>
void heapSort(vector<T>*,int);

template <class T>
void maxHeapify(vector<T>*,int,int);

int main(void) {
    vector<Person> vct = {
        P("L.","Calderon"),
        P("P.","Perla"),
        P("R.","Menendez"),
        P("G.","Arevalo"),
        P("F.","Vargas")
    };

    heapSort(&vct, vct.size());

    for(Person i : vct)
        cout << i << endl;

    return 0;
}

//Float, double or int
template <class T>
void heapSort(vector<T>* vct, int size) {
    for(int i = size / 2 - 1; i >= 0; i--)
        maxHeapify(vct, size, i);

    for(int i = size - 1; i > 0; i--) {
        swap(vct->at(0), vct->at(i));
        maxHeapify(vct, i, 0);
    }
}

template <class T> 
void maxHeapify(vector<T>* vct, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && vct->at(left) > vct->at(largest)) 
        largest = left;
    
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