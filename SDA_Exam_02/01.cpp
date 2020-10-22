#include <iostream>

using namespace std;

struct StackNode {
    int n;
    StackNode* next;
};

struct Node {
    StackNode* data;
    Node* left;
    Node* right;
    
    Node() {}
    Node(StackNode* _sd): data(_sd)  {
        left = right = NULL;
    }
};

void inOrder(Node*);
void preOrder(Node*);
void postOrder(Node*);
void remove(Node**,int);
void push(StackNode**,int);
int inOrderSuccesor(Node*);
void travelStack(StackNode*);
void insertInTree(int, Node**);

int main(void) {
    Node* tree = NULL;
    int n = 0;

    cout << "Enter n integer numbers or press CTRL+D: \n";
    while(cin >> n) {
        insertInTree(n, &tree);
    }

    cout << "inOrder: \n"; inOrder(tree); cout << endl;
    cout << "preOrder: \n";  preOrder(tree); cout << endl;
    cout << "postOrder: \n"; postOrder(tree); cout << endl;

    return 0;
}

void push(StackNode** stack, int data) {
    StackNode* newNode = new StackNode;
    newNode->n = data;
    newNode->next = *stack;
    *stack = newNode;
}

void travelStack(StackNode* stack) {
    if(stack) {
        cout << stack->n << "   ";
        travelStack(stack->next);
    }
}

void insertInTree(int n, Node** root) {
    if(!*root) {
        //Creating a new stack 
        StackNode* newStack = NULL;
        //Pushing new integer into the new stack
        push(&newStack, n);
        //Creating a new stack leaf 
        *root = new Node(newStack);    
    }
    else {
        //If the integer is equal to a number 
        //in the stack, it will be pushed 
        if(n == (*root)->data->n) {
            push(&(*root)->data, n);
            return;
        }
        else if(n < (*root)->data->n) 
            insertInTree(n, &(*root)->left);
        else
            insertInTree(n, &(*root)->right);
    }
}

void inOrder(Node* root) {
    //Left->Root->Right
    if(root) {
        //Left
        inOrder(root->left);
        //Root
        travelStack(root->data);
        cout << endl;
        //Right
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    //Root->Left->Right
    if(root) {
        //Root
        travelStack(root->data);
        cout << endl;
        //Left
        preOrder(root->left);
        //Right
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    //Left->Right->Root
    if(root) {
        //Left
        postOrder(root->left);
        //Right
        postOrder(root->right);
        //Root
        travelStack(root->data);
        cout << endl;
    }
}

