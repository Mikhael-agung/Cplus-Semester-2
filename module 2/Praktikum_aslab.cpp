// main.cpp

#include <iostream>
#include <string>

using namespace std;

struct Pasien {
    int ID;
    string nama;
    int usia;
    string diagnosis;
    Pasien* next;
};

// Fungsi untuk menambahkan pasien baru ke linked list
void tambahPasien(Pasien*& head, int id, string n, int a, string d) {
    Pasien* pasienBaru = new Pasien;
    pasienBaru->ID = id;
    pasienBaru->nama = n;
    pasienBaru->usia = a;
    pasienBaru->diagnosis = d;
    pasienBaru->next = head;
    head = pasienBaru;
}

// Fungsi untuk menampilkan semua pasien dalam linked list
void tampilkanPasien(Pasien* head) {
    Pasien* current = head;
    while (current != nullptr) {
        cout << "ID Pasien: " << current->ID << endl;
        cout << "Nama: " << current->nama << endl;
        cout << "Usia: " << current->usia << endl;
        cout << "Diagnosis: " << current->diagnosis << endl;
        cout << "---------------------" << endl;
        current = current->next;
    }
}

// Fungsi untuk menghapus pasien dari linked list berdasarkan ID
void hapusPasien(Pasien*& head, int id) {
    Pasien* current = head;
    Pasien* prev = nullptr;

    while (current != nullptr && current->ID != id) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Pasien dengan ID " << id << " tidak ditemukan." << endl;
        return;
    }

    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
    cout << "Pasien dengan ID " << id << " berhasil dihapus." << endl;
}

int main() {
    Pasien* head = nullptr;
    int pilihan;
    int id, usia;
    string nama, diagnosis;

    do {
        cout << "1. Tambah Pasien\n2. Tampilkan Pasien\n3. Hapus Pasien\n4. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan ID Pasien: ";
                cin >> id;
                cout << "Masukkan Nama Pasien: ";
                cin >> nama;
                cout << "Masukkan Usia Pasien: ";
                cin >> usia;
                cout << "Masukkan Diagnosis Pasien: ";
                cin >> diagnosis;
                tambahPasien(head, id, nama, usia, diagnosis);
                break;
            case 2:
                tampilkanPasien(head);
                break;
            case 3:
                cout << "Masukkan ID Pasien yang akan dihapus: ";
                cin >> id;
                hapusPasien(head, id);
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    // Membersihkan memori
    Pasien* current = head;
    while (current != nullptr) {
        Pasien* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}