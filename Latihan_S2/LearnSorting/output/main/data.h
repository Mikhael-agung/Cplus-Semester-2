#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan elemen ke linked list
void append(Node** head_ref, int new_data);

// Fungsi untuk mencetak elemen dari linked list
void printList(Node* node);

// Fungsi sorting
void bubbleSort(Node* head, bool ascending);
void selectionSort(Node* head, bool ascending);
void insertionSort(Node** head_ref, bool ascending);
void mergeSort(Node** headRef, bool ascending);

#endif // LINKED_LIST_H
