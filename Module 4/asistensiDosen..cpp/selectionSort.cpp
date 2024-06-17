#include <iostream>
using namespace std;

// Struktur node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Fungsi untuk melakukan selection sort
void selectionSort(Node* head, bool ascending) {
    if (head == nullptr) return;

    Node* current = head;

    while (current != nullptr) {
        Node* minMax = current;
        Node* next = current->next;

        while (next != nullptr) {
            if (ascending ? (next->data < minMax->data) : (next->data > minMax->data)) {
                minMax = next;
            }
            next = next->next;
        }

        if (minMax != current) {
            swap(current->data, minMax->data);
        }
        
        current = current->next;
        printList(head);  // Cetak linked list setelah setiap iterasi
    }
}

int main() {
    Node* head = nullptr;
    int data[] = {2, 10, 3, 1, 17, 25, 16, 9, 18};
    size_t n = sizeof(data) / sizeof(data[0]);

    // Menambahkan data ke linked list
    for (size_t i = 0; i < n; i++) {
        append(head, data[i]);
    };

    cout << "Data asli: ";
    printList(head);

    int choice;
    cout << "Pilih metode pengurutan:\n";
    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    cout << "Pilihan Anda: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "\nProses pengurutan secara ascending:\n";
            selectionSort(head, true);
            break;
        case 2:
            cout << "\nProses pengurutan secara descending:\n";
            selectionSort(head, false);
            break;
        default:
            cout << "Pilihan tidak valid!\n";
    }

    cout << "\nHasil pengurutan: ";
    printList(head);

    return 0;
}
