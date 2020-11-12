#include "ej_tt.h"
#include <iostream>

using namespace std;

template<class T>
void swap(T* a, T* b);

void quickSort(Node* head);
Node* lastNode(Node* head);
void _quickSort(Node* low, Node* high);
Node* partition(Node* low, Node* high);

int main() {
    Node* dl = NULL;
    srand(time(NULL));

    //for(int i = 0; i < 10; i++) 
    pushBack(&dl, NodeData(rand() & 100 + 1, "as"));
    pushBack(&dl, NodeData(rand() & 100 + 1, "Ae"));
    pushBack(&dl, NodeData(rand() & 100 + 1, "sc"));
    pushBack(&dl, NodeData(rand() & 100 + 1, "br"));
    pushBack(&dl, NodeData(rand() & 100 + 1, "xl"));
    
    traverseFront(dl);

    quickSort(dl);

    traverseFront(dl);
    return 0;
}

template<class T>
void swap(T* a, T* b) {
    T aux = *a;
    *a = *b;
    *b = aux;
}

void quickSort(Node* head) {
    Node* last = lastNode(head);

    _quickSort(head,last);
}

Node* lastNode(Node* head) {
    while(head && head->next) 
        head = head->next;
    
    return head;
}

void _quickSort(Node* low, Node* high) {
    if(high && low != high && low != high->next) {
        Node* pivot = partition(low, high);

        _quickSort(low, pivot->prev);
        _quickSort(pivot->next, high);
    }
}

Node* partition(Node* low, Node* high) {
    char pivot = tolower(high->nd.s[0]);
    Node* i = low->prev;

    for(Node* j = low; j != high; j = j->next) {
        if(tolower(j->nd.s[0]) >= pivot) {
            i = (!i) ? low : i->next;
            
            swap(&(i->nd), &(j->nd));
        }
    }

    i = (!i) ? low : i->next;

    swap(&(i->nd), &(high->nd));
    return i;
}