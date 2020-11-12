#include <iostream>

using namespace std;

/*
Hacer una función en C++ que, dado un BST y dos enteros A y B, 
borre del BST todos los nodos
que contengan datos en el rango [A, B].
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

void inOrder(Node* root);
void remove(Node** root, int data);
int inOrderSuccesor(Node* rightSubTree);
void insertInTree(int data, Node** root);
int removeInInterval(Node** root, int A, int B);

#pragma endregion

int main() {
    Node* tree = NULL;
    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        insertInTree(rand() % 10,&tree);
    }

    cout << "inOrder: "; inOrder(tree); cout << endl;
    removeInInterval(&tree, 1, 5);
    cout << "inOrder: "; inOrder(tree); cout << endl;

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

int removeInInterval(Node** root, int A, int B) {
    if(*root) {
        if(A > (*root)->data) 
            return 0 + removeInInterval(&(*root)->right, A, B);

        else if(B < (*root)->data)
            return 0 + removeInInterval(&(*root)->left, A, B);

        else {
            //If node is leaf
            if(!(*root)->left && !(*root)->right) {
                Node* aux = *root;
                *root = NULL;

                delete aux;
                return 1 + removeInInterval(root, A, B);
            }
            //If node has only right side
            else if(!(*root)->left && (*root)->right) {
                Node* aux = *root;
                *root = (*root)->right;

                delete aux;
                return 1 + removeInInterval(root, A, B);
            }
            //If node has only left side
            else if((*root)->left && !(*root)->right) {
                Node* aux = *root;
                *root = (*root)->left;

                delete aux;
                return 1 + removeInInterval(root, A, B);
            }
            else {
                (*root)->data =  inOrderSuccesor((*root)->right);

                //Delete inOrderSuccessor
                remove(&(*root)->right,(*root)->data);
                return 1 + removeInInterval(root, A, B);
            }
        }
    }

    return 0;
}

int inOrderSuccesor(Node* rightSubTree) {
    while(rightSubTree->left) {
        rightSubTree = rightSubTree->left;
    }

    return rightSubTree->data;
}

#pragma endregion