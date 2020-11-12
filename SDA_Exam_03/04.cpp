#include <iostream>

using namespace std;

struct StackNode {
    int n;
    StackNode* next;
};

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node() {}
    Node(int _d): data(_d)  {
        left = right = NULL;
    }
};

int levelOrder(Node* root);
bool printLevel(Node* root, int level);
void push(StackNode** stack, int data);
void insertInTree(int data, Node** root);
void stackToBST(StackNode* stack, Node** even, Node** odd);

int main(void) {
    StackNode* stack = NULL;
    Node* even = NULL;
    Node* odd = NULL;
    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        push(&stack, rand() % 100 + 1);
    }

    stackToBST(stack, &even, &odd);

    int evenLevel = levelOrder(even);
    int oddLevel = levelOrder(odd);

    //Check both levels 
    cout << "Even level: " << levelOrder(even) << "\n";
    cout << "Odd level: " << levelOrder(odd) << "\n";

    if(evenLevel == oddLevel)
        cout << "Both have equal levels" << "\n";
    else {
        cout << (evenLevel > oddLevel ? 
        "The BST of odd numbers has the least amount of levels." : 
        "The BST of even numbers has the least amount of levels.") << "\n";
    }

    return 0;
}

void push(StackNode** stack, int data) {
    StackNode* newNode = new StackNode;
    newNode->n = data;
    newNode->next = *stack;
    *stack = newNode;
}

void insertInTree(int data, Node** root) {
    if(!*root) 
        *root = new Node(data);    
    else {
        if(data < (*root)->data) 
            insertInTree(data, &(*root)->left);
        else
            insertInTree(data, &(*root)->right);
    }
}

void stackToBST(StackNode* stack, Node** even, Node** odd) {
    if(stack) {
        //Inserting odd or even numbers in tress
        if(stack->n % 2 == 0) 
            insertInTree(stack->n, even);
        else
            insertInTree(stack->n, odd);

        stackToBST(stack->next, even, odd);
    }
}

bool printLevel(Node* root, int level) {
    if(!root)
        return false;
    //When level hits one, we have traversed all tree.
    if(level == 1)   
        return true;
    //Couting levels in lefft and right side of tree
    bool left = printLevel(root->left, level - 1);
    bool right = printLevel(root->right, level - 1);

    return left || right;
}

int levelOrder(Node* root) {
    int level = 1;
    //When recieving false, we have hit bottom of the tree
    while(printLevel(root,level)) 
        level++;

    //returns correct level
    return level - 1;
}