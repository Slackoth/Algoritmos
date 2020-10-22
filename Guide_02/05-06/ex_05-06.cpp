#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
    string word;
    Node* next;
};

typedef struct Node* SimpleNode;

struct Queue {
    Node* front;
    Node* back;
};

void pop(Queue*);
bool empty(Queue);
void push(Queue*,string);
int iterativeSize(Queue);
void travelQueue(SimpleNode);
int recursiveSize(SimpleNode);
void splitPhrase(Queue*,string);
void reverseQueue(SimpleNode*,SimpleNode*);

int main(void) {
    Queue q;
    q.front = q.back = NULL;

    cout << "Enter a phrase: " << endl;
    string phrase;
    getline(cin,phrase);
    splitPhrase(&q,phrase);
    travelQueue(q.front);
    reverseQueue(&q.front,&q.back);
    travelQueue(q.front);
}

int iterativeSize(Queue q) {
    SimpleNode front = q.front;
    int count = 0;
    while(front) {
        count++;
        front->next;
    }
    return count;

}
int recursiveSize(SimpleNode front) {
    return front ? 1 + recursiveSize(front->next) : 0;
}
bool empty(Queue q) {
    return q.front == NULL;
}
void push(Queue* q, string data) {
    SimpleNode newNode = new Node;
    newNode->word = data;
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
void pop(Queue* q) {
    SimpleNode aux = q->front;
    q->front = q->front->next;
    delete aux;
}
void swap(Queue* q, Queue* qu) {
    SimpleNode frontAux = q->front;
    SimpleNode backAux = q->back;

    q->front = qu->front;
    q->back = qu->back;

    qu->front = frontAux;
    qu->back = backAux;
}
void travelQueue(SimpleNode front) {
    if(front) {
        cout << front->word << endl;
        travelQueue(front->next);
    }
}
void splitPhrase(Queue* q, string phrase) {
    string word = "";
    Queue** qu;
    for(auto letter : phrase) {
        if(letter == ' ') {
            push(&(*q),word);
            word = "";
        }
        else {
            word = word + letter;
        }
    }
    push(&(*q),word);
}
void reverseQueue(SimpleNode* front,SimpleNode* back) {
    SimpleNode head = NULL;
    SimpleNode body = NULL;

    head = *front;
    body = head->next;

    // cout << "1st front: " <<  (*front)->word << endl;
    // cout << "1st head: " <<  head->word << endl;
    // if(body)
    //     cout << "1st body: " <<  body->word << endl;

    if(!body)
        //*back = body;
        return;

    reverseQueue(&body,back);

    // cout << "2nd front: " <<  (*front)->word << endl;
    // cout << "2nd head: " <<  head->word << endl;
    // if(body)
    //     cout << "2nd body: " <<  body->word << endl;

    head->next->next = head;
    *back = head;
    head->next = NULL;
    *front = body;

    // cout << "3th front: " <<  (*front)->word << endl;
    // cout << "3th head: " <<  head->word << endl;
    // if(body)
    //     cout << "3th body: " <<  body->word << endl;

}