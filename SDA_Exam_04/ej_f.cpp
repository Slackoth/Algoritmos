#include <iostream>

using namespace std;

int randomNumber();

int main() {
    cout << randomNumber() << "\n";

    return 0;
}

int randomNumber() {
    srand(time(NULL));
    
    return -100 + rand() % 201;
}