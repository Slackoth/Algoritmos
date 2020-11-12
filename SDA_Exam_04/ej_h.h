#ifndef EJ_H_H
#define EJ_H_H
#include <iostream>
#include "two_int.h"

using namespace std;

TwoInt randomNumbers(int a, int b) {
    int n = a + rand() % (b - a + 1);
    int m = a + rand() % (b - a + 1);;

    return TwoInt(n,m);
}

#endif