#include <cstdlib>
#include <iostream>

using namespace std;

template<class T>
struct Node {
    T info;
    Node<T>* next;
    Node<T>* prev;

    Node() { next = prev = NULL; } 
    Node(T _i): info(_i) { next = prev = NULL; }
};

template<class T>
void swap(T* a, T* b);

template<class T>
void quickSort(Node<T>* head);

template<class T>
void traverseFront(Node<T>* dl);

template<class T>
Node<T>* lastNode(Node<T>* head);

template<class T>
void pushBack(Node<T>** dl, T info);

template<class T>
void _quickSort(Node<T>* low, Node<T>* high);

template<class T>
Node<T>* partition(Node<T>* low, Node<T>* high);

int main(void) {
    Node<int>* dl = NULL;
    srand(time(NULL));

    for(int i = 0; i < 10; i++) 
        pushBack(&dl,rand() % 21);

    
    traverseFront(dl);

    quickSort(dl);

    traverseFront(dl);

    return 0;
}

template<class T>
void traverseFront(Node<T>* dl) {
    if(dl) {
        cout << dl->info << "  ";

        traverseFront(dl->next);
    }
    else
        cout << endl;
}

template<class T>
void pushBack(Node<T>** dl, T info) {
    Node<T>* newNode = new Node<T>(info);

    if(!*dl) 
        *dl = newNode;
    else {
        Node<T>* aux = *dl;

        while(aux->next) 
            aux = aux->next;

        aux->next = newNode;
        newNode->prev = aux;
    }
}

template<class T>
void quickSort(Node<T>* head) {
    // if(!head || !head->next)
    //     return;

    Node<T>* last = lastNode(head);

    _quickSort(head,last);
}

template<class T>
Node<T>* lastNode(Node<T>* head) {
    while(head && head->next) 
        head = head->next;
    
    return head;
}

template<class T>
void _quickSort(Node<T>* low, Node<T>* high) {
    if(high && low != high && low != high->next) {
        Node<T>* pivot = partition(low, high);

        _quickSort(low, pivot->prev);
        _quickSort(pivot->next, high);
    }
}

template<class T>
Node<T>* partition(Node<T>* low, Node<T>* high) {
    T pivot = high->info;
    Node<T>* i = low->prev;

    for(Node<T>* j = low; j != high; j = j->next) {
        if(j->info <= pivot) {
            i = (!i) ? low : i->next;
            
            swap(&(i->info), &(j->info));
        }
    }

    i = (!i) ? low : i->next;

    swap(&(i->info), &(high->info));
    return i;
}

template<class T>
void swap(T* a, T* b) {
    T aux = *a;
    *a = *b;
    *b = aux;
}
