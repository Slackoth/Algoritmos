#include <cstdlib>
#include <iostream>

using namespace std;

struct Pokemon {
    string name;
    string type1;
    string type2;
    
    Pokemon() {}
    Pokemon(string _n,string _t1, string _t2): name(_n),type1(_t1),type2(_t2) {}
};

typedef struct NodeData Data;

struct Node {
    Pokemon pokemon;
    Node* next;
};

typedef struct Node* SimpleNode;

void travelList(SimpleNode,int,int);
void pushFront(SimpleNode*,Pokemon);

int main(void) {
    SimpleNode newList = NULL;
    
    //Filling list
    pushFront(&newList,Pokemon("pa","A","A"));
    pushFront(&newList,Pokemon("ca","B",""));
    pushFront(&newList,Pokemon("pe","C","C"));
    pushFront(&newList,Pokemon("da","D",""));
    pushFront(&newList,Pokemon("pi","E",""));

    travelList(newList,0,0);
    
}

void pushFront(SimpleNode* list, Pokemon data) {
    SimpleNode newNode = new Node;
    newNode->pokemon = data;
    newNode->next = *list;
    *list = newNode;
}
void travelList(SimpleNode list,int first,int second) {
    //Traversing list
    while(list) {
        if(list->pokemon.name[0] == 'p')
            first++;
        if(list->pokemon.type2 == "") 
            second++;
        list = list->next;
    }
    cout << first << " pokemons fullfill the 1st condition" << endl;
    cout << second << " pokemons fullfill the 2nd condition" << endl;
}