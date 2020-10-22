#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
    int n;
    Node* next;
};

typedef struct Node* SimpleNode;

void insertLast(SimpleNode&, int);
void printSimpleLinkedList(SimpleNode&);

int main(void) {
    SimpleNode list = NULL;
    srand (time(NULL));

    for(int i = 0; i < 5; i++) {
        insertLast(list,rand() % 1501);
    }
    printSimpleLinkedList(list);

}

void insertLast(SimpleNode &list, int number) {
    SimpleNode newNode = new Node;
    newNode->n = number;
    newNode->next = NULL;
    if(!list) {
        list = newNode;
    }
    else {
        SimpleNode jump = list;
        while(jump->next) {
            jump = jump->next;
        }
        jump->next = newNode;
    }
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