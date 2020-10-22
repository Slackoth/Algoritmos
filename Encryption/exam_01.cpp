#include <cstdlib>
#include <iostream>

using namespace std;

string encrypt(string);

int main(void) {
    string m = "";

    cout << "Ingrese el mensaje a encriptar: ";
    getline(cin,m);

    cout << "\nMensaje encriptado: ";
    cout << encrypt(m) << endl;
}

string encrypt(string message) {
    int length = message.length();
    string eMessage = "";

    for(int i = 0; i < length; i++) {
        switch(message[i]) {
            case 'a':
            case 'A':
                eMessage += "$$$\\";
                break;
            case 'e':
            case 'E':
                eMessage += "$$\\";
                break;
            case 'i':
            case 'I':
                eMessage += "$$$$$\\";
                break;
            case 'o':
            case 'O':
                eMessage += "$\\";
                break;
            case 'u':
            case 'U':
                eMessage += "$$$$\\";
                break;
            default:
                eMessage += message[i];
                break;
        }
    }

    return eMessage;
}