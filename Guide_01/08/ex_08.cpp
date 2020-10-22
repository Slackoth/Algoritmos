#include <cstdlib>
#include <iostream>

using namespace std;

struct Register {
    string name;
    char sex;
    int age;
};

typedef struct Register* Student;

struct Node {
    Student student;
    Node* next;
};

typedef struct Node* SimpleNode;

void insertInFront(SimpleNode&, Student);
void createStudent(Student&,string,char,int,int);
void printStudent(Student&,int);
void printSimpleLinkedList(SimpleNode&);
void maleFemale(SimpleNode&);

int main(void) {
    SimpleNode list = NULL;
    Student student1 = new Register;
    Student student2 = new Register;
    createStudent(student1,"Edward",'M',15,0);
    createStudent(student2,"Alex",'M',16,1);
    //printStudent(student1,2);
    insertInFront(list,student1);
    insertInFront(list,student2);
    printSimpleLinkedList(list);
    maleFemale(list);
    printSimpleLinkedList(list);

}

void insertInFront(SimpleNode &node, Student data) {
    SimpleNode newNode = new Node;
    newNode->student = data;
    newNode->next = node;
    node = newNode;
}

void createStudent(Student &student,string name,char sex,int age,int position) {
    student->name = name;
    student->age = age;
    student->sex = sex;
};

void printStudent(Student &student, int size) {
    //for(int i = 0; i < size; i++) {
        cout << "Name: " << student->name << endl;
        cout << "Age: " << student->age << endl;
        cout << "Sex: " << student->sex << endl;
    //}
}

void maleFemale(SimpleNode &node) {
    if(node) {
        if(node->student->sex == 'M') {
            node->next->student->sex = 'F';
        }
    }
    else {
        cout << "The list is empty!" << endl;
    }
}

void printSimpleLinkedList(SimpleNode &node) {
    if(node) {
        SimpleNode jump = node;
        int cont = 1;
        while (jump) {
            cout << "#" << cont << ":" << endl;
            cout << jump->student->name << endl;
            cout << jump->student->age << endl;
            cout << jump->student->sex << endl;
            cont++;
            jump = jump->next;
        }
    }
    else {
        cout << "The list is empty!" << endl;
    }
    
}