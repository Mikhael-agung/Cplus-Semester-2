#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Barang_07651 {
    string nama_07651;
    Barang_07651* next;
};

struct Stack_07651 {
    Barang_07651* top;
};

void initStack(Stack_07651& barang) {
    barang.top = nullptr;
}

void push(Stack_07651& barang, const string& nama) {
    Barang_07651* newBarang = new Barang_07651;
    newBarang->nama_07651 = nama;
    newBarang->next = barang.top;
    barang.top = newBarang;
    cout << "Barang berhasil ditambahkan." << endl;
}

void viewBarang(const Stack_07651& barang) {
    if (!barang.top) {
        cout << "Gudang Barang kosong." << endl;
        return;
    }

    cout << "List Barang Yang ada di gudang." << endl;
    cout << "No. || Nama Barang ||" << endl;

    Barang_07651* current = barang.top;
    int count = 1;
    while (current) {
        cout << count << setw(15) << current->nama_07651 << endl;
        current = current->next;
        count++;
    }
}

void ambilBarang(Stack_07651& barang) {
    if (!barang.top) {
        cout << "Gudang kosong. Tidak ada barang yang bisa diambil." << endl;
        return;
    }

    Barang_07651* temp = barang.top;
    barang.top = barang.top->next;
    cout << "Barang " << temp->nama_07651 << " berhasil diambil." << endl;
    delete temp;

};

int main() {
    Stack_07651 Gudang;
    initStack(Gudang);

    int pilihan;
    do {
        cout << "Pengelolahan Barang gudang PT. Gudang Gula" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Tampilkan Nama Barang" << endl;
        cout << "3. Ambil Barang" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukan Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            string nama;
            cin.ignore();
            cout << "Masukan Nama Barang: ";
            getline(cin, nama);
            push(Gudang, nama);
            break;
        }

        case 2:
            viewBarang(Gudang);
            break;

        case 3:
            ambilBarang(Gudang);
            break;

        case 4:
            cout << "Program selesai" << endl;
            break;

        default:
            cout << "Pilihan Yang anda pilih tidak ada." << endl;
            break;
        }
    } while (pilihan != 4);

    return 0;
}
