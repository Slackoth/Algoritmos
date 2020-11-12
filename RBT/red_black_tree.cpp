#include <iostream>

using namespace std;

enum Side { LEFT, RIGHT };
enum Color { RED, BLACK };

struct Node {
    int i;
    Color c;
    Node* left,* right,* parent;

    Node() {}
    Node(int _i, Color _c): i(_i), c(_c) {
        parent = left = right = NULL;
    }
};

#pragma region prototypes

void inOrder(Node* tree);
void preOrder(Node* tree);
void postOrder(Node* tree);
void insertInTree(Node** tree, int i);
Node* insertNewNode(Node** tree, int i);
void leftRotation(Node** tree, Node** A);
void rightRotation(Node** tree, Node** A);
void leftRight(Node** tree, Node** newNode);
void rightLeft(Node** tree, Node** newNode);
void fixInsertion(Node** tree, Node** newNode);
void leftLeft(Node** tree, Node** parent, Node** grandpa);
void rightRight(Node** tree, Node** parent, Node** grandpa);

#pragma endregion

int main() {
    Node* tree = NULL;
    
    int array[] = { 4, 7, 12, 15, 3, 5, 14, 18, 16, 17 };

    for(int i = 0; i < 10; i++) {
        insertInTree(&tree, array[i]);
    }

    cout << "preOrder: "; preOrder(tree); cout << endl;

    return 0;
}

#pragma region rotations

void leftRotation(Node** tree, Node** B) {
    Node* A = (*B)->parent;
    A->right = (*B)->left;

    if((*B)->left)
        (*B)->left->parent = A;
    
    (*B)->parent = A->parent;

    if(!A->parent)
        *tree = *B;
    else if(A == A->parent->left)
        A->parent->left = *B;
    else
        A->parent->right = *B;
    
    (*B)->left = A;
    A->parent = *B;
}

void rightRotation(Node** tree, Node** B) {
    Node* A = (*B)->parent;
    A->left = (*B)->right;

    if((*B)->right)
        (*B)->right->parent = A;
    
    (*B)->parent = A->parent;

    if(!A->parent)
        *tree = (*B);
    else if(A == A->parent->left)
        A->parent->left = (*B);
    else
        A->parent->right = (*B);
    
    (*B)->right = A;
    A->parent = *B;
}

#pragma endregion

#pragma region insertSubcases

void leftLeft(Node** tree, Node** parent, Node** grandpa) {
    //Save grandpa reference
    Node* formerGrandpa = *grandpa;

    rightRotation(tree, parent);

    //Color parent BLACK and grandpa RED
    (*parent)->c = BLACK;
    formerGrandpa->c = RED;
}

void leftRight(Node** tree, Node** newNode) {
    leftRotation(tree, newNode);

    //newNode becomes parent and parent becomes newNode
    leftLeft(tree, newNode, &(*newNode)->parent);
}

void rightLeft(Node** tree, Node** newNode) {
    rightRotation(tree, newNode);

    //newNode becomes parent and parent becomes newNode
    rightRight(tree, newNode, &(*newNode)->parent);
}

void rightRight(Node** tree, Node** parent, Node** grandpa) {
    //Save grandpa reference
    Node* formerGrandpa = *grandpa;

    leftRotation(tree, parent);

    //Color parent BLACK and grandpa RED
    (*parent)->c = BLACK;
    formerGrandpa->c = RED;
}

#pragma endregion

#pragma region insertion 

void insertInTree(Node** tree, int i) {
    if(!*tree)
        *tree = new Node(i, BLACK);
    else {
        Node* newNode = insertNewNode(tree, i);
        //cout << newNode->c << ":" << newNode->i << endl;
        fixInsertion(tree, &newNode);
    }
}

Node* insertNewNode(Node** tree, int i) {
    Node* newNode = NULL;

    if(i < (*tree)->i) {
        if(!(*tree)->left) {
            newNode = new Node(i, RED);
            newNode->parent = *tree;
            (*tree)->left = newNode;
        }
        else
            newNode = insertNewNode(&(*tree)->left, i);
    }
    else {
        if(!(*tree)->right) {
            newNode = new Node(i, RED);
            newNode->parent = *tree;
            (*tree)->right = newNode;
        }
        else
            newNode = insertNewNode(&(*tree)->right, i);
    }

    return newNode;
}

void fixInsertion(Node** tree, Node** newNode) {
    Side parentSide, childSide;
    Node* parent = (*newNode)->parent;
    Node* uncle = NULL,* grandpa = NULL;

    //If newNode is root
    if((*newNode)->c != BLACK && !(*newNode)->parent) {
        (*newNode)->c = BLACK;
        return;
    }
    
    if(parent)
        grandpa = parent->parent;
    
    //If parent is BLACK, do nothing, otherwise:
    if(parent && grandpa && parent->c != BLACK) {
        parentSide = (grandpa->left == parent) ? LEFT : RIGHT;
        childSide = (parent->left == *newNode) ? LEFT : RIGHT;
        uncle = (parentSide == LEFT) ? grandpa->right : grandpa->left;

        //NULL nodes are BLACK
        if(!uncle || uncle->c == BLACK) {
            //Check if is subcase LL, LR, RL or RR
            if(parentSide == LEFT && childSide == LEFT)
                leftLeft(tree, &parent, &grandpa);
            else if(parentSide == LEFT && childSide == RIGHT)
                leftRight(tree, newNode);
            else if(parentSide == RIGHT && childSide == LEFT)
                rightLeft(tree, newNode);
            else
                rightRight(tree, &parent, &grandpa);
        }
        else {
            //Color parent & uncle BLACK
            parent->c = BLACK;
            uncle->c = BLACK;

            //Color grandpa RED
            grandpa->c = RED;
            
            //grandpa becomes the newNode
            fixInsertion(tree, &grandpa);
        }
    }
}

#pragma endregion

#pragma region traversals
//(tree->c == 0 ? "RED" : "BLACK") << ":"
void inOrder(Node* tree) {
    if(tree) {
        inOrder(tree->left);
        cout << tree->c << ":" << tree->i << "\t";
        inOrder(tree->right);
    }
}

void preOrder(Node* tree) {
    if(tree) {
        cout << tree->c << ":" << tree->i << "\t";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void postOrder(Node* tree) {
    if(tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->c << ":" << tree->i << "\t";
    }
}

#pragma endregion
