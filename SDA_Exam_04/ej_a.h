#include <iostream>

using namespace std;

// string userName();

// int main() {
//     cout << userName() << "\n";
//     return 0;
// }

string userName() {
    string name;

    cout << "Ingrese su nombre: \n" ;
    getline(cin, name);

    return name;
}