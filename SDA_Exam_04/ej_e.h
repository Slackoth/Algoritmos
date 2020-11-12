#include <iostream>
#include "two_int.h"

using namespace std;

TwoInt userNumber(int a, int b) {
    int n = 0, m = 0;

    while(n < a || n > b || m < a || m > b) {
        cout << "Ingrese el primer numero: \n" ;
        cin >> n;

        cout << "Ingrese el segundo numero: \n" ;
        cin >> m;
    }

    return TwoInt(n, m);
}