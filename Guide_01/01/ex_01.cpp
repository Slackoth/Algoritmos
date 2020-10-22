#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
    int n;
    Node* next;
};

typedef struct Node* SimpleNode;

template<class T>
T insertInFront(SimpleNode&, T);
void printSimpleLinkedList(SimpleNode&);
void orderSimpleLinkedList(SimpleNode&);

int main(void) {
    srand (time(NULL));

    //The arrow operator is used with a pointer to an object.
    SimpleNode node = NULL;
    for(int i = 1; i <= 10; i++) {
        insertInFront<int>(node,rand() % 1501);
    }
    orderSimpleLinkedList(node);
    cout << "1st list: " << endl;
    printSimpleLinkedList(node);

    cout << "*********" << endl;

    SimpleNode node2 = NULL;
    SimpleNode jump = node;
    while(jump) {
        if(jump->n < 100) {
            insertInFront<int>(node2,jump->n);
        }
        jump = jump->next;
    }
    cout << "2nd list: " << endl;
    printSimpleLinkedList(node2);
    
}
template<class T>
T insertInFront(SimpleNode &node, T data) {
    SimpleNode newNode = new Node;
    newNode->n = data;
    newNode->next = node;
    node = newNode;
    return newNode->n;
}

void printSimpleLinkedList(SimpleNode &node) {
    if(node) {
        SimpleNode jump = node;
        while (jump) {
            cout << jump->n << endl;
            jump = jump->next;
        }
    }
    else {
        cout << "The list is empty!" << endl;
    }
    
}

void orderSimpleLinkedList(SimpleNode &node) {
    SimpleNode jump = node;
    while (jump) {
        SimpleNode jump2 = jump->next;
        while(jump2) {
            if(jump->n >= jump2->n) {
                int data = jump2->n;
                jump2->n = jump->n;
                jump->n = data;
            }
            jump2 = jump2->next;
        }
        jump = jump->next;
    }
}