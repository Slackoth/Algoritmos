#include <iostream>

using namespace std;

/*
Hacer una función en C++ que, dado un BST y un dato, 
encuentre el sucesor PRE ORDER del
nodo que contiene dicho dato.
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

void inOrder(Node*);
void preOrder(Node*);
void postOrder(Node*);
void remove(Node**,int);
int inOrderSuccesor(Node*);
void insertInTree(int, Node**);
int preOrderSuccessor(Node*,Node*);
int findPreOrderSuccessor(Node**,int,Node*);

int main(void) {
    Node* tree = NULL;
    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        insertInTree(rand() % 10 + 1,&tree);
    }

    cout << "preOrderSuccessor: " << findPreOrderSuccessor(&tree, 9, NULL) << endl;

    cout << "inOrder: "; inOrder(tree); cout << endl;
    cout << "preOrder: ";  preOrder(tree); cout << endl;
    cout << "postOrder: "; postOrder(tree); cout << endl;
}

void insertInTree(int data, Node** root) {
    if(!*root) {
        *root = new Node(data);    
    }
    else {
        if(data < (*root)->data) {
            insertInTree(data, &(*root)->left);
        }
        else
            insertInTree(data, &(*root)->right);
    }
}

void inOrder(Node* root) {
    //Left->Root->Right
    if(root) {
        //Left
        inOrder(root->left);
        //Root
        cout << root->data << " ";
        //Right
        inOrder(root->right);
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

void postOrder(Node* root) {
    //Left->Right->Root
    if(root) {
        //Left
        postOrder(root->left);
        //Right
        postOrder(root->right);
        //Root
        cout << root->data << " ";
    }
}

//1. Node is completed root->Has both non-null children.
//2. Node is only child->Has one null child.
//3. Node is a leaf.
void remove(Node** root,int data) {
    if(*root) {
        if(data < (*root)->data) 
            remove(&(*root)->left,data);
        else if(data > (*root)->data)
            remove(&(*root)->right,data);
        else {
            //If node is leaf
            if(!(*root)->left && !(*root)->right) {
                Node* aux = *root;
                *root = NULL;

                delete aux;
            }
            //If node has only right side
            else if(!(*root)->left && (*root)->right) {
                Node* aux = *root;
                *root = (*root)->right;

                delete aux;
            }
            //If node has only left side
            else if((*root)->left && !(*root)->right) {
                Node* aux = *root;
                *root = (*root)->left;

                delete aux;
            }
            else {
                (*root)->data =  inOrderSuccesor((*root)->right);

                //Delete inOrderSuccessor
                remove(&(*root)->right,(*root)->data);
            }
        }
    }
}

int inOrderSuccesor(Node* rightSubTree) {
    while(rightSubTree->left) {
        rightSubTree = rightSubTree->left;
    }

    return rightSubTree->data;
}

int findPreOrderSuccessor(Node** root, int data, Node* parent) {
    if(*root) {
        if(data < (*root)->data) 
            return 0 + findPreOrderSuccessor(&(*root)->left,data, *root);
        
        else if(data > (*root)->data)
            return 0 + findPreOrderSuccessor(&(*root)->right,data, *root);
        
        else 
            return preOrderSuccessor(*root, parent);
    }
    
    return 0;
}

int preOrderSuccessor(Node* root, Node* parent) {
    //If node has left side
    if(root->left) {
        return root->left->data;
    }
    //If node has right side
    else if(root->right) {
        return root->right->data;
    }
    //if node is leaf
    else if(root->left && !root->right) {
        return parent->right ? parent->right->data : 0;
    }

    else
        return 0;
}