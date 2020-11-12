#include "size.h"
#include "ej_a.h"
#include "ej_b.h"
#include "ej_j.h"
#include "ej_l.h"
#include "ej_kk.h"
#include "ej_ll.h"
#include "ej_mm.h"
#include "ej_ss.h"
#include "ej_rr.h"
#include "ej_tt.h"
#include "ej_xx.h"
#include "ej_uu.h"
#include "ej_ww.h"
#include "ej_yy.h"
#include <iostream>
#include "two_int.h"
#include "position.h"

using namespace std;

int main() {
    srand(time(NULL));
    string name = userName();
    int p, c = 0, mSize = 11;

    char** m1 = new char*[mSize];
    int** m2 = new int*[mSize];

    for(int i = 0; i < mSize; i++)
        m1[i] = new char[mSize];

    for(int i = 0; i < mSize; i++)
        m2[i] = new int[mSize];

    initInt(&p, 10);
    spaceMatrix(m1, mSize);
    ceroMatrix(m2, mSize);
    
    cout << "Intento de insercion debido a kk -> " << (kkFunction(m2, mSize) ? "Exitosa." : "Fallida.")  << "\n";
    cout << "Intento de insercion debido a ll -> " << (llFunction(m2, mSize) ? "Exitosa." : "Fallida.")  << "\n";
    cout << "Intento de insercion debido a ll -> " << (llFunction(m2, mSize) ? "Exitosa." : "Fallida.")  << "\n";
    cout << "Intento de insercion debido a mm -> " << (mmFunction(m2, mSize) ? "Exitosa." : "Fallida.")  << "\n";    
    
    rrFunction(&p, &c, m2, m1, mSize);
    printMatrix(m1, mSize);
    
    Node* dl = readCsv("data.csv");

    pushBack(&dl, NodeData(p, name));
    quickSort(dl);
    cutList(&dl, 10);
    traverseFront(dl);
    writeCsv(dl, "finished.csv");

    return 0;
}