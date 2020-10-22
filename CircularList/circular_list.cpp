#include <cstdlib>
#include <iostream>

using namespace std;

struct NodeData {
    int n;
    char c;

    NodeData() {}
    NodeData(int _n,char _c): n(_n),c(_c) {}
};

typedef struct NodeData Data;

struct Node {
    Data data;
    Node* next;
};

int size(Node*);
bool empty(Node*);
void traverseList(Node*);
bool removeAt(Node**,int);
Node* pushBack(Node*,Data);
Node* pushFront(Node*,Data);
void pushAt(Node**,Data,int);

int main(void) {
    Node* last = NULL;

    last = pushBack(last,Data(6, 'e'));
    last = pushBack(last,Data(5, 's'));
    last = pushBack(last,Data(4, 'r'));

    //traverseList(last);

    last = pushFront(last,Data(3, 'c'));
    last = pushFront(last,Data(2, 'd'));
    last = pushFront(last,Data(1, 'e'));
    
    //traverseList(last);

    pushAt(&last,Data(11,'f'),0);
    pushAt(&last,Data(12,'g'),1);

    //traverseList(last);

    removeAt(&(last->next),0);
    removeAt(&(last->next),1);

    //traverseList(last);

}

bool empty(Node* last) {
    return last == NULL;
}
int size(Node* last) {
    Node* aux = last;
    int count = 0;
    do {
        count++;
        aux = aux->next;
    } while (aux != last);

    return count;   
}
void traverseList(Node* last) {
    Node* aux = last;
    do {
        cout << aux->data.c << "    ";
        cout << aux->data.n << endl;

        aux = aux->next;
    } while (aux != last);
}
Node* pushBack(Node* last, Data data) {
    Node* newNode = new Node;
    newNode->data = data;

    if(!last) {
        last = newNode;
        newNode->next = last;
    }
    else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;

    }

    return last;
}
Node* pushFront(Node* last,Data data) {
    Node* newNode = new Node;
    newNode->data = data;

    if(!last) {
        last = newNode;
        newNode->next = last;
    }
    else {
        newNode->next = last->next;
        last->next = newNode;
    }

    return last;
}
void pushAt(Node** last,Data data,int pos) {
    if(pos == 0) {
        *last = pushFront(*last,data);
    }
    else {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
    
        Node* aux = (*last)->next;

        int count = 0;
        while(pos != count) {
            count++;
            aux = aux->next;
        }

        newNode->next = aux->next;
        aux->next = newNode;
    }
}
bool removeAt(Node** head,int pos) {
    if(pos == 0) {
        *head = (*head)->next;
        return true;
    }
    else {
        Node* aux = NULL;
        Node* jump = *head;
        
        int count = 0;
        while(pos != count) {
            pos--;
            aux = jump;
            jump = jump->next;
        }
        
        aux->next = jump->next;
        delete(jump);

        return true;

    }
}
