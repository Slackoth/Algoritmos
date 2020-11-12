#include <iostream>

using namespace std;

/*
Hacer una función en C++, que dada una lista enlazada y 
ordenada de enteros L, coloque todos
los datos en un BST.
*/

#pragma region strcuts

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node() {}
    Node(int _d): data(_d)  {
        left = right = NULL;
    }
};

struct ListNode {
    int i;
    ListNode* next;

    ListNode() {}
    ListNode(int _i): i(_i) {}
};

#pragma endregion

#pragma region prototypes

void preOrder(Node* root);
void travelList(ListNode*);
void pushFront(ListNode**,int);
void traverseList(ListNode* list);
void insertInTree(int data, Node** root);
void listToBST(ListNode* list, Node** root);

#pragma endregion

int main() {
    Node* tree = NULL;
    ListNode* list = NULL;
    
    for(int i = 10; i >= 0; i--) {
        pushFront(&list, i);
    }

    traverseList(list); cout << endl;

    listToBST(list, &tree);

    cout << "preOrder: ";  preOrder(tree); cout << endl;

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

void pushFront(ListNode** list, int i) {
    ListNode* newNode = new ListNode(i);
    newNode->next = *list;
    *list = newNode;
}

void traverseList(ListNode* list) {
    if(list) {
        cout << list->i << "\t";
        traverseList(list->next);
    }
}

void listToBST(ListNode* list, Node** root) {
    if(list) {
        insertInTree(list->i, root);
        listToBST(list->next, root);
    }
}

#pragma endregion