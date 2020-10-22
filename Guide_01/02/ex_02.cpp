#include <cstdlib>
#include <iostream>
#include <functional>

using namespace std;

struct Node {
    float n;
    Node* next;
};

typedef struct Node* SimpleNode;

struct storedlambdas {
    function<void(SimpleNode&,float)> insertInFront;
    function<void(SimpleNode&)> printList;
    function<void(SimpleNode&,SimpleNode&)> fillCompleteList;
};

int main(void) {
    storedlambdas sl;
    SimpleNode mNode = NULL;
    SimpleNode nNode = NULL;
    SimpleNode mnNode = NULL;

    sl.insertInFront = [](SimpleNode &node,float x) {
        SimpleNode newNode = new Node;
        newNode->n = x;
        newNode->next = node;
        node = newNode;
    };
    sl.printList = [](SimpleNode &node) {
        SimpleNode jump = node;
        while(jump) {
            cout << jump->n << endl;
            jump = jump->next;
        }
    };
    sl.fillCompleteList = [](SimpleNode &node, SimpleNode &nodeToCreate) {
        SimpleNode jump = node;
        while(jump) {
            SimpleNode newNode = new Node;
            newNode->n = jump->n;
            newNode->next = nodeToCreate;
            nodeToCreate = newNode;
            jump = jump->next;
        }
    };

    cout << "Enter a # in m: " << endl;
    float m;
    while(cin >> m && m) {
        sl.insertInFront(mNode,m);
        cout << "Enter a # in m: " << endl;
    }
    cout << endl;
    cin.clear();
    cin.ignore();

    cout << "Enter a # in n: " << endl;
    float n;
    while(cin >> n) {
            sl.insertInFront(nNode,n);
            cout << "Enter a # in n: " << endl;
    }
    cin.clear();
    cin.ignore();

    sl.printList(mNode);
    sl.printList(nNode);
    cout << "**********" << endl;
    sl.fillCompleteList(mNode,mnNode);
    sl.fillCompleteList(nNode,mnNode);
    sl.printList(mnNode);

}

