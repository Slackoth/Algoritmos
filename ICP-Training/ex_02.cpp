#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
Implementarlo en un BST -> Use inOrder

You just bought all components for your new PC!
You start placing the CPU in the moherboard socket, gently applying a small layer of 
thermal paste. Then it's time to place the motherboard in the case, after that the 
process is pretty straight forward. But, the time of cable management has come. 
You don't like how you made the work so you need to find a way to make it look clean 
and nice.

Every component has a cable to be conected, each cable has a k value representing 
the lenght of it. The components that go straight into the motherboard 
(without a cable) have a lenght of 0.

After giving some thought to it, you think that the best way to make it look clean 
is to find a nice way to sort the process. You then think of an algorithm that follows:
• You need to place first every component that goes straight into the motherboard
• All components with even length needs to be placed from higher to lower length
• All components with odd length needs to be placed from lower to higher length
• Special components (prime number length) need to be placed last in any particular 
  order

Your output will be the component names in the order that need to be placed
*/

struct Component {
    string name;
    int length;

    Component() {}
    Component(string _n, int _l): name(_n), length(_l) {}

    bool operator<=(const Component& rhs) {
        return this->length <= rhs.length;
    }

    bool operator>=(const Component& rhs) {
        return this->length >= rhs.length;
    }
};

typedef Component c;

int isPrime(int n);
void swap(c* a, c* b);
int ascPartition(vector<c>* vct, int low, int high);
int descPartition(vector<c>* vct, int low, int high);
void quickSort(vector<c>* vct, int low, int high, bool flag);

int main(void) {
    int n, length;
    string name;
    vector<c> even, odd, prime;

    cout << "Enter n:\n";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter name:\n";
        cin >> name;

        cout << "Enter length:\n";
        cin >> length;

        if(length == 0)
            even.push_back(c(name, length));
        else if(isPrime(length))
            prime.push_back(c(name, length));
        else
            (length % 2 == 0) ? even.push_back(c(name, length)) : odd.push_back(c(name, length));
    }

    quickSort(&even, 0, even.size() - 1, true);
    quickSort(&odd, 0, odd.size() - 1, false);

    for(vector<c>::reverse_iterator it = even.rbegin(); it != even.rend(); it++)
        cout << it->name << "\t";
    cout << endl;

    for(c it : odd)
        cout << it.name << "\t";
    cout << endl;
    
    for(c it : prime)
        cout << it.name << "\t"; 
    cout << endl;
}

int isPrime(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0)
            return false;
    }

    return true;
}

void quickSort(vector<c>* vct, int low, int high, bool flag) {
    if(low < high) {
        int pivot = flag ? descPartition(vct, low, high) : ascPartition(vct, low, high);

        quickSort(vct, low, pivot - 1, flag);
        quickSort(vct, pivot + 1, high, flag);
    }
}

int ascPartition(vector<c>* vct, int low, int high) {
    c pivot = vct->at(high);
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(vct->at(j) <= pivot) {
            i++;
            swap(vct->at(i), vct->at(j));
        }
    }

    swap(vct->at(i + 1), vct->at(high));
    return i + 1;
}

int descPartition(vector<c>* vct, int low, int high) {
    c pivot = vct->at(high);
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(vct->at(j) >= pivot) {
            i++;
            swap(vct->at(i), vct->at(j));
        }
    }

    swap(vct->at(i + 1), vct->at(high));
    return i + 1;
}

void swap(c* a, c* b) {
    c aux = *a;
    *a = *b;
    *b = aux;
}