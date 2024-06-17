#include <iostream>
#include "data.h"
using namespace std;

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = new_node;
    } else {
        Node* last = *head_ref;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
    }
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void bubbleSort(Node* head, bool ascending) {
    if (head == nullptr) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ascending ? ptr1->data > ptr1->next->data : ptr1->data < ptr1->next->data) {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void selectionSort(Node* head, bool ascending) {
    Node* temp = head;

    while (temp) {
        Node* minMax = temp;
        Node* r = temp->next;

        while (r) {
            if (ascending ? r->data < minMax->data : r->data > minMax->data)
                minMax = r;
            r = r->next;
        }

        swap(temp->data, minMax->data);
        temp = temp->next;
    }
}

void insertionSort(Node** head_ref, bool ascending) {
    if (*head_ref == nullptr) return;

    Node* sorted = nullptr;
    Node* current = *head_ref;

    while (current) {
        Node* next = current->next;
        if (sorted == nullptr || (ascending ? sorted->data >= current->data : sorted->data <= current->data)) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next && (ascending ? temp->next->data < current->data : temp->next->data > current->data)) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head_ref = sorted;
}

Node* sortedMerge(Node* a, Node* b, bool ascending) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    if (ascending ? a->data <= b->data : a->data >= b->data) {
        a->next = sortedMerge(a->next, b, ascending);
        return a;
    } else {
        b->next = sortedMerge(a, b->next, ascending);
        return b;
    }
}

void frontBackSplit(Node* source, Node** frontRef, Node** backRef) {
    if (source == nullptr || source->next == nullptr) {
        *frontRef = source;
        *backRef = nullptr;
        return;
    }

    Node* slow = source;
    Node* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

void mergeSort(Node** headRef, bool ascending) {
    if (*headRef == nullptr || (*headRef)->next == nullptr) return;

    Node* head = *headRef;
    Node* a;
    Node* b;

    frontBackSplit(head, &a, &b);

    mergeSort(&a, ascending);
    mergeSort(&b, ascending);

    *headRef = sortedMerge(a, b, ascending);
}
