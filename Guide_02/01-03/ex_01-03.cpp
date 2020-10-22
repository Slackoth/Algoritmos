#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef struct Node* SimpleNode;

int size(SimpleNode);
void pop(SimpleNode*);
bool empty(SimpleNode);
SimpleNode top(SimpleNode);
void push(SimpleNode*,int);
void traverseStack(SimpleNode);
void reverseStack(SimpleNode*);
int replace(SimpleNode*,int,int);
void saveDigits(SimpleNode*,int);

int main(void) {
    SimpleNode stk = NULL;
    SimpleNode stk1 = NULL;
    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        push(&stk,rand() % 5);
    }

    //saveDigits(&stk1,1512358);
    //replace(&stk,9,2);
    //reverseStack(&stk);

    //traverseStack(stk);
    //traverseStack(stk1);
    
}

int size(SimpleNode stack) {
    return stack ? 1 + size(stack->next) : 0;
}
bool empty(SimpleNode stack) {
    return stack == NULL;
}
SimpleNode top(SimpleNode stack) {
    SimpleNode top = new Node;
    top->data = stack->data;
    top->next = NULL;
    return top;
}

void push(SimpleNode* stack, int data) {
    SimpleNode newNode = new Node;
    newNode->data = data;
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
int replace(SimpleNode* stack,int n,int o) {
    if(!*stack)
        return 0;
    if((*stack)->data == o)  {
        (*stack)->data = n;
        return 1 + replace(&(*stack)->next,n,o);
    }
    else
        return 0 + replace(&(*stack)->next,n,o);
}
void traverseStack(SimpleNode stack) {
    if(stack) {
        cout << stack->data << "  ";
        traverseStack(stack->next);
    }
    else {
        cout << endl;
    }
}
void reverseStack(SimpleNode* stack) {
    SimpleNode head = NULL;
    SimpleNode body = NULL;

    head = *stack;
    body = head->next;

    if(!body)
        return;

    reverseStack(&body);

    head->next->next = head;
    head->next = NULL;
    *stack = body;
}
void saveDigits(SimpleNode* list,int n) {
    while(n > 0) {
        push(list,n % 10);
        n /= 10;
    }
}