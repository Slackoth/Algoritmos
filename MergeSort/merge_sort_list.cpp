#include <cstdlib>
#include <iostream>

using namespace std;

struct NodeData {
    int n;
    char c;

    NodeData() {}
    NodeData(int _n,char _c): n(_n),c(_c) {}

    bool operator==(const NodeData& rhs) {
        return this->n == rhs.n && this->c == rhs.c; 
    }
    bool operator<=(const NodeData& rhs) {
        return this->n <= rhs.n;
    }
};

typedef struct NodeData Data;

struct Node {
    Data info;
    Node* next;
};

int size(Node*);
Node* mergeSort(Node*);
Node* merge(Node*,Node*);
void traverseList(Node*);
void pushBack(Node**,Data);

int main(void) {
    Node* list = NULL;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        pushBack(&list,Data(rand() % 16,'a'));
    }
    cout << "No" << endl;
    traverseList(list);
    cout << "Yes" << endl;
    list = mergeSort(list);
    traverseList(list);
    
}

int size(Node* list) {
    if(list) 
        return 1 + size(list->next);
    else
        return 0;
}
void traverseList(Node* list) {
    if(list) {
        cout << "N: " << list->info.n << " C: " <<  list->info.c <<  endl;
        traverseList(list->next);
    }
}
void pushBack(Node** list,Data data) {
    Node* newNode = new Node;
    newNode->info = data;
    newNode->next = NULL;
    
    if(!*list) 
        *list = newNode;
    else {
        Node* aux = *list;
        
        while(aux->next) 
            aux = aux->next;
        
        aux->next = newNode;
    }   
}
Node* mergeSort(Node* list) {
    if(!list || !list->next)
        return list;
    
    int lSize = size(list);
    
    Node* left; Node* right; Node* aux;
    left = right = NULL; aux = list;

    for(int i = 0; i < lSize; i++) {
        if(i < lSize / 2)
            pushBack(&left,aux->info);
        else
            pushBack(&right,aux->info);
        
        aux = aux->next;
    }

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left,right);
}
Node* merge(Node* left, Node* right) {
    Node* mergedList = NULL;
    
    while(left && right) {
        if(left->info <= right->info) {
            pushBack(&mergedList,left->info);
            left = left->next;
        }
        else {
            pushBack(&mergedList,right->info);
            right = right->next;
        }  
    }

    while(left) {
        pushBack(&mergedList,left->info);
            left = left->next;
    }
    while (right) {
        pushBack(&mergedList,right->info);
        right = right->next;
    }

    return mergedList;
    
}