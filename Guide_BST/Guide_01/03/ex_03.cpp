#include <iostream>

using namespace std;

/*
Escribir una función recursiva 
que encuentre el número de nodos de un árbol binario. 
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
int countNodes(Node*);
int countLeaves(Node*);
void remove(Node**,int);
int countBranches(Node*);
int inOrderSuccesor(Node*);
void insertInTree(int, Node**);

int main(void) {
    Node* tree = NULL;
    srand(time(NULL));

    for(int i = 0; i <= 10; i++) {
        insertInTree(rand() % 29 + 2,&tree);
        //insertInTree(i,&tree);
    }

    cout << "inOrder: "; inOrder(tree); cout << endl;
    cout << "preOrder: ";  preOrder(tree); cout << endl;
    cout << "postOrder: "; postOrder(tree); cout << endl;

    cout << "Total of nodes: " << countNodes(tree) << endl;
    cout << "Total of leaves: " << countLeaves(tree) << endl;
    cout << "Total of branches: " << countBranches(tree) << endl;

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
void remove(Node** root, int data) {
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

int countNodes(Node* root) {
    if(!root)
        return 0;

    int count = 1;
    
    if(root->left)
        count += countNodes(root->left);

    if(root->right)
        count += countNodes(root->right);
    
    return count;
}

int countLeaves(Node* root) {
    if(!root)
        return 0;

    int count = 0;

    if(!root->left && !root->right) 
        return count + 1;

    if(root->left)
        count += countLeaves(root->left);

    if(root->right)
        count += countLeaves(root->right);
    
    return count;
}

int countBranches(Node* root) {
    if(!root)
        return 0;
    
    int count = 1;

    if(!root->left && !root->right) 
        return 0;

    if(root->left)
        count += countBranches(root->left);
        
    if(root->right)
        count += countBranches(root->right);
    
    return count;
}