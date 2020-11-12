#include "ej_tt.h"
#include <iostream>

using namespace std;

// void cutList(Node** dl, int sizeLimit);

// int main() {
//     Node* dl = NULL;

//     for(int i = 0; i < 15; i++) 
//         pushBack(&dl, NodeData(i, "sa"));

//     traverseFront(dl);

//     cutList(&dl, 10);

//     traverseFront(dl);
    
//     return 0;
// }

void cutList(Node** dl, int sizeLimit) {
    if(!*dl)
        return;
    
    int lSize = size(*dl);
    int count = 0;

    if(lSize > sizeLimit) {
        Node* aux = *dl;
        
        while(count < sizeLimit) {
            count++;
            aux = aux->next;
        }

        while(aux) {
            Node* auxPrev = aux->prev;
            Node* toRemove = aux;
            aux = aux->next;
            auxPrev->next = aux;

            if(aux)
                aux->prev = auxPrev;

            delete(toRemove);
        }
    }
    else
        return;
}