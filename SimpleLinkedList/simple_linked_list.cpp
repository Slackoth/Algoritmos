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
};

typedef struct NodeData Data;

struct Node {
    Data info;
    Node* next;
};

typedef struct Node* SimpleNode;

int size(SimpleNode);
bool empty(SimpleNode);
void travelList(SimpleNode);
int remove(SimpleNode*,Data);
void pushBack(SimpleNode*,Data);
void pushFront(SimpleNode*,Data);
void pushAt(SimpleNode*,Data,int);
bool removeAt(SimpleNode*,int,int);
bool removeFirstEncounter(SimpleNode*,Data);

template <class Predicative>
int removeIf(SimpleNode*,Predicative);

int main(void) {
    SimpleNode newList = NULL;

    cout << "Is empty: " << (empty(newList) ? "Yes" : "No") << endl;

    pushFront(&newList,Data(1,'A'));
    pushFront(&newList,Data(2,'B'));
    pushBack(&newList,Data(3,'C'));
    pushBack(&newList,Data(4,'D'));
    pushAt(&newList,Data(5,'E'),3);

    cout << "Is empty: " << (empty(newList) ? "Yes" : "No") << endl;
    cout << "Size: " << size(newList) << endl;

    //remove(&newList,Data(2,'B'));
    //cout << "Is deleted: " << (removeFirstEncounter(&newList,Data(4,'D')) ? "Yes" : "No") << endl; 
    //cout << "Is deleted: " << (removeAt(&newList,0,3) ? "Yes" : "No") << endl;
    removeIf(&newList,[](Data data)-> bool {
        return data.n % 2 == 0;
    });
    travelList(newList);
    
    
}

int size(SimpleNode list) {
    if(list) 
        return 1 + size(list->next);
    else
        return 0;

}
bool empty(SimpleNode list) {
    if(!list)
        return true;
    else 
        return false;
}
void pushBack(SimpleNode* list,Data data) {
    SimpleNode newNode = new Node;
    newNode->info = data;
    newNode->next = NULL;
    
    if(!*list) 
        *list = newNode;
    else {
        SimpleNode aux = *list;
        
        while(aux->next) 
            aux = aux->next;
        
        aux->next = newNode;
    }   
}
void pushFront(SimpleNode* list, Data data) {
    SimpleNode newNode = new Node;
    newNode->info = data;
    newNode->next = *list;
    *list = newNode;
}
void travelList(SimpleNode list) {
    if(list) {
        cout << "N: " << list->info.n << " C: " <<  list->info.c <<  endl;
        travelList(list->next);
    }
}
int remove(SimpleNode* list, Data data) {
    if(!*list)
        return 0;
    if((*list)->info == data) {
        SimpleNode aux = *list;
        *list = (*list)->next;
        delete aux;
        
        return 1 + remove(list,data);
    }
    else 
        return 0 + remove(&(*list)->next,data);
}
void pushAt(SimpleNode* list,Data data,int pos) {
    SimpleNode newNode = new Node;
    newNode->info = data;

    if(!*list || pos == 0) {
        newNode->next = *list;
        *list = newNode;
    }
    else {
        SimpleNode aux = *list;
        
        while(pos != 1) { 
            pos--;
            aux = aux->next;
        }

        newNode->next = aux->next;
        aux->next = newNode;
    }
}
bool removeFirstEncounter(SimpleNode* list, Data data) {
    if(!*list)
        return false;
    if((*list)->info == data) {
        SimpleNode aux = *list;
        *list = (*list)->next;
        delete aux;

        return true;
    }
    else {
        return false + removeFirstEncounter(&(*list)->next,data);
    }
}
bool removeAt(SimpleNode* list,int current,int pos) {
    if(!*list)
        return false;
    if(current == pos) {
        SimpleNode aux = *list;
        *list = (*list)->next;
        delete aux;

        return true;
    }
    else
        return false + removeAt(&(*list)->next,current+1,pos);
}
template <class Predicative>
int removeIf(SimpleNode* list,Predicative condition) {
    if(!*list)
        return 0;
    if(condition((*list)->info)) {
        SimpleNode aux = *list;
        *list = (*list)->next;
        delete aux;

        return 1 + removeIf(list,condition);
    }
    else 
        return 0 + removeIf(&(*list)->next,condition);
}
