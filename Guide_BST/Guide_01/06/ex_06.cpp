#include <iostream>

using namespace std;

/*
Escribe una función que dados dos árboles binarios A y B, 
determine si son idénticos o no. 
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
bool equalTrees(Node*,Node*);
void insertInTree(int, Node**);

int main(void) {
    Node* tree = NULL;
    Node* tree2 = NULL;
    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        //insertInTree(rand() % 26,&tree);
        insertInTree(i,&tree2);
        insertInTree(i,&tree);
    }

    cout << "inOrder: "; inOrder(tree); cout << endl;
    cout << "inOrder2: "; inOrder(tree2); cout << endl;
    cout << "Are the trees equal? " << (equalTrees(tree, tree2) ? "Yes" : "No") << endl;
    // cout << "preOrder: ";  preOrder(tree); cout << endl;
    // cout << "postOrder: "; postOrder(tree); cout << endl;
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

bool equalTrees(Node* rootA, Node* rootB) {
    bool flag = true;

    if(rootA && rootB) {
        if(rootA->data == rootB->data) {
            flag = flag && equalTrees(rootA->left, rootB->left);
            flag = flag && equalTrees(rootA->right, rootB->right);
        }
        else
            flag = false;

        return flag;
    }
    
    else if(!rootA && !rootB) 
        return flag && true;
    else 
        return flag && false;
}
