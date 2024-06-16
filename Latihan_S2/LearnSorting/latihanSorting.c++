#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan elemen ke linked list
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
}

// Fungsi untuk mencetak elemen dari linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Bubble Sort dengan flag untuk linked list
void bubbleSort(Node* head, bool ascending) {
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    if (head == nullptr) return;

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

// Selection Sort untuk linked list
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

// Insertion Sort untuk linked list
void insertionSort(Node** head_ref, bool ascending) {
    Node* sorted = nullptr;
    Node* current = *head_ref;

    while (current) {
        Node* next = current->next;
        if (!sorted || (ascending ? sorted->data >= current->data : sorted->data <= current->data)) {
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

// Merge dua sublist untuk merge sort
Node* sortedMerge(Node* a, Node* b, bool ascending) {
    Node* result = nullptr;

    if (!a) return b;
    if (!b) return a;

    if (ascending ? (a->data <= b->data) : (a->data >= b->data)) {
        result = a;
        result->next = sortedMerge(a->next, b, ascending);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next, ascending);
    }

    return result;
}

// Membagi linked list menjadi dua bagian
void frontBackSplit(Node* source, Node** frontRef, Node** backRef) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

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

// Merge Sort untuk linked list
void mergeSort(Node** headRef, bool ascending) {
    Node* head = *headRef;
    Node* a;
    Node* b;

    if (!head || !head->next) return;

    frontBackSplit(head, &a, &b);

    mergeSort(&a, ascending);
    mergeSort(&b, ascending);

    *headRef = sortedMerge(a, b, ascending);
}

int main() {
    Node* head = nullptr;
    int choice, value, sortChoice;
    bool ascending;
        

        cout << "masukan inputa anda: ";
    while (true) {
        cin >> value;
        if (value == -1) break;
        append(&head, value);   
    }

    do {
        cout << "1. Bubble Sort linked list\n";
        cout << "2. Selection Sort linked list\n";
        cout << "3. Insertion Sort linked list\n";
        cout << "4. Merge Sort linked list\n";
        cout << "5. Cetak linked list\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        if (choice == 7) break;

        switch (choice) {
            case 1:
                cout << "1. Ascending\n";
                cout << "2. Descending\n";
                cout << "Masukkan pilihan: ";
                cin >> sortChoice;
                ascending = (sortChoice == 1);
                bubbleSort(head, ascending);
                cout << "Linked list telah diurutkan dengan Bubble Sort.\n";
                break;
            case 2:
                cout << "1. Ascending\n";
                cout << "2. Descending\n";
                cout << "Masukkan pilihan: ";
                cin >> sortChoice;
                ascending = (sortChoice == 1);
                selectionSort(head, ascending);
                cout << "Linked list telah diurutkan dengan Selection Sort.\n";
                break;
            case 3:
                cout << "1. Ascending\n";
                cout << "2. Descending\n";
                cout << "Masukkan pilihan: ";
                cin >> sortChoice;
                ascending = (sortChoice == 1);
                insertionSort(&head, ascending);
                cout << "Linked list telah diurutkan dengan Insertion Sort.\n";
                break;
            case 4:
                cout << "1. Ascending\n";
                cout << "2. Descending\n";
                cout << "Masukkan pilihan: ";
                cin >> sortChoice;
                ascending = (sortChoice == 1);
                mergeSort(&head, ascending);
                cout << "Linked list telah diurutkan dengan Merge Sort.\n";
                break;
            case 5:
                cout << "Isi linked list: ";
                printList(head);
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (true);

    return 0;
}
