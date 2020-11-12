#include <iostream>

using namespace std;

int randomNumber() {
    srand(time(NULL));

    return -100 + rand() % 201;
}