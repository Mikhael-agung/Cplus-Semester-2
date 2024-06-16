#include <iostream>
#include "data.h"

using namespace std;

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
