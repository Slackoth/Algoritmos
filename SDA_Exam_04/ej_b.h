#include <iostream>

using namespace std;

// void initIntVar(int* i, int value);

// int main() {
//     int i;
    
//     initIntVar(&i, 10);

//     cout << "i: " << i << "\n";

//     return 0;
// }

void initInt(int* i, int value) {
    *i = value;
}

