#include <cmath>
#include <iostream>

using namespace std;

/*
4. Modificar el ejercicio anterior, para que el BST 
resultante sea lo más balanceado posible.
5. Hacer una función en C++ que, dado un arreglo de 
enteros que representa la secuencia IN ORDER de un BST,
construya dicho BST
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

template<class T>
void swap(T*,T*);

void inOrder(Node*);
void preOrder(Node*);
void postOrder(Node*);
void remove(Node**,int);
int inOrderSuccesor(Node*);
int partition(int*,int,int);
void quickSort(int*,int,int);
void insertInTree(int,Node**);
void arrayToBST(Node**,int*,int*);
Node* arrayToBalancedBST(int*,int,int);

int main(void) {
    Node* tree = NULL;
    int size = 10;
    int* arr = new int[size];
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10 + 1;
        cout << arr[i] << "\t";
    }
    cout << "\n";

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << "\n";
    
    tree = arrayToBalancedBST(arr, 0, size - 1);

    cout << "inOrder: "; inOrder(tree); cout << endl;
    cout << "preOrder: ";  preOrder(tree); cout << endl;
    cout << "postOrder: "; postOrder(tree); cout << endl;
}

Node* arrayToBalancedBST(int* arr, int low, int high) {
    if (low > high)  
        return NULL;  

    int mid = (low + high)/2;  
    
    Node *root = new Node(arr[mid]);  

    root->left = arrayToBalancedBST(arr, low, mid - 1);  
    root->right = arrayToBalancedBST(arr, mid + 1, high);  
  
    return root;  
}

void arrayToBST(Node** root, int* arr, int* size) {
    for(int i = 0; i < *size; i++) 
        insertInTree(arr[i], root);
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

void quickSort(int* arr, int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high], i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[high]);
    return i;
}

template<class T>
void swap(T* a, T* b) {
    T aux = *a;
    *a = *b;
    *b = aux;
}