#include "ej_tt.h"
#include <iostream>

using namespace std;

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