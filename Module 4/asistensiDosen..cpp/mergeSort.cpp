#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void append (Node*& head, int data){
    Node* newNode = new Node{data, nullptr};
    if (head == nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp-> next != nullptr){
        temp = temp-> next;
    }

    temp-> next = newNode;
}

void viewList(Node* head){
    Node* temp = head;
    while (temp){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
    cout << endl;   
}

