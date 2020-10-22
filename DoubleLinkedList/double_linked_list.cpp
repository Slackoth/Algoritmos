#include <cstdlib>
#include <iostream>

using namespace std;

struct NodeData {
    int n;
    char c;

    NodeData() {}
    NodeData(int _n,char _c): n(_n),c(_c) {}

    bool operator==(const NodeData& rhs) {
        return this->c == rhs.c && this->n == rhs.n;
    }
};

typedef struct NodeData Data;

struct Node {
    Data data;
    Node* next;
    Node* prev;
};

struct DoubleList {
    Node* front;
    Node* back;

    DoubleList() {
        front = back = NULL;
    }
};

int size(Node*);
bool empty(Node*);
void traverseBack(Node*);
void traverseFront(Node*);
void pushAt(Node**,Data,int);
int remove(Node**,Node**,Data);
void pushBack(DoubleList*,Data);
void pushFront(DoubleList*,Data);
bool removeAt(Node**,Node**,int,int);
bool removeFirst(Node**,Node**,Data);

int main(void) {
    DoubleList dl;

    pushFront(&dl,Data(1,'a'));
    pushFront(&dl,Data(2,'b'));
    pushFront(&dl,Data(3,'c'));

    // pushBack(&dl,Data(4,'d'));
    // pushBack(&dl,Data(5,'e'));
    // pushBack(&dl,Data(6,'f'));

    traverseFront(dl.front);
    // traverseBack(dl.back);
    // remove(&dl.front,&dl.back,Data(1,'a'));
    //removeFirst(&dl.front,&dl.back,Data(2,'b'));
    //removeAt(&dl.front,&dl.back,1,0);
    
    // // traverseFront(dl.front);
    traverseFront(dl.front);
    cout << "front: " << dl.front->data.n << endl;
    cout << "back: " << dl.back->data.n << endl;
    // traverseBack(dl.back);
    

}

int size(Node* front) {
    if(front)
        return 1 + size(front->next);
    else
        return 0;
}

bool empty(Node* front) {
    return front == NULL;
}

void pushFront(DoubleList* dl,Data data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;

    if(!dl->front) {
        newNode->next = NULL;
        dl->front = dl->back = newNode;
    }
    else {
        newNode->next = dl->front;
        dl->front->prev = newNode;
        dl->front = newNode;

    }
}

void traverseFront(Node* front) {
    if(front) {
        cout << front->data.c << "  ";
        cout << front->data.n << endl;

        traverseFront(front->next);
    }
    else
        cout << endl;
}

void pushBack(DoubleList* dl,Data data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if(!dl->back) {
        newNode->prev = NULL;
        dl->front = dl->back = newNode;
    }
    else {
        newNode->prev = dl->back;
        dl->back->next = newNode;
        dl->back = newNode;

    }
}

void pushAt(Node** front,Data data,int pos) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if(pos == 0) {
        newNode->next = *front;
        (*front)->prev = newNode;
        *front = newNode;
    }
    else {
        Node* aux = *front;

        int count = 0;
        while(count < pos - 1) {
            count++;
            aux = aux->next;
        }

        newNode->prev = aux;
        newNode->next = aux->next;
        aux->next->prev = newNode;
        aux->next = newNode;
    }
}

void traverseBack(Node* back) {
     if(back) {
        cout << back->data.c << "  ";
        cout << back->data.n << endl;

        traverseBack(back->prev);
    }
    else
        cout << endl;
}

int remove(Node** front,Node** back,Data d) {
    if(*front) {
        if((*front)->data == d) {
            if(!(*front)->prev) {
                *front = (*front)->next;
                (*front)->prev = NULL;
            }
            else {
                Node* auxPrev = (*front)->prev;
                *front = (*front)->next;

                if(*front) {
                    (*front)->prev = auxPrev;
                }
                else
                    *back = auxPrev;

                auxPrev->next = *front;
            }

            return 1 + remove(front,back,d);
        }
        else
            return 0 + remove(&(*front)->next,back,d);
    }
    else
        return 0;
}

bool removeFirst(Node** front,Node** back,Data d) {
    if(*front) {
        if((*front)->data == d) {
            if(!(*front)->prev) {
                *front = (*front)->next;
                (*front)->prev = NULL;
            }
            else {
                Node* auxPrev = (*front)->prev;
                *front = (*front)->next;

                if(*front) {
                    (*front)->prev = auxPrev;
                }
                else
                    *back = auxPrev;

                auxPrev->next = *front;
            }

            return true;
        }
        else
            return false + removeFirst(&(*front)->next,back,d);
    }
    else
        return false;
}

bool removeAt(Node** front,Node** back,int pos,int current) {
    if(*front) {
        if(current == pos) {
            if(!(*front)->prev) {
                *front = (*front)->next;
                (*front)->prev = NULL;
            }
            else {
                Node* auxPrev = (*front)->prev;
                *front = (*front)->next;

                if(*front) {
                    (*front)->prev = auxPrev;
                }
                else
                    *back = auxPrev;

                auxPrev->next = *front;
            }

            return true;
        }
        else
            return false + removeAt(&(*front)->next,back,pos,current+1);
    }
    else
        return false;
}