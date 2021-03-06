#include "ej_tt.h"
#include <iostream>

using namespace std;

template<class T>
void swap(T* a, T* b) {
    T aux = *a;
    *a = *b;
    *b = aux;
}

Node* partition(Node* low, Node* high) {
    int pivot = high->nd.i;
    Node* i = low->prev;

    for(Node* j = low; j != high; j = j->next) {
        if(j->nd.i >= pivot) {
            i = (!i) ? low : i->next;
            
            swap(&(i->nd), &(j->nd));
        }
    }

    i = (!i) ? low : i->next;

    swap(&(i->nd), &(high->nd));
    return i;
}

void _quickSort(Node* low, Node* high) {
    if(high && low != high && low != high->next) {
        Node* pivot = partition(low, high);

        _quickSort(low, pivot->prev);
        _quickSort(pivot->next, high);
    }
}

Node* lastNode(Node* head) {
    while(head && head->next) 
        head = head->next;
    
    return head;
}

void quickSort(Node* head) {
    Node* last = lastNode(head);

    _quickSort(head,last);
}



