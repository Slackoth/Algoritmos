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
void pop(SimpleNode*);
bool empty(SimpleNode);
SimpleNode top(SimpleNode);
void push(SimpleNode*,Data);
void travelStack(SimpleNode);

int main(void) {

}

int size(SimpleNode stack) {
    return stack ? 1 + size(stack->next) : 0;

}
bool empty(SimpleNode stack) {
    return stack == NULL;
}
SimpleNode top(SimpleNode stack) {
    SimpleNode top = new Node;
    top->info = stack->info;
    top->next = NULL;
    return top;
}
void push(SimpleNode* stack, Data data) {
    SimpleNode newNode = new Node;
    newNode->info = data;
    newNode->next = *stack;
    *stack = newNode;
}

void pop(SimpleNode* stack) {
    SimpleNode aux = *stack;
    *stack = (*stack)->next;
    delete aux;
}

void swap(SimpleNode* stack, SimpleNode* stack2) {
    SimpleNode aux = *stack;
    
    *stack = *stack2;
    *stack2 = aux;
}
void travelStack(SimpleNode stack) {
    if(stack) {
        cout << stack->info.c << endl;
        cout << stack->info.n << endl;
        travelStack(stack->next);
    }
}