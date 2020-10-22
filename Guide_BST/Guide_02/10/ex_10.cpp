#include <iostream>

using namespace std;

/*
Hacer una función en C++ que, dado un BST y un dato, 
encuentre el sucesor POST ORDER del
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
void insertInTree(int, Node**);
int postOrderSuccesor(Node*,Node*);
int findPostOrderSuccesor(Node**,int,Node**);

int main(void) {
    Node* tree = NULL;
    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        insertInTree(rand() % 10 + 1,&tree);
    }

    cout << "postOrderSuccessor: " << findPostOrderSuccesor(&tree, 9, &tree) << endl;

    cout << "inOrder: "; inOrder(tree); cout << endl;
    cout << "preOrder: ";  preOrder(tree); cout << endl;
    cout << "postOrder: "; postOrder(tree); cout << endl;
}

int findPostOrderSuccesor(Node** root, int data, Node** parent) {
    if(*root) {
        if(data < (*root)->data) 
            return 0 + findPostOrderSuccesor(&(*root)->left,data, &(*root));
        
        else if(data > (*root)->data)
            return 0 + findPostOrderSuccesor(&(*root)->right,data, &(*root));
        
        else 
            return postOrderSuccesor(*root, *parent);
    }
    
    return 0;
}

int postOrderSuccesor(Node* root, Node* parent) {
    //If node is root
    if(root->data == parent->data)
        return 0;
    //If node's parent right side is null or if node is right side child
    else if(!parent->right || parent->right == root)
        return parent->data;
    //If node is left side child and node's parent has right side
    else if(parent->left == root && parent->right)
        return inOrderSuccesor(parent->right);
    //If node is left side child and node's parent right side is null
    else if(parent->left == root && !parent->right)
        return parent->data;

    else
        return 0;
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