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
    identitasPasien* pasienBaru = new identitasPasien;
    pasienBaru ->ID = id;
    pasienBaru ->nama = nama;
    pasienBaru ->usia = usia;
    pasienBaru ->diagnosis = penyakit;
    head = pasienBaru;
}

// untuk menampilkan data pasien
void viewPasien(identitasPasien* head){
    identitasPasien* current = head;
    while(current != nullptr){
        cout << "|| ID Pasien || Nama Pasien || Usia || Diagnosa ||" << endl;
        cout << setw(10) << current->ID << setw(10) << current ->nama << setw(10) << current ->usia << setw(10) << current ->diagnosis << endl;
        cout << "==========================================" << endl;
        current = current ->next;
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