#include <iostream>

using namespace std;

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

int size(Node* root);
void inOrder(Node* root);
void preOrder(Node* root);
void postOrder(Node* root);
void insertInTree(int data, Node** root);
void toMaxHeap(Node* root, int* arr, int* i);
void toMinHeap(Node* root, int* arr, int* i);
void toArrayInOrder(Node* root, int* arr, int* i);

#pragma endregion;

int main() {
    Node* tree = NULL;
    int i = 0;
    srand(time(NULL));

    for(int j = 0; j < 10; j++) {
        insertInTree(rand() % 10,&tree);
    }

    cout << "inOrder: "; inOrder(tree); cout << endl;

    int s = size(tree),* arr = new int[s];

    toArrayInOrder(tree, arr, &i);

    cout << "arr: ";
    for(int j = 0; j < s; j++)
        cout << arr[j] << "\t";
    cout << endl;

    i = 0;
    toMinHeap(tree, arr, &i);

    cout << "preOrder: "; preOrder(tree); cout << endl;

    i = s;
    toMaxHeap(tree, arr, &i);

    cout << "preOrder: "; preOrder(tree); cout << endl;

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
    if(root) {
        inOrder(root->left);
        
        cout << root->data << " ";

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
    if(root) {
        postOrder(root->left);
        postOrder(root->right);

        cout << root->data << " ";
    }
}

int size(Node* root) {
    if(root)
        return size(root->left) + 1 + size(root->right);
    else 
        return 0;
}

void toArrayInOrder(Node* root, int* arr, int* i) {
    if(root) {
        toArrayInOrder(root->left, arr, i);
        
        arr[*i] = root->data;
        (*i)++;

        toArrayInOrder(root->right, arr, i);
    }
}

void toMinHeap(Node* root, int* arr, int* i) {
    if(root) {
        root->data = arr[*i];
        (*i)++;

        toMinHeap(root->left, arr, i);
        toMinHeap(root->right, arr, i);
    }
}

void toMaxHeap(Node* root, int* arr, int* i) {
    if(root) {
        (*i)--;
        root->data = arr[*i];
        
        toMaxHeap(root->left, arr, i);
        toMaxHeap(root->right, arr, i);
    }
}

#pragma endregion