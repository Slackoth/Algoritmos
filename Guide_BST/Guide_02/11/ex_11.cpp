#include <iostream>

using namespace std;

/*
Hacer una función en C++ que, dado un BST y un dato, 
encuentre el antecesor IN ORDER del
nodo que contiene dicho dato
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
int inOrderPredecessor(Node*);
void insertInTree(int, Node**);
int findInOrderPredecessor(Node**,int,int);

int main(void) {
    Node* tree = NULL;
    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        insertInTree(rand() % 10 + 1,&tree);
    }

    cout << "inOrderPredecessor: " << findInOrderPredecessor(&tree, 9, 0) << endl;

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

int findInOrderPredecessor(Node** root, int data, int predecessor) {
    if(*root) {
        if(data < (*root)->data) 
            return 0 + findInOrderPredecessor(&(*root)->left, data, predecessor);
        
        else if(data > (*root)->data) {
            predecessor = (*root)->data;
            return 0 + findInOrderPredecessor(&(*root)->right, data, predecessor);
        }
        
        else {
            if((*root)->left) 
                //right most node of the left sub tree
                return inOrderPredecessor((*root)->left);
            
            else
                return predecessor;
        }
    }

    return 0;
}

int inOrderPredecessor(Node* root) {
    while(root->right) {
        root = root->right;
    }

    return root->data;
}


