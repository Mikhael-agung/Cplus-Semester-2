#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
    string jurusan;
    Mahasiswa* next;
    Mahasiswa* prev;
};

Mahasiswa* awal = NULL;
Mahasiswa* akhir = NULL;
Mahasiswa* baru;
Mahasiswa* bantu;

void tambahDepan(string nama, int umur, string jurusan) {
    baru = new Mahasiswa;
    baru->nama = nama;
    baru->umur = umur;
    baru->jurusan = jurusan;
    baru->next = NULL;
    baru->prev = NULL;

    if (awal == NULL) {
        awal = baru;
        akhir = baru;
    } else {
        baru->next = awal;
        awal->prev = baru;
        awal = baru;
    }
}

void tambahTengah(string nama, int umur, string jurusan, int posisi) {
    bantu = awal;
    for(int i=1;i<posisi;i++){
        if(bantu->next!=NULL){
            bantu = bantu->next;
        }else{
            cout<<"Posisi Tidak valid\n";
            return;       
        }
    }

    baru = new Mahasiswa;
    baru->nama = nama;
    baru->umur = umur;
    baru->jurusan = jurusan;
    baru->next = bantu->next;
    baru->prev = bantu;
    bantu->next = baru;

    if(baru->next!=NULL){
        baru->next->prev= baru;
    }
}

void tambahBelakang(string nama, int umur, string jurusan) {
    baru = new Mahasiswa;
    baru->nama = nama;
    baru->umur = umur;
    baru->jurusan = jurusan;
    baru->next = NULL;
    baru->prev = NULL;

    if (akhir == NULL) {
        awal = baru;
        akhir = baru;
    } else {
        akhir->next = baru;
        baru->prev = akhir;
        akhir = baru;
    }
}

void hapusDepan(){
    if(awal == NULL){
        cout<<"List Kosong, tidak ada yang bisa dihapus\n";
        return;
    }

    Mahasiswa* hapus = awal;
    awal = awal->next;
    if(awal != NULL){
        awal->prev = NULL;
    }else{
        akhir = NULL;
    }
    delete hapus;
    cout<<"Data di depan berhasil dihapus.\n";
}

void hapusBelakang(){
    if(awal == NULL){
        cout<<"List Kosong, tidak ada yang bisa dihapus\n";
        return;
    }

    Mahasiswa* hapus;
    if(awal == akhir){
        hapus = awal;
        awal = NULL;
        akhir = NULL;
    }else{
        hapus = akhir;
        akhir = akhir->prev;
        akhir->next = NULL;
    }
    delete hapus;
    cout<<"Data di belakang berhasil dihapus.\n";
}

void hapusTengah(int posisi){
    if(awal == NULL){
        cout<<"List Kosong, data tidak ada yang berhasil di hapus\n";
        return;
    }

    if(posisi == 1){
        hapusDepan();
        return;
    }

    Mahasiswa* hapus;
    Mahasiswa* bantu = awal;
    for(int i=0;i<posisi-1;i++){
        if(bantu->next != NULL){
            bantu = bantu->next;
        }else{
            cout<<"Tidak Valid\n";
            return;
        }
    }

    hapus = bantu->next;
    bantu->next = hapus->next;
    if(hapus->next != NULL){
        hapus->next->prev = bantu;
    }
    delete hapus;
    cout<<"Data Di Posisi tengah ke-"<<posisi<<"Berhasil dihapus\n";
}

void tampilkanDataMahasiswa() {
    bantu = awal;
    while (bantu != NULL) {
        cout << "\nNama: " << bantu->nama << endl;
        cout << "Umur: " << bantu->umur << endl;
        cout << "Jurusan: " << bantu->jurusan << endl;
        bantu = bantu->next;
    }
}

/**
 * @brief The main function of the program.
 * 
 * @return int The exit status of the program.
 */
int main() {
    string nama, jurusan;
    int umur;
    int pilihan;
    int posisi;

    do {
        cout << "\tPROGRAM DATA MAHASISWA\n";
        cout << "1. Tambah Data Mahasiswa di Depan\n";
        cout << "2. Tambah Data Mahasiswa di Belakang\n";
        cout << "3. Tambah Data Mahasiswa di Tengah\n";
        cout << "4. Hapus Data Mahasiswa di Depan\n";
        cout << "5. Hapus Data Mahasiswa di Belakang\n";
        cout << "6. Hapus Data Mahasiswa di Tengah\n";
        cout << "7. Tampilkan Data Mahasiswa\n";
        cout << "8. Keluar\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Umur Mahasiswa: ";
                cin >> umur;
                cout << "Masukkan Jurusan Mahasiswa: ";
                cin.ignore();
                getline(cin, jurusan);
                tambahDepan(nama, umur, jurusan);
                break;
            case 2:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Umur Mahasiswa: ";
                cin >> umur;
                cout << "Masukkan Jurusan Mahasiswa: ";
                cin.ignore();
                getline(cin, jurusan);
                tambahBelakang(nama, umur, jurusan);
                break;
            case 3:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Umur Mahasiswa: ";
                cin >> umur;
                cout << "Masukkan Jurusan Mahasiswa: ";
                cin.ignore();
                getline(cin, jurusan);
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                tambahTengah(nama, umur, jurusan, posisi);
                break;
            case 4:
                hapusDepan();
                break;
            case 5:
                hapusBelakang();
                break;
            case 6:
                cout << "Daftar Data Mahasiswa:\n";
                tampilkanDataMahasiswa();
                break;
            case 7:
                cout << "Masukkan Posisi Tengah yang ingin di Hapus :";
                cin >> posisi;
                hapusTengah(posisi);
                break;
            case 8:
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 8);

    return 0;
}