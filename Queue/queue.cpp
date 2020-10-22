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

struct Queue {
    Node* front;
    Node* back;
};

void pop(Queue*);
bool empty(Queue);
void push(Queue*,Data);
int iterativeSize(Queue);
void travelQueue(SimpleNode);
int recursiveSize(SimpleNode);

int main(void) {

}

int iterativeSize(Queue q) {
    SimpleNode front = q.front;
    int count = 0;
    while(front) {
        count++;
        front->next;
    }
    return count;

}
int recursiveSize(SimpleNode front) {
    return front ? 1 + recursiveSize(front->next) : 0;
}
bool empty(Queue q) {
    return q.front == NULL;
}
void push(Queue* q, Data data) {
    SimpleNode newNode = new Node;
    newNode->info = data;
    newNode->next = NULL;
    
    if(!q->front) {
        q->front = newNode;
        q->back = newNode;
    }
    else {
        q->back->next = newNode;
        q->back = newNode;
    }
}
void pop(Queue* q) {
    SimpleNode aux = q->front;
    q->front = q->front->next;
    delete aux;
}

void swap(Queue* q, Queue* qu) {
    SimpleNode frontAux = q->front;
    SimpleNode backAux = q->back;

    q->front = qu->front;
    q->back = qu->back;

    qu->front = frontAux;
    qu->back = backAux;
}
void travelStack(SimpleNode front) {
    if(front) {
        cout << front->info.n << endl;
        cout << front->info.c << endl;
        travelStack(front->next);
    }
}