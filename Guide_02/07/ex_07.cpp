#include <cstdlib>
#include <iostream>

using namespace std;

enum operation {WITHDRAW, DEPOSIT, CONSULT, UPDATE, PAY};

struct Transaction {
    operation op;
    double duration;

    Transaction() {}
    Transaction(operation _o,double _d): op(_o),duration(_d) {}
};

struct Person {
    string name;
    Transaction tr;
    int nTimes;
    Person() {}
    Person(string _n,Transaction _t,int _nt): name(_n),tr(_t),nTimes(_nt) {}
    
};

typedef Person Client;

struct Node {
    Client cl;
    Node* next;
};

typedef struct Node* SimpleNode;

struct Queue {
    Node* front;
    Node* back;
};

int size(SimpleNode);
double average(Queue q);
void travelQueue(SimpleNode);
void push(Queue* q, Client cl);

int main(void) {
    Queue q;
    Transaction tr;
    q.front = q.back = NULL;

    srand(time(NULL));
    int opt = 0;
    //int letter = 0;
    operation op;
    float duration = 0.0;
    //string al = "QWERTYUIOPASDFGHJKLZXCVBNM";

    for(int i = 1; i <= 5; i++) {
        opt = rand() % 5;
        //letter = rand() % 25;
        switch (opt) {
        case 0:
            op = WITHDRAW;
            duration = 4.0;
            break;
        case 1:
            op = DEPOSIT;
            duration = 2.0;
            break;
        case 2:
            op = CONSULT;
            duration = 3.5;
            break;
        case 3:
            op = UPDATE;
            duration = 5.0;
            break;
        case 4:
            op = PAY;
            duration = 2.0;
            break;
        
        default:
            break;
        }
        push(&q,Client(Person("Dunno",Transaction(op,duration),opt)));
    }
    travelQueue(q.front);
    cout << "Average: " << average(q) << endl;

}
void travelQueue(SimpleNode front) {
    if(front) {
        cout << "name: " << front->cl.name << endl;
        cout << "operation: " << front->cl.tr.op << endl;
        cout << "duration: " << front->cl.tr.duration << endl;
        cout << "# of times: " << front->cl.nTimes << endl;
        travelQueue(front->next);
    }
}
void push(Queue* q, Client cl) {
    SimpleNode newNode = new Node;
    newNode->cl = cl;
    newNode->next = NULL;
    
    if(!q->front) {
        q->front = newNode;
        q->back = newNode;
    }
    else {
        q->back->next = newNode;
        q->back = newNode;
    }
}
double average(Queue q) {
    SimpleNode front = q.front;
    double total = 0;
    while(front) {
        total+=front->cl.nTimes*front->cl.tr.duration;
        front = front->next;
    }
    return total/size(q.front);

}
int size(SimpleNode front) {
    return front ? 1 + size(front->next) : 0;
}