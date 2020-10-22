#include <iostream>
#include <cmath>

using namespace std;

struct StackNode {
    float amount;
    StackNode* next;
};

struct Album {
    int label;
    StackNode* sales;

    Album() {}
    Album(int _l, StackNode* _s): label(_l), sales(_s) {}
};

template <class T>
void swap(T* a, T* b);

bool isInt(float* amount);
int makeLabel(StackNode* stack);
bool isThreeDecimal(float* amount);
void travelStack(StackNode* stack);
void heapSort(Album* arr, int size);
void push(StackNode** stack, float data);
void minHeapify(Album* arr, int size, int i);
StackNode* toStack(float** albums, int* size, int* index);
void fillAlbumList(int* size, float** albums, Album* list);

int main(void) {
    int n = 5;
    float** albums = new float*[n];
    srand(time(NULL));
    
    for (int i = 0; i < n; i++) {
        albums[i] = new float[n];
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            albums[i][j] = (rand() % 2 + 5000) / 1000.0f;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << albums[i][j] << "\t";
        
        cout << "\n";
    }

    Album* arr = new Album[n];

    fillAlbumList(&n, albums, arr);

    for (int i = 0; i < n; i++) {
        cout << "Label: " << arr[i].label << "\n";
        travelStack(arr[i].sales);
        cout << "\n";
    }

    heapSort(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        cout << "Album #" << abs(i - n) << "\n";
        cout << "Label: " << arr[i].label << "\n";
        cout << "**********" << "\n";
    }
    cout << "\n";

    return 0;
}

void fillAlbumList(int* size, float** albums, Album* list) {
    for(int i = 0; i < *size; i++) {
        StackNode* newStack = toStack(albums, size, &i);
        int label = makeLabel(newStack);
        list[i] = Album(label, newStack);
    }
}

StackNode* toStack(float** albums, int* size, int* index) {
    StackNode* newStack =  NULL;

    for (int i = 0; i < *size; i++) 
        push(&newStack, albums[*index][i]);
    
    return newStack;
}

void push(StackNode** stack, float data) {
    StackNode* newNode = new StackNode;
    newNode->amount = data;
    newNode->next = *stack;
    *stack = newNode;
}

void travelStack(StackNode* stack) {
    if(stack) {
        cout << stack->amount << "   ";
        travelStack(stack->next);
    }
}

int makeLabel(StackNode* stack) {
    if(!stack)
        return 0;

    if(stack->next && isThreeDecimal(&stack->amount) == true && isInt(&stack->next->amount) == true) 
        return 1 + makeLabel(stack->next);

    return 0 + makeLabel(stack->next);
}

bool isThreeDecimal(float* amount) {
    if(*amount == int(*amount))
        return false;

    string decimals = to_string(*amount);
    bool flag = true;
    int count = 0;
    
    decimals = decimals.substr(decimals.find("."));

    if(decimals[3] == '0')
        return false;

    return flag && decimals[4] == '0' ? true : false;
}

bool isInt(float* amount) {
    return *amount == int(*amount);
}
template <class T>
void swap(T* a, T* b) {
    T aux = *a;
    *a = *b;
    *b = aux;
}

void heapSort(Album* arr, int size) {
    for(int i = size / 2 - 1; i >= 0; i--)
        minHeapify(arr, size, i);

    for(int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        minHeapify(arr, i, 0);
    }
}

void minHeapify(Album* arr, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left].label < arr[i].label) 
        smallest = left;
    
    if(right < size && arr[right].label < arr[smallest].label)
        smallest = right;
   
    if(smallest != i) {
        Album aux = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = aux;

        minHeapify(arr, size, smallest);
    }
}