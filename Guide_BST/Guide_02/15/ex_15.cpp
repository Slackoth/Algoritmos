#include <iostream>

using namespace std;

/*
Hacer una función en C++ que, dado un BST y un entero N, 
encuentre dos nodos en el BST
cuyos datos sumen N.
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node() {}
    Node(int _d): data(_d)  {
        left = right = NULL;
    }
};

#pragma region prototypes

void preOrder(Node* root);
void insertInTree(int data, Node** root);
bool findSummandsForN(Node* tree, Node* root, int n);
Node* searchForSummand(Node* root, Node* node, int data);

#pragma endregion

int main() {
    Node* tree = NULL;
    int n = 0;
    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        insertInTree(rand() % 10,&tree);
    }

    cout << "preOrder: ";  preOrder(tree); cout << endl;
    cout << "Digite un numero: \n";
    cin >> n;
    
    cout << (findSummandsForN(tree, tree, n) == false ? 
        "No se encontraron los sumandos." : "") << endl;

    return 0;
}

#pragma region functions

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

void preOrder(Node* root) {
    //Root->Left->Right
    if(root) {
        //Root
        cout << root->data << " ";
        //Left
        preOrder(root->left);
        //Right
        preOrder(root->right);
    }
}

bool findSummandsForN(Node* tree, Node* root, int n) {
    Node* summand = NULL;

    if(root) {
        if(root->data <= n) {
            summand = searchForSummand(tree, root, n - root->data);
        }
        
        if(summand) {
            cout << "Nodo #1: " << root->data << "\nNodo #2: " << summand->data;
            return true;
        }
        else {
            return false || findSummandsForN(tree, root->left, n);
            return false || findSummandsForN(tree, root->right, n);
        }
    }

    return false;
}

Node* searchForSummand(Node* root, Node* node, int data) {
    if(root) {
        if(data < root->data) 
            return searchForSummand(root->left, node, data);
        else if(data > root->data || root == node)
            return searchForSummand(root->right, node, data);
        else
            return root;
    }

    return NULL; 
}

#pragma endregion