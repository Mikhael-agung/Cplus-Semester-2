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
};

void viewList(Node* head){
    Node* temp = head;
    while (temp){
        cout << temp-> data << " ";
        temp = temp-> next;
    };
    cout << endl;   
};

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

void bubbleSortWithFlag(Node* head, bool ascending) {
    if (head == nullptr) return;
    bool swapped;
    Node* lptr = nullptr;

    do {
        swapped = false;
        Node* ptr1 = head;

        while (ptr1->next != lptr) {
            if (ascending ? (ptr1->data > ptr1->next->data) : (ptr1->data < ptr1->next->data)) {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
        viewList(head);  // Cetak linked list setelah setiap iterasi
    } while (swapped);
}

int main() {
    Node* head = nullptr;
    int data[] = {2, 10, 3, 1, 17, 25, 16, 9, 18};
    int n = sizeof(data) / sizeof(data[0]);
    int pilihan;

    for (int i = 0; i < n; i++) {
        append(head, data[i]);
    }

    cout << "Linked List sebelum di urutka: ";
    viewList(head);
    do
    {
        cout << "Pilih metode pengurutan:\n";
        cout << "1. Ascending\n";
        cout << "2. Descending\n";
        cout << "3. keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;    

        switch(pilihan){
            case 1:
                bubbleSortWithFlag(head, true);
                cout << "Hasil pengurutan Ascending: ";
                viewList(head);
                break;
            case 2: 
                bubbleSortWithFlag(head, false);
                cout << "Hasil Pengurutan Descending: ";
                viewList(head);
                break;
            case 3:
                cout << "Terima kasih telah menggunakan program ini" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
            }
    } while (pilihan != 3);
    return 0;
}