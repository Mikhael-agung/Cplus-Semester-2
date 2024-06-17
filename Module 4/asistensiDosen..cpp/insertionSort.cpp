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

void insertionSort(Node*& head, bool ascending){
    if(head == nullptr) return;

    Node* current = head;
    Node* sorted = nullptr;
    
    while(current != nullptr){
        Node* next = current-> next;
        if (sorted == nullptr || (ascending ? sorted-> data >= current-> data : sorted-> data <= current-> data)){
            current-> next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while(temp-> next != nullptr && (ascending ? temp-> next-> data < current-> data : temp-> next-> data > current-> data)){
                temp = temp-> next;
            }
            current-> next = temp-> next;
            temp-> next = current;
        }
        current = next;
        viewList(sorted);
    }
    head = sorted;
}


int main(){
    Node* head = nullptr;
    int pilihan;
    int data[] = {2, 10, 3, 1, 17, 25, 16, 9, 18};
    size_t n = sizeof(data) / sizeof(data[0]);


    for (size_t i = 0; i < n; i++){
        append(head, data[i]);
    }

    cout << "Data asli: ";
    viewList(head);

    do
    {
    cout << "Pilih mentode pengurutan: \n";
    cout << "1. Ascending\n";
    cout << "2. Descending\n";  
    cout << "3. Keluar\n";
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

        switch (pilihan){
            case 1:
                cout << "Proses pengurutan dengan ascending\n";
                insertionSort(head, true);
                cout << "Hasil pengurutan dengan ascending: ";
                viewList(head);
                break;

            case 2:
                cout << "Proses pengurutan dengan descending\n";
                insertionSort(head, false);
                cout << "Hasil pengurutan dengan descending: ";
                viewList(head);
                break;

            case 3:
                cout << "Keluar dari program\n";
                break;

            default:    
                cout << "Pilihan tidak valid\n";
                break;
            }
    } while (pilihan != 3);

    return 0;
}