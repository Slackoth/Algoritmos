#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int gcd(int,int);
double* generateKey(double,double);
string encryptMessage(double,double,string);
string decryptMessage(int,int,string);

int main(void) {
    // double* pointer = generateKey(2,7);
    double n = pow(6,5);
    double m = fmod(4,14);
    double p = pow(n,11);
    double l = fmod(p,14);
    cout << m << endl;

    // cout << "Public key: " << pointer[0] << endl;
    // cout << "Encrypt key: " << pointer[1] << endl;
    // cout << "Decrypt key: " << pointer[2] << endl;

    // string b = encryptMessage(pointer[1],pointer[0],"ABC");
    //decryptMessage(pointer[2],pointer[0],b);

}

int gcd(int a, int b) {
    if(a == 0)
        return b;
    return gcd(b % a, a);
}

double* generateKey(double p, double q) {
    srand(time(NULL));

    double* keys = new double[3];
    double pKey = p*q;
    double phi = (p-1) * (q-1);
    int eKey = 5;//rand() % (phi - 2) + 2;
    int dKey = 11;
    
    // while(gcd(eKey,phi) != 1) {
    //     eKey = rand() % (phi - 2) + 2;
    // }

    // while(gcd(dKey*eKey,phi) != 1) {
    //     dKey = rand() % 19 + 2;
    // }

    keys[0] = pKey;
    keys[1] = eKey;
    keys[2] = dKey;

    return keys;
}

string encryptMessage(double eKey, double pKey, string message) {
    string encryptM = "";
    int length = message.length();
    double n = pow(int(message[0]),5);
    double a = pow(n,11);
    double b = fmod(a,14);
    cout << b << "ads" << endl;

    for(int i = 0; i < length; i++) {
        cout << "codeCharAt: " << int(message[i]) << endl;
        double n = pow(int(message[i]),eKey);
        cout << "n: " << n << endl;
        cout << "n % pKey: " << fmod(n,pKey) << endl;
        encryptM += char((fmod(n,pKey)) + 33);
    }

    cout << "encryptM: " << encryptM << endl;

    return encryptM;
}

string decryptMessage(int dKey, int pKey, string encryptM) {
    string decryptM = "";
    int length = encryptM.length();

    for(int i = 0; i < length; i++) {
        cout << "codeCharAt: " << int(encryptM[i]) << endl;
        int r = int(encryptM[i]) - 33;
        cout << "real codeCharAt: " << r << endl;
        long long p = pow(r,dKey);
        cout << "pow: " << p << endl;
        int m = p % pKey;
        cout << "mod: " << m << endl;
    }

    return "";
}
