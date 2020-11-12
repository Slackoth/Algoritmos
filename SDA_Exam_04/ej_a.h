#include <iostream>

using namespace std;

string userName() {
    string name;

    cout << "Ingrese su nombre: \n" ;
    getline(cin, name);

    return name;
}