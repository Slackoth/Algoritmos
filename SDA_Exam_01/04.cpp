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
    bool signedForm;
    Data info;
    Node* next;
};

typedef struct Node* SimpleNode;

void pop(SimpleNode*);
SimpleNode top(SimpleNode);
void travelStack(SimpleNode);
void push(SimpleNode*,bool,Data);
void signForms(SimpleNode*,SimpleNode*);

int main(void) {
    //Creating both stacks
    SimpleNode stack = NULL;
    SimpleNode completed = NULL;

    string alphabet = "QWERTY";

    //Filling unsigned forms
    for (int i = 0; i < 6; i++)
    {
        push(&stack,false,Data(i,alphabet[i]));
    }

    cout << "*****Incompleted stack*****" << endl;
    travelStack(stack);
    //Signing forms
    signForms(&stack,&completed);
    cout << "*****Completed stack*****" << endl;
    travelStack(completed);
    


}

void signForms(SimpleNode* stack,SimpleNode* completed) {
    SimpleNode aux = *stack;
    SimpleNode stackTop = NULL;
    while (aux)
    {   //Obtaininig the node from stack top
        //The data must be the same
        stackTop = top(*stack);
        //Pushing this new node to the completed stack
        push(&(*completed),true,stackTop->info);
        
        aux = aux->next;
        //Removing the signed form from the incompleted stack
        pop(&(*stack));
    }
    
}
SimpleNode top(SimpleNode stack) {
    SimpleNode top = new Node;
    top->signedForm = stack->signedForm;
    top->info = stack->info;
    top->next = NULL;
    return top;
}
void push(SimpleNode* stack, bool sign, Data data) {
    SimpleNode newNode = new Node;
    newNode->signedForm = sign;
    newNode->info = data;
    newNode->next = *stack;
    *stack = newNode;
}
void pop(SimpleNode* stack) {
    SimpleNode aux = *stack;
    *stack = (*stack)->next;
    delete aux;
}
void travelStack(SimpleNode stack) {
    if(stack) {
        cout << "c: " << stack->info.c << "  ";
        cout << "n: " << stack->info.n << endl;
        cout << "Signed form? " << (stack->signedForm ? "Yes" : "No") << endl;
        travelStack(stack->next);
    }
}