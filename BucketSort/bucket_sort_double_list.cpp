#include <iostream>
#include <vector>

using namespace std;

struct Node {
    float f;
    Node* next;
    Node* prev;
};

#pragma region prototypes

int listSize(Node* list);
void traverseList(Node* list);
void pushBack(Node**, float f);
void insertionSort(Node* bucket);
void bucketSort(float* arr, int size);

#pragma endregion

int main() {
    float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };

    bucketSort(arr, 6);

    for (int i = 0; i < 6; i++) 
        cout << arr[i] << "\t";
    cout << "\n";

    return 0;
}

void pushBack(Node** list,float f) {
    Node* newNode = new Node;
    newNode->f = f;
    newNode->next = NULL;
    
    if(!*list) 
        *list = newNode;
    else {
        Node* aux = *list;
        
        while(aux->next) 
            aux = aux->next;
        
        aux->next = newNode;
        newNode->prev = aux;
    }   
}

int listSize(Node* list) {
    if(list) 
        return 1 + listSize(list->next);
    else
        return 0;
}

void traverseList(Node* list) {
    if(list) {
        cout << list->f << "\t";
        traverseList(list->next);
    }
}

void bucketSort(float* arr, int size) {
    Node* bucket[size];

    for(int i = 0; i < size; i++) {
        Node* newList = NULL;
        bucket[i] = newList;
    }

    for(int i = 0; i < size; i++) {
        int bIndex = size * arr[i];

        pushBack(&bucket[bIndex], arr[i]);
    }

    for(int i = 0; i < size; i++) 
        insertionSort(bucket[i]);
    
    int index = 0;
    for(int i = 0; i < size; i++) 
        for(Node* aux = bucket[i]; aux != NULL; aux = aux->next) {
            arr[index] = aux->f;
            
            index++;
        }
}

void insertionSort(Node* bucket) {
    if(bucket && bucket->next) {
        for(Node* auxj = bucket->next; auxj != NULL; auxj = auxj->next) {
            float key = auxj->f;
            Node* auxi = auxj->prev;

            while(auxi != NULL && auxi->f > key) {
                auxi->next->f = auxi->f;
                auxi = auxi->prev;
            }
            
            auxi = (!auxi) ? bucket : auxi->next;
            auxi->f = key;
        }
    }
}