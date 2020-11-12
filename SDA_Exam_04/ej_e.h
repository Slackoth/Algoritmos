#include <iostream>
#include "two_int.h"

using namespace std;

// struct TwoInt {
//     int n;
//     int m;

//     TwoInt() {}
//     TwoInt(int _n, int _m): n(_n), m(_m) {}
// };


// TwoInt userNumber(int a, int b);

// int main() {
//     TwoInt twoInt = userNumber(-10, 10);
    
//     cout << "Numero 1: " << twoInt.n << "\n";
//     cout << "Numero 2: " << twoInt.m << "\n";

//     return 0;
// }

TwoInt userNumber(int a, int b) {
    //cout << "a: " << a << " b: " << b << "\n";
    int n = 0, m = 0;
    //cout << "n: " << n << " m: " << m << "\n";

    while(n < a || n > b || m < a || m > b) {
        cout << "Ingrese el primer numero: \n" ;
        cin >> n;

        cout << "Ingrese el segundo numero: \n" ;
        cin >> m;
    }

    return TwoInt(n, m);
}