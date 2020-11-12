#ifndef EJ_TT_H
#define EJ_TT_H
#include <iostream>

using namespace std;

struct NodeData {
    int i;
    string s;

    NodeData() {}
    NodeData(int _i, string _s): i(_i),s(_s) {}

    bool operator==(const NodeData& rhs) {
        return this->i == rhs.i && this->s == rhs.s;
    }
};

struct Node {
    NodeData nd;
    Node* next,* prev;

    Node() {}
    Node(NodeData _nd): nd(_nd) { next = prev = NULL; }
};

int size(Node* dl) {
    if(dl)
        return 1 + size(dl->next);
    else
        return 0;
}

bool empty(Node* dl) {
    return dl == NULL;
}

void pushFront(Node** dl, NodeData nd) {
    Node* newNode = new Node(nd);
    //newNode->prev = NULL;

    if(!*dl) {
        //newNode->next = NULL;
        //dl->front = dl->back = newNode;
        *dl = newNode;
    }
    else {
        newNode->next = *dl;
        (*dl)->prev = newNode;
        *dl = newNode;

    }
}

void traverseFront(Node* dl) {
    if(dl) {
        cout << dl->nd.i << "\t";
        cout << dl->nd.s << endl;

        traverseFront(dl->next);
    }
    else
        cout << endl;
}

void pushBack(Node** dl, NodeData nd) {
    Node* newNode = new Node(nd);
    //newNode->next = NULL;
    
    if(!*dl) 
        *dl = newNode;
    else {
        Node* aux = *dl;
        
        while(aux->next) 
            aux = aux->next;
        
        aux->next = newNode;
        newNode->prev = aux;
    }   
}

void traverseBack(Node* dl) {
    if(dl) {
        Node* aux = dl;
        
        while(aux->next)
            aux = aux->next;
        
        while(aux) {
            cout << aux->nd.i << "\t";
            cout << aux->nd.s << endl;

            aux = aux->prev;
        }
    }
}

int remove(Node** dl, NodeData nd) {
    if(*dl) {
        if((*dl)->nd == nd) {
            if(!(*dl)->prev) {
                *dl = (*dl)->next;
                (*dl)->prev = NULL;
            }
            else {
                Node* auxPrev = (*dl)->prev;
                *dl = (*dl)->next;

                if(*dl) 
                    (*dl)->prev = auxPrev;
                
                auxPrev->next = *dl;
            }
            return 1 + remove(dl, nd);
        }
        else
            return 0 + remove(&(*dl)->next, nd);
    }
    else
        return 0;
}

#endif