// main.cpp

#include <iostream>
#include <string>
#include <iomanip> // For setw()

using namespace std;

struct Pasien
{
    int ID;
    string nama;
    int usia;
    string diagnosis;
    Pasien *next;
};

// Fungsi untuk menambahkan pasien baru ke linked list
void tambahPasien(Pasien *&head, int id, string nama, int usia, string diagnosa)
{
    Pasien *current = head;
    while (current != nullptr)
    {
        if (current->ID == id)
        {
            cout << "Maaf, ID yang Anda masukkan sudah terdaftar." << endl;
            return;
        }
        current = current->next;
    }

    Pasien *pasienBaru = new Pasien;
    pasienBaru->ID = id;
    pasienBaru->nama = nama;
    pasienBaru->usia = usia;
    pasienBaru->diagnosis = diagnosa;
    pasienBaru->next = nullptr;

    if (head == nullptr)
    {
        head = pasienBaru;
    }
    else
    {
        current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = pasienBaru;
    }
}

// Fungsi untuk menampilkan semua pasien dalam linked list
void viewPasien(Pasien *head)
{
    Pasien *current = head;
    cout << "|| ID Pasien || Nama Pasien || Usia || Diagnosa ||" << endl;
    while (current != nullptr)
    {
        cout << "|| " << setw(10) << current->ID << " "
             << setw(12) << current->nama << " "
             << setw(5) << current->usia << " "
             << setw(10) << current->diagnosis << " ||" << endl;
        current = current->next;
    }
    cout << "===========================================" << endl;
}

// Fungsi untuk mencari pasien berdasarkan ID atau nama
void cariPasien(Pasien *head, int id, string n)
{
    Pasien *current = head;
    bool found = false;
    while (current != nullptr)
    {
        if (current->ID == id || current->nama == n)
        {
            cout << "ID Pasien: " << current->ID << endl;
            cout << "Nama: " << current->nama << endl;
            cout << "Usia: " << current->usia << endl;
            cout << "Diagnosis: " << current->diagnosis << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found)
    {
        cout << "Pasien dengan ID " << id << " atau nama " << n << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk menghapus pasien dari linked list berdasarkan ID
void hapusPasien(Pasien *&head, int id)
{
    Pasien *current = head;
    Pasien *prev = nullptr;

    while (current != nullptr && current->ID != id)
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Pasien dengan ID " << id << " tidak ditemukan." << endl;
        return;
    }

    if (prev == nullptr)
    {
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    delete current;
    cout << "Pasien dengan ID " << id << " berhasil dihapus." << endl;
}

int main()
{
    Pasien *head = nullptr;
    int pilihan;
    int id, usia;
    string nama, diagnosis;

    do
    {
        cout << "1. Tambah Pasien\n2. Tampilkan Pasien\n3. Cari Pasien\n4. Hapus Pasien\n5. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
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
            viewPasien(head);
            break;
        case 3:
            cout << "Masukkan ID atau Nama Pasien yang akan dicari: ";
            cin >> id >> nama;
            cariPasien(head, id, nama);
            break;
        case 4:
            cout << "Masukkan ID Pasien yang akan dihapus: ";
            cin >> id;
            hapusPasien(head, id);
            break;
        case 5:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);

    // Membersihkan memori
    Pasien *current = head;
    while (current != nullptr)
    {
        Pasien *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}