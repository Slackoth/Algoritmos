#include <iostream>

using namespace std;

/*
Escribe una función que indique si un árbol binario es un 
árbol de búsqueda
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

bool isBST(Node*);
void inOrder(Node*);
void preOrder(Node*);
void postOrder(Node*);
void remove(Node**,int);
int inOrderSuccesor(Node*);
void falseInsert(int, Node**);
void insertInTree(int, Node**);

int main(void) {
    Node* tree = NULL;
    Node* treeB = NULL;
    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        insertInTree(rand() % 26,&tree);
        falseInsert(rand() % 26,&treeB);
    }

    cout << "inOrder: "; inOrder(tree); cout << endl;
    cout << "preOrder: ";  preOrder(tree); cout << endl;
    cout << "postOrder: "; postOrder(tree); cout << endl;
    cout << "Is it a search tree? " << (isBST(tree) ? "Yes" : "No") << endl;
    cout << "Is it a search tree? " << (isBST(treeB) ? "Yes" : "No") << endl;
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

void falseInsert(int data, Node** root) {
    if(!*root) {
        *root = new Node(data);    
    }
    else {
        if(data > (*root)->data) {
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

                delete(aux);
            }
            //If node has only right side
            if(!(*root)->left && (*root)->right) {
                Node* aux = *root;
                *root = (*root)->right;

                delete(aux);
            }
            //If node has only left side
            else if((*root)->left && !(*root)->right) {
                Node* aux = *root;
                *root = (*root)->left;

                delete(aux);
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

bool isBST(Node* root) {
    int flag = true;

    if(root) {
        if(root->left) 
            if(root->left->data < root->data)
                flag = flag && isBST(root->left);
            else
                return false;
        
        if(root->right) 
            if(root->right->data >= root->data)
                flag = flag && isBST(root->right);
            else
                return false;
        
        return flag;
    }

    return flag;
}