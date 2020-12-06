#include "ej_a.h"
#include "ej_b.h"
#include "ej_j.h"
#include "ej_l.h"
#include "ej_kk.h"
#include "ej_ll.h"
#include "ej_mm.h"
#include "ej_rr.h"
#include "ej_tt.h"
#include "ej_xx.h"
#include "ej_uu.h"
#include "ej_ww.h"
#include "ej_yy.h"
#include <iostream>
#include "two_int.h"
#include "position.h"
#include "directions.h"

/*
¿De qué se trata la aplicación? 
1. Manipulación de variables y estructuras de datos correcta (matrices y listas).
2. Edición de un archivo csv.
3. Estructurización de una aplicación.
*/

using namespace std;

int main() {
    srand(time(NULL));
    string name = userName();
    int p, c = 0, mSize = 10;
    bool flag = false;

    char** m1 = new char*[mSize];
    int** m2 = new int*[mSize];

    for(int i = 0; i < mSize; i++)
        m1[i] = new char[mSize];

    for(int i = 0; i < mSize; i++)
        m2[i] = new int[mSize];

    initInt(&p, 0);
    spaceMatrix(m1, mSize);
    ceroMatrix(m2, mSize);

    while(flag != true)
        flag = kkFunction(m2, mSize);
    
    flag = false;
    while(flag != true)
        flag = llFunction(m2, mSize);

    flag = false;
    while(flag != true)
        flag = llFunction(m2, mSize);

    flag = false;
    while(flag != true)
        flag = mmFunction(m2, mSize);
    
    rrFunction(&p, &c, m2, m1, mSize);
    
    Node* dl = readCsv("data.csv");

    pushFront(&dl, NodeData(p, name));
    quickSort(dl);
    cutList(&dl, 10);

    cout << "Lista cortada: " << endl; traverseFront(dl);
    
    writeCsv(dl, "data.csv");

    return 0;
}