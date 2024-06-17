#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan elemen ke linked list
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

// Merge dua sublist untuk merge sort
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

// Membagi linked list menjadi dua bagian
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

// Merge Sort untuk linked list
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

int main() {
    Node* head = nullptr;
    int value;

    cout << "Masukkan nilai ke linked list (masukkan -1 untuk berhenti):" << endl;
    while (true) {
        cin >> value;
        if (value == -1) break;
        append(&head, value);
    }

    int choice;
    bool ascending;
    do {
        cout << "\nPilih metode pengurutan:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Cetak linked list\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        if (choice == 6) break;

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
                cout << "1. Ascending\n";
                cout << "2. Descending\n";
                cout << "Masukkan pilihan: ";
                int sortChoice;
                cin >> sortChoice;
                ascending = (sortChoice == 1);

                if (choice == 1) {
                    bubbleSort(head, ascending);
                    cout << "Linked list telah diurutkan dengan Bubble Sort.\n";
                } else if (choice == 2) {
                    selectionSort(head, ascending);
                    cout << "Linked list telah diurutkan dengan Selection Sort.\n";
                } else if (choice == 3) {
                    insertionSort(&head, ascending);
                    cout << "Linked list telah diurutkan dengan Insertion Sort.\n";
                } else if (choice == 4) {
                    mergeSort(&head, ascending);
                    cout << "Linked list telah diurutkan dengan Merge Sort.\n";
                }
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
