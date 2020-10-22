#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
    float n;
    Node* next;
};

typedef struct Node* SimpleNode;

template<class T>
T insertInFront(SimpleNode&, T);
void printSimpleLinkedList(SimpleNode&);
void printSpecifiedNode(SimpleNode&, int);
void multiplyNumInsideList(SimpleNode&);
void oddPairList(SimpleNode&);

int main(void) {
    SimpleNode list = NULL;
    cout << "Enter a #: " << endl;
    float m;
    while(cin >> m) {
        insertInFront<int>(list,m);
        cout << "Enter a #: " << endl;
    }
    cout << endl;
    cin.clear();
    cin.ignore();
    
    int option = 0;
    while(option != 5) {
        cout << "Enter an option: " << endl;
        cout << "1. Print list. \n2. Multiply list. \n3. Odd and pair numbers." << endl;
        cout << "4. Print specified node. \n5. Exit." << endl;
        cin >> option;
        switch(option) {
            case 1: printSimpleLinkedList(list); break;
            case 2: multiplyNumInsideList(list); break;
            case 3: oddPairList(list); break;
            case 4: 
                cout << "Enter a position: " << endl;
                int position;
                cin >> position;
                printSpecifiedNode(list,position);
                break;
            case 5: break;
            default: break;
        };

    }
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
        int cont = 0;
        while (jump) {
            cont++;
            cout << jump->n << endl;
            jump = jump->next;
        }
        cout << "# of nodes: " << cont << endl;
    }
    else {
        cout << "The list is empty!" << endl;
    }
    
}

void printSpecifiedNode(SimpleNode &node, int position) {
if(node) {
        SimpleNode jump = node;
        int cont = 1;
        while (cont < position && jump) {
            cont++;
            jump = jump->next;
        }
        if (!jump) {
            cout << "No node found in position: " << position << endl;
        }
        else {
            cout << "Node position: " << cont << endl;
            cout << "Node content: " << jump->n << endl;
            if (jump->next) {
                cout << "Next node content: " << jump->next->n << endl;
            }
            else {
                cout << "No other node found." << endl;
            }
        }
        
        
        
    }
    else {
        cout << "The list is empty!" << endl;
    }
}

void multiplyNumInsideList(SimpleNode &node) {
    if(node) {
        SimpleNode jump = node;
        int multipliedTotal = 1;
        while (jump) {
            multipliedTotal*=jump->n;
            jump = jump->next;
        }
        cout << "Multiplied total: " << multipliedTotal << endl;
    }
    else {
        cout << "The list is empty!" << endl;
    }
}

void oddPairList(SimpleNode &node) {
    if(node) {
        SimpleNode jump = node;
        while (jump) {
            int n = jump->n;
            if(n % 2 == 0) {
                cout << "Pair: " << n << endl;
            }
            else {
                cout << "Odd: " << n << endl;
            }
            jump = jump->next;
        }
    }
    else {
        cout << "The list is empty!" << endl;
    }
}