#include "ej_tt.h"
#include <fstream>
#include <iostream>

using namespace std;

// Node* readData(string filename);
// void writeCsv(Node* dl, string filename);

// int main() {
//     Node* dl = readData("data.csv");
//     //traverseFront(dl);
//     writeCsv(dl, "data.csv");
//     return 0;
// }

Node* readCsv(string filename) {
    fstream file(filename);
    Node* dl = NULL;
    string line;

    if(!file.is_open()) 
        throw std::runtime_error("Could not open file!");

    while(getline(file, line)) {
        int pos = line.find(',');
        string s = line.substr(1, pos - 2);
        int i = stoi(line.substr(pos + 1));

        pushBack(&dl, NodeData(i, s));
    }    

    return dl;
}




