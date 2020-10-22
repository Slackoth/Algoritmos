#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
    int n;
    Node* next;
};

typedef struct Node* SimpleNode;

void insertInFront(SimpleNode&, int);
SimpleNode orderAsc(SimpleNode&);
void printSimpleLinkedList(SimpleNode&);
int deleteBeforeLast(SimpleNode&);

int main(void) {
    srand(time(NULL));
    SimpleNode list = NULL;
    for(int i = 1; i <= 5; i++) {
        insertInFront(list,rand() % 101);
    }
    list = orderAsc(list);
    printSimpleLinkedList(list);
    deleteBeforeLast(list);
    printSimpleLinkedList(list);


}

void insertInFront(SimpleNode &node, int number) {
    SimpleNode newNode = new Node;
    newNode->n = number;
    newNode->next = node;
    node = newNode;
}

SimpleNode orderAsc(SimpleNode &node) {
    if(!node || !node->next) 
        return node;

    SimpleNode aux = NULL;
    
    while(node) {
        SimpleNode current = node;
        node = node->next;

        if(!aux || current->n < aux->n) {
            current->next = aux;
            aux = current;
        }
        else {
            SimpleNode aux2 = aux;

            while(aux2) {
                if(!aux2->next || current->n < aux2->next->n) {
                    current->next = aux2->next;
                    aux2->next = current;
                    break;
                }
                aux2 = aux2->next;
            }
        }
    }
    return aux;
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

int deleteBeforeLast(SimpleNode &node) {
    if(node) {
        while(node) {
            if(!node->next->next) {
                SimpleNode aux = node;
                node = node->next;
                delete aux;
                break;
            }
            node = node->next;
        }
        return 1;
        // if(!node->next->next){
        //     SimpleNode aux = node;
        //     node = node->next;
        //     delete aux;

        //     return 1;
        // }
        // else
        //     return 0 + deleteBeforeLast(node->next);
    }
    else
        return 0;
}