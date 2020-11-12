#include <iostream>

using namespace std;

int userNumber();

int main() {
    cout << userNumber() << "\n";
    return 0;
}

int userNumber() {
    int n;

    cout << "Ingrese un numero: \n" ;
    cin >> n;

    return n;
}