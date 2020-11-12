#include "ej_tt.h"
#include <fstream>
#include <iostream>

using namespace std;

void writeCsv(Node* dl, string filename) {
    ofstream file(filename);

    while(dl) {
        string s = '"' + dl->nd.s + '"' + ',' + to_string(dl->nd.i);
        file << s + "\n";
        dl = dl->next;
    }
}