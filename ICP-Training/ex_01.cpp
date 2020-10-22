#include <iostream>

using namespace std;

/*
Bobby is a garderner hamster. He has a big garden with n meters of space.
One day, he decides that he doesn't like anymore the way his garden looks so 
he will move the trees so it looks a little better, but he's a perfectionist 
so he wants them to alternate between the smalles and the biggest tree still 
unplanted. Every tree occupies different amount of space (based on the quantity 
of nodes that it has) and the total size of the arrangement of trees needs to 
be less than the total garden space.

Input
A value n where n < 10^5
A value m that represents the quantity of trees that Bobby has
For every tree, you'll get their inOrder and preOrder traversals

Output
Print the sequence that represents the tree arrangement
*/

struct Traversal {
    string inOrder;
    string preOrder;

    Traversal() {}
    Traversal(string _i, string _p): inOrder(_i), preOrder(_p) {}

    bool operator<=(const Traversal& rhs) {
        return this->inOrder.length() <= rhs.inOrder.length();
    }
};

typedef Traversal order;

struct Node {
    order data;
    Node* next;
    Node* prev;

    Node() {}
    Node(order _d): data(_d) { next = prev = NULL;}
};

void quickSort(Node* head);
Node* lastNode(Node* head);
void swap(order* a, order* b);
int getAndDeleteLast(Node** db);
void pushBack(Node** db, order data);
void _quickSort(Node* low, Node* high);
Node* partition(Node* low, Node* high);

int main(void) {
    int n, m;
    Node* db = NULL;
    string in, pre;

    cout << "Enter n:\n";
    cin >> n;
    cout << "Enter m:\n";
    cin >> m;

    for(int i = 0; i < m; i++) {
        cout << "Enter inOrder:\n";
        cin >> in;
        cout << "Enter preOrder:\n";
        cin >> pre;

        pushBack(&db, order(in, pre));
    }

    quickSort(db);

    int total = 0, aux = 0, prev = 0;

    while(db && total <= n) {
        if(aux % 2 == 0) {
            prev = db->data.inOrder.length();
            db = db->next;
        }
        else {
            prev = getAndDeleteLast(&db);
        }

        cout << prev << "\t";
        total += prev;
        aux++;
    }

    return 0;
}

int getAndDeleteLast(Node** db) {
    int data;
    
    if(!(*db)->next) {
        data = (*db)->data.inOrder.length();
        *db = NULL;

        delete *db;
        return data;
    }

    Node* aux = *db;

    while(aux->next) 
        aux = aux->next;

    data = aux->data.inOrder.length();
    aux->prev->next = NULL;
    aux = NULL;
    
    delete aux;
    return data;
}

void pushBack(Node** db, order data) {
    Node* newNode = new Node(data);

    if(!*db) {
        *db = newNode;
    }
    else {
        Node* aux = *db;

        while(aux->next) 
            aux = aux->next;
        
        aux->next = newNode;
        newNode->prev =  aux;
    }
}

void quickSort(Node* head) {
    if(!head || !head->next)
        return;

    Node* last = lastNode(head);

    _quickSort(head,last);
}

Node* lastNode(Node* head) {
    while(head && head->next) 
        head = head->next;
    
    return head;
}

void _quickSort(Node* low, Node* high) {
    if(high && low != high && low != high->next) {
        Node* pivot = partition(low, high);

        _quickSort(low, pivot->prev);
        _quickSort(pivot->next, high);
    }
}

Node* partition(Node* low, Node* high) {
    order pivot = high->data;
    Node* i = low->prev;

    for(Node* j = low; j != high; j = j->next) {
        if(j->data <= pivot) {
            i = (!i) ? low : i->next;
            
            swap(&(i->data), &(j->data));
        }
    }

    i = (!i) ? low : i->next;

    swap(&(i->data), &(high->data));
    return i;
}

void swap(order* a, order* b) {
    order aux = *a;
    *a = *b;
    *b = aux;
}