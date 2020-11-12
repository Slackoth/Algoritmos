#include <iostream>

using namespace std;

int userNumber(int a, int b);

int main() {
    cout << userNumber(-10, 10) << "\n";
    return 0;
}

int userNumber(int a, int b) {
    int n;

    while(n < a || n > b) {
        cout << "Ingrese un numero: \n" ;
        cin >> n;
    }

    return n;
}