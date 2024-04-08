#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct identitasPasien{
    int ID;
    string nama;
    int usia;
    string diagnosis;
    identitasPasien* next;
};

// untuk menambahkan pasien
void addPasien(identitasPasien*& head, int id, string nama, int usia, string penyakit){
    // Validasi ID apakah sudah pernah terdaftar sebelumnya
    identitasPasien* current = head;
    while(current != nullptr){
        if(current->ID == id){
            cout << "Maaf ID yang anda masukan sudah terdaftar." << endl;
            return;
        }
        current = current ->next;
    }

    identitasPasien* pasienBaru = new identitasPasien;
    pasienBaru ->ID = id;
    pasienBaru ->nama = nama;
    pasienBaru ->usia = usia;
    pasienBaru ->diagnosis = penyakit;
    head = pasienBaru;

    if (head == nullptr){
        head = pasienBaru;
    } else {
        current = head;
        while(current ->next != nullptr){
            current = current ->next;
        }
        current ->next = pasienBaru;
    }
    
}

// untuk menampilkan data pasien
void viewPasien(identitasPasien* head){
    identitasPasien* current = head;
    while(current != nullptr){
        cout << "|| ID Pasien || Nama Pasien || Usia || Diagnosa ||" << endl;
        while (current != nullptr){
        cout << setw(10) << current->ID << setw(10) << current ->nama << setw(10) << current ->usia << setw(10) << current ->diagnosis << endl;
        current = current ->next;
        }
        cout << "==========================================" << endl;
    }
}


int main (){
    int pilihan;
    int id, usia;
    string nama, diagnosis;
    identitasPasien* head = nullptr;

    do
    {
        cout << "PRI APP" << endl;
        cout << "1. Tambah Pasien\n2. Tampilkan Pasien\n3. Cari Pasien\n4. Hapus Pasien\n5. Exit\n";
        cout << "Masukan Pilihan anda: ";
        cin >> pilihan ;
        switch (pilihan)
        {
        case 1:
            cout << "Masukan ID pasien: ";
            cin >> id;
            cout << "Masukan nama pasien: ";
            cin >> nama;
            cout << "Masukan Usia Pasien: ";
            cin >> usia;
            cout << "Masukan Diagnosis: ";
            cin >> diagnosis; 
            addPasien(head, id, nama, usia, diagnosis);
            break;

        case 2:
            viewPasien(head);
            break;  

        case 3:

            break;

        case 4:

            break;

        case 5:
            cout << "Terima kasih sudah menggunakan program ini";
            break;
        
        default:
            cout << "Pilihan yang anda masukan tidak ada.";
            break;
        }
    } while (pilihan != 5);
    

}