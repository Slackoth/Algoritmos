#ifndef EJ_H_H
#define EJ_H_H
#include <iostream>
#include "two_int.h"

using namespace std;

// struct TwoInt {
//     int n;
//     int m;

//     TwoInt() {}
//     TwoInt(int _n, int _m): n(_n), m(_m) {}
// };

TwoInt randomNumbers(int a, int b) {
    //srand(time(NULL));
    
    int n = a + rand() % (b - a + 1);
    int m = a + rand() % (b - a + 1);;

    return TwoInt(n,m);
}

#endif