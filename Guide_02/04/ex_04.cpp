#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
    int n;
    Node* next;
};

typedef struct Node* SimpleNode;

int size(SimpleNode);
void pop(SimpleNode*);
bool empty(SimpleNode);
SimpleNode top(SimpleNode);
void push(SimpleNode*,int);
void travelStack(SimpleNode);

int main(void) {
    SimpleNode odd = NULL;
    SimpleNode pair = NULL;
    
    cout << "Enter the #: " << endl;
    int n;
    while(cin >> n) {
        if(n % 2 == 0)
            push(&pair,n);
        else
            push(&odd,n);

        cout << "Enter the #: " << endl;
    }
    if(size(odd) == size(pair))
        cout << "The # of odd and pair numbers are equal." << endl;
    else
        cout << "The # of odd and pair numbers are not equal." << endl;

}

int size(SimpleNode stack) {
    return stack ? 1 + size(stack->next) : 0;

}
bool empty(SimpleNode stack) {
    return stack == NULL;
}
SimpleNode top(SimpleNode stack) {
    SimpleNode top = new Node;
    top->n = stack->n;
    top->next = NULL;
    return top;
}
void push(SimpleNode* stack, int data) {
    SimpleNode newNode = new Node;
    newNode->n = data;
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
        cout << stack->n << endl;
        travelStack(stack->next);
    }
}