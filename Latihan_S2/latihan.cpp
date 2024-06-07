#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Barang {
    int id;
    string nama;
    int jumlah;
    float harga;
    Barang* next;
};

Barang* head = nullptr;
int currentId = 1; // Variabel untuk menyimpan ID terakhir yang digunakan

void perbaruiID() {
    Barang* temp = head;
    int id = 1;
    while (temp != nullptr) {
        temp->id = id++;
        temp = temp->next;
    }
}

void tambahBarang(string nama, int jumlah, float harga) {
    Barang* newBarang = new Barang;
    newBarang->id = currentId++; // Menggunakan currentId sebagai ID baru dan kemudian increment
    newBarang->nama = nama;
    newBarang->jumlah = jumlah;
    newBarang->harga = harga;
    newBarang->next = nullptr;

    if (head == nullptr) {
        head = newBarang;
    } else {
        Barang* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newBarang;
    }

    perbaruiID(); // Perbarui ID setelah menambahkan barang baru
}

void hapusBarang(string nama) {
    Barang* temp = head;
    Barang* prev = nullptr;

    while (temp != nullptr && temp->nama != nama) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Barang tidak ditemukan." << endl;
        return;
    }

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    perbaruiID(); // Panggil fungsi ini setelah penghapusan
    cout << "Barang berhasil dihapus." << endl;
}

void perbaruiBarang(string nama, string namaBaru, int jumlah, float harga) {
    Barang* temp = head;
    while (temp != nullptr) {
        if (temp->nama == nama) {
            temp->nama = namaBaru;
            temp->jumlah = jumlah;
            temp->harga = harga;
            cout << "Barang berhasil diperbarui." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Barang tidak ditemukan." << endl;
}

void tampilkanBarang() {
    Barang* temp = head;
    cout << left << setw(10) << "No." << setw(20) << "Nama Barang" 
         << setw(10) << "Jumlah" << setw(10) << "Harga" << endl;
    cout << "-----------------------------------------------------" << endl;
    while (temp != nullptr) {
        cout << left << setw(10) << temp->id << setw(20) << temp->nama 
             << setw(10) << temp->jumlah << setw(10) << temp->harga << endl;
        temp = temp->next;
    }
}

void shellSort() {
    int n = 0;
    Barang* temp = head;
    while (temp != nullptr) {
        n++;
        temp = temp->next;
    }

    int gap, i, j;
    Barang** array = new Barang*[n];
    temp = head;

    for (i = 0; i < n; i++) {
        array[i] = temp;
        temp = temp->next;
    }

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            Barang* temp = array[i];
            for (j = i; j >= gap && array[j - gap]->id > temp->id; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }

    head = array[0];
    temp = head;
    for (i = 1; i < n; i++) {
        temp->next = array[i];
        temp = temp->next;
    }
    temp->next = nullptr;
    delete[] array;

    perbaruiID(); // Pastikan ID diperbarui setelah sorting
}

Barang* sequentialSearch(string nama) {
    Barang* temp = head;
    while (temp != nullptr) {
        if (temp->nama == nama) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

int main() {
    int pilihan, jumlah;
    string nama, namaBaru;
    float harga;

    do {
        cout << "Menu:\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Hapus Barang\n";
        cout << "3. Perbarui Barang\n";
        cout << "4. Tampilkan Barang\n";
        cout << "5. Urutkan Barang (Shell Sort)\n";
        cout << "6. Cari Barang (Sequential Search)\n";
        cout << "7. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Barang: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Jumlah Barang: ";
                cin >> jumlah;
                cout << "Masukkan Harga Barang: ";
                cin >> harga;
                tambahBarang(nama, jumlah, harga);
                cout << "Barang berhasil ditambahkan." << endl;
                break;
            case 2:
                cout << "Masukkan Nama Barang yang akan dihapus: ";
                cin.ignore();
                getline(cin, nama);
                hapusBarang(nama);
                break;
            case 3:
                cout << "Masukkan Nama Barang yang akan diperbarui: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Nama Barang Baru: ";
                getline(cin, namaBaru);
                cout << "Masukkan Jumlah Barang Baru: ";
                cin >> jumlah;
                cout << "Masukkan Harga Barang Baru: ";
                cin >> harga;
                perbaruiBarang(nama, namaBaru, jumlah, harga);
                break;
            case 4:
                tampilkanBarang();
                break;
            case 5:
                shellSort();
                cout << "Barang berhasil diurutkan menggunakan Shell Sort." << endl;
                break;
            case 6:
                cout << "Masukkan Nama Barang yang dicari: ";
                cin.ignore();
                getline(cin, nama);
                {
                    Barang* result = sequentialSearch(nama);
                    if (result != nullptr) {
                        cout << "Barang ditemukan:" << endl;
                        cout << "ID: " << result->id << endl;
                        cout << "Nama: " << result->nama << endl;
                        cout << "Jumlah: " << result->jumlah << endl;
                        cout << "Harga: " << result->harga << endl;
                    } else {
                        cout << "Barang tidak ditemukan." << endl;
                    }
                }
                break;
            case 7:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != 7);

    return 0;
}
