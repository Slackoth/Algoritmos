#ifndef EJ_G_H
#define EJ_G_H
#include <iostream>

using namespace std;

int randomNumber(int a, int b) {
    return a + rand() % (b - a + 1);
}

#endif